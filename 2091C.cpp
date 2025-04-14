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
    if(n&1){
        int mid = ceil(n/2.0);
        int mid1 = mid;
        vi order;

        order.pb(mid);

        while (order.size() <= n)
        {
            mid = (mid +2)%n;
            if(mid == 0){
                order.pb(n);
            }
            else order.pb(mid);
        }
        
        vi ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[(i+mid1)%n] = order[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
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