#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8005;
vector<int>g[8005];
bool vis[8005];
string s[MAXN];
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
    int n; cin>>n;
    vector<vector<int>>reach(n);
    vector<pair<int,int>>vp;
    vector<pair<int,int>>edges;
    for(int i=0; i<n; i++){
        cin>>s[i];
        for(int j=0; j<n; j++) if(s[i][j]=='1') reach[i].push_back(j); 
        vp.push_back({reach[i].size(),i});
    }
    
    sort(vp.begin(),vp.end()); 
    bitset<MAXN>carry;
    for(int i=0,u; i<n; i++){
        u = vp[i].second;
        carry.reset();
        carry.set(u);
        for(int j=i-1,v; j>=0; j--){
            v = vp[j].second;
            if(s[u][v]=='1' && !carry.test(v)){
                edges.push_back({u,v});
                for(int w : reach[v]){
                    carry.set(w);
                }
            }
        }
        for(int j=0;  j<n; j++){
            if((s[u][j]=='1') != carry.test(j)){
                cout<<"No\n"; return;
            }
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