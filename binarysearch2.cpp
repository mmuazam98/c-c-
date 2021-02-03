#include <iostream>
using namespace std;

int BinarySearch(int arr[], int p, int r, int n)
{
    if (p <= r)
    {
        int mid = (p + r) / 2;
        if (arr[mid] == n)
            return mid;
        if (arr[mid] > n)
            return BinarySearch(arr, p, mid - 1, n);
        if (arr[mid] < n)
            return BinarySearch(arr, mid + 1, r, n);
    }
    return -1;
}

int main()
{
    int a, n;
    cout << "enter the size of array";
    cin >> a;
    int arr[a];
    cout << "enter the values of array";

    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < a - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            i = -1;
        }
    }
    cout << "\n";
    for (int i = 0; i < a; i++)
    {
        cout << " " << arr[i];
    }

    cout << "\nenter element to be searched:";
    cin >> n;

    cout << "element found at index position: " << BinarySearch(arr, 0, a - 1, n);

    return 0;
}