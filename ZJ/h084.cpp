#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

int n, k;
vector<long long> hss, wss;

bool check(long long h){
	int post = 0;
	int count = 0;
	
	for(int i=0; i<n; i++){
		if(h <= hss[i]) count++;
		else count = 0;
		
		if(wss[post] <= count) {
			count -=wss[post];
			post++;
		}
		
		if(post >= k) break;
	}
	
	return (post == k);
}

int main(){
	fastio;
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		long long t;
		cin >> t;
		hss.push_back(t);
	}
	for(int i=0; i<k; i++){
		long long t;
		cin >> t;
		wss.push_back(t);
	}

	vector<long long> hs = hss;
	sort(hs.begin(), hs.end());
	
	int l=0, r=n-1;
	long long ans=-1;
	while(l <= r){
		int mid = (l+r)/2;
		if(check(hs[mid])) {
			ans = hs[mid];
			l = mid+1;
		}
		else r = mid-1;
	}
	
	cout << ans;
}