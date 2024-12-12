/*
    令global cycle為所有倖存的牛cycle的LCM
    如果一個global cycle沒有牛被吃即可結束模擬
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define em emplace_back

int lcm(int a, int b){
	return a*b/__gcd(a, b);
}

int main(){
	fastio;
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<vector<int>> cows(n);
		vector<int> alive(n);
		vector<int> sizs(n);
		
		for(int i=0; i<n; i++){
			cin >> sizs[i];
			alive[i] = i;
			for(int j=0, k; j<sizs[i]; j++){
				cin >> k;
				cows[i].em(k);
			}
		}
		
		int days = 0;
		int lst_eat_day = 0;
		
		while(true){
			int cycle = 1;
			for(int idx: alive){
				cycle = lcm(cycle, sizs[idx]);
			}
			
			bool eat = false;
			for(int d=0; d<cycle; d++){
				if(alive.empty()) break;

				vector<int> milk;
				for(int idx: alive) milk.em(cows[idx][(days+d) % sizs[idx]]);
				int mn = *min_element(all(milk));
				
				if(count(all(milk), mn) > 1) continue;
				else {
					eat = true;
					lst_eat_day = days+d;
					auto idx = find(all(milk), mn) - milk.begin();
					alive.erase(alive.begin()+idx);
				}
			}
			
			days += cycle;
			
			if(alive.empty()) break;
			if(!eat) break;
		}
		
		int C = alive.size();
		int D = (C==n? 0: lst_eat_day+1);
		
		cout << C << ' ' << D << '\n';
		
	}
}