import socket
UDP_IP = "192.168.0.9"  
UDP_PORT = 139 

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("192.168.0.9",139))
while True:
    data, addr = sock.recvfrom(2)  
    print(data)