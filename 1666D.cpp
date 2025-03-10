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

void solve(string &s, string &t)
{
    // Write your solution here
    map<char, int> mpp1;
    map<char, int> mpp2;
    for(auto &ch : s){
        mpp1[ch]++;
    }
    for(auto& ch : t){
        mpp2[ch]++;
    }
    int i = 0, j = 0;
    int n = s.length();
    int m = t.length();

    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            if (mpp2[t[j]] > mpp1[s[i]])
            {
                break;
            }
            if (mpp1[s[i]] == mpp2[t[j]])
            {
                mpp2[t[j]]--;
                j++;
            }
        }
        mpp1[s[i]]--;
        i++;
    }

    if (j == m)
    {
        yes;
       
    }
    else
    {
        no;
       
    }
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        solve(s, t);
    }

    return 0;
}