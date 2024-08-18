#include <iostream>
using namespace std;
void pushZeroes(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] == 0)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {1, 0, 4, 5, 0, 11, 0, 0, 56};
    int length = sizeof(arr) / sizeof(arr[0]);
    pushZeroes(arr, length);
    return 0;
}