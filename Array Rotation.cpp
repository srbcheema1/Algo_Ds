#include <iostream>
using namespace std;
void once_rotation(float arr[], int no_elements)
{
    int flag = arr[0];
    for (int i = 0; i < no_elements - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[no_elements - 1] = flag;
}
float rotate_array(float arr[], int no_elements, int no_rotations)
{
    float flag = 0;
    if (no_elements == 0)
    {
        cout << "Empty Array" << endl;
    }
    else if (no_elements > 100)
    {
        cout << "Out of Bound" << endl;
    }
    else
    {
        for (int j = 0; j < no_rotations; j++)
        {
            once_rotation(arr, no_elements);
        }

        cout << "Final array after rotation is : ";

        for (int j = 0; j <= no_elements - 1; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
int main()
{
    float arr[100];
    int no_rotations, no_elements;
    cout << "Enter the number of elements in an array: ";
    cin >> no_elements;

    if (no_elements > 0 && no_elements <= 100)
    {
        cout << "Enter the value of elements : ";
        for (int i = 0; i < no_elements; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter the number of rotations : ";
        cin >> no_rotations;
    }

    rotate_array(arr, no_elements, no_rotations);
    cout << endl;
    
    return 0;
}
