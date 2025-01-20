#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int y;
        cin >> n >> y;
        vector<int> a(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int maxDiff = INT_MIN;
        maxDiff = max(maxDiff, 2 * (y - a[n - 1]));
        maxDiff = max(maxDiff,a[0]-0);
        for (int i = 0; i < n - 1; i++)
        {
            maxDiff = max(maxDiff, a[i + 1] - a[i]);
        }

        cout << maxDiff << endl;
    }
}