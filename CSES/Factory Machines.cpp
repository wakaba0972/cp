#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
vector<ull> vs;

// 條件函數
ull condition(ull target, ull time){
    // 若超出target，回傳ULLONG_MAX
	// 避免overflow, 並保持condition()單調遞增

	ull sums = 0;
	for(ull i: vs) {
		if(sums+(time/i) > target) return ULLONG_MAX;
		sums += (time/i);
	}
	
	return sums;
}

// 對答案二分搜
ull bsearch(ull target, ull l=1, ull r=ULLONG_MAX-1){
	if(l >= r) return l;
	
	ull mid = (r-l)/2 + l;
	ull mv = condition(target, mid);
	
	if(target <= mv) return bsearch(target, l, mid);
	else return bsearch(target, mid+1, r);
}


int main(){
	ull n, t;
	cin >> n >> t;
	
	for(ull tmp, i=0; i<n; i++){
		cin >> tmp;
		vs.push_back(tmp);
	}
	
	cout << bsearch(t) << endl;
}