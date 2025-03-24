#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

void solve(ll x,ll y,ll a) {
    // Write your solution here
    a = a%(x+y);
    long double a1 = a+0.5;
    int i = 1;
    
    while (a1 > 0)
    {
        if(i&1){
            a1 -= x;
            if(a1 <= 0){
                no;
                return;
            }
        }
        else {
            a1-= y;
            if(a1 <= 0){
                yes;
                return;
            }
        }
        i++;
    }
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        ll x,y,a;
        cin >> x>>y>>a;
        solve(x,y,a);
    }

    return 0;
}