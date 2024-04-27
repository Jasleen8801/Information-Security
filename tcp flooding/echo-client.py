import socket
import time

HOST = "127.0.0.1"
PORT = 65432
NUM_CONNECTIONS = 1000

def create_connection():
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b"Hello, world")
    data = s.recv(1024)
    print("Received", repr(data))

if __name__ == "__main__":
  for _ in range(NUM_CONNECTIONS):
    create_connection()
    time.sleep(0.1)