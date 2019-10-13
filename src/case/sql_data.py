import pandas as pd
import numpy as np
from collections import namedtuple

db_info = namedtuple('db_info', ['type','ip', 'port', 'usr','pwd','db','table','data'])

class sql_data:
    db_infos=[]
    def __init__(self,file_path):
        df = pd.read_excel(file_path, sheet_name="set_db").replace(np.nan,'', regex=True)   
        for index, row in df.iterrows():
            info=db_info(type=row['type'],ip=row['ip'],port=row['port'],usr=row['usr'],pwd=row['pwd'],db=row['db'],table=row['table'],data=row['data'])
            self.db_infos.append(info)
                # print(row['ip'])
                # print(row['port'])
                # print(row['usr'])
                # print(row['pwd'])
                # print(row['db'])
                # print(row['table'])
                # print(row['data'])

    def traversing(self):
        for index in range(len(self.db_infos)):
            print("\n=============")
            print("ip:",self.db_infos[index].ip,"\nport:",self.db_infos[index].port,"\nusr:",self.db_infos[index].usr,"\npwd:", 
            self.db_infos[index].pwd,"\ndb:",self.db_infos[index].db,"\ntable:",self.db_infos[index].table,"\ndata:",self.db_infos[index].data)
            print("=============")

    

# path='E:/sourceCode/RBT_TEST_PLANT/data-x.xlsx'
# if __name__=="__main__":
#     sql_pre=sql_data(path)
#     sql_pre.traversing()