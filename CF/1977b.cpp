/*
    凡有[1, 1]皆可化為[-1, 0, 1]
    以這個思路去解題
*/

#include<bits/stdc++.h>
using namespace std;

void sol(int n){
	bitset<32> bs = n;
	vector<short> vs(33);
	vector<short> cry(33);

	for(int i=0; i<32; i++) vs[i] = bs[i];
	
	for(int i=0; i<32; i++){
		if(vs[i] == 1 && vs[i+1] == 1){
			vs[i] = -1;
			vs[i+1] = 0;
			cry[i+2] = 1;

			for(int j=0; j<32; j++){
				if(vs[j] == 1 && cry[j] == 1){
					vs[j] = cry[j] = 0;
					cry[j+1] = 1; 
				}
				else if(cry[j]) {
					vs[j] = 1;
					cry[j] = 0;
				}
			}
		}
	}
	
	int lpos = 0;
	for(int i=32; i>=0; i--) if(vs[i] != 0) {lpos = i; break;}
	
	cout << lpos+1 << '\n';
	for(int i=0; i<=lpos; i++) cout << vs[i] << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		sol(n);
	}
}