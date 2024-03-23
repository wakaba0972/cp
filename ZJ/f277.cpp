#include<bits/stdc++.h>
using namespace std;

struct profile{
    string nam;
    int cla;
    int num;
    string intr;
};

bool cmp(profile a, profile b){
    if(a.cla < b.cla) return true;
    else if(a.cla > b.cla) return false;
    else return (a.num < b.num);
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int n;
    cin >> n;

    profile prof[n];
    for(int i=0; i<n; i++) cin >> prof[i].nam >> prof[i].cla >> prof[i].num >> prof[i].intr;

    sort(prof, prof+n, cmp);

    for(auto p: prof){
        cout << p.cla << ' ' << p.num << ' ' << p.nam << '\n' << p.intr << '\n';
    }
}