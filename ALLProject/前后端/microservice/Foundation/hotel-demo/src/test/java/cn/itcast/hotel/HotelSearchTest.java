package cn.itcast.hotel;

import cn.itcast.hotel.pojo.HotelDoc;
import com.alibaba.fastjson.JSON;
import org.apache.http.HttpHost;
import org.elasticsearch.action.search.SearchRequest;
import org.elasticsearch.action.search.SearchResponse;
import org.elasticsearch.client.RequestOptions;
import org.elasticsearch.client.RestClient;
import org.elasticsearch.client.RestHighLevelClient;
import org.elasticsearch.index.query.BoolQueryBuilder;
import org.elasticsearch.index.query.QueryBuilders;
import org.elasticsearch.search.SearchHit;
import org.elasticsearch.search.SearchHits;
import org.elasticsearch.search.aggregations.AggregationBuilders;
import org.elasticsearch.search.aggregations.Aggregations;
import org.elasticsearch.search.aggregations.bucket.terms.Terms;
import org.elasticsearch.search.fetch.subphase.highlight.HighlightBuilder;
import org.elasticsearch.search.fetch.subphase.highlight.HighlightField;
import org.elasticsearch.search.sort.SortOrder;
import org.elasticsearch.search.suggest.Suggest;
import org.elasticsearch.search.suggest.SuggestBuilder;
import org.elasticsearch.search.suggest.SuggestBuilders;
import org.elasticsearch.search.suggest.completion.CompletionSuggestion;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.util.CollectionUtils;

import java.io.IOException;
import java.util.List;
import java.util.Map;

public class HotelSearchTest {
    private RestHighLevelClient client;

    /**
     * 查询所有
     * @throws IOException
     */
    @Test
    void testMatchAll() throws IOException {
        // 1. 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2. 准备DSL
        request.source()
                .query(QueryBuilders.matchAllQuery());
        // 3. 发送请求
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);

        // 4. 解析响应结果
        handleResponse(response);
        // System.out.println("matchAll查询结果是： " + response);
    }

    /**
     * match查询
     * @throws IOException
     */
    @Test
    void testMatch() throws IOException {
        // 1. 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2. 准备DSL
        request.source()
                .query(QueryBuilders.matchQuery("all", "如家"));
        // 3. 发送请求
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);
        // 4. 解析响应结果
        handleResponse(response);
        // System.out.println("match查询结果是： " + response);
    }

    /**
     * boolean查询
     * @throws IOException
     */
    @Test
    void testBool() throws IOException {
        // 1. 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2. 准备DSL
        // 2.1 准备BooleanQuery
        BoolQueryBuilder booledQuery = QueryBuilders.boolQuery();
        // 2.2 添加term
        booledQuery.must(QueryBuilders.termQuery("city", "深圳"));
        // 2.3 添加range
        booledQuery.filter(QueryBuilders.rangeQuery("price").lte(250).gt(150));

        request.source().query(booledQuery);
        // 3. 发送请求
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);
        // 4. 解析响应结果
        handleResponse(response);
        // System.out.println("match查询结果是： " + response);
    }


    /**
     * 分页和排序查询
     * @throws IOException
     */
    @Test
    void testPageAndSort() throws IOException {
        // 1. 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2. 准备DSL
        request.source()
                .query(QueryBuilders.matchAllQuery())   // 查询所有
                .sort("price", SortOrder.ASC)     // 排序，顺序
                .from(0).size(10);                      // 分页
        // 3. 发送请求
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);
        // 4. 解析响应结果
        handleResponse(response);
        // System.out.println("match查询结果是： " + response);
    }

    /**
     * 高亮显示查询
     * @throws IOException
     */
    @Test
    void testHighLight() throws IOException {
        // 1. 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2. 准备DSL
        request.source()
                .query(QueryBuilders.matchQuery("all", "如家"))
                .highlighter(new HighlightBuilder()
                        .field("name")
                        .requireFieldMatch(false)
                );
        // 3. 发送请求
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);
        // 4. 解析响应结果
        handleResponse(response);
        // System.out.println("match查询结果是： " + response);
    }

    /**
     * 抽取的代码-解析响应结果
     * @param response
     */
    private static void handleResponse(SearchResponse response) {
        // 4. 打印结果
        SearchHits searchHits = response.getHits();
        // 4.1 获取总条数
        long total = searchHits.getTotalHits().value;
        System.out.println("总共搜索到" + total + "条数据");
        // 4.2 文档数组
        SearchHit[] hits = searchHits.getHits();
        // 4.3 遍历
        for (SearchHit hit : hits) {
            // 获取文档源source
            String json = hit.getSourceAsString();
            // 反序列化
            HotelDoc hotelDoc = JSON.parseObject(json, HotelDoc.class);
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
            System.out.println("hotelDoc = " + hotelDoc);
        }
    }


    /**
     * 搜索聚合
     * @throws IOException
     */
    @Test
    void testAggregation() throws IOException {
        // 1 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2 准备DSL
        // 2.1 设置size
        request.source().size(0);
        // 2.2 聚合
        request.source().aggregation(AggregationBuilders
                .terms("brand_agg")
                .field("brand")
                .size(20));
        // 3 发送请求
        SearchResponse response = client.search(request, RequestOptions.DEFAULT);
        // 4 解析结果
        // System.out.println(response);
        handleResponse2(response);
    }

    private static void handleResponse2(SearchResponse response) {
        // 1 解析所有结果
        Aggregations aggregations = response.getAggregations();
        // 2 根据名称获取聚合结果
        Terms brandAgg = aggregations.get("brand_agg");
        // 3 获取桶
        List<? extends Terms.Bucket> buckets = brandAgg.getBuckets();
        // 4 遍历
        for (Terms.Bucket bucket : buckets) {
            String keyAsString = bucket.getKeyAsString();
            System.out.println(keyAsString);
        }
    }


    /**
     * Suggestion 自动补全
     * @throws IOException
     */
    @Test
    void testSuggestion() throws IOException {
        // 1. 准备Request
        SearchRequest request = new SearchRequest("hotel");
        // 2. 准备DSL
        request.source().suggest(new SuggestBuilder().addSuggestion(
                "suggestions",
                SuggestBuilders.completionSuggestion("suggestion")
                        .prefix("h")
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
        for (CompletionSuggestion.Entry.Option option : options) {
            String text = option.getText().toString();
            System.out.println(text);
        }
    }

    @BeforeEach
    void setUp() {
        this.client = new RestHighLevelClient(RestClient.builder(
                HttpHost.create("http://192.168.209.130:9200")
        ));
    }

    @AfterEach
    void tearDown() throws IOException {
        this.client.close();
    }
}
