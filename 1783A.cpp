#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define si set<int>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(vi &a,int n) {
    // Write your solution here
    vi p(n,0);
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i-1] + a[i-1];
        if(p[i]==a[i]){
            swap(a[0],a[n-1]);
            break;
        }
    }
    yes;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi a(n);
        si s;
        for (int i = 0; i < n; i++)
        {   
            cin>>a[i];
            s.insert(a[i]);
        }
        if(s.size() == 1){
            no;
        }
        else solve(a,n);
    }

    return 0;
}