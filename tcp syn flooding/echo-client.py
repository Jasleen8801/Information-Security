import socket
import time
import threading

from echo_server import start_tcp_server

HOST = "127.0.0.1"
PORT = 65432
NUM_CONNECTIONS = 1000

def create_connection():
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b"Hello, world")
    data = s.recv(1024)
    print("Received", repr(data))

def syn_flood():
  for _ in range(NUM_CONNECTIONS):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
      s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
      s.connect((HOST, PORT))

if __name__ == "__main__":
  server_thread = threading.Thread(target=start_tcp_server)
  server_thread.start()

  time.sleep(1)

  syn_flood()
