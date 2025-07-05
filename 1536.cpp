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

void solveB(string &s, ll n)
{
    // Write your solution here
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (s.find(c) == string::npos)
        {
            cout << c << endl;
            return;
        }
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (char i = 'a'; i <= 'z'; i++)
        {
            string st;
            st += c;
            st += i;
            if (s.find(st) == string::npos)
            {
                cout << st << endl;
                return;
            }
        }
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        for (char i = 'a'; i <= 'z'; i++)
        {
            for (char j = 'a'; j <= 'z'; j++)
            {
                string st;
                st += c;
                st += i;
                st += j;
                if (s.find(st) == string::npos)
                {
                    cout << st << endl;
                    return;
                }
            }
        }
    }

    
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        solveB(s, n);
    }

    return 0;
}