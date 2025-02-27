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

void solve(string &s, ll n, ll x, ll k)
{
    // Write your solution here
    ll i = 0;
    ll cnt = 0;
    ll pos = x;
    ll secReq = 0;
    ll cntR=0,cntL=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='L')cntL++;
        else cntR++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='L'){
            pos--;
        }
        else{
            pos++;
        }
        secReq++;
        if(pos == 0){
            cnt++;
            if(cntL == cntR){
                ll rem = k - secReq;
                if(rem > 0){
                    cnt += rem/n;
                }
            }
            break;
        }
    }

   
    cout << cnt << endl;
    
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, k;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        solve(s, n, x, k);
    }

    return 0;
}