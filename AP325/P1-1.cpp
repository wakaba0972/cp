#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

int sol(){
	string s;
	cin >> s;
	if(s == "f") return 2*sol()-1;
	else if(s == "g") return sol()+2*sol()-3;
	else return stoi(s);
}

int main(){
	fastio;
	cout << sol();
}