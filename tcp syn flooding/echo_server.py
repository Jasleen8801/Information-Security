import socket
import threading

HOST = "127.0.0.1"
PORT = 65432

def handle_client(conn, addr):
  print(f"Connected by {addr}")
  while True:
    data = conn.recv(1024)
    if not data:
      break
    conn.sendall(data)
  conn.close()

def start_tcp_server():
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind((HOST, PORT))
    s.listen()
    print("TCP server started...")
    while True:
      conn, addr = s.accept()
      client_thread = threading.Thread(target=handle_client, args=(conn, addr))
      client_thread.start()

# if __name__ == "__main__":
#   start_tcp_server()
