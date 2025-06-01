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

bool f(vll&a,int i,int j,int x){
    while (i<=j)
    {
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            if(a[i]==x){
                i++;
            }
            else if(a[j]==x){
                j--;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

void solve(vll&a,int n) {
    // Write your solution here
    int i=0;
    int j=n-1;
    while (i<=j)
    {
        /* code */
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            break;
        }
    }
    ll x = a[i];
    ll y = a[j];
    bool f1 = f(a,i+1,j,x);
    bool f2 = f(a,i,j-1,y);
    if(f1||f2){
        yes;
        return;
    }
    no;

}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        solve(a,n);
    }

    return 0;
}
