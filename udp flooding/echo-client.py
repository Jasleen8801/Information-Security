import socket

HOST = "127.0.0.1"
PORT = 65432
NUM_PACKETS = 1000

def send_packet():
  with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    for _ in range(NUM_PACKETS):
      s.sendto(b"Hello, world!", (HOST, PORT))

if __name__ == "__main__":
  send_packet()