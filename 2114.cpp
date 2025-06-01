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


const int MOD = 1e9 + 7;
const int INF = INT_MAX;

bool isInteger(double N) {
    // A small epsilon to account for floating point inaccuracies
    return std::fabs(N - std::round(N)) < 1e-9;
}

void solveA(std::string& s) {
    int year = std::stoi(s);

    double x = std::sqrt(year);

    if (isInteger(x)) {
        int sum_ab = static_cast<int>(std::round(x)); 
     
        std::cout << 0 << " " << sum_ab << std::endl;

    } else {
        std::cout << -1 << std::endl;
    }
}


void solveB(string s,int n,int k){
    int c0=0,c1=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '0')c0++;
        else c1++;
    }
    int rem = 2*k;
    if(c0-rem == c1 || c1-rem == c0){
        yes;
        return;
    }
    no;
}


int main() {
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        // ll n,k;
        // cin>>n>>k;

        string s;
        cin>>s;
        solveA(s);
    }

    return 0;
}