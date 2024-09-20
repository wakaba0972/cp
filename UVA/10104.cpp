#include<bits/stdc++.h>
using namespace std;

pair<int, int> extgcd(int a, int b){
	if(!b) return {1, 0};
	pair<int ,int> res = extgcd(b, a % b);
	return {res.second, res.first - (a / b) * res.second};
}

int main(){
	int a, b;
	while(cin >> a >> b){
		auto p = extgcd(a, b);
		cout << p.first << ' ' << p.second << ' ' << a*p.first + b*p.second << '\n';
	}
}