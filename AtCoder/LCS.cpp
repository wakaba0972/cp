#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long

string s1, s2;

vector<vector<int>> mem(3001, vector<int>(3001, -1));
vector<vector<char>> dir(3001, vector<char>(3001));


int lcs(int i, int j){
	if(i == -1 || j == -1) return 0;
	if(mem[i][j] != -1) return mem[i][j];
	if(s1[i] == s2[j]) {
		dir[i][j] = 2;
		return lcs(i-1, j-1) + 1;
	}
	else {
		if(lcs(i-1, j) > lcs(i, j-1)){
			dir[i][j] = 3;
			return mem[i][j] = lcs(i-1, j);
		}
		else {
			dir[i][j] = 4;
			return mem[i][j] = lcs(i, j-1);
		}
	}
}

string trace(int i, int j){
	if(i == -1 || j == -1) return "";
	switch(dir[i][j]){
		case 2:
			return  trace(i-1, j-1) + s1[i];
		case 3:
			return trace(i-1, j);
		case 4:
			return trace(i, j-1);
		default:
			return "";
	}
}

// 定義lcs(i, j) = lcs(i-1, j-1) + 1, while s1[i] == s2[j]
//                 max(lcs(i-1, j), lcs(i, j-1)), while s1[i] != s2[j]

int main(){
	fastio;
	
	cin >> s1 >> s2;
	lcs(s1.size()-1, s2.size()-1);
	cout << trace(s1.size()-1, s2.size()-1);
}