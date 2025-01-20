#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(vi &arr, int n)
{
    // Write your solution here
    bool f  = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            no;
            return;
        }
        else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            if (arr[i + 1] > arr[i - 1])
            {
                swap(arr[i + 1], arr[i]);
            }
            else
            {
                no;
                return;
            }
        }
    }
    yes;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        for (size_t i = 0; i < n; i++)
        {
            /* code */
            cin >> arr[i];
        }

        solve(arr, n);
    }

    return 0;
}