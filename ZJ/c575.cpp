#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

int n, k;
vector<int> ps;

bool check(int d){
	int idx = 0;
	int range_end = 0;
	
	for(int i=0; i<k; i++){
		range_end = ps[idx]+d;
		while(idx<n && ps[idx]<=range_end) idx++;
		if(idx >= n) break;
	}
	
	return (idx >= n);
}

int main(){
	fastio;
	
	cin >> n >> k;
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		ps.push_back(t);
	}
	
	sort(ps.begin(), ps.end());
	
	int l=1, r=ps[n-1]-ps[0];
	
	while(l < r){
		int mid = (l+r)/2;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	
	cout << r;
}