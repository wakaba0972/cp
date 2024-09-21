#include<bits/stdc++.h>
using namespace std;

pair<long long, long long> extgcd(long long a, long long b){
	if(!b) return {1, 0};
	pair<long long ,long long> res = extgcd(b, a % b);
	return {res.second, res.first - (a / b) * res.second};
}

int main(){
	long long n;
	while(cin >> n){
		if(!n) break;
		
		long long c1, n1 ,c2, n2;
		cin >> c1 >> n1 >> c2 >> n2;
		
		if(n % __gcd(n1, n2)) {
			cout << "failed\n";
			continue;
		}
		
		pair<long long, long long> p = extgcd(n1, n2);
		long long g = p.first * n1 + p.second * n2;
		p.first *= n/g, p.second *= n/g;
		
		long long mn = ceil((-g)*p.first / (double)n2);
		long long mx = floor(g*p.second / (double)n1);
		
		if(mn > mx) {
			cout << "failed\n";
			continue;
		}
		
		if((n2/g*c1 - n1/g*c2)*mn < (n2/g*c1 - n1/g*c2)*mx){
			cout << p.first + n2/g*mn << ' ' << p.second - n1/g*mn << endl;
		}
		else{
			cout << p.first + n2/g*mx << ' ' << p.second - n1/g*mx << endl;
		}

	}

	
}