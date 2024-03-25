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
    
    //建立二維表格
    vector<string> ans(mx);
    
    //填入表格，每個句子後的空格補-1(不包含句子中的空格)
    for(int i=0; i<mx; i++){
        for(int j=vs.size()-1; j>=0; j--){
            if(i < vs[j].size()){
                ans[i] += vs[j][i];
            }
            else ans[i] += -1;
        }
    }
    
    //尋找右上角的-1位置
    int tp = mx-1;
    for(; tp>-1; tp--){
    	if(ans[tp][vs.size()-1] != -1) break;
    }

    //從右邊刪除-1，以進行縮排
    for(int i=tp; i<mx; i++){
    	for(int j=vs.size()-1; j>0; j--){
    		if(ans[i][j] != -1) break;
    		ans[i].pop_back();
    	}
    }
    
    //從左邊刪除-1，以空格取代
    for(int i=0; i<mx; i++) for(int j=0; j<vs.size(); j++) if(ans[i][j] == -1) ans[i][j] = ' ';
    
    for(string s: ans) cout << s << '\n';
}