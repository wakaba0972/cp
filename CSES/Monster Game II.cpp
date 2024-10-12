#include<bits/stdc++.h>
using namespace std;

#define XRANGE 1000000
#define MAXN 200005
#define ll long long
#define oo LLONG_MAX

ll s[MAXN], f[MAXN], dp[MAXN];
ll ds[MAXN];
vector<ll> stmp;

struct discrete{ //離散化
	ll length;
	ll ds[MAXN];
	vector<ll> stmp;
	
	void init(int n){ //離散化s[]
		for(int i=0; i<=n; i++) stmp.push_back(s[i]);
		sort(stmp.begin(), stmp.end());
		stmp.erase(unique(stmp.begin(), stmp.end()), stmp.end());
		for(int i=0; i<=n; ++i) ds[i] = lower_bound(stmp.begin(), stmp.end(), s[i]) - stmp.begin();
		length = stmp.size();
	}
	ll ith(int i) {return stmp[i];} //return第i大的值
	int get(int i) {return ds[i];} //return原序列第i個是第幾大
} disc;

struct line{
	ll m, b = oo;
	ll y(ll x) {return m*disc.ith(x) + b;}
} seg[XRANGE<<2];

void update(line ins, ll pos=1, ll l=1, ll r=XRANGE){
	if(l==r) {
		if(ins.y(l) < seg[pos].y(l)) seg[pos] = ins;
		return;
	}
	ll mid = (l+r)>>1, l_pos = pos<<1, r_pos = (pos<<1)+1;
	if(seg[pos].m < ins.m) swap(ins, seg[pos]);
	if(seg[pos].y(mid) < ins.y(mid)) update(ins, r_pos, mid+1, r);
	else{
		swap(ins, seg[pos]);
		update(ins, l_pos, l, mid);
	}
}
ll query(ll x, ll pos=1, ll l=1, ll r=XRANGE){
	if(l==r) return seg[pos].y(x);
	ll mid = (l+r)>>1, l_pos = pos<<1, r_pos = (pos<<1)+1, res = seg[pos].y(x); 
	if(x <= mid) return min(res, query(x, l_pos, l, mid));
	else return min(res, query(x, r_pos, mid+1, r));
}

int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	
	ll n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> s[i];
	for(int i=1; i<=n; i++) cin >> f[i];
	s[0] = 0, f[0] = k;

	disc.init(n);

	for(int i=0; i<=n; i++){
		update({f[i], dp[i]}, 1, 1, disc.length+1);
		dp[i+1] = query(disc.get(i+1), 1, 1, disc.length+1);
	}

	cout << dp[n];
}