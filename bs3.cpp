#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, d;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    cin >> d;

    int f, l, m;
    f = 0;
    l = n - 1;
    while (f <= l)
    {
        m = (f + l) / 2;
        if (d == a[m])
        {
            cout << m;
            break;
        }
        else if (d > a[m])
            f = m + 1;
        else if (d < a[m])
            l = m - 1;
        else
        {
            cout << "index not found";
        }
    }

    return 0;
}