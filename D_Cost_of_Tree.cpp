#include <bits/stdc++.h>
using namespace std;
long long a[200005],h[200005],wsum[200005],sum[200005],ans[200005],n;
vector<int>g[200005];
void dfs(int u, int p){
    h[u] = 1;
    sum[u] = a[u];
    wsum[u] = 0;
    int m = g[u].size(),v;
    vector<long long int>hvec(m,0),ph(m);
    for(int i=0; i<m; i++){
        v=g[u][i];
        if(i>0) ph[i] = ph[i-1];
        if(v==p) continue;
        dfs(v,u);
        h[u] = max(h[u],h[v]+1);
        sum[u] += sum[v];
        wsum[u] += sum[v] + wsum[v];
        hvec[i] = h[v];
        if(i>0) ph[i] = max(ph[i-1],h[v]);
        else    ph[i] = h[v];
    }
    
    for(int i=m-2; i>=0; i--){
        hvec[i] = max(hvec[i], hvec[i+1]);
    }
    ans[u] = wsum[u];

    for(int i=0; i<m; i++){
        v = g[u][i];
        if(v==p) continue;

        long long height = 0;
        if(i>0) height = max(height, ph[i-1]);
        if(i<m-1) height = max(height,hvec[i+1]);

        ans[u] = max(ans[u], wsum[u]+height*sum[v]);
        ans[u] = max(ans[u], wsum[u]-wsum[v]+ans[v]);
    }

}
void solve() {
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        g[i].clear();
    }
    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);

    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}