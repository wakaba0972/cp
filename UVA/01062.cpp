#include<bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

int main() {
	fastio;
	
	int cases = 1;
	string s;
	while(true){
		cin >> s;
		
		if(s == "end") break;
		
		vector<char> st;
		st.push_back({s[0]});
		for(int i=1; i<s.size(); i++){
			int min_diff = 999, min_idx = -1;
			
			for(int j=0; j<st.size(); j++){
				if(s[i] <= st[j]) {
					if(st[j] - s[i] < min_diff){
						min_diff = st[j] - s[i];
						min_idx = j;
					}
				}
			}
			
			if(min_idx >= 0) st[min_idx] = s[i];
			else st.push_back(s[i]);
		}
		
		cout << "Case " << cases++ << ": " << st.size() << endl;
	}
}