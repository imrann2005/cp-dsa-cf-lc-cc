#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
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

void solve(string &s)
{
    // Write your solution here
    set<char> st;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        /* code */
        if (st.count(s[i]))
        {
            break;
        }
        st.insert(s[i]);
    }
    int d = st.size();
    //cout<<d<<endl;
    for (int i = d; i < n; i++)
    {
        if(s[i] != s[i-d]){
            no;
            return;
        }
    }
    yes;

    
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}