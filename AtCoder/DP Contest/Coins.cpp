#include<bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long

vector<double> ps(3000);
vector<vector<double>> mem(3000, vector<double>(3000));
vector<vector<bool>> done(3000, vector<bool>(3000));

double f(int i, int j){
	if(i == 1 && j == 1) return ps[1];
	if(i == 1 && j == 0) return 1 - ps[1];
	if(done[i][j]) return mem[i][j];
	done[i][j] = true;
	if(j == 0) return mem[i][j] = (1 - ps[i]) * f(i-1, 0);
	if(i == j) return mem[i][j] = ps[i] * f(i-1, j-1);
	return mem[i][j] = (1-ps[i]) * f(i-1, j) + ps[i] * f(i-1, j-1);
}

int main(){
	fastio;
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> ps[i+1];
	}
	
	double ans = 0;
	for(int i=n; i > (n-i); i--){
		ans += f(n, i);
	}
	
	cout << fixed << setprecision(10) << ans; 
}