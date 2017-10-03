#Simple way to check for primes using Pyton.

#Prompt user for a integer
Number = int(input("Enter any integer to check if prime number "))
#Set starting divisor to 2
Divisor = 2
for Divisor in range (Divisor, Number) : #Test every number between 2 and the integer
        if Number % Divisor == 0:
            prime = False # Tell computer to make prime false
            break #End loop
        Divisor += 1 #Add 1 to the divisor
            
else:
    prime = True # If number % divisor does not equal 0, number must be a prime, so mark as true
#Print results
if prime == True :
    print("Your number is a prime")
if prime == False :
    print("Your number is not a prime")
