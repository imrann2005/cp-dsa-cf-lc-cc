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

void solveC(vi&a,int n) {
    // Write your solution here
    int mn = 1;
    int mx = n;
    int l=0,r=n-1;
    while (l < r)
    {
        /* code */
        if(a[l]==mn){
            mn++;
            l++;
        }
        else if(a[l]==mx){
            l++;
            mx--;
            
        }
        else if(a[r]==mn){
            mn++;
            r--;
        }
        else if(a[r]==mx){
            mx--;
            r--;
        }
        else{
            cout<<l+1<<" "<<r+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solveC(a,n);
    }

    return 0;
}