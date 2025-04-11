/*
	每次都取最小的兩個數字相加
	使用priority_queue
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		priority_queue<long long> PQ;
		for(int tt, i=0; i<n; i++){
			cin >> tt;
			PQ.push(-tt);
		}
		
		long long scost = 0;
		while(1){
			long long u = -PQ.top();
			PQ.pop();
			long long v = -PQ.top();
			PQ.pop();
			
			scost += u+v;
			
			if(PQ.empty()) break;
			PQ.push(-(u+v));
		}
		
		cout << scost << '\n';
	}
}