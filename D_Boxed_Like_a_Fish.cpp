#include <bits/stdc++.h>
using namespace std;
vector<int>g[500005];
int dist[500005],k,root,n;
void dfs(int u, int p){
    if(g[u].size()==1){dist[u] = 0; return;}
    vector<int>ndists;
    for(int v : g[u]){
        if(v==p) continue;
        dfs(v,u);
        ndists.push_back(dist[v]);
    }

    if(ndists.size()==1){
        dist[u] = ndists[0]+1;
        return;
    }
    
    sort(ndists.begin(),ndists.end());
    if(ndists[0]+ndists[1]+2 <= k+1) dist[u] = 0;
    else                           dist[u] = ndists[0]+1;
}
void solve() {
    cin>>n>>k>>root;
    for(int i=1; i<=n; i++){
        g[i].clear();
        dist[i] = k+1;
    }
    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(root,0);
    if(dist[root]) cout<<"NO\n";
    else           cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}