import paramiko
from configparser import ConfigParser
class ssh_tool:
    def __init__(self):
        cfg= ConfigParser()
        cfg.read('./init.ini',encoding="utf-8")
        self.ip=cfg.get('shell','ip')
        self.port=int(cfg.get('shell','port'))
        self.user=cfg.get('shell','user')
        self.password=cfg.get('shell','password')

    def ssh_exec(self,commond):
        self.client = paramiko.SSHClient()
        self.client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        self.client.connect(self.ip,self.port,self.user,self.password,timeout = 10)
        stdin,stdout,stderr = self.client.exec_command(commond)
        
        out=stdout.readlines()
        err=stderr.readlines()
        self.client.close()

        # if len(err):
        #     print("error")
        return out,err

# if __name__=="__main__":
#     ssh = ssh_tool()
#     print(ssh.ip,ssh.port,ssh.user,ssh.password)
#     commond="touch /bbc;"
#     stdout,stderr =ssh.ssh_exec(commond)
#     print("stdout=",stdout)
#     print("stderr=",stderr)
    