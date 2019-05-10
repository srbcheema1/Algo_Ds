#This is implementation of pattern8 in python3
# Input n as integer
n = int(input())

#Set count =1
count = 1

# for loop for printing the patterns
for i in range(0,n):
    s=""
    for j in range(0,i+1):
        if n >= count:
            s=s+str(count)
            count+=1
    print(s)


##Output
##10
##1
##23
##456
##78910

