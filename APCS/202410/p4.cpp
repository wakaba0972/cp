/*
	考慮當前列車的行程是[s, d]，如果有其他列車的終點在[s, d-1]之間，便可以轉乘這台列車抵達站點d。
	所以我們用終點去小到大排序所有列車，然後用二分搜分別找出第一個終點 ≥ s的列車和最後一個終點 < d的列車的位置，分別是p1和p2，
	設dp[i]為搭乘第i班列車的方法數，那很明顯dp[i] = dp[p1] + dp[p1+1] + ...... + dp[p2]; 
	接下來用線段樹等方法維護區間和就好了
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll tree[200000 << 2];
ll p;

void update(ll v, int g, int l, int r, int pos=0){
	if(l == r && l == g){
		tree[pos] = (tree[pos] + v) % p;
		return;
	}
	int mid = (l+r)>>1;
	if(g <= mid) update(v, g, l, mid, (pos<<1)+1);
	else update(v, g, mid+1, r, (pos<<1)+2);
	tree[pos] = (tree[(pos<<1)+1] + tree[(pos<<1)+2]) % p;
}

ll query(int gl, int gr, int l, int r, int pos=0){
	if(l == gl && r == gr){
		return tree[pos];
	}
	int mid = (l+r)>>1;
	if(gr <= mid) return query(gl, gr, l, mid, (pos<<1)+1);
	else if(gl > mid) return query(gl, gr, mid+1, r, (pos<<1)+2);
	else return (query(gl, mid, l, mid, (pos<<1)+1) + query(mid+1, gr, mid+1, r, (pos<<1)+2)) % p;
}

struct train{
	int s, d;
};

bool cmp(train &a, train &b){
	return a.d < b.d;
}

bool cmp2(train &a, int d){
	return a.d < d;
}

int main(){
	ll n, m;
	cin >> n >> m >> p;
	
	vector<ll> dp(n);
	vector<train> ts(n);
	
	for(int i=0; i<n; i++) cin >> ts[i].s;
	for(int i=0; i<n; i++) cin >> ts[i].d;
	
	sort(ts.begin(), ts.end(), cmp);
	
	for(int i=0; i<n; i++) if(ts[i].s == 0) update(1, i, 0, n);

	//for(int i=0; i<n; i++) cout << ts[i].s << ' ' << ts[i].d << endl;

	for(int i=1; i<n; i++){
		auto it1 = lower_bound(ts.begin(), ts.end(), ts[i].s, cmp2);
		auto it2 = lower_bound(ts.begin(), ts.end(), ts[i].d, cmp2);
		
		if((*it1).d == ts[i].d) continue;
		if(it2 - it1 > 0){
			//for(; it1!=it2; it1++) dp[i] = (dp[i] + dp[it1-ts.begin()]) % p ;
			update(query(it1-ts.begin(), it2-ts.begin()-1, 0, n), i, 0, n);
		}
		
		//cout << query(i, i, 0, n);

	}
	
	//for(int i=0; i<n; i++) cout << query(i, i, 0, n) << ' ';
	
	ll res = 0;
	for(int i = n-1; i>=0; i--){
		if(ts[i].d == m) res = (res + query(i, i, 0, n)) % p;
		else break;
	}
	
	cout << res;
}