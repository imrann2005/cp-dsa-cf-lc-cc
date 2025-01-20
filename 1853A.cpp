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

void solve(vi &a, int n)
{
    // Write your solution here
    int mini = INT_MAX;
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            int ops = (a[i]-a[i-1])/2 + 1;
            mini = min(mini,ops);
        }
        else if(a[i]==a[i-1]){
            mini = min(mini,1);
        }
        else
        {
            cout << 0 << endl;
            return;
        }
    }
    cout<<mini << endl;
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
        vi a(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        solve(a, n);
    }

    return 0;
}