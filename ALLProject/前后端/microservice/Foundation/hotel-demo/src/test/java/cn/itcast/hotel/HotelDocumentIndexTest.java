package cn.itcast.hotel;

import cn.itcast.hotel.pojo.Hotel;
import cn.itcast.hotel.pojo.HotelDoc;
import cn.itcast.hotel.service.impl.HotelService;
import com.alibaba.fastjson.JSON;
import org.apache.http.HttpHost;
import org.elasticsearch.action.bulk.BulkRequest;
import org.elasticsearch.action.delete.DeleteRequest;
import org.elasticsearch.action.get.GetRequest;
import org.elasticsearch.action.get.GetResponse;
import org.elasticsearch.action.index.IndexRequest;
import org.elasticsearch.action.update.UpdateRequest;
import org.elasticsearch.client.RequestOptions;
import org.elasticsearch.client.RestClient;
import org.elasticsearch.client.RestHighLevelClient;
import org.elasticsearch.common.xcontent.XContentType;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.io.IOException;
import java.util.List;

@SpringBootTest
public class HotelDocumentIndexTest {
    @Autowired
    private HotelService hotelService;

    private RestHighLevelClient client;

    @Test
    void testInit() {
        System.out.println(client);
    }

    /**
     * 根据id新增文档数据
     * @throws IOException
     */
    @Test
    void testAddDocument() throws IOException {
        // 根据id查询酒店数据
        Hotel hotel = hotelService.getById(61083L);
        // 转换为文档类型
        HotelDoc hotelDoc = new HotelDoc(hotel);

        // 1. 准备Request对象
        IndexRequest request = new IndexRequest("hotel").id(hotel.getId().toString());
        // 2. 准备Json文档
        request.source(JSON.toJSONString(hotelDoc), XContentType.JSON);
        // 3. 发送请求
        client.index(request, RequestOptions.DEFAULT);
    }

    /**
     * 查询文档
     * @throws IOException
     */
    @Test
    void testGetDocumentById() throws IOException {
        // 1. 准备Request
        GetRequest request = new GetRequest("hotel", "61083");
        // 2. 发送请求，得到响应
        GetResponse response = client.get(request, RequestOptions.DEFAULT);
        // 3. 解析响应结果
        String json = response.getSourceAsString();
        HotelDoc hotelDoc = JSON.parseObject(json, HotelDoc.class);
        System.out.println("查询结果： " + hotelDoc);
    }

    /**
     * 修改文档
     * @throws IOException
     */
    @Test
    void testUpdateDocumentById() throws IOException {
        // 1. 创建request对象
        UpdateRequest request = new UpdateRequest("hotel", "61083");
        // 2. 准备参数，每2个参数为一对 key value
        request.doc(
                "price", "952",
                "starName", "四钻"
        );
        // 3. 更新文档
        client.update(request,RequestOptions.DEFAULT);
    }

    /**
     * 删除文档
     * @throws IOException
     */
    @Test
    void testDeleteDocument() throws IOException {
        // 1. 准备Request
        DeleteRequest request = new DeleteRequest("hotel", "61083");
        // 2. 发送请求
        client.delete(request, RequestOptions.DEFAULT);
    }


    @Test
    void testBulkRequest() throws IOException {
        // 批量查询酒店数据
        List<Hotel> hotels = hotelService.list();
        // 1. 创建Request
        BulkRequest request = new BulkRequest();
        // 2. 准备参数，添加多个新增的Request

        // 转换为文档类型HotelDoc
        for (Hotel hotel : hotels) {
            HotelDoc hotelDoc = new HotelDoc(hotel);
            request.add(new IndexRequest("hotel")
                    .id(hotelDoc.getId().toString())
                    .source(JSON.toJSONString(hotelDoc), XContentType.JSON));
        }
        // 3. 发送请求
        client.bulk(request, RequestOptions.DEFAULT);
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
