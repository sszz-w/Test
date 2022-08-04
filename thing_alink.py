import sys
from linkkit import linkkit
import threading
import traceback
import inspect
import time
import logging
# test
# vscode 测试
# 修改文件夹后测试

# config log
__log_format = '%(asctime)s-%(process)d-%(thread)d - %(name)s:%(module)s:%(funcName)s - %(levelname)s - %(message)s'
logging.basicConfig(format=__log_format)


class CustomerThing(object):
    def __init__(self, host_name, product_key, device_name, device_secret):
        self.host_name = host_name
        self.product_key = product_key
        self.device_name = device_name
        self.device_secret = device_secret
        self.__linkkit = linkkit.LinkKit(
            host_name=self.host_name,
            product_key=self.product_key,
            device_name=self.device_name,
            device_secret=self.device_secret)
        self.__linkkit.enable_logger(logging.DEBUG)
        self.__linkkit.on_device_dynamic_register = self.on_device_dynamic_register
        self.__linkkit.on_connect = self.on_connect
        self.__linkkit.on_disconnect = self.on_disconnect
        self.__linkkit.on_topic_message = self.on_topic_message
        self.__linkkit.on_subscribe_topic = self.on_subscribe_topic
        self.__linkkit.on_unsubscribe_topic = self.on_unsubscribe_topic
        self.__linkkit.on_publish_topic = self.on_publish_topic
        self.__linkkit.on_thing_enable = self.on_thing_enable
        self.__linkkit.on_thing_disable = self.on_thing_disable
        self.__linkkit.on_thing_event_post = self.on_thing_event_post
        self.__linkkit.on_thing_prop_post = self.on_thing_prop_post
        self.__linkkit.on_thing_prop_changed = self.on_thing_prop_changed
        self.__linkkit.on_thing_call_service = self.on_thing_call_service
        self.__linkkit.on_thing_raw_data_post = self.on_thing_raw_data_post
        self.__linkkit.on_thing_raw_data_arrived = self.on_thing_raw_data_arrived
        self.__linkkit.thing_setup("tsl.json")
        self.__linkkit.config_device_info("Eth|03ACDEFF0032|Eth|03ACDEFF0031")
        self.__call_service_request_id = 0

    def on_device_dynamic_register(self, rc, value, userdata):
        if rc == 0:
            print("dynamic register device success, value:" + value)
        else:
            print("dynamic register device fail, message:" + value)

    def on_connect(self, session_flag, rc, userdata):
        print("on_connect:%d,rc:%d,userdata:" % (session_flag, rc))

    def on_disconnect(self, rc, userdata):
        print("on_disconnect:rc:%d,userdata:" % rc)

    def on_topic_message(self, topic, payload, qos, userdata):
        print("on_topic_message:" + topic + " payload:" + str(payload) + " qos:" + str(qos))
        pass

    def on_subscribe_topic(self, mid, granted_qos, userdata):
        print("on_subscribe_topic mid:%d, granted_qos:%s" %
              (mid, str(','.join('%s' % it for it in granted_qos))))
        pass

    def on_unsubscribe_topic(self, mid, userdata):
        print("on_unsubscribe_topic mid:%d" % mid)
        pass

    def on_publish_topic(self, mid, userdata):
        print("on_publish_topic mid:%d" % mid)

    def on_thing_prop_changed(self, params, userdata):
        print("on_thing_prop_changed params:" + str(params))

    def on_thing_enable(self, userdata):
        print("on_thing_enable")

    def on_thing_disable(self, userdata):
        print("on_thing_disable")

    def on_thing_event_post(self, event, request_id, code, data, message, userdata):
        print("on_thing_event_post event:%s,request id:%s, code:%d, data:%s, message:%s" %
              (event, request_id, code, str(data), message))
        pass

    def on_thing_prop_post(self, request_id, code, data, message, userdata):
        print("on_thing_prop_post request id:%s, code:%d, data:%s message:%s" %
              (request_id, code, str(data), message))

    def on_thing_raw_data_arrived(self, payload, userdata):
        print("on_thing_raw_data_arrived:%s" % str(payload))

    def on_thing_raw_data_post(self, payload, userdata):
        print("on_thing_raw_data_post: %s" % str(payload))

    def on_thing_call_service(self, identifier, request_id, params, userdata):
        print("on_thing_call_service identifier:%s, request id:%s, params:%s" %
              (identifier, request_id, params))
        self.__call_service_request_id = request_id
        pass

    def connect(self):
        self.__linkkit.connect_async()
        tips = "1: disconnect\n" +\
               "2 connect&loop\n" +\
               "3 subscribe topic\n" + \
               "4 unsubscribe topic\n" + \
               "5 public topic\n" +\
               ""

    def post_msg(self):
        # prop_data 设备消息
        prop_data = {
            "CurrentTemperature": 12,
            "CurrentHumidity": 23,
            "GeoLocation": {
                "Longitude": 34,
                "Latitude": 45,
                "Altitude": 56,
                "CoordinateSystem": 1
            }
        }
        self.__linkkit.thing_post_property(prop_data)


if __name__ == "__main__":
    sdk_test = CustomerThing("cn-shanghai", "hgduS6gNubx", "sdk_test", "1774e3d6d131ae45b2ab673d507fbae2")
    # 设备连接
    sdk_test.connect()
    sdk_test_2 = CustomerThing("cn-shanghai", "hgduS6gNubx", "sdk_test_2", "dbd61f8c71ffb2133004ffa75f5dbe13")
    sdk_test_2.connect()
    time.sleep(10)
    while True:
        # 发送设备消息
        sdk_test.post_msg()
        sdk_test_2.post_msg()
        time.sleep(10)
