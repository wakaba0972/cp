#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

int main(){
	fastio;
	
	int n;
	cin >> n;
	
	while(n--){
		bool res = true;
		int a, b;
		cin >> a >> b;
		
		int bb = 2*b-a;
		bb /= 3;
		
		int aa = a - bb;
		aa /= 2;

		if(2*aa+bb != a) res = false;
		if(2*bb+aa != b) res = false;
		if(aa < 0 || bb < 0) res = false;
		if((!a && b) || (a && !b)) res = false;
		
		cout << (res? "YES\n": "NO\n");
		
	}
}