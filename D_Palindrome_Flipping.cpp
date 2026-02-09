#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> opers(string s){
    vector<pair<int,int>>ret;
    int fone=-1,sone=-1,cur=0,n=s.size();
    while(cur<n){
        if(fone==-1){
            while(cur<n && s[cur]!='1') cur++; 
            if(cur<n) fone=cur++;
        }
        if(sone==-1){
            while(cur<n && s[cur]!='1') cur++; 
            if(cur<n) sone=cur++;
        }
        if(fone>-1 && sone>-1){
            ret.push_back({fone,sone});
            if(fone+2<sone){
                ret.push_back({fone+1,sone-1});
                fone=-1,sone=-1;
            }else if(fone+2==sone){
                fone++, sone=-1;
            }else fone=-1, sone=-1;
        }
    }
    if(fone>-1){
        if(n-1-fone> fone-1){
            ret.push_back({fone+1,n-1});
            ret.push_back({fone,n-1});
        }else{
            ret.push_back({0,fone-1});
            ret.push_back({0,fone});
        }
    }
    return ret;
}
void solve() {
    int n; string s,t;
    cin>>n>>s>>t;
    int fone=-1,sone=-1,cur=0;
    vector<pair<int,int>>f1 = opers(s);
    vector<pair<int,int>>f2 = opers(t);
    reverse(f2.begin(), f2.end());

    cout<<f1.size()+f2.size()<<endl;
    for(auto it : f1) cout<<it.first+1<<' '<<it.second+1<<'\n';
    for(auto it : f2) cout<<it.first+1<<' '<<it.second+1<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}