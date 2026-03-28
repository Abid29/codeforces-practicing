#include <bits/stdc++.h>
using namespace std;
vector<int>g[200005];
int cnt[2],ind,vis[200005];
void dfs(int u){
    cnt[vis[u]]++;
    for(int v : g[u]){
        if(vis[v]==-1){
            vis[v] = vis[u]^1;
            dfs(v);
        }else if(vis[v]==vis[u]) ind=1;
    }
}
void solve() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++){
        g[i].clear();
        vis[i]=-1;
    }
    for(int i=0,u,v; i<m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]==-1){
            vis[i] = 0;
            cnt[0]=cnt[1]=ind=0;
            dfs(i);
            if(!ind) ans += max(cnt[0],cnt[1]);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}