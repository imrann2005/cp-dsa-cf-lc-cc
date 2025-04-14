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
    set<int>st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
        st.insert(b[i]);
    }
    map<int,int>mpp1;
    map<int,int>mpp2;
    mpp1[a[0]] = 1;
    mpp2[b[0]] = 1;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==a[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }
        mpp1[a[i]] = max(mpp1[a[i]],cnt);
    }
    cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if(b[i]==b[i-1])cnt++;
        else{
            cnt = 1;
        }
        mpp2[b[i]] = max(mpp2[b[i]],cnt);
    }
    int mx = 1;
    for (auto &it : st)
    {
        mx = max(mx,mpp1[it]+mpp2[it]);
        
    }
    
    cout<<mx<<endl;
    
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vi a(n),b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        
        
        solve(a,b,n);
    }

    return 0;
}