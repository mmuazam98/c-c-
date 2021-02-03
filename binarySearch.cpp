#include <iostream>
using namespace std;
int binarySearch(int a[], int n, int e)
{
    int f, l, m;
    f = 0;
    l = n - 1;
    while (f <= l)
    {
        m = (f + l) / 2;
        if (e == a[m])
            return m;
        else if (e > a[m])
            f = m + 1;
        else
            l = m - 1;
    }
    return -1;
}
void binarySort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            i = -1;
        }
    }
}
int main()
{
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEnter the element to be searched: ";
    cin >> x;
    binarySort(arr, n);

    int res = binarySearch(arr, n, x);
    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    if (res != -1)
        cout << "\nElement found at position " << res + 1 << " (index = " << res << ")";
    else
        cout << "\nElement is not found";
    return 0;
}