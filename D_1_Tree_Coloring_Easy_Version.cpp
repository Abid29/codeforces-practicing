#include <bits/stdc++.h>
using namespace std;
vector<int>g[200005];
int n_anc[200005],cnt_dep[200005];

void dfs(int u, int p, int depth){
    cnt_dep[depth]++;
    n_anc[depth+1] += (g[u].size()>1||u==1);
    for(int v : g[u]){
        if(v==p) continue;
        dfs(v,u,depth+1);
    }
}

void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        g[i].clear();
        n_anc[i] = cnt_dep[i] = 0;
    }  
    for(int i=1,u,v; i<n; i++){
        cin>>u>>v; 
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,1);
    
    int totalset=0;
    for(int depth=1; depth<=n; depth++){
        totalset = max(totalset, cnt_dep[depth]+(n_anc[depth]==1));
    }
    cout<<totalset<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
} 