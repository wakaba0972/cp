/*
    令f(k,n): 1 <= i,j <= n, i和j的最大公因數為k的有序對(i,j)數量
    aka 滿足gcd(i,j)=k 且 1 <= i,j <= n的有序對(i, j)數量

    根據排容原理，以k為最大公因數的序對數=以k為公因數的序對數-以k的倍數為公因數的序對數
    又，以k的倍數為公因數的序對數=k的倍數為最大公因數的序對數總和
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

vector<ll> mem(100001, -1);

ll f(ll k, int& n){
	if(mem[k] >= 0) return mem[k];
	
	mem[k] = (n/k) * (n/k);
	for(ll i=k+k; i<=n; i+=k) mem[k] -= f(i, n);
	return mem[k];
}

int main(){
	fastio;
	
	int n;
	cin >> n;
	
	ull res = 0;
	for (int k=n; k >= 1; k--) res += k*f(k, n);
	cout << res;
}