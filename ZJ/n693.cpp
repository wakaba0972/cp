/*
    Problem: UVA 10721 - Bar Codes
		state definition:
		f(n, k, m) = 共n個units, 恰好k個bars, 每個bar最多m units的可能數
		
		transition:
		f(n, k, m) = f(n-1, k-1, m) // 第1個bar長度為 1 unit
					+f(n-2, k-1, m) // 第2個bar長度為 2 unit
					...
					+f(n-m, k-1, m) // 第2個bar長度為 m unit
					
		base case:
		f(n, k, m)  = 0, if n<k or n<=0 or k<=0
					= 0, if k=1 and n>m
					= 1, if k=1 and n<=m
*/

#include<bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

long long mem[51][51];
bool isvisit[51][51];

long long f(int n, int k, int m){
	if(isvisit[n][k]) return mem[n][k];
	else{
		if(n<k || n<=0 || k<=0) mem[n][k] = 0;
		else if(k==1 && n<=m) mem[n][k] = 1;
		else if(k==1 && n>m) mem[n][k] = 0;
		else{
			for(int i=n-1; i>=n-m && i>0; i--) {
				mem[n][k] += f(i, k-1, m);
			}
		}
		
		isvisit[n][k] = true;
		return mem[n][k];
	}
}

int main(){
	fastio;
	
	long long n, k, m;
	while(cin >> n >> k >> m){
		memset(mem, 0, sizeof(mem));
		memset(isvisit, 0, sizeof(isvisit));
		cout << f(n, k, m) << endl;;
	}
}