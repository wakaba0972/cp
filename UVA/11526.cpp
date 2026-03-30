#include<bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

int main() {
	fastio
	
  register int k;
  cin >> k;
  
  while (k--) {
    register long long n;
    cin >> n;

    register long long res = n, l = 1, r = 1;
    while (r < n) {
    	l = r + 1, r = n / (n / l);
      	res += (r - l + 1) * (n / l);
    }
    cout << res << endl;
  }
}