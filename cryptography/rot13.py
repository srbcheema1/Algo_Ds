from __future__ import print_function
# def encrypt(str):
#     output = ''
#     for c in str:
#         if c >= 'A' and c <= 'Z':
#             out += chr(ord('A') + (ord(c) - ord('A') - 13) % 26)
#         elif c >= 'a' and c <= 'z':
#             out += chr(ord('a') + (ord(c) - ord('a') - 13) % 26)
#         else:
#             out += c
#     return out

def decrypt(str):
    out = ''
    for c in str:
        if c >= 'A' and c <= 'Z':
            out += chr(ord('A') + (ord(c) - ord('A') + 13) % 26)
        elif c >= 'a' and c <= 'z':
            out += chr(ord('a') + (ord(c) - ord('a') + 13) % 26)
        else:
            out += c
    return out


def main():
	s0=input("Enter Message: ")

	# if input("Encrypt or Decrypt [e/d]: ")=='e':
	#     s1 = encrypt(s0)	
	#    else:
 	#    	s1 = decrypt(s0)
 	#    print_function(s1)
	# if input('Encrypt or decrypt [e/d]: ') == 'e':
		# s1 = encrypt(s0)
	# else:
	s1 = decrypt(s0)
	print("Decrypted Message is: ",s1)

if __name__ == '__main__':
	main()