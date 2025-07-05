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

int help(string &s, int st, int e, char ch)
{
    int i = st;
    int j = e;
    int cnt = 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            if (s[i] == ch)
            {
                i++;
                cnt++;
            }
            else if (s[j] == ch)
            {
                j--;
                cnt++;
            }
            else
            {
                return -1;
            }
        }
    }
    return cnt;
}

void solveC(string &s, int n)
{
    // Write your solution here
    int i = 0, j = n - 1;
    bool f = 1;
    while (i < j)
    {
        /* code */
        if (s[i] != s[j])
        {
            char ch1 = s[i];
            char ch2 = s[j];

            int s1 = help(s, i, j - 1, ch2);
            int s2 = help(s, i + 1, j, ch1);
            if (s1 == -1)
            {
                cout << s2 << endl;
                return;
            }
            if (s2 == -1)
            {
                cout << s1 << endl;
                return;
            }
            cout << min(s1, s2) << endl;
            f = 0;
            break;
        }
        i++;
        j--;
    }
    if (f)
    {
        cout << 0 << endl;
        return;
    }
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        solveC(s, n);
    }

    return 0;
}