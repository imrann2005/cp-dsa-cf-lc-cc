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
    int c1=1;
    int c3=1;
    int c5=1;
    int c0=3;
    int c2=2;

    for (int i = 0; i < n; i++)
    {
        if(a[i] == 0){
            c0--;
        }
        else if(a[i]==1){
            c1--;
        }
        else if(a[i] == 3){
            c3--;
        }
        else if(a[i]==5){
            c5--;
        }
        else if(a[i]==2){
            c2--;
        }

        if(c0<=0 && c1<=0 && c2<=0 && c3<=0 && c5<=0){
            cout<<i+1<<endl;
            return;
        }
    }

    cout<<0<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n);
    }

    return 0;
}