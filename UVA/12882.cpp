// 把每個rectangle分解成4個edge，然後依照x座標和y座標分別排序
// 然後依序檢查是否有交集，如果有交集就把他們合併

#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")

struct rect{
	int x1, y1, w, h;
};

struct edge{
	int s, t, p, i;
};

inline bool cmp(edge &a, edge &b){
	if(a.p == b.p) return a.s < b.s;
	return a.p < b.p;
}

inline bool intersect(edge &a, edge &b){
	return (a.t >= b.s);
}

rect rs[50001];
int par[50001], siz[50001];
vector<edge> eX, eY;
inline int find(int x) {
	return (par[x] == x? x: par[x] = find(par[x]));
}

inline void unite(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(siz[x] < siz[y]) swap(x, y);
	par[y] = x;
	siz[x] += siz[y];
}

int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	
	int t, x, y, w, h;
	
	while(cin >> t){
		eX.clear();
		eY.clear();
		
		
		for(int i=0; i<t; i++) par[i] = i;
		for(int i=0; i<t; i++) siz[i] = 1;
	
		for(int i=0; i<t; i++){
			cin >> x >> y >> w >> h;
			rs[i] = {x, y, w, h};
			eX.push_back({x, x+w, y, i});
			eX.push_back({x, x+w, y+h, i});
			eY.push_back({y, y+h, x, i});
			eY.push_back({y, y+h, x+w, i});
		}
		
		sort(eX.begin(), eX.end(), cmp);
		sort(eY.begin(), eY.end(), cmp);
		
		for(int i=0; i<(t<<1)-1; i++) {
			for(int j=i+1; j<(t<<1)-1 && eX[i].p==eX[j].p; j++) if(intersect(eX[i], eX[j])) unite(eX[i].i, eX[j].i);
		}
		for(int i=0; i<(t<<1)-1; i++) {
			for(int j=i+1; j<(t<<1)-1 && eY[i].p==eY[j].p; j++) if(intersect(eY[i], eY[j])) unite(eY[i].i, eY[j].i);
		}
		
		unordered_map<int, long long> mp;
		long long mx = 0;
		for(int i=0; i<t; i++){
			mp[find(i)] += rs[i].w * rs[i].h;
			mx = max(mx, mp[find(i)]);
		}
		
		cout << mx << '\n';
	}
}