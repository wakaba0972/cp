/*
    尋找[a[i], b[i]] 與b[n]的距離
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> v1(n), v2(n+1);
		for(int i=0; i<n; i++) cin >> v1[i];
		for(int i=0; i<n+1; i++) cin >> v2[i];
		
		int mn = 2147483647;
		for(int i=0; i<n; i++){
			int l = min(v1[i], v2[i]);
			int r = max(v1[i], v2[i]);
			
			if(l <= v2[n] && v2[n] <= r){ //middle
				mn = 0;
			}
			else if(v1[i] < v2[i]){ // v1 -> v2
				if(v2[n] < v1[i]){ // n v1 v2
					mn = min(mn, abs(v1[i] - v2[n]));
				}else { // v1 v2 n
					mn = min(mn, abs(v2[i] - v2[n]));
				}
			}
			else { // v2 <- v1
				if(v2[n] < v2[i]){ // n v2 v1
					mn = min(mn, abs(v2[i] - v2[n]));
				}else { // v2 v1 n
					mn = min(mn, abs(v1[i] - v2[n]));
				}
			}
		}
		//cout << mn << endl;
		long long ans = mn+1;
		for(int i=0; i<n; i++){
			ans += abs(v1[i] - v2[i]);
		}
		
		cout << ans << '\n';
	}
}