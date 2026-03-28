#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8005;
vector<int>g[8005];
bool vis[8005];
bool isTree(int u, int p){
    if(vis[u]) return false;
    vis[u]=true;
    bool ret = true;
    for(int v : g[u]){
        if(v==p) continue;
        ret &= isTree(v,u);
    }
    return ret;
}
void solve() {
    unsigned int n; cin>>n;
    vector<bitset<MAXN>>adj(n);
    vector<pair<int,int>>vp;
    vector<pair<int,int>>edges;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<n; j++) if(s[j]=='1') adj[i].set(j); 
        vp.push_back({adj[i].count(),i});
    }
    
    sort(vp.begin(),vp.end());
    bitset<MAXN>carry;
    for(int i=0,u; i<n; i++){
        u = vp[i].second;
        carry.reset();
        carry.set(u);
        for(int j=i-1,v; j>=0; j--){
            v = vp[j].second;
            if(adj[u].test(v) && !carry.test(v)){
                edges.push_back({u,v});
                carry |= adj[v];
            }
        }
        if((carry^adj[u]).count()){
            cout<<"No\n"; return;
        }
    }
    for(int i=0; i<n; i++){
        g[i].clear();
        vis[i]=false;
    }
    for(auto it : edges){
        g[it.first].push_back(it.second);
        g[it.second].push_back(it.first);
    }
    if(!isTree(0,-1)){
        cout<<"No\n"; return;
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            cout<<"No\n"; return;
        }
    }
    cout<<"Yes\n";
    for(auto &it : edges){
        cout<<it.first+1<<' '<<it.second+1<<'\n';
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