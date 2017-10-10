#include <stdio.h>

void shellsort(int arr[], int num)

{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)  
    {

       // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..i-1] are already in 
        //gapped order keep adding one more element until the
        //entire array is gap sorted.
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}

int main()

{
    int arr[30];
    int k,  num;
    printf("Enter total no. of elements : ");
    scanf("%d", &num);
    printf("\nEnter %d numbers: ", num);
    for (k =  0 ; k < num; k++)
    {
        scanf("%d", &arr[k]);
    }
    shellsort(arr, num);
    printf("\n Sorted array is: ");
    for (k = 0; k < num; k++)
        printf("%d ", arr[k]);
    return 0;

}