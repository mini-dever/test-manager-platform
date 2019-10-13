import pandas as pd
import numpy as np
from collections import namedtuple

http_info = namedtuple('http_info', ['type','url', 'headers', 'data','expect_result'])

class http_data:
    http_infos=[]
    def __init__(self,file_path):
        df = pd.read_excel(file_path, sheet_name="set_http").replace(np.nan,'', regex=True)  
        for index, row in df.iterrows():
            info=http_info(type=row['type'],url=row['url'],headers=row['headers'],data=row['data'],expect_result=row['expect_result'])
            self.http_infos.append(info)

    def traversing(self):
        for e in self.http_infos:
            print("=============")
            print("type:",e.type)
            print("url:",e.url)
            print("headers:",e.headers)
            print("data:",e.data)
            print("expect_result:",e.expect_result)
            print("=============")


path='E:/sourceCode/RBT_TEST_PLANT/data-x.xlsx'
if __name__=="__main__":
    http=http_data(path)
    http.traversing()