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

void solve(vi&a,int n,int k) {
    // Write your solution here
    int e=0,o=0;
    int mn = INT_MAX;
    int ops = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]%k == 0){
            cout<<0<<endl;
            return;
        }
        mn = min(mn,(k-(a[i]%k)));
        if(a[i] & 1)o++;
        else e++;
    }
    if(k == 4){
        if(e >= 2){
            cout<<0<<endl;
            return;
        }
        ops = min(mn,2-e);
        cout<<ops<<endl;
        return;
    }
    else{
        cout<<mn<<endl;
        return;
    }
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n>>k;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n,k);
    }

    return 0;
}