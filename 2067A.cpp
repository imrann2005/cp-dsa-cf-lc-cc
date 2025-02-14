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

void solve(int x,int y) {
    // Write your solution here
    if(y-x > 1){
        no;
        return;
    }
    if(((y%9 - x%9)+9)%9 == 1){
        
            yes;
            return;
        
    }
    no;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int x,y;
        cin>>x>>y;
        solve(x,y);
    }

    return 0;
}