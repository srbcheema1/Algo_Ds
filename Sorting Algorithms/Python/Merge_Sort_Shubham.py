def Merge(A,l,mid,r):
    Z=A[l:mid+1]
    X=A[mid+1:r+1]
    first_len=len(Z)
    second_len=len(X)
    
    i=0
    j=0
    while(i<first_len and j<second_len):
        if(Z[i]>X[j]):
            A[l]=X[j]
            j+=1
            l+=1
        else:
            A[l]=Z[i]
            i+=1
            l+=1
    if(i<first_len):
        while(i<first_len):
            A[l]=Z[i]
            i+=1
            l+=1
    elif(j<second_len):
        while(j<second_len):
            A[l]=X[j]
            l+=1
            j+=1

    



def Mergesort(A,l,r):
    if(l<r):
        mid=(l+r)//2
        Mergesort(A,l,mid)
        Mergesort(A,mid+1,r)
        Merge(A,l,mid,r)
    

q=int(input())
A=[int(x) for x in input().split()]
l=0
r=len(A)-1
Mergesort(A,l,r)
print(A)

