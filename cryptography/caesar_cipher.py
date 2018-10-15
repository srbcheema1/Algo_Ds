#from __future__ import print_function
def encrypt(text, key):
	result=""
	for i in range(len(text)):
		char = text[i]

		#uppercase
		if(char.isupper()):
			result+=chr((ord(char)+key-65)%26 + 65)
		#lowercase
		else:
			result+=chr((ord(char)+key-97)%26 + 97)
	return result
def decrypt(text, key):
	result=""
	for i in range(len(text)):
		char = text[i]
		#uppercase
		if(char.isupper()):
			result+=chr((ord(char)-key-39)%26 + 97)
		#lowercase
		else:
			result+=chr((ord(char)-key-71)%26 + 97)
	return result
def main():
	text=input("Enter Message: ")
	e=input("Encrypt or Decrypt [e/d]: ")
	key=int(input("Enter Key Between [0-25]: "))
	if e=='e':
		s1 = encrypt(text, key)
		print("Encrypted Message is : "+s1)	
	else:
		s1 = decrypt(text, key)
		print("Decrypted Message is : "+s1)

if __name__ == '__main__':
	main()