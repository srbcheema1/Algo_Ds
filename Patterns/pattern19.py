n=int(input())
s=2*(n-1)-1
for i in range (0,n):
    for j in range(1,i+2):
        print(j,end=" ")
    for k in range(s,-1,-1):
        print(" ",end=' ')
    for j in range(i+1,0,-1):
        print(j,end=" ")
    print(" ")
    s=s-2
    
    
/*
    
5
    
    
1                 1  
1 2             2 1  
1 2 3         3 2 1  
1 2 3 4     4 3 2 1  
1 2 3 4 5 5 4 3 2 1

*/
