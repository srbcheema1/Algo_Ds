n=int(input())
for i in range(1,n+1):
    for j in range(1,i+1):
        print(j,end='')
    for k in range(i-1,0,-1):
        print(k,end='')
    print(" ")
for i in range(n,0,-1):
    for j in range(1,i):
        print(j,end='')
    for k in range(i-2,0,-1):
        print(k,end='')
    print(" ")


/*

5

1 
121 
12321 
1234321 
123454321 
1234321 
12321 
121 
1

*/
