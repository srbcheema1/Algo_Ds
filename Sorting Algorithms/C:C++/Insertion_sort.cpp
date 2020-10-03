/* C++ Program - Insertion Sort */
		
#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int size, arr[50], i, j, temp;
	cout<<"Enter Array Size : ";
	cin>>size;
	cout<<"Enter Array Elements : ";
	for(i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	cout<<"Sorting array using selection sort ... \n";
	int j,small;
	for(int i=1;i<size;i++)
	{
		small=arr[i];
		j=i-1;
		while((j>=0) && (small<arr[j]))
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=small;
	}
	cout<<"Array after sorting : \n";
	for(i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	getch();
}
