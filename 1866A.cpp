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
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve() {
    // Write your solution here
}

int main() {
    fast_io;

    int n;
    cin>>n;
    vi arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mini = INT_MAX;
    rep(i,0,n){
        mini = min(mini,abs(arr[i]));
    }
    cout<<mini<<endl;
    return 0;
}