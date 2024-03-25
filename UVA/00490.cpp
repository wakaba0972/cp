// why????

#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(), cout.tie(), ios::sync_with_stdio(0);

    int mx = -1;
    string s;
    vector<string> vs;
    while(getline(cin, s)){
        //s += '\n';
        int ls = s.size();
        mx = max(mx, ls);

        vs.push_back(s);
    }
    
    vector<string> ans(mx);
    
    for(int i=0; i<mx; i++){
        for(int j=vs.size()-1; j>=0; j--){
            if(i < vs[j].size()){
                ans[i] += vs[j][i];
            }
            else ans[i] += -1;
        }
    }
    
    int tp = mx-1, deep = -1, ii = vs.size();
    for(auto v: vs) deep = max(deep, ii);
    for(int i=vs.size()-1; i>=0; i--){
    	if(vs[i].size() == deep) ii = i;
    }
    
    for(; tp>-1; tp--){
    	if(ans[tp][vs.size()-1] != -1) break;
    }
    
    for(int i=tp; i<mx; i++){
    	for(int j=vs.size()-1; j>ii-2; j--){
    		if(ans[i][j] != -1) break;
    		ans[i].pop_back();
    	}
    }
    
    for(int i=0; i<mx; i++) for(int j=0; j<vs.size(); j++) if(ans[i][j] == -1) ans[i][j] = ' ';
    
    for(string s: ans) cout << s << '\n';
}