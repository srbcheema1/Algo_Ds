# Input n as integer
n = int(input())
#Set count =1
count = 1
# for loop for printing the patterns
for i in range(1, n+1):
    s = ""
    for j in range(n-i, 0, -1):
        s = s+" "
    for j in range(1, i+1):
        s = s+str(count)
        count += 1
    print(s)


##Output
##4
##   1
##  23
## 456
##78910

