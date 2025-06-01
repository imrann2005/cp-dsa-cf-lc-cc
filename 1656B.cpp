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

void solve(vll&a,int n,int k) {
    // Write your solution here
    sort(all(a));
    int i=0;
    int j=1;
    while (i<n && j<n)
    {
        if(a[i]+abs(k) == a[j]){
            yes;
            return;
        }
        else if(a[i]+abs(k) <= a[j]){
            i++;
        }
        else{
            j++;
        }
    }
   no;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(a,n,k);
    }

    return 0;
}