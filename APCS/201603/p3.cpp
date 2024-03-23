#include<bits/stdc++.h>
using namespace std;

#define MAX 100001
typedef unsigned long long ull;

int n;
int tree[MAX << 3];

void update(int v, int g, int l, int r, int pos=0){
    if(l == r && l == g){
        tree[pos] += v;
        return;
    }

    int mid = (l + r) >> 1;

    if(g <= mid) update(v, g, l, mid, (pos << 1)+1);
    else update(v, g, mid+1, r, (pos << 1)+2);

    tree[pos] =  tree[(pos << 1)+1] + tree[(pos << 1)+2];
    return;
}

ull query(int gl, int gr, int l, int r, int pos=0){
    if(l == gl && r == gr){
        return tree[pos];
    }

    int mid = (l + r) >> 1;

    if(gr <= mid){
        return query(gl, gr, l, mid, (pos << 1)+1);
    }
    else if(gl > mid){
        return query(gl, gr, mid+1, r, (pos << 1)+2);
    }
    else{
        return query(gl, mid, l, mid, (pos << 1)+1) + query(mid+1, gr, mid+1, r, (pos << 1)+2);
    }
}

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    ull ans = 0;
    map<int, priority_queue<int>> mp;

    cin >> n;
    for(int t, i=0; i<(n << 1); i++){
        cin >> t;
        mp[t].push(i);
    }

    for(auto it=mp.begin(); it!=mp.end(); it++){
        int r = it->second.top();
        it->second.pop();   
        int l = it->second.top();
        it->second.pop();

        ans += query(l, r, 0, (n << 1) - 1);
        update(1, l, 0, (n << 1) - 1);
        update(1, r, 0, (n << 1) - 1);
    }

    cout << ans;
}