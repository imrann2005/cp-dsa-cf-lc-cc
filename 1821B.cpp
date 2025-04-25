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

void solve(vi&a,vi&b,int n) {
    // Write your solution here
    int i=0;
    while (i<n)
    {
       if(a[i]!=b[i]){
        break;
       }
       else i++;
    }
    int j=n-1;
    while (j>=0)
    {
        if(a[j]!=b[j]){
            break;
        }
        else j--;
    }
    int i2=i-1;
    int j2=j+1;
    while (i2>=0)
    {
        if(b[i2]<=b[i]){
            i--;
            i2--;
        }
        else break;
    }
    while (j2<n)
    {
        if(b[j2]>=b[j]){
            j++;
            j2++;
        }
        else break;
    }
    cout<<i+1<<" "<<j+1<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi a(n);
        vi b(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        
        
        solve(a,b,n);
    }

    return 0;
}