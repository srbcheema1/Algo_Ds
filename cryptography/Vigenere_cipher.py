def encrypt(text, key):
	#enc=list()
	result=""
	for i in range(len(text)):
		char = text[i]
		#uppercase
		if(char.isupper()):
			result+=chr((ord(char)+(ord(key[i%len(key)])-ord("A"))-65)%26 + 65)
		#lowercase
		else:
			result+=chr((ord(char)+(ord(key[i%len(key)])-ord("a"))-97)%26 + 97)
	return result
def main():
	text=str(input("Enter Message: "))
	key=input("Enter String For Encryption: ")
	s1 = encrypt(text, key)
	print("Encrypted Message is : "+s1)

if __name__ == '__main__':
	main()