from scapy.layers.inet import IP, UDP
import time
from scapy.sendrecv import send

ip_dst = '127.0.0.127'
ip_src = '10.99.99.99'
udp_sport = 321
udp_dport = 123
payload = b'\x01\x0f'

packet = IP(dst=ip_dst, src=ip_src) / UDP(sport=udp_sport, dport=udp_dport) / payload

while True:
  send(packet)
  time.sleep(1)

# to be done using 'sudo python3 main.py'