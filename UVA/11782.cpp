/*
    f(u, l, h)表示以u為根的子樹, 最多選擇l個節點，能堵住所有通往leaf的路徑的最大值，h表示u在整顆樹中的高度
    很顯然的，如果選擇u，則不會選u的子樹，如果選擇u的子樹，則不會選u，因此從兩種情況取最大值即可
    選擇u時，相當於f(u, 1, h) = tree[u]
    選擇u的子樹時，則要給左子樹i個選擇，右子樹l-i個選擇，也就是mx = max(f(u*2+1, i, h+1) + f(u*2+2, l-i, h+1)), i = [1, l-1]
    然後要注意，n和k是獨立的，所以可能出現計算到leaf了，但l>1的情況，也就是超過樹高，因此我們多設一個變數h，紀錄此時的高度，
    如果h > n，則直接return -21474836，表示這個情況不可能發生
    當然如果能換個寫法最好，反正這樣寫這題能AC XD
    最後，因為題目是說最多選擇l個節點，所以也要看2 <= i < l的情況，所以取mx = max(u, i, h), i = [1, l-1]
*/

#include<bits/stdc++.h>
using namespace std;

int n, k;
int tree[(1<<20)+10];
int mem[(1<<20)+10][21];
bool done[(1<<20)+10][21];

void build(int pos, int h){
	if(h > n) return;
	cin >> tree[pos];
	build((pos<<1)+1, h+1);
	build((pos<<1)+2, h+1);
}

int f(int u, int l, int h){
	if(done[u][l]) return mem[u][l];
	if(h > n) {
		return -21474836;
	}
	done[u][l] = true;
	
	int mx = tree[u];
	for(int i=2; i<l; i++) mx = max(mx, f(u, i, h));
	for(int i=1; i<l; i++) mx = max(mx, f((u<<1)+1, i, h+1) + f((u<<1)+2, l-i, h+1));
	return mem[u][l] = mx;
}

int main(){
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	while(cin >> n){
		if(n == -1) break;
		
		cin >> k;
		
		build(0, 0);
		cout << f(0, k, 0) << '\n';
		memset(done, 0, sizeof(done));
	}
}