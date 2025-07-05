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

void solveB(ll n)
{
    // Write your solution here
    map<ll,ll>mpp;
    bool ans = 0;
    vector<vector<ll>>a;
    for (int i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        vll temp;
        for (int j = 0; j < k; j++)
        {
            ll x;
            cin >> x;
            temp.pb(x);
            mpp[x]++;
        }
        a.pb(temp);
    }
    for (int i = 0; i < a.size(); i++)
    {
        bool f = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
            /* code */
            if(mpp[a[i][j]] <= 1){
                f = 1;
            }
        }
        if(f == 0){
            yes;
            return;
        }
        
    }
    no;
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
        // vector<vll> a;
        solveB(n);
    }

    return 0;
}