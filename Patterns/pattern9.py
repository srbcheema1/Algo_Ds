# This is the implementation of pattern9 in Python3
# Input as integer
n = int(input())
#For loop to print the pattern 
for i in range(1,n+1):
    print(' '*(n-i)+ str(i)*i)
    

# Output format
"""
5

    1
   22
  333
 4444
55555

"""
