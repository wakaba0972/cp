#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

vector<int> build(){
	int n = sqrt(2000000000)+1;
	vector<int> primes;
	vector<bool> isprime(n, true);
	
	for(int i=2; i<=n; i++){
		if(isprime[i]) {
			primes.push_back(i);
			for(int j=i*i; j<=n; j+=i) isprime[j] = false;
		}
	}
	
	return primes;
}

int main(){
	fastio;
	vector<int> primes = build();
	
	int n;
	while(cin >> n){
		int idx = 0;
		int sum = 0;
		while(n>1 && idx<primes.size()){
			while(n%primes[idx]==0){
				n /= primes[idx];
				sum += primes[idx];
			}
			idx++;
		}
		if(n>1) sum += n;
		
		cout << sum << endl;
	}
}