#include<bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

int main() {
	fastio;
	
	int t;
	cin >> t;
	
	for(int k=0; k<t; k++){
		int mp[100][100];
		memset(mp, 0, sizeof(mp));
		
		int a, b, c, d;
		for(int i=0; i<2; i++){
			cin >> a >> b >> c >> d;
			for(int j=min(a, c); j<max(a, c); j++) for(int z=min(b, d); z<max(b, d); z++){
				mp[j][z]++;
			}
		}
		
		int r1 = 0, r2 = 0, r3 = 0;
		for(int i=0; i<100; i++){
			for(int j=0; j<100; j++){
				if(mp[i][j] == 0) r1++;
				else if(mp[i][j] == 1) r2++;
				else if(mp[i][j] == 2) r3++;
			}
		}

		cout << "Night " << k+1 << ": " << r3 << ' ' << r2 << ' ' << r1 << endl;
	}
}