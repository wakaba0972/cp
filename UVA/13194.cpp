#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define MAX 1000001

vector<int> ptable;
vector<pair<ull, int>> prime_factors;
set<ull> factors;
ull res = 1;

void gen_ptable(){
    bitset<MAX> isprime;
    isprime.set();
    isprime[0] = isprime[1] = false;

    ull sqr = sqrt(MAX);
    for(int i=2; i<=sqr; i++){
        if(isprime[i]) {
            for(int j=(i<<1); j<MAX; j+=i) isprime[j] = false;
        }
    }

    for(int i=2; i<MAX; i++) if(isprime[i]) ptable.push_back(i);

    //for(ull i: ptable) cout << i << '\n';
}

void dfs(int idx=0){
    if(idx >= prime_factors.size()) return;

    for(int i=0; i<=prime_factors[idx].second; i++){
        if(i) res *= prime_factors[idx].first;
        factors.insert(res);
        
        dfs(idx+1);
    }

    for(int i=0; i<prime_factors[idx].second; i++) res /= prime_factors[idx].first;
    //res /= (ull)pow(prime_factors[idx].first, prime_factors[idx].second-1);
}

ull fsum(ull n){
    prime_factors.clear();
    factors.clear();
    res = 1;

    ull cn = n;

    for(int p: ptable){
        if(cn == 1) break;
        if(!(cn%p)) prime_factors.push_back({p, 0});
        while(!(cn%p)){
            cn /= p;
            prime_factors.back().second++;
        }
    }
    if(cn > 1) prime_factors.push_back({cn, 1});

    //for(auto p: prime_factors) cout << p.first << ' ' << p.second << endl;
    
    dfs();

    //for(auto i: factors) cout << i << endl;

    return accumulate(factors.begin(), factors.end(), -n);
}

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    gen_ptable();

    int t;
    cin >> t;

    ull n, s;
    while(t--){
        cin >> n;
        s = fsum(n);
        //cout << s << '\n';

        if(s == n) cout << "perfect\n";
        else if(s > n) cout << "abundant\n";
        else cout << "deficient\n";
    }
}