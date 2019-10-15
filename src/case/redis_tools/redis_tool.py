import redis
import pymysql
from configparser import ConfigParser

class redis_helper  :
    def __init__(self):
        cfg= ConfigParser()
        cfg.read('./init.ini',encoding="utf-8")
        host=cfg.get('redis','host')
        port=cfg.get('redis','port')
        self.__redis = redis.StrictRedis(host, port) 
        print(host,port)
    

    def get(self,key):
        if self.__redis.exists(key): 
            return self.__redis.get(key) 
        else: 
            return ""

    def set(self,key,value):
        self.__redis.set(key,value)


# if __name__=="__main__":
#     redis=redis_helper()
#     redis.set("name","yohan")
#     name=redis.get("name")
#     print(name)