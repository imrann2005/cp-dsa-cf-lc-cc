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

void solve(ll n)
{
    // Write your solution here
    int c3 = 0, c2 = 0;
    while (n % 3 == 0)
    {
        c3++;
        n = n / 3;
    }
    while (n % 2 == 0)
    {
        c2++;
        n = n / 2;
    }
    if (n == 1)
    {
        if (c2 > c3)
        {
            cout << -1 << endl;
            return;
        }
        int ops = 0;
        ops += c3;
        ops += c3 - c2;
        cout << ops << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

void solveC(){
        int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		map<int, int> cnt;
		int mx = 0;
		for (auto &it : a) {
			if (it % k == 0) continue;
			++cnt[k - it % k];
			mx = max(mx, cnt[k - it % k]);
		}
		long long ans = 0;
		for (auto it : cnt) {
            auto key = it.first;
            auto value = it.second;
			if (value == mx) {
				ans = k * 1ll * (value - 1) + key + 1;
			}
		}
		cout << ans << endl;
}

void threeVals(){
    ll n,x;
    cin>>n>>x;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(all(a));
    //2 7 5 1
    //1 
    
    for(int i=0;i<n;i++){
        ll s = a[i].first;
        int j = i+1;
        int k = n-1;

        while (j<k)
        {
            /* code */
            ll sum = a[j].first + a[k].first;
            if(s + sum == x){
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<endl;
                return;
            }
            else if(s + sum > x){
                k--;
            }
            else{
                j++;
            }
        }
        
    }

    cout<<"IMPOSSIBLE\n";
}

int main()
{
    fast_io;

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     // ll n;
    //     // cin >> n;
    //     // solve(n);
    //     threeVals();
    // }

    threeVals();

    return 0;
}

/*
2 7 5 1
n=4,x=8

1 2 5 7


*/