package com.itheima.publisher;

import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.Test;
import org.springframework.amqp.rabbit.connection.CorrelationData;
import org.springframework.amqp.rabbit.core.RabbitTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.util.concurrent.ListenableFutureCallback;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

@SpringBootTest
@Slf4j
public class SpringAmqpTest {
    @Autowired
    private RabbitTemplate rabbitTemplate;

    @Test
    public void testSimpleQueue() {
        // 队列名称
        String queueName = "simple.queue";
        // 消息
        String message = "hello, spring amqp!";
        // 发送消息
        rabbitTemplate.convertAndSend(queueName, message);
    }

    @Test
    public void testWorkQueue() throws InterruptedException {
        String queueName = "work.queue";
        for (int i = 1; i <= 50; i++) {
            String message = "hello, worker,  message_" + i;
            rabbitTemplate.convertAndSend(queueName, message);
            Thread.sleep(10);
        }
    }

    @Test
    public void testFanoutQueue() {
        // 交换机名称
        String exchangeName = "root.fanout";
        String message = "hello, everyone!";
        // 发送消息
        rabbitTemplate.convertAndSend(exchangeName, "", message);
    }


    @Test
    public void testDirectQueue() throws InterruptedException {
        // 交换机名称
        String exchangeName = "root.direct";
        String message = "hello, blue!";
        // 发送消息

        rabbitTemplate.convertAndSend(exchangeName, "blue", message);
        Thread.sleep(20);
        message = "hello, yellow!";
        rabbitTemplate.convertAndSend(exchangeName, "yellow", message);
        Thread.sleep(20);
        message = "hello, red!";
        rabbitTemplate.convertAndSend(exchangeName, "red", message);
    }

    @Test
    public void testTopicQueue() {
        // 交换机名称
        String exchangeName = "root.topic";
        String message = "hello, china.weather";
        rabbitTemplate.convertAndSend(exchangeName, "china.weather", message);
        message = "hello, china.news";
        rabbitTemplate.convertAndSend(exchangeName, "china.news", message);
        message = "hello, japan.news";
        rabbitTemplate.convertAndSend(exchangeName, "japan.news", message);
    }


    @Test
    public void testSendMap() throws InterruptedException {
        // 准备消息
        Map<String,Object> msg = new HashMap<>();
        msg.put("name", "柳岩");
        msg.put("age", 21);
        // 发送消息
        rabbitTemplate.convertAndSend("object.queue", msg);
    }


    @Test

    void testConfirmCallback() {

        // 1. 创建cd
        CorrelationData cd = new CorrelationData(UUID.randomUUID().toString());
        // 2. 添加ConfirmCallback
        cd.getFuture().addCallback(new ListenableFutureCallback<CorrelationData.Confirm>() {
            @Override
            public void onFailure(Throwable ex) {
                log.error("消息回调失败", ex);
            }

            @Override
            public void onSuccess(CorrelationData.Confirm result) {
                log.debug("收到confirm callback回执");
                if (result.isAck()) {
                    // 消息发送成功
                    log.debug("消息发送成功， 收到ack");
                } else {
                    // 消息发送失败
                    log.error("消息发送失败，收到nack，原因：{}", result.getReason());
                }
            }
        });

        rabbitTemplate.convertAndSend("hmall.direct", "red", "hello", cd);
    }
}