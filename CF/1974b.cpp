#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    
    int t, l;
    string s, r = "", ans = "";
    set<char> st;
    unordered_map<char, char> mp;
    
    cin >> t;
    while(t--){
        cin >> l >> s;
        for(char c: s) st.insert(c);
        for(char c: st) r += c;
        //cout << r << endl;
        
        l = r.size();
        for(int i=0; i<l; i++) mp[r[i]] = r[l-i-1];
        
        for(char c: s) ans += mp[c];
        cout << ans << '\n';
        
        r = "";
        ans = "";
        st.clear();
        mp.clear();
    }
}