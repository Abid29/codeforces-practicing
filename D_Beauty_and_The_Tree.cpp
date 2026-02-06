#include <bits/stdc++.h>
using namespace std;
int b[100005],n,dsum[100005], scdsum[100005], pcdsum[100005],depth[100005],ans[100005];
vector<int>g[100005];
vector<int>totneg[100005];
multiset<int>mxval[100005];
void dfs1(int u, int p, int dep){
    depth[u] = dep;
    dsum[dep] += b[u];
    for(int v : g[u]){
        dfs1(v,u,dep+1);
    }
}
void dfs2(int u, int p){
    if(g[u].empty()){
        totneg[u].push_back(b[u]);
        mxval[u].insert(dsum[depth[u]]-b[u]);
        ans[u] = max(dsum[depth[u]]-b[u], max(pcdsum[depth[u]-1], scdsum[depth[u]+1]));
        return;
    }
    int bigchild = -1, big = -1;
    for(int v : g[u]){
        dfs2(v,u);
        if(big < (int)totneg[v].size()) big = totneg[v].size(), bigchild = v;
    }
    mxval[u].swap(mxval[bigchild]);
    totneg[u].swap(totneg[bigchild]);
    vector<int>cur;
    int sz=0;

    for(int v : g[u]){
        if(v==bigchild) continue;
        for(int i=totneg[v].size()-1,j=0; i>=0; i--,j++){
            if(sz==j) cur.push_back(totneg[v][i]),sz++;
            else      cur[j] += totneg[v][i];
        }
        totneg[v].clear();
        mxval[v].clear();     
    }
    for(int i=totneg[u].size()-1,j=0,m=cur.size(); j<m; j++,i--){
        mxval[u].erase(mxval[u].find(dsum[depth[u]+j+1]-totneg[u][i]));
        totneg[u][i] += cur[j];
        mxval[u].insert(dsum[depth[u]+j+1]-totneg[u][i]);
    }
    totneg[u].push_back(b[u]);
    mxval[u].insert(dsum[depth[u]]-b[u]);

    ans[u] = max(*mxval[u].rbegin(),max(pcdsum[depth[u]-1], scdsum[depth[u]+totneg[u].size()]));
}
void solve() {
    cin>>n;
    for(int i=1; i<=n; i++){
        dsum[i] = 0;
        totneg[i].clear(), g[i].clear(), mxval[i].clear();
        cin>>b[i];
    }

    for(int i=2,p; i<=n; i++){
        cin>>p; g[p].push_back(i);
    }

    dfs1(1,0,1);
    for(int i=1; i<=n; i++) pcdsum[i] = max(dsum[i], pcdsum[i-1]);
    scdsum[n+1] = 0;
    for(int i=n; i>0; i--) scdsum[i] = max(scdsum[i+1], dsum[i]); 

    dfs2(1,0);

    for(int i=2; i<=n; i++) cout<<ans[i]<<'\n';
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
} 