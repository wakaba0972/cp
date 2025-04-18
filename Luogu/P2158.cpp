/* 
    給定n*n的方陣，求所有gcd(x,y)=1的(x,y)的數量
    
    若(x',y')被某點(x,y)遮擋了，則(x',y')必為(x,y)的整倍數
    因此只要找gcd(x,y)=1的(x,y)的數量就好
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define eb emplace_back
#define pb push_back
#define rep(s, n) for(int i=s; i<n; ++i)
#define oo 2000000000

vector<ll> mem(40001, -1);

ll f(ll k, int n){
	if(mem[k] >= 0) return mem[k];
	
	mem[k] = (n/k) * (n/k);
	for(ll i=k+k; i<=n; i+=k) mem[k] -= f(i, n);
	return mem[k];
}

int main(){
	fastio;
	
	int n;
	cin >> n;
	
	if(n==1) cout << 0;
	else if(n==2) cout << 3;
	else cout << f(1, n-1)+2;
	
}