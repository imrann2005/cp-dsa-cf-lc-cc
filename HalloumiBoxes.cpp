#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n, int k)
{
    /* Check non dec first*/
    bool flag = is_sorted(a.begin(), a.end());
    if (flag)
    {
        cout << "YES\n";
        return;
    }
    if (k >= 2)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    int n, k;
    while (t--)
    {
        cin >> n >> k;
        vector<int> arr(n);
        for (size_t i = 0; i < n; i++)
        {
            /* code */
            cin >> arr[i];
        }
        solve(arr, n, k);
    }

    return 0;
}
