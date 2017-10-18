# Function for nth fibonacci number - Dynamic Programing
# Taking 1st two fibonacci nubers as 0 and 1
 
FibArray = [0,1]
 
def fibonacci(n):
    if n<0:
        print("Incorrect input")
    elif n<=len(FibArray):
        return FibArray[n-1]
    else:
        temp_fib = fibonacci(n-1)+fibonacci(n-2)
        FibArray.append(temp_fib)
        return temp_fib
 
# Driver Program
#Suppose we wan't to print the 9th fibonacci number
#You can ask for user input and substitute in place of 9

print(fibonacci(9))
