a=int(input("Enter a natural number"))#Taking input
if a==0:
    print(0)
else:
    l=[]
    while(a>0):
        b=a%2        #Calculating the remainder
        a=a//2       #Updating the value of a
        l.append(b)  #Storing the values of b in a list
    l.reverse()
print("The binary equivalent is:",end="")
for i in l:
    print(i,end="")
        


