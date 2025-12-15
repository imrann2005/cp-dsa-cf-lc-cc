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

vector<int> getSieve(int n)
{
    vector<int> primes(n + 1, 1);
    vector<int> primeList;
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == 1)
        {
            // primeList.pb(i);
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
            primeList.push_back(i);
    }
    return primeList;
}

vector<int> primes = getSieve(50);

bool ask(int divi)
{
    cout << divi << endl;
    string response;
    cin >> response;

    return response == "yes";
}

void bearNdPrime()
{
    // Write your solution here
    int cnt = 0;
    int psq[] = {4, 9, 25, 49, 81};

    for (int i = 0; i < 5; i++)
    {
        int divi = psq[i];
        if (ask(divi))
        {
            cout << "composite" << endl;
            return;
        }
    }

    for (int i = 0; i < min(15, (int)primes.size()); i++)
    {
        /* code */
        int divi = primes[i];
        if (ask(divi))
        {
            cnt++;
        }
        if (cnt >= 2)
        {
            break;
        }
    }

    if (cnt <= 1)
    {
        cout << "prime" << endl;
    }
    else
        cout << "composite" << endl;
}

ll ask2(ll l, ll r)
{
    cout << "? " << l << " " << r << endl;
    ll response;
    cin >> response;
    return response;
}

void flamingo()
{
    ll n;
    cin >> n;
    vll a(n + 1);
    vll q(n + 1);
    q[1] = ask2(1, n);
    q[2] = ask2(2, n);
    a[1] = q[1] - q[2];
    ll s = a[1];
    for (int i = 3; i <= n; i++)
    {
        q[i] = ask2(i - 2, i - 1);
        a[i - 1] = q[i] - a[i - 2];
        s += a[i - 1];
    }

    a[n] = q[1] - s;
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void pythagorean()
{
    ll n;
    cin >> n;
    ll b = n - 1;

    ll mx = (sqrt(2 * b + 1)) - 1;
    ll ans = mx / 2;

    cout << ans << endl;
}

bool guessKthZeroChk(ll n, ll mid, ll k)
{
    cout << "? " << 1 << " " << mid << endl;
    ll response;
    cin >> response;

    ll numZero = mid - response;
    return numZero >= k;
}

void guessKthZero()
{
    ll n, t;
    cin >> n >> t;
    ll k;
    cin >> k;
    ll l = 1;
    ll h = n;
    ll ans = -1;
    while (l <= h)
    {
        /* code */
        ll mid = (l + h) >> 1;
        if (guessKthZeroChk(n, mid, k))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "! " << ans << endl;
}

void sheep()
{
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '*')
        {
            a[i] = 1;
        }
        else
            a[i] = 0;
    }

    vll pre(n, 0);
    vll suff(n, 0);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        pre[i] = s;
    }
    s = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        /* code */
        s += a[i];
        suff[i] = s;
    }
    ll cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            cnt += min(suff[i], pre[i]);
    }
    cout << cnt << endl;
}

bool chk3(vll &a, vll &pre, ll n, ll mid)
{
    cout << "? " << mid + 1 << " ";
    for (int i = 0; i <= mid; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl
         << flush;
    ll response;
    cin >> response;
    ll ans1 = pre[mid];
    return response > ans1;
}

void interview()
{
    ll n;
    cin >> n;
    vll a(n);
    vll pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> a[i];
    }
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        pre[i] = s;
    }
    ll l = 0;
    ll h = n - 1;
    ll ans = 0;
    while (l <= h)
    {
        ll mid = (l + h) >> 1;
        if (chk3(a, pre, n, mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "! " << ans + 1 << endl
         << flush;
}

ll chkLocalMin(ll mid)
{
    ll response;
    cout << "? " << mid << endl;
    cin >> response;
    return response;
}

void localMin()
{
    ll n;
    cin >> n;
    ll l = 1;
    ll h = n;
    ll ans = n;
    while (l <= h)
    {
        /* code */
        ll mid = (l + h) >> 1;
        ll a = (mid - 1 == 0) ? 1e9 : chkLocalMin(mid - 1);
        ll b = chkLocalMin(mid);
        ll c = (mid + 1 == n + 1) ? 1e9 : chkLocalMin(mid + 1);

        if (b < a && b < c)
        {
            ans = mid;
            break;
        }
        else if (a < b)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << "! " << ans << endl;
}

int askFindMine(ll l, ll r, ll n, ll m)
{
    if (l < 1 || l > n || r < 1 || r > m)
        return -1;
    cout << "? " << l << " " << r << endl<<flush;
    int response;
    cin >> response;
    return response;
}

void findMine()
{
    ll n, m;
    cin >> n >> m;
    ll d = askFindMine(1, 1, n, m);
    ll x1 = min(1 + d, n);
    ll y1 = d - (x1-1) + 1;
    ll y2 = min(1 + d, m);
    ll x2 = d - (y2-1) + 1;

    int d1 = askFindMine(x1, y1, n, m);
    int d2 = askFindMine(x2, y2, n, m);

    if (d1 % 2 == 0)
    {
        ll d3 = askFindMine(x1 - d1 / 2, y1 + d1 / 2, n, m);
        if (d3 == 0)
        {
            cout << "! " << x1 - d1 / 2 << " " << y1 + d1 / 2 << endl<<flush;
            return;
        }
    }
    cout << "! " << x2 + d2 / 2 << " " << y2 - d2 / 2 << endl<<flush;
}

ll askGuessingGreatest(ll l,ll r){
    ll response;
    cout<<"? "<<l<<" "<<r<<endl<<flush;
    cin>>response;
    return response;
}

ll right(ll left,ll right){
    ll i = left-1;
    ll l = left;
    ll h = right;
    ll ans = h;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        ll q = askGuessingGreatest(i,mid);
        if(q==i){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

ll left(ll left,ll right){
    ll i = right+1;
    ll l = left;
    ll h = right;
    ll ans = l;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        ll q = askGuessingGreatest(mid,i);
        if(q==i){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    
    return ans;
}

void guessingGreatest() {
    ll n;
    cin >> n;
    ll ans;

    ll q1 = askGuessingGreatest(1, n);

    ll q2 = -1;
    if (q1 > 1) {
        q2 = askGuessingGreatest(1, q1);
    }

    if (q1 == 1) {
        ans = right(q1 + 1, n);  
    }
    else if (q2 == q1) {
        ans = left(1, q1 - 1);
    }
    else {
        if (q1 + 1 <= n) ans = right(q1 + 1, n);
        else ans = q1; 
    }

    cout << "! " << ans << endl << flush;
}

ll asklostNums(ll left,ll right){
    cout<<"? "<<left<<" "<<right<<endl<<flush;
    ll response;
    cin>>response;
    return response;
}

void lostNums(){
    int x[] = {4,8,15,16,23,42};
    ll tgt = 108;
    map<ll,pair<ll,ll>>mpp;
    for (int i = 0; i < 6; i++)
    {
        /* code */
        for (int j = i+1; j < 6; j++)
        {
            ll p = x[i]*x[j];
            mpp[p] = {x[i],x[j]};
        }
    }
    
    vll ans(6);
    ll p1 = asklostNums(1,2);
    auto x1 = mpp[p1];
    ans[0] = x1.first;
    ans[1] = x1.second;
    ll p2 = asklostNums(1,3);
    auto x2 = mpp[p2];
    if(x2.first == ans[0] || x2.second == ans[0]){
        ans[2] = p2/ans[0];
    }
    else{
        ans[0] = x1.second;
        ans[1] = x1.first;
        ans[2] = x2.first == ans[0] ? x2.second : x2.first;
    }

    ll p3 = asklostNums(1,4);
    ans[3] = p3/ans[0];
    ll p4 = asklostNums(1,5);
    ans[4] = p4/ans[0];
    ll sum = 0;
    for(int i=0;i<5;i++){
        sum += ans[i];
    }
    ans[5] = tgt-sum;

    cout<<"! ";
    for (int i = 0; i < 6; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl<<flush;
    
}

bool lftChk(ll l,ll r){
    ll lft = l;
    ll right =  r;
    cout<<"? "<<lft<<" "<<right<<endl<<flush;
    ll f  = 0;
    for (int i = 0; i < r-l+1; i++)
    {
        /* code */
        ll x;
        cin>>x;
        if(x>=lft && x<=right){
            f++;
        }
        // else{
        //     return false;
        // }
    }
    return f&1;//agar odd hai toh uss side jana hai
}

void fixedPtGuessing(){
    ll n;
    cin>>n;
    ll l=1;
    ll h=n;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(lftChk(l,mid)){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<"! "<<l<<endl<<flush;
}

bool chkKeshiParty(ll mid,vll&a,vll&b,ll n){
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(b[i]>=cnt && a[i]>=(mid-cnt-1)){
            cnt++;
        }
        if(cnt==mid){
            break;
        }
    }
    return cnt >= mid;
}

void keshiParty(){
    ll n;
    cin>>n;
    vll a(n+1);
    vll b(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    
    ll l=1;
    ll h=n;
    ll ans = 1;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(chkKeshiParty(mid,a,b,n)){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    cout<<ans<<endl;
}

bool chkSaveNature(vll&p,ll n,ll mid,ll a,ll x,ll b,ll y,ll k){
    ll lcm = (a*b)/__gcd(a,b);
    ll cmn = (mid)/lcm;
    ll a1 = mid/a - cmn;
    ll b1 = mid/b - cmn;

    int idx = 0;
    ll amt = 0;
    for (int i = 0; i < cmn && idx < n; i++)
    {
        amt += (x+y)*(p[idx]/100);
        idx++;
    }

    if(x>y){
    for (int i = 0; i < a1 && idx<n; i++)
    {
        amt += (x)*(p[idx]/100);
        idx++;
    }
    for (int i = 0; i < b1 && idx<n; i++)
    {
        amt += (y)*(p[idx]/100);
        idx++;
    }
    }
    else{
    for (int i = 0; i < b1 && idx<n; i++)
    {
        amt += (y)*(p[idx]/100);
        idx++;
    }
    for (int i = 0; i < a1 && idx<n; i++)
    {
        amt += (x)*(p[idx]/100);
        idx++;
    }
    }
    return amt >= k;
}

void saveTheNature(){
    ll n;
    cin>>n;
    vll p(n);
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    ll x,a;
    cin>>x>>a;
    ll y,b;
    cin>>y>>b;
    ll k;
    cin>>k;
    sort(all(p),greater<ll>());
    ll l=1;
    ll h=n;
    ll ans = -1;
    while (l<=h)
    {
        /* code */
        ll mid = (l+h)>>1;
        if(chkSaveNature(p,n,mid,a,x,b,y,k)){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    //if(chkSaveNature())
    cout<<ans<<endl;
}

bool rulerChk(ll l,ll mid){
    cout<<"? "<<l<<" "<<mid<<endl<<flush;
    ll response;
    cin>>response;

    return response==(l*mid);
}

void ruler(){
    ll l = 1;
    ll h = 999;
    ll ans = h;
    while (l<=h)
    {
        /* code */

        ll mid = (l+h)>>1;
        if(rulerChk(l,mid)){
            l = mid+1;
        }
        else{
            ans = mid;
            h = mid-1;
        }
    }

    cout<<"! "<<l<<endl<<flush;
    
}

int main()
{
    //fast_io;

    // guessKthZero();
    // findMine();
    //lostNums();
    ll t;
    cin >> t;
    while (t--)
    {
        ruler();
    }

    //ruler();

    return 0;
}

/*

Mixing Water
h c t
30 10 20

30-10 = 20

41 15 30

41
init dif = (41-30 = 11)
41-15 = 26/2 = 13 diff = 27
41-15+41 = (67/3 = 23) diff = 

t - (x*h - y*c)/(x+y) -> 0 

18 13 18


7
1 2 1 2 1 2 1

6 8 3 1 5 1 5

1 - [6,3,5,5] -> [6,5,5,3]
2 - [8,1,1] - > [8,1,1]

k=1 : 6+5+5+3+8+1+1 = 29
k=2 : 6+5+5+3+8+1 = 28
k=3 : 6+5+5+8+1+1 = 26

*/