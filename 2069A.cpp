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

void solve(vi&a,int n) {
    // Write your solution here
    int p=0,q=1,r=2;
    while (r < n)
    {
        if(a[p]==1 && a[q]==0 && a[r]==1){
            no;
            return;
        }
        p++;
        q++;
        r++;
    }
    yes;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi b(n);
        for (int i = 0; i < n-2; i++)
        {
            cin >> b[i];
        }
        
        solve(b,n);
    }

    return 0;
}