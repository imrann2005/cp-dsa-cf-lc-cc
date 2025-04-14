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

void solve(int n,int m,int l,int r) {
    // Write your solution here
    int cnt = 0;
    int x = n-m;
    while (r > 0 && cnt < x)
    {
        if(cnt == x){
            cout<<l<<" "<<r<<endl;
            return;
        }
        cnt++;
        r--;
    }
    if(cnt == x){
        cout<<l<<" "<<r<<endl;
        return;
    }
    while (l < 0 && cnt < x)
    {
        if(cnt == x){
            cout<<l<<" "<<r<<endl;
            return;
        }
        cnt++;
        l++;
    }
    if(cnt == x){
        cout<<l<<" "<<r<<endl;
    }
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,m,l,r;
        cin >> n>>m>>l>>r;
        solve(n,m,l,r);
    }

    return 0;
}