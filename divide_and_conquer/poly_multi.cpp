#include <iostream>
using namespace std;
int *multiply(int A[], int B[], int m, int n)
{
   int *prod = new int[m+n-1];

   for (int i = 0; i<m+n-1; i++)
     prod[i] = 0;

   for (int i=0; i<m; i++)
   {
     for (int j=0; j<n; j++)
         prod[i+j] += A[i]*B[j];
   }

   return prod;
}
void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
       cout << poly[i];
       if (i != 0)
        cout << "x^" << i ;
       if (i != n-1)
       cout << " + ";
    }
}

int main()
{
       int n,m;
cin>>m>>n;
int A[m],B[n];
for(int i=0;i<m;i++){
cin>>A[i];
}
for(int i=0;i<n;i++){
        cin>>B[i];
}
    cout << "First polynomial is \n";
    printPoly(A, m);
    cout << "Second polynomial is \n";
    printPoly(B, n);

    int *prod = multiply(A, B, m, n);

    cout << "Product polynomial is \n";
    printPoly(prod, m+n-1);

    return 0;
}

