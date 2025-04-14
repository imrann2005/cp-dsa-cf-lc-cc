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

void solve(string&s,int n) {
    // Write your solution here
    vi left(n,0);
    vi right(n,0);

    set<char>st;

    for (int i = 0; i < n; i++)
    {
        st.insert(s[i]);
        left[i] = st.size();
    }
    st.clear();
    for (int i = n-1; i>=0; i--)
    {
        st.insert(s[i]);
        right[i] = st.size();
    }
    
    int mx = 0;

    for (int i = 0; i < n-1; i++)
    {
        int s = left[i]+right[i+1];
        mx = max(mx,s);
    }
  
    cout<<mx<<endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s,n);
    }

    return 0;
}