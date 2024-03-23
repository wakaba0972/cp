#include<bits/stdc++.h>
using namespace std;

#define MAX 500001
#define ll long long

int n;
int ns[MAX];
ll tree[MAX << 2];
ll tag[MAX << 2];

void build(int pos, int l, int r){
    if(l == r){
        tree[pos] = ns[l];
        return;
    }

    int mid = (l+r) >> 1;
    
    build((pos<<1)+1, l, mid);
    build((pos<<1)+2, mid+1, r);

    tree[pos] = tree[(pos<<1)+1] + tree[(pos<<1)+2];
}

void update(int pos, int l, int r, int gl, int gr, int v){
    if(l == gl && r == gr){
        tree[pos] += v * (r - l + 1);
        tag[pos] += v;
        return;
    }

    int mid = (l+r) >> 1;
    
    if(tag[pos]){
        tag[(pos<<1)+1] += tag[pos];
        tag[(pos<<1)+2] += tag[pos];
        tree[(pos<<1)+1] += tag[pos] * (mid - l + 1);
        tree[(pos<<1)+2] += tag[pos] * (r - mid);
        tag[pos] = 0;
    }

    if(gr <= mid){
        update((pos<<1)+1, l, mid, gl, gr, v);
    }
    else if(gl > mid){
        update((pos<<1)+2, mid+1, r, gl, gr, v);
    }
    else{
        update((pos<<1)+1, l, mid, gl, mid, v);
        update((pos<<1)+2, mid+1, r, mid+1, gr, v);
    }

    tree[pos] = tree[(pos<<1)+1] + tree[(pos<<1)+2];
}

ll query(int pos, int l, int r, int gl, int gr){
    if(l == gl && r == gr){
        return tree[pos];
    }

    int mid = (l+r) >> 1;

    if(tag[pos]){
        tag[(pos<<1)+1] += tag[pos];
        tag[(pos<<1)+2] += tag[pos];
        tree[(pos<<1)+1] += tag[pos] * (mid - l + 1);
        tree[(pos<<1)+2] += tag[pos] * (r - mid);
        tag[pos] = 0;
    }
    
    if(gr <= mid){
        return query((pos<<1)+1, l, mid, gl, gr);
    }
    else if(gl > mid){
        return query((pos<<1)+2, mid+1, r, gl, gr);
    }
    else{
        return query((pos<<1)+1, l, mid, gl, mid) + query((pos<<1)+2, mid+1, r, mid+1, gr);
    }
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);
    
    cin >> n;
    for(int i=0; i<n; i++) cin >> ns[i];

    build(0, 0, n-1);
    
    int x, y, z;
    char c;
    while(cin >> x >> y >> c){
        if(c == 'u') cin >> z;

        if(c == 'q') cout << query(0, 0, n-1, x, y) << '\n';
        else update(0, 0, n-1, x, y, z);
    }
}