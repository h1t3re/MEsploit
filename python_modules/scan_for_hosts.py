from scapy.all import *
import sys

class Iface:
	number = 0
	name = ""
	mac = ""
	ips = []	
	default_ip = ""

	def __init__(self, number=0, name="", mac=""):
		self.name = name
		self.number = number
		self.mac = mac

	def get_number(self):
		return self.number

	def get_name(self):
		return self.name
	
	def get_mac(self):
		return self.mac
	
	def get_ip_list(self):
		return self.ips
	
	def get_default_ip(self):
		if len(self.default_ip) >= 8:
			return self.default_ip
		else: 
			return None

	def set_default_ip(self, ip):
		if ip in self.ips:
			self.default_ip = ip

	def add_ip(self, ip):
		self.ips.append(ip)
	
	def print_iface(self):
		print(str(self.number)+": ", end="")
		print(self.name+": ", end="")
		print(self.mac, end="\n")
		for ip in self.ips:
			print(ip, end="\n")
		print("\n")	

def scan_for_host(iface=None):
	iface.print_iface()
	t = iface.get_default_ip()
	reply = None
	if not t:
		return 0	
	l = t.split(".")[:-1]
	network = l[0] + '.' + l[1] + '.' + l[2] + '.'
	for i in range(1, 255):
		ip = network + str(i)
		print("Scanning "+ip+" ... ", end="")
		sr(IP(dst=ip)/ICMP(type=8), rcv_pks=reply, timeout=1, verbose=0)
		if reply is not None:
			print("up", end="\n")
		else:
			print("down", end="\n")	
	

def main():
	interface_number = 1
	choosed_interface_number = " "
	ifaces = scapy.interfaces.get_if_list()
	for iface in ifaces:
		print(str(interface_number)+": "+iface, end="\n") 
		interface_number = interface_number +1
	print("\n\n")
	print("Select the number of interface to use: ", end="\n")
	iface_number = input()
	iface_number = iface_number.strip('\n')
	try:
		interface_num = int(iface_number)
	except ValueError:
		sys.exit("Please select a valid number\n")
	print("Getting interface configuration ...", end="")
	interface_config = scapy.interfaces.resolve_iface(ifaces[interface_num-1])
	iface = Iface(interface_num, ifaces[interface_num-1], interface_config.mac)
	print(" done", end="\n")
	print("Storing interface configuration ...", end="")
	iface.add_ip(interface_config.ip)
	iface.set_default_ip(interface_config.ip)
	print(" done", end="\n")
	iface.print_iface()
	up_ips = scan_for_host(iface)
	
	return 0

if __name__ == "__main__":
	main()
