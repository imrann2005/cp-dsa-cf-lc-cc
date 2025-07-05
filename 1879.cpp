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

const int MOD = 998244353;
const int INF = INT_MAX;

ll fact(ll x)
{
    ll ans = 1;
    for (int i = 1; i <= x; i++)
    {
        /* code */
        ans = (ans * i)%MOD;
    }
    return ans;
}

void solveC(string &s)
{
    // Write your solution here
    ll i = 0, j = 0;
    ll n = s.length();
    ll cnt = 0;
    ll total = 1;
    ll remcnt = 0;
    while (i < n && j < n)
    {
        /* code */
        while (j < n && s[i] == s[j])
        {
            /* code */
            j++;
        }
        j--;
        ll len = (j - i) + 1;
        ll rem = len - 1;
        remcnt += rem;
        cnt += rem;
        total = (total * len) % MOD;
        i = j;
        i++;
        j++;
    }
    if(i<n){
        j--;
        ll len = (j - i) + 1;
        ll rem = len - 1;
        cnt += rem;
        remcnt += rem;
        total = (total * len) % MOD;
    }
    total = (total % MOD * fact(remcnt) % MOD) % MOD;
    cout << cnt << " " << total << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solveC(s);
    }

    return 0;
}