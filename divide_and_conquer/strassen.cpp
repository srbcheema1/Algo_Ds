#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


void createMatrix(int **A4,int size);
void output(int **A, int size);
void standardMult(int **A, int **B, int **C, int size);
void strassens(int **A, int **B, int **C, int size);
void Add(int **A, int **B, int **T, int n);
void Sub(int **A, int **B, int **T, int n);




int main() {
	int size = 8;
	
	
	int **A, **B, **C;

	for(int size=16;size<2048;size*=2){

	A = new int *[size];
	B = new int *[size];
	C = new int *[size];

	
	for(int i=0; i<size; i++) {
		A[i] = new int[size];
		B[i] = new int[size];
		C[i] = new int[size];
	}

	//Matrices for i,j as i*j%1000
	createMatrix(A,size);
	createMatrix(B,size);


	
	cout<<"Size of the matrix : "<<size<<"*"<<size<<endl<<endl;
	//Multiplying Matrices using Standard Method
	
	int time = clock();
	standardMult(A,B,C,size);
	int now=clock();
	//output(C,size);
	cout<<"Standard Multiplication: "<<(now-time)/1000000.0<<" Seconds"<<endl; 

	//Multiplying Matrices using Strassen's Algorithm
	//cout<<endl<<endl<<"Strassen's way" <<endl;
	time = clock();
	strassens(A,B,C,size);
	now=clock();
	//output(C,size);
	cout<<"Stressen's multiplication : "<<(now-time)/1000000.0<<" Seconds"<<endl<<endl; 

}}



//Add matrices
void Add(int **A, int **B, int **T, int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			T[i][j] = A[i][j] + B[i][j];
		}
	}
}

//Subtract matricess
void Sub(int **A, int **B, int **T, int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			T[i][j] = A[i][j] - B[i][j];
		}
	}
}


//method for matrix generation
void createMatrix(int **A,int size) {
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			A[i][j] = (i+1)*(j+1) % 1000;
		}
	}
}

//method to print a matrix
void output(int **A, int size) {
	cout<<endl;
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

//traditional method of multiplying two square matrices
void standardMult(int **A, int **B, int **C, int size) {
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			C[i][j] = 0;
			for(int k=0; k<size; k++) {
				C[i][j] += A[i][k] * B [k][j];
			}
		}
	}
}

//strassen's product
void strassens(int **A, int **B, int **C, int size) {
	if ( size <= 100)
	{
		standardMult(A,B,C,size);
	}
	else 
	{
		//Divide and conquer step
		int n = size/2;
		int N = size/2;
		int newsize = size/2;

		//Smaller matrices
		int **A11, **A12, **A21, **A22, **B11, **B12, **B21, **B22, **C11, **C12, **C21, **C22;

		//Matrices for Strassens
		int **M1, **M2, **M3, **M4, **M5, **M6, **M7;

	
		int **P, **Q;

		//memory allocation for columns
		A11 = new int *[n];A12 = new int *[n];A21 = new int *[n];A22 = new int *[n];
		B11 = new int *[n];B12 = new int *[n];B21 = new int *[n];B22 = new int *[n];
		C11 = new int *[n];C12 = new int *[n];C21 = new int *[n];C22 = new int *[n];
		
		//stressens matrices
		M1 = new int *[n];
		M2 = new int *[n];
		M3 = new int *[n];
		M4 = new int *[n];
		M5 = new int *[n];
		M6 = new int *[n];
		M7 = new int *[n];

		P = new int *[n];
		Q = new int *[n];

		//memory allocation for columns
		for(int i=0; i<N; i++) {
			A11[i] = new int[N];A12[i] = new int[N];A21[i] = new int[N];A22[i] = new int[N];
			B11[i] = new int[N];B12[i] = new int[N];B21[i] = new int[N];B22[i] = new int[N];
			C11[i] = new int[N];C12[i] = new int[N];C21[i] = new int[N];C22[i] = new int[N];

			M1[i] = new int[N];
			M2[i] = new int[N];
			M3[i] = new int[N];
			M4[i] = new int[N];
			M5[i] = new int[N];
			M6[i] = new int[N];
			M7[i] = new int[N];

			P[i] = new int[N];
			Q[i] = new int[N];

		}

		//Dividing input matrices A and B into 4 submatrices each.
		for (int i = 0; i < newsize; i++) {
			for (int j = 0; j < newsize; j++) {
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + newsize];
				A21[i][j] = A[i + newsize][j];
				A22[i][j] = A[i + newsize][j + newsize];

				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + newsize];
				B21[i][j] = B[i + newsize][j];
				B22[i][j] = B[i + newsize][j + newsize];
			}
		}

		//M1
		Sub(B12,B22,P,n);strassens(A11,P,M1,n);

		//M2
		Add(A11,A12,P,n);strassens(P,B22,M2,n);

		//M3
		Add(A21,A22,P,n);strassens(P,B11,M3,n);

		//M4
		Sub(B21,B11,P,n);strassens(A22,P,M4,n);

		//M5
		Add(A11,A22,P,n);Add(B11,B22,Q,n);strassens(P,Q,M5,n);

		//M6
		Sub(A12,A22,P,n);Add(B21,B22,Q,n);strassens(P,Q,M6,n);

		//M7
		Sub(A11,A21,P,n);Add(B11,B12,Q,n);strassens(P,Q,M7,n);

		//C11
		Add(M4,M5,P,n);Sub(M6,M2,Q,n);Add(P,Q,C11,n);

		//C12
		Add(M1,M2,C12,n);

		//C21
		Add(M3,M4,C21,n);

		//C22
		Add(M1,M5,P,n);	Add(M3,M7,Q,n);	Sub(P,Q,C22,n);

		//algorithm part
		for (int i = 0; i < n ; i++) {
			for (int j = 0 ; j < n ; j++) {
				C[i][j] = C11[i][j];
				C[i][j + n] = C12[i][j];
				C[i + n][j] = C21[i][j];
				C[i + n][j + n] = C22[i][j];
			}
		}
	}
}






