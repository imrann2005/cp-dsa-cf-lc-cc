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



void solve(vi&a,int n) {
    // Write your solution here
    int cnt = 0;
    int l=0,r=0;
    while (r < n)
    {
        if(cnt >= 2)break;
        if(a[r] != 0){
            r++;
        }
        else{
            if(l!=r)cnt++;
            l = r;
            r++;
            l++;
        }
    }
    if(l!=r)cnt++;
    if(cnt >= 2 ){
        cout << 2 << endl;
    }
    else cout<<cnt<<endl;
    
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