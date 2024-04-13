package cn.itcast.hotel;

import org.apache.http.HttpHost;
import org.elasticsearch.action.admin.indices.delete.DeleteIndexRequest;
import org.elasticsearch.client.RequestOptions;
import org.elasticsearch.client.RestClient;
import org.elasticsearch.client.RestHighLevelClient;
import org.elasticsearch.client.indices.CreateIndexRequest;
import org.elasticsearch.client.indices.GetIndexRequest;
import org.elasticsearch.common.xcontent.XContentType;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.IOException;

import static cn.itcast.hotel.constants.HotelConstants.MAPPING_TEMPLATE;

public class HotelIndexTest {
    private RestHighLevelClient client;

    @Test
    void testInit() {
        System.out.println(client);
    }

    /**
     * 创建索引库
     * @throws IOException
     */
    @Test
    void createHotelIndex() throws IOException {
        // 1. 创建Request对象
        CreateIndexRequest request = new CreateIndexRequest("hotel");
        // 2. 准备请求的对象
        request.source(MAPPING_TEMPLATE, XContentType.JSON);
        // 3. 发送请求
        client.indices().create(request, RequestOptions.DEFAULT);
    }

    /**
     * 删除索引表
     * @throws IOException
     */
    @Test
    void delHotelIndex() throws IOException {
        // 1. 创建Request对象
        DeleteIndexRequest request = new DeleteIndexRequest("hotel");
        // 2. 发送请求
        client.indices().delete(request, RequestOptions.DEFAULT);
    }

    /**
     * 查询索引库是否存在
     * @throws IOException
     */
    @Test
    void testExistsHostelIndex() throws IOException {
        // 1. 创建Request对象
        GetIndexRequest request = new GetIndexRequest("hotel");
        // 2. 发送请求
        boolean exist = client.indices().exists(request, RequestOptions.DEFAULT);
        // 3. 输出
        System.out.println(exist ? "索引库已经存在" : "索引库不存在");
    }


    /**
     * 这两个是在每个测试方法运行之前运行的
     */

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
