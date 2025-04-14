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

void solve(int n) {
    // Write your solution here
    n--;
    int x = log2(n);
    int p2 = pow(2,x);
    for (int i = n ; i >= p2; i--)
    {
        cout<<i<<" ";
    }
    for (int i = 0; i < p2; i++)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}