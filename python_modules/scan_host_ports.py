from scapy.all import *
import sys
import socket

def scan_open_ports_of(ip=None):
	print("Open ports are: ", end="\n")
	for dest_port in range(1, 65536):
		try:
			with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
				if sock.connect_ex((ip, dest_port)) == 0:
					 print(dest_port, end="\n")
		except (OSError, ValueError):
			print("error", end="\n")
	return False

def main():
	print("Enter ip of the host to scan :", end="\n")
	p = input()
	ip = p.strip('\n')
	scan_open_ports_of(ip)
	return 0

if __name__ == "__main__":
	main()
