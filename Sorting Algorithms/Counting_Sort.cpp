#include<iostream>
using namespace std;

int main()
{
 int N,x;

    cin>>N;
    int A[N];
    //The elements of the array must not exceed the size of the array.
    //This algo is ideally suited for numbers within a range with repetitions.
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }

     // Find the maximum value in A[]
    int K = 0;
    for(int i=0; i<N; i++) {
        K = max(K, A[i]);
    }

    int Aux[N];
      // Initialize the elements of Aux[] with 0
    for(int i=0 ; i<=K; i++) {
        Aux[i] = 0;
    }

     // Store the frequencies of each element of A[],
    // by mapping its value as the index of Aux[] array
    for(int i=0; i<N; i++) {
        Aux[A[i]]++;
    }

    int sortedA[N];
    int j = 0;
    for(int i=0; i<=K; i++) {
        int tmp = Aux[i];
        // Aux stores which element occurs how many times,
        // Add i in sortedA[] according to the number of times i occured in A[]
        while(tmp--) {

            sortedA[j] = i;
            j++;
        }
    }
    for(int i=0;i<N; i++)
    {
        cout<<sortedA[i]<<" ";

    }



}
