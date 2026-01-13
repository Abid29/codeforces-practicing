#include <bits/stdc++.h>
using namespace std;
vector<int>tree[200005],val[200005];
void cal(int u, int p){
    set<int>st,newst;
    
    for(int v : tree[u]){
        if(v==p) continue;
        cal(v,u);
        for(int it : val[v]){
            if(!st.empty()){
                for(int ele : st) newst.insert((ele+it)%3);
            }else{
                newst.insert(it);
            }
        }
        st = newst;
        newst.clear();
    }
    st.insert(1);
    for(int ele : st) val[u].push_back(ele);
}
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        tree[i].clear(), val[i].clear();
    }

    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cal(1,0);
    if(!val[1][0]) cout<<"YES\n";
    else           cout<<"NO\n";
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}