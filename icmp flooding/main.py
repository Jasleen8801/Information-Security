import subprocess

def icmp_flood(host, count):
    command = f"ping -c {count} {host}"
    subprocess.run(command, shell=True)

if __name__ == "__main__":
    icmp_flood('127.0.0.1', 1000)