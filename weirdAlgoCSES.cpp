#include <bits/stdc++.h>
using namespace std;

void algo(long long n){
    std::cout << n << " ";
    
    if(n==1) return;
    
    if(n%2==0){
        /*Even*/
        algo(n/2);
    }
    else{
        /*Odd*/
        algo(3*n + 1);
    }
}

int main() {

int n;
cin >> n;

algo(n);
	return 0;
}