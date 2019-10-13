import pandas as pd
import numpy as np
from collections import namedtuple

file_info = namedtuple('file_info', ['host', 'port', 'usr','pwd','file_location','write_way','data'])

class file_data:
    file_infos=[]
    def __init__(self,file_path):
        df = pd.read_excel(file_path, sheet_name='set_file').replace(np.nan,'', regex=True) 
        for index, row in df.iterrows():
            info=file_info(host=row['host'],port=row['port'],usr=row['usr'],pwd=row['pwd'],file_location=row['file_location'],data=row['data'],write_way=row['write_way'])
            self.file_infos.append(info)

    def traversing(self):
        for ele in self.file_infos:
            print("===========")
            print("host:",ele.host,"port:",ele.port,",usr:",ele.usr,",pwd:",ele.pwd,",file_location:",ele.file_location,
            ",write_way:",ele.write_way,",data:",ele.data)
            print("===========")


# path='E:/sourceCode/RBT_TEST_PLANT/data-x.xlsx'

# if __name__=="__main__":
#     file=file_data(path)
#     file.traversing()
    
  