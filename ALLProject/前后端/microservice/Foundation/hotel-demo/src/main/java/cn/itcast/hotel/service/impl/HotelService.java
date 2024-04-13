package cn.itcast.hotel.service.impl;

import cn.itcast.hotel.mapper.HotelMapper;
import cn.itcast.hotel.pojo.Hotel;
import cn.itcast.hotel.pojo.HotelDoc;
import cn.itcast.hotel.pojo.PageResult;
import cn.itcast.hotel.pojo.RequestParams;
import cn.itcast.hotel.service.IHotelService;
import com.alibaba.fastjson.JSON;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.elasticsearch.action.delete.DeleteRequest;
import org.elasticsearch.action.index.IndexRequest;
import org.elasticsearch.action.search.SearchRequest;
import org.elasticsearch.action.search.SearchResponse;
import org.elasticsearch.client.RequestOptions;
import org.elasticsearch.client.RestHighLevelClient;
import org.elasticsearch.common.geo.GeoPoint;
import org.elasticsearch.common.unit.DistanceUnit;
import org.elasticsearch.common.xcontent.XContentType;
import org.elasticsearch.index.query.BoolQueryBuilder;
import org.elasticsearch.index.query.QueryBuilders;
import org.elasticsearch.index.query.functionscore.FunctionScoreQueryBuilder;
import org.elasticsearch.index.query.functionscore.ScoreFunctionBuilders;
import org.elasticsearch.search.SearchHit;
import org.elasticsearch.search.SearchHits;
import org.elasticsearch.search.aggregations.AggregationBuilders;
import org.elasticsearch.search.aggregations.Aggregations;
import org.elasticsearch.search.aggregations.bucket.terms.Terms;
import org.elasticsearch.search.fetch.subphase.highlight.HighlightField;
import org.elasticsearch.search.sort.SortBuilders;
import org.elasticsearch.search.sort.SortOrder;
import org.elasticsearch.search.suggest.Suggest;
import org.elasticsearch.search.suggest.SuggestBuilder;
import org.elasticsearch.search.suggest.SuggestBuilders;
import org.elasticsearch.search.suggest.completion.CompletionSuggestion;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.CollectionUtils;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Service
public class HotelService extends ServiceImpl<HotelMapper, Hotel> implements IHotelService {

    @Autowired
    private RestHighLevelClient client;

    @Autowired
    private HotelService hotelService;

    @Override
    public PageResult search(RequestParams params) throws IOException {
        // 1. 准备request
        SearchRequest request = new SearchRequest("hotel");
        // 2. 准备DSL
        // 2.1 query
        buildBasicqQuery(params, request);
        // 3. 分页
        int page = params.getPage();
        int size = params.getSize();
        request.source().from((page - 1) * size).size(size);
        // 2.3 排序
        String location = params.getLocation();
        if (location != null && !location.equals("")) {
            request.source().sort(SortBuilders
                    .geoDistanceSort("location", new GeoPoint(location))
                    .order(SortOrder.ASC)
                    .unit(DistanceUnit.KILOMETERS)
            );
        }
        // 3. 发送请求，得到响应
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);
        // 4. 解析响应
        return handleResponse(response);
    }

    private static void buildBasicqQuery(RequestParams params, SearchRequest request) {
        // 构建BooleanQuery
        BoolQueryBuilder booledQuery = QueryBuilders.boolQuery();
        // 关键词搜搜
        String key = params.getKey();
        if (key == null || "".equals(key)) {
            booledQuery.must(QueryBuilders.matchAllQuery());
        } else {
            booledQuery.must(QueryBuilders.matchQuery("all", key));
        }
        // 3.城市条件
        if (params.getCity() != null && !params.getCity().equals("")) {
            booledQuery.filter(QueryBuilders.termQuery("city", params.getCity()));
        }
        // 4.品牌条件
        if (params.getBrand() != null && !params.getBrand().equals("")) {
            booledQuery.filter(QueryBuilders.termQuery("brand", params.getBrand()));
        }
        // 5.星级条件
        if (params.getStarName() != null && !params.getStarName().equals("")) {
            booledQuery.filter(QueryBuilders.termQuery("starName", params.getStarName()));
        }
        // 6.价格
        if (params.getMinPrice() != null && params.getMaxPrice() != null) {
            booledQuery.filter(QueryBuilders
                    .rangeQuery("price")
                    .gte(params.getMinPrice())
                    .lte(params.getMaxPrice())
            );
        }

        // 2. 算分控制
        FunctionScoreQueryBuilder functionScoreQuery =
                QueryBuilders.functionScoreQuery(
                        // 原始查询，相关性算分查询
                        booledQuery,
                        // function score的数组
                        new FunctionScoreQueryBuilder.FilterFunctionBuilder[]{
                                // 其中的一个function score 元素
                                new FunctionScoreQueryBuilder.FilterFunctionBuilder(
                                        // 过滤条件
                                        QueryBuilders.termQuery("isAD", true),
                                        // 算分函数
                                        ScoreFunctionBuilders.weightFactorFunction(10)
                                )
                        });

        // 7.放入source
        request.source().query(functionScoreQuery);
    }

    @Override
    public Map<String, List<String>> filters(RequestParams params) throws IOException {
        // 1 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2 准备DSL
        // 2.1 query
        buildBasicqQuery(params, request);
        // 2.2 设置size
        request.source().size(0);
        // 2.3 聚合
        buildAggregation(request);
        // 3 发送请求
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);
        // 4 解析结果
        Map<String, List<String>> result = new HashMap<>();
        // 4.1 解析所有结果
        Aggregations aggregations = response.getAggregations();
        // 4.2 根据品牌名称获取品牌结果
        List<String> brandList = getAggByName(aggregations, "brandAgg");
        result.put("brand", brandList);
        List<String> cityList = getAggByName(aggregations, "cityAgg");
        result.put("city", cityList);
        List<String> starList = getAggByName(aggregations, "starAgg");
        result.put("starName", starList);
        System.out.println(result);
        return  result;
    }

    @Override
    public List<String> getSuggestion(String prefix) throws IOException {
        // 1. 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2. 准备DSL
        request.source().suggest(new SuggestBuilder().addSuggestion(
                "suggestions",
                SuggestBuilders.completionSuggestion("suggestion")
                        .prefix(prefix)
                        .skipDuplicates(true)
                        .size(10)
        ));
        // 3. 发起请求
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);
        // 4. 解析结果
        // 4.1 获取结果
        Suggest suggest = response.getSuggest();
        // 4.2 根据名称获取解析结果
        CompletionSuggestion suggestion =  suggest.getSuggestion("suggestions");
        // 4.3 获取options
        List<CompletionSuggestion.Entry.Option> options = suggestion.getOptions();
        // 4.4 遍历
        ArrayList<String> list = new ArrayList<>(options.size());
        for (CompletionSuggestion.Entry.Option option : options) {
            String text = option.getText().toString();
            list.add(text);
        }
        return list;
    }

    /**
     * 根据id新增
     * @param id
     */
    @Override
    public void insertById(Long id) throws IOException {
        // 1 根据id找到
        Hotel hotel = hotelService.getById(id);
        // 2 转换为文档类型
        HotelDoc hotelDoc = new HotelDoc(hotel);
        // 3 转换为json
        String jsonString = JSON.toJSONString(hotelDoc);

        // 1 准备request
        IndexRequest request = new IndexRequest("hotel").id(hotelDoc.getId().toString());
        // 2 准备DSL
        request.source(jsonString, XContentType.JSON);
        // 3 发送请求
        client.index(request, RequestOptions.DEFAULT);
    }

    /**
     * 根据id删除
     * @param id
     */
    @Override
    public void deleteById(Long id) throws IOException {
        // 1 准备request
        DeleteRequest request = new DeleteRequest("hotel");
        // 2 发送请求
        client.delete(request, RequestOptions.DEFAULT);
    }

    private static List<String> getAggByName(Aggregations aggregations, String aggName) {
        // 4.2 根据名称获取聚合结果
        Terms brandAgg = aggregations.get(aggName);
        // 4.3 获取桶
        List<? extends Terms.Bucket> buckets = brandAgg.getBuckets();
        // 4.4 遍历
        List<String> brandList = new ArrayList<>();
        for (Terms.Bucket bucket : buckets) {
            String keyAsString = bucket.getKeyAsString();
            brandList.add(keyAsString);
        }
        return brandList;
    }

    /**
     * 聚合抽取
     * @param request
     */
    private static void buildAggregation(SearchRequest request) {
        request.source().aggregation(AggregationBuilders
                .terms("brandAgg")
                .field("brand")
                .size(20)
        );
        request.source().aggregation(AggregationBuilders
                .terms("cityAgg")
                .field("city")
                .size(20)
        );
        request.source().aggregation(AggregationBuilders
                .terms("starAgg")
                .field("starName")
                .size(20)
        );
    }


    /**
     * 抽取的代码-解析响应结果
     * @param response
     */
    private static PageResult handleResponse(SearchResponse response) {
        // 4. 打印结果
        SearchHits searchHits = response.getHits();
        // 4.1 获取总条数
        long total = searchHits.getTotalHits().value;
        // System.out.println("总共搜索到" + total + "条数据");
        // 4.2 文档数组
        SearchHit[] hits = searchHits.getHits();
        // 4.3 遍历
        ArrayList<HotelDoc> hotelDocs = new ArrayList<>();
        for (SearchHit hit : hits) {
            // 获取文档源source
            String json = hit.getSourceAsString();
            // 反序列化
            HotelDoc hotelDoc = JSON.parseObject(json, HotelDoc.class);
            // 获取排序值
            Object[] sortValues = hit.getSortValues();
            if (sortValues.length > 0) {
                Object sortValue = sortValues[0];
                hotelDoc.setDistance(sortValue);
            }
            // 获取高亮结果
            Map<String, HighlightField> highlightFields = hit.getHighlightFields();
            if (!CollectionUtils.isEmpty(highlightFields)) { // 增加代码的健壮性
                // 根据字段名字获取结果
                HighlightField highlightField = highlightFields.get("name");
                // 将结果拿出转换为字符串
                String name = highlightField.getFragments()[0].string();
                // 将结果覆盖文档
                hotelDoc.setName(name);
            }
            hotelDocs.add(hotelDoc);
            // System.out.println("hotelDoc = " + hotelDoc);
        }
        return new PageResult(total, hotelDocs);
    }

}
