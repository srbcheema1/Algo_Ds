#Python Prime checker. Not the most efficient way to check for primes, but very easy to code!

num = int(input("Enter a integer to get primes up to ")) #Get highest number for prime
div=2 #Set divisor to intitally 2
for num in range(2,num): #Check if prime
    prime = True #If prime is true set flag.
    for div in range(2,num): #If number can be divided by any number, from 2 to the number-1
        if (num % div == 0):#If evenly divided, the number will therefore be notprime.
            prime = False #set prime to false
    if prime: 
       print (num)
