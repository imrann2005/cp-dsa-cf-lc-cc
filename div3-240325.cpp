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

void solveA(string &s, int n)
{
    // Write your solution here
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            cnt++;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            c += (cnt - 1);
        }
        else
            c += (cnt + 1);
    }

    cout << c << endl;
}

void solveB(int n, int x)
{
    if (x == n)
    {
    }
    for (int i = 0; i < x; i++)
    {
        cout << i << " ";
    }
    for (int i = x + 1; i < n; i++)
    {
        cout << i << " ";
    }
    if (x != n)
    {
        cout << x << endl;
    }
}

void solveC(vll &a, vll &b, int n, int k)
{
    bool f = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (f == 0 && b[i] != -1)
        {
            f = 1;
            sum += a[i] + b[i];
        }
        else if (b[i] != -1)
        {
            ll s = 0;
            s += a[i];
            s += b[i];
            if (s != sum)
            {
                cout << 0 << endl;
                return;
            }
        }
    }
    if (f == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i] == -1)
            {
                ll d = sum - a[i];
                if (d >= 0 && d <= k)
                {
                }
                else
                {
                    cout << 0 << endl;
                    return;
                }
            }
        }
        cout << 1 << endl;
        return;
    }
    sort(all(a));
    ll mx = a[n-1]-a[0];
    if (mx <= k)
    {
        cout << k - mx + 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

void solveD(vll&a,vll&b,int n,int m){
    int i=0;
    int j=0;
    bool f0=0,f1=0;
    int idx1 = -1;
    while (i < n && j<m)
    {
        /* code */
        if(a[i]>=b[j]){
            i++;
            j++;
        }
        else i++;
    }
    ll mn = LLONG_MAX;
    if(j>=m){
        cout<<0<<endl;
        return;
    }
    if(j==m-1){
        mn = min(mn,b[j]);
    }
    if(j<=m-1){
        idx1 = j;
        f0=1;
    }
    i=n-1;
    j=m-1;
    while (i>=0 && j>=0)
    {
        if(a[i] >= b[j]){
            i--;
            j--;
        }
        else i--;
    }
    if(j<0){
        cout<<0<<endl;
        return;
    }
    if(j==0){
        mn = min(mn,b[j]);
    }
    int idx2=-1;
    if(j>=0){
        idx2 = j;
        f1 = 1;
    }
    if(idx1 == idx2 && (idx2-0 == 1) && ()){
        mn = min(mn,b[idx1]);
    }
    else if(idx1 > idx2 ){
        if(idx2-0 == 1){
            mn = min(mn,b[idx2]);

        }
        if(m-idx1 == 1){
            mn = min(mn,b[idx1]);

        }

    }
    else
    {
        cout<<-1<<endl;
        return;
    }
    

    cout<<mn<<endl;

}

int main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vll a(n);
        vll b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
        }
        solveD(a, b, n, k);
    }

    return 0;
}