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

void solveC(string &s, ll n)
{
    // Write your solution here
    ll cnt = 0;
    s = "x" + s;
    vi c(n + 1, 0);
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j += i)
        {
            if (s[j] == '1')
                break;
            else c[j] = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if(s[i]=='0')cnt += c[i];
    }
    cout<<cnt<<endl;
    
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        solveC(s, n);
    }

    return 0;
}