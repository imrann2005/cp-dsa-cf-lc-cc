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

void solveA() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a > c || b > d) {
        no;
        return;
    }
    {
        int mx = max(a, b);
        int mn = min(a, b);
        if (mx > 2 * (mn + 1)) {
            no;
            return;
        }
    }

    {
        int x = c - a;
        int y = d - b;
        int mx = max(x, y);
        int mn = min(x, y);
        if (mx > 2 * (mn + 1)) {
            no;
            return;
        }
    }

    yes;
}

void solveB(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll mx = 0;
    int i=0,j=0;
    while (i<n)
    {
        if(s[i]=='1'){
            j = i;
            while (j<n && s[j]==s[i])
            {
                mx = max(mx,(ll)j-i+1);
                j++;
            }
            i = j;    
        }
        else i++;
    }
    if(mx >= k){
        no;
        return;
    }

    vll a(n,0);
    int val  = n;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0'){
            a[i] = val;
            val--;
        }

    }
    val = 1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==0){
            a[i] = val;
            val++;
        }
    }
    yes;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;
    
}

void solveC(){
    ll n;
    cin>>n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    map<ll,ll>mpp;
    
    cout<<s<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        solveC();
    }

    return 0;
}