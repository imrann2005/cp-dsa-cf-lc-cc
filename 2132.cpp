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

void solveA() {
    ll n;
    cin>>n;
    string a;
    cin>>a;
    ll m;
    cin>>m;
    string b;
    cin>>b;
    string o;
    cin>>o;
    for (int i = 0; i < m; i++)
    {
        /* code */
        if(o[i]=='V'){
            a = b[i]+a;
        }
        else{
            a.push_back(b[i]);
        }
    }
    cout<<a<<endl;
}

void solveB()
{
    ll n;
    cin>>n;
    ll x;
    ll cnt = 0;
    vll ans;
    ll p = 1;
    for(int i=1;i<=17;i++){
        p = p*10;
        x = 1 + p;
        if((n%x) == 0){
            cnt++;
            // if(ans.size()==0){
            //     ans.pb(x);
            // }
            ans.pb(n/x);
        }
    }
    sort(all(ans));
    cout<<cnt<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    if (cnt)cout<<endl;
}

ll ipow(ll base, int exp) {
    ll res = 1;
    while (exp--) {
        res *= base;
    }
    return res;
}

void solveC1() {
    long long n;
    cin >> n;
    long long ans = 0;
    int x = 0;
    while (n > 0) {
        int d = n % 3; 
        n /= 3;

        if (d > 0) {
            long long b = ipow(3, x);
            long long cost = ipow(3, x + 1);
            if (x > 0) cost += x * ipow(3, x - 1);
            ans += d * cost;
        }
        x++;
    }

    cout << ans << "\n";
}

void ballBerland(){
    ll a,b,k;
    cin>>a>>b>>k;
    map<ll,ll>bmpp;
    map<ll,ll>gmpp;
    vector<pair<ll,ll>>arr(k);
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin>>x;
        arr[i].first = x;
        bmpp[x]++;
    }
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin>>x;
        arr[i].second = x;
        gmpp[x]++;
    }
    sort(all(arr));

    ll cnt = 0;
    ll n = k;
    n--;
    for(auto it : arr){
        ll x = it.first;
        ll y = it.second;
        ll xtraX = bmpp[x]-1;
        ll xtraY = gmpp[y]-1;
        
        cnt += (n-(xtraX+xtraY));
        n--;
        bmpp[x]--;
        gmpp[y]--;
        if(bmpp[x] == 0){
            bmpp.erase(x);
        }
        if(gmpp[y] == 0){
            gmpp.erase(y);
        }
    }

    cout<<cnt<<endl;
}

void orac(){
    int n;
    cin>>n;
    vi a(1e6,0);
    vi f(1e6,0);
    for(int i = 1; i<=n; i++)
			cin>>a[i];
		for(int i = 1; i<=n; i++)
			f[i] = 1;
		for(int i = 1; i<=n; i++) 
			for(int j = i*2; j<=n; j += i)
				if(a[i]<a[j])
					f[j] = max(f[j],f[i]+1);
		int ans = 0;
		for(int i = 1; i<=n; i++)
			ans = max(ans,f[i]);
		cout << ans << endl;
}

int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        orac();
    }

    return 0;
}