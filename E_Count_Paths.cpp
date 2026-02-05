#include <bits/stdc++.h>
using namespace std;
long long n, c[200005], ans;
vector<int>g[200005];
map<int,long long>cnt[200005];
void dfs(int u, int p){
    cnt[u][c[u]]=1;
    for(int v : g[u]){
        if(v==p) continue;
        dfs(v,u);

        if(cnt[v].size() > cnt[u].size()) cnt[u].swap(cnt[v]);
        for(auto it : cnt[v]){
            ans += it.second * cnt[u][it.first];
            cnt[u][it.first]+=it.second;
        }
        cnt[v].clear();
        cnt[u][c[u]] = 1;
    }
}
void solve() {
    cin>>n;
    for(int i=1; i<=n; i++){
        g[i].clear(),cnt[i].clear();
        cin>>c[i];
    }

    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans = 0;
    dfs(1,0);
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}