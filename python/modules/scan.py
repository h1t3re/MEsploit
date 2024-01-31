from scapy.all import scapy as scapy

def scan_for_host():
	return 0

def main():
	interface_number = 1
	choosed_interface_number = ' '
	interfaces = scapy.interfaces.get_if_list()
	for interface in interfaces:
		print(str(interface_number)+": ") 
		print(interface, end="\n")
		interface_number = interface_number +1
	while type(choosed_interface_number) is not int: 
		choosed_interface_number = input("Enter the number of interface to use: ")
	choosed_interface = interfaces[choosed_interface_number]
	print("The selected interface is :"+choosed_interface)
	scan_for_host()
	return 0

if __name__ == "__main__":
	main()
