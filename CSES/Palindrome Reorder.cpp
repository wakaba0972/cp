#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

int main(){
	fastio;
	
	string s;
	cin >> s;
	
	vector<int> cnts(26, 0);
	for(char &c: s) cnts[c-'A']++;
	
	bool res = true;
	char single = 0;
	string s1, s2;
	
	for(int i=0; i<26; i++){
		while(cnts[i] > 0){
			if(cnts[i] == 1) {
				if(single) res = false;
				single = i+'A';
				break;
			}
			else{
				s1 += (i+'A');
				s2 += (i+'A');
				cnts[i] -= 2;
			}
		}
	}
	
	reverse(s2.begin(), s2.end());
	if(!res) cout << "NO SOLUTION" << endl;
	else {
		if(single) cout << s1 << single << s2;
		else cout << s1 << s2;
	}
}