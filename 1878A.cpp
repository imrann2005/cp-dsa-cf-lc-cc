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

void solve(vi &arr,int n,int k) {
    // Write your solution here
    for (size_t i = 0; i < n; i++)
    {
       if(arr[i] == k){
        yes;
        return;
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
        vi arr(n);
        for (size_t i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        solve(arr,n,k);
    }

    return 0;
}