/*
    用segment tree去儲存每個子區間operation的結果
    用or還是xor，利用變數oper決定
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
bool oper;
vector<int> ns(1<<17);
vector<int> tree(1<<19);

void build(int pos=0, int l=0, int r=(1<<n)-1){
	if(l == r) {tree[pos] = ns[l]; oper = true; return;}
	int mid = ((l+r)>>1);
	
	build((pos<<1)+1, l, mid);
	build((pos<<1)+2, mid+1, r);
	
	if(oper) tree[pos] = tree[(pos<<1)+1] | tree[(pos<<1)+2];
	else tree[pos] = tree[(pos<<1)+1] ^ tree[(pos<<1)+2];
	
	oper = !oper;
	return;
}

void update(int g, int v, int pos=0, int l=0, int r=(1<<n)-1){
	if(l == r && g == r){
		tree[pos] = v;
		oper = true;
		return;
	}
	int mid = ((l+r)>>1);
	
	if(g <= mid) update(g, v, (pos<<1)+1, l, mid);
	else update(g, v, (pos<<1)+2, mid+1, r);
	
	if(oper) tree[pos] = tree[(pos<<1)+1] | tree[(pos<<1)+2];
	else tree[pos] = tree[(pos<<1)+1] ^ tree[(pos<<1)+2];
	
	oper = !oper;
	return;
}

int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i=0; i<(1<<n); i++) cin >> ns[i];
	
	build();

	for(int i=0; i<m; i++){
		int p, b;
		cin >> p >> b;
		update(p-1, b);
		cout << tree[0] << '\n';
	}
}