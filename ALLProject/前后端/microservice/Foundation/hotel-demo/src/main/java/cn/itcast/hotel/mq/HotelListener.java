package cn.itcast.hotel.mq;

import cn.itcast.hotel.constants.MqConstants;
import cn.itcast.hotel.service.impl.HotelService;
import org.springframework.amqp.rabbit.annotation.RabbitListener;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.io.IOException;

@Component
public class HotelListener {

    @Autowired
    private HotelService hotelService;
    /**
     * 监听酒店新增或者修改的业务
     * @param id
     */
    @RabbitListener(queues = MqConstants.HOTEL_INSERT_QUEUE)
    public void listenHotelInsertOrUpdate(Long id) throws IOException {
        hotelService.insertById(id);
    }

    /**
     * 监听酒店删除的业务
     * @param id
     */
    @RabbitListener(queues = MqConstants.HOTEL_DELETE_QUEUE)
    public void listenHotelDeleteOrUpdate(Long id) throws IOException {
        hotelService.deleteById(id);
    }

}
