import pandas as pd
import numpy as np
from collections import namedtuple

check_data = namedtuple('check_data', ['type','ip', 'port', 'usr','pwd','db','table','data','expect_result'])

class check_db:
    check_datas=[]
    def __init__(self,file_path):
        df = pd.read_excel(file_path, sheet_name="check_db").replace(np.nan,'', regex=True)   
        for index, row in df.iterrows():
            info=check_data(type=row['type'],ip=row['ip'],port=row['port'],usr=row['usr'],pwd=row['pwd'],db=row['db'],table=row['table'],data=row['data'],expect_result=row['expect_result'])
            self.check_datas.append(info)

    def traversing(self):
        for index in range(len(self.check_datas)):
            print("\n=============")
            print("ip:",self.check_datas[index].ip,"\nport:",self.check_datas[index].port,"\nusr:",self.check_datas[index].usr,"\npwd:", 
            self.check_datas[index].pwd,"\ndb:",self.check_datas[index].db,"\ntable:",self.check_datas[index].table,"\ndata:",
            self.check_datas[index].data,"\nexpect_result:",self.check_datas[index].expect_result)
            print("=============")

path='E:/sourceCode/RBT_TEST_PLANT/data-x.xlsx'
if __name__=="__main__":
    ckdb=check_db(path)
    ckdb.traversing()
    