#include <bits/stdc++.h>
using namespace std;
map<int, int>cnt[100005],boro[100005];
vector<int>q[100005],g[100005];
int col[100005],k[100005],ans[100005];

void dfs(int u, int p){
    cnt[u][col[u]]++, boro[u][1]++;
    for(int v : g[u]){
        if(v==p) continue;
        dfs(v,u);
        if(cnt[u].size() < cnt[v].size()){
            cnt[u].swap(cnt[v]);
            boro[u].swap(boro[v]);
        }
        for(auto it : cnt[v]){
            int ind = cnt[u][it.first];
            cnt[u][it.first] += it.second;
            for(int val=ind+1; val<=ind+it.second; val++) boro[u][val]++;
        }
    }
    for(int id : q[u]){
        ans[id] += boro[u][k[id]];
    }
}

int main() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>col[i];
        g[i].clear();
    }
    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1,u; i<=m; i++){
        cin>>u>>k[i];
        q[u].push_back(i);
    }
    dfs(1,0);
    for(int i=1; i<=m; i++) cout<<ans[i]<<endl;
}