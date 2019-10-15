#!/usr/bin/python3
import os
import pymysql
import pandas as pd
from configparser import ConfigParser

class mysql_tool:
     def __init__(self):
        cfg= ConfigParser()
        cfg.read('./init.ini',encoding="utf-8")
        self.host=cfg.get('mysql','host')
        self.port=cfg.get('mysql','port')
        self.user=cfg.get('mysql','user')
        self.password=cfg.get('mysql','password')
        self.db=cfg.get('mysql','db')
        self.charset=cfg.get('mysql','charset')

     def execute_sql(self,sql):
        try:
             # 打开数据库连接
            if self.port.isdigit() is False:
                self.port='3306'

            db = pymysql.connect(host=self.host,port=int(self.port),user=self.user,password=self.password,db=self.db,charset=self.charset)
 
            # 使用cursor()方法获取操作游标 
            cursor = db.cursor()
            # 执行SQL语句
            print("execute_sql",sql)
            cursor.execute(sql)
            # fetchone(): 该方法获取下一个查询结果集。结果集是一个对象
            # fetchall(): 接收全部的返回结果行.
            # rowcount: 这是一个只读属性，并非方法，直接返回执行execute()方法后影响的行数。
            results = cursor.fetchall()
            if True:
                db.commit()

            return results
        except Exception as e:
            print ("execute_sql Error:",e)
        else:
                # 关闭数据库连接
            db.close()

     def  check_db(self,sql):
        try:
            if self.port.isdigit() is False:
                self.port='3306'
            
            db = pymysql.connect(host=self.host,port=int(self.port),user=self.user,password=self.password,db=self.db,charset=self.charset)
  
            cursor = db.cursor()
            
            cursor.execute(sql)
            results = cursor.fetchall()
            return results
        except Exception as e:
            print ("check_db Error:",e)
        else:
            db.close()
            return None
                
# if __name__=="__main__":
#        mysql=mysql_tool()
#        sql_query = r"INSERT INTO `auth_user` (`id`, `password`, `last_login`, `is_superuser`, `username`, `first_name`, `last_name`, `email`, `is_staff`, `is_active`, `date_joined`, `pwd`) VALUES (0,'pbkdf2_sha256$100000$vqJ8ZsmJHWre$3rw7m4AUj4LCDxGe+sIYsQGjSNJAOyHX5Vj0UWxcOBo=','2019-10-09 16:26:32.279082',0,'yzl','','','972765230@qq.com',1,1,'2019-10-09 14:23:47.252467','MXFhenhzdzI='),(0,'pbkdf2_sha256$100000$GXBNcXljxONp$1UbVRPXOXqpl4It2+sfvH/nCXDjRB2MlpYTDgBWYRHU=','2019-10-09 16:27:53.659876',0,'xiaocaix','','','',0,1,'2019-10-09 16:24:45.093608','eGlhb2NhaXhpYW9jYWk=');"
#        print(mysql.host,mysql.port,mysql.user,mysql.password,mysql.db,mysql.charset)
#        mysql.execute_sql(sql_query)

