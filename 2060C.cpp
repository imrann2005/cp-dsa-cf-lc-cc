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

void solve(vi&a,int l,int h,int k) {
    // Write your solution here
    sort(all(a));
    int score = 0;
    while (l < h)
    {
        if(a[l] + a[h] < k){
            l++;
        }
        else if(a[l] + a[h] == k){
            l++;
            h--;
            score++;
        }
        else{
            h--;
        }
    }
    cout<<score<<endl;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vi a(n,0);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(a,0,n-1,k);
    }

    return 0;
}