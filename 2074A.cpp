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

void solve(int l,int r,int d,int u) {
    // Write your solution here
    ll d1 = l*l + u*u;
    ll d2 = u*u + r*r;
    ll d3 = r*r + d*d;
    ll d4 = l*l + d*d;
    if((d1==d2) && (d2==d3) && (d3==d4) && (d4==d1)){
        yes;
        return;
    }
    no;
    return;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int l,r,d,u;
        cin>>l>>r>>d>>u;
        if(l==r && r==d && d==u){
            yes;
        }
        else no;
        //solve(l,r,d,u);
    }

    return 0;
}