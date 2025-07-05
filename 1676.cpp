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

void solveG()
{
   int n;
	cin >> n;
	vector<int> child[n + 7];
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		child[x].push_back(i);
	}
	string s;
	cin >> s;
	int res = 0;
	function<int(int)> dp = [&] (int x) {
		int bal = (s[x - 1] == 'B') ? -1 : 1;
		if (child[x].empty()) {return bal;}
		for (int i : child[x]) {
			bal += dp(i);
		}
		if (bal == 0) {res++;}
		return bal;
	};
	dp(1);
	cout << res << '\n';
}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        solveG();
    }

    return 0;
}