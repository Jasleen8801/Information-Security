import socket

HOST = "127.0.0.1"
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
  # AF_INET is the address family for IPv4
  # SOCK_STREAM is the socket type for TCP 
  s.bind((HOST, PORT)) # bind the socket to the address
  s.listen() # enable the server to accept connections
  conn, addr = s.accept() 
  with conn:
    print(f"Connected by {addr}")
    while True:
      data = conn.recv(1024) # receive data from the client of at most 1024 bytes
      if not data:
        break
      conn.sendall(data)