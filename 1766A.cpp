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

void solve(int n)
{
    // Write your solution here

    if (n <= 10)
    {
        cout << n << endl;
    }
    else if (n <= 100)
    {
        cout << 9 + n / 10 << endl;
    }
    else if (n <= 1000)
    {
        cout << 9 + 9 + n / 100 << endl;
    }
    else if (n < 10000)
    {
        cout << 9 + 9 + 9 + n / 1000 << endl;
    }
    else if (n < 100000)
    {
        cout << 9 + 9 + 9 + 9 + n / 10000 << endl;
    }
    else
    {
        cout << 9 + 9 + 9 + 9 + 9 + n / 100000 << endl;
    }
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
        solve(n);
    }

    return 0;
}