#include <bits/stdc++.h>
using namespace std;

#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define vll vector<ll>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void solve(vi &a, vi &b, int n, int p1)
{
    // Initialize cost to 0
    ll c = 0;

    // Directly inform at least one resident
    c += p1;
    int rem = n - 1; // Remaining residents to inform

    // Priority queue to store the cost of sharing (b[i]) and the number of shares (a[i])
    priority_queue<pii, vector<pii>, greater<pii>> minh;
    for (int i = 0; i < n; i++)
    {
        minh.push({b[i], a[i]});
    }

    // Use the sharing mechanism to inform the rest
    while (!minh.empty() && rem > 0)
    {
        auto p = minh.top();
        int f = p.first;  // Cost per share
        int s = p.second; // Maximum number of shares
        minh.pop();

        // If sharing is cheaper than directly informing
        if (f < p1)
        {
            // Number of residents we can inform using this sharing option
            int can_inform = min(rem, s);
            c += (ll)f * can_inform;
            rem -= can_inform;
        }
    }

    // If there are still remaining residents, directly inform them
    if (rem > 0)
    {
        c += (ll)p1 * rem;
    }

    cout << c << endl;
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        vi a(n);
        vi b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        solve(a, b, n, p);
    }

    return 0;
}