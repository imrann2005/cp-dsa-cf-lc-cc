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

vector<int> findnse(vi&a,int n){
    stack<int>st;
    vi nse(n);
    for (int i = n-1; i >= 0; i--)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? -1 : st.top();
        st.push(i);
        
    }
    return nse;
    
}

vi findPse(vi&a,int n){
    stack<int>st;
    vi pse(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            /* code */
            st.pop();
        }
        pse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return pse;
}

void solve(vi&a,int n) {
    // Write your solution here
    vi nse = findnse(a,n);
    vi pse = findPse(a,n);

    for (int i = 0; i < n; i++)
    {
        if(nse[i] != -1 && pse[i]!=n){
            yes;
            cout<<pse[i]+1<<" "<<i+1<<" "<<nse[i]+1<<endl;
            return;
        }
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
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        
        solve(a,n);
    }

    return 0;
}