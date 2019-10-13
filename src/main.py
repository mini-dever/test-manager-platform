#from db_util.mysql_tool import mysql_tool

from remote_util.ssh_tool import ssh_tool

from case.sql_data import sql_data

import db_util  
import base
import case
import unittest
import json
import requests



def run_sql(sql_db,sql_conf):
    for i in sql_conf.db_infos:
        sql_db.execute_sql(i.data)


def gen_file(session,file):
    for e in file.file_infos:
        strcmd="echo "+e.data+e.write_way+e.file_location
        session.ssh_exec(strcmd)
    pass

path='E:/sourceCode/RBT_TEST_PLANT/data-x.xlsx'

if __name__=="__main__":
    testsql=db_util.mysql_tool()
    getsql=sql_data(path)
    run_sql(testsql,getsql)

    file=case.file_data(path)
    session=ssh_tool()
    gen_file(session,file)

    http=case.http_data(path)
    http.traversing()
    for e in http.http_infos:
        try:
            headers=json.loads(e.headers)
            results = requests.post(e.url, data=e.data, headers=headers).text
            if results != '':
                rsp=json.loads(results)
                print(json.dumps(rsp['TraceInfo'],indent=1))
            else:
                print("服务器无响应，请检查配置或重试!")
        except requests.exceptions.ConnectionError:
            print("建立连接失败，请检查服是否启动。")

        



