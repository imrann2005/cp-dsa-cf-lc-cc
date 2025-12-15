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

void solveA()
{
    // Write your solution here
    ll n;
    cin >> n;
    int mn = INT_MAX;
    int nn = n;
    if (nn < 10)
    {
        cout << nn << endl;
        return;
    }
    while (nn > 0)
    {
        /* code */
        int x = nn % 10;
        mn = min(mn, x);
        nn = nn / 10;
    }
    cout << mn << endl;
}

void solveB()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> a[i];
    }
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (j < n)
    {
        /* code */
        if (a[j] == 0)
        {
            while (a[j] == 0 && (j - i + 1) < k && j < n)
            {
                /* code */
                j++;
            }
            if (j < n && a[j] == 0 && (j - i + 1) == k)
            {
                cnt++;
                i = j;
                i += 2;
                j += 2;
            }
            else
            {
                i = j;
                j++;
                i++;
            }
        }
        else
        {
            i++;
            j++;
        }
    }

    cout << cnt << endl;
}

void solveC()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back({x, i + 1});
    }
    sort(all(a));
    int st = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].second == k)
        {
            st = i;
        }
    }
    int w = 1;
    st++;
    while (st < n)
    {
        /* code */
        int diff = a[st].first - a[st - 1].first;
        int diff2 = a[st-1].first - w;
        if (diff - diff2 > 1)
        {
            no;
            return;
        }
        else
        {
            st++;
            w += diff;
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
        solveC();
    }

    return 0;
}