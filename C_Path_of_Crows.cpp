#include <bits/stdc++.h>
using namespace std;
set<int>g[303];
int p[303],par[303];
void dfs(int u, int parent){
    par[u] = parent;
    for(int v : g[u]){
        if(v==parent) continue;
        dfs(v,u);
    }
}
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        g[i].clear(); cin>>p[i];
    }

    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }
    vector<array<int,3>>operations;
    for(int i=1; i<n; i++){
        dfs(p[i],0);

        while(par[p[i+1]]!=p[i]){
            operations.push_back({p[i+1],par[p[i+1]],par[par[p[i+1]]]});

            g[par[p[i+1]]].erase(g[par[p[i+1]]].find(p[i+1]));
            g[p[i+1]].erase(g[p[i+1]].find(par[p[i+1]]));
            g[par[par[p[i+1]]]].insert(p[i+1]);
            g[p[i+1]].insert(par[par[p[i+1]]]);
            par[p[i+1]] = par[par[p[i+1]]];
        }
    }

    cout<<operations.size()<<endl;
    for(auto it : operations){
        for(int val : it) cout<<val<<' ';
        cout<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}