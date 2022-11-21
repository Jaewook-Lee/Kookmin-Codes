#include <iostream>
using namespace std;

void print_array(int _arr[], int n)
{
    for (int p = 0; p < n; p++)
    {
        printf("%d ", _arr[p]);
    }
    printf("\n");
}

void cocktail_sort(int arr[], int n)
{
    int last_forward_swapped = n;
    int last_backward_swapped = 0;
    for (int pass = 1; pass < n; pass++)
    {
        bool swapped = false;
        if (pass % 2 != 0)
        {
            int forward_swapped = 0;
            for (int i = last_backward_swapped; i < last_forward_swapped - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    swap(arr[i], arr[i + 1]);
                    forward_swapped = i + 1;
                    swapped = true;
                }
            }
            last_forward_swapped = forward_swapped;
        }
        else
        {
            int backward_swapped = n;
            for (int i = last_forward_swapped; i > last_backward_swapped; i--)
            {
                if (arr[i - 1] > arr[i])
                {
                    swap(arr[i - 1], arr[i]);
                    backward_swapped = i - 1;
                    swapped = true;
                }
            }
            last_backward_swapped = backward_swapped;
        }
        print_array(arr, n);

        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int my_arr[10] = {0, 1, 5, 3, 4, 2, 6, 7, 8, 9};
    cocktail_sort(my_arr, 10);
    printf("Result: ");
    for (int idx = 0; idx < 10; idx++)
    {
        printf("%d ", my_arr[idx]);
    }
    cout << "\n";
    return 0;
}