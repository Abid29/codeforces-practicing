#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
set<int>g[1000005];
vector<int>ans;
void dfs(int u){
    if(g[u].empty()) return;
    int i = *g[u].begin();
    g[u].erase(g[u].begin());
    if(a[i]!=u){
        ans.push_back(i);
        g[a[i]].erase(g[a[i]].find(i));
    }else{
        g[b[i]].erase(g[b[i]].find(i));
    }
    
    dfs(b[i]+a[i]-u);
}
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        g[i].clear();
    }
    for(int i=1; i<=n; i++){
        cin>>b[i];
        if(a[i]==b[i]) continue;
        g[a[i]].insert(i);
        g[b[i]].insert(i);
    }

    for(int i=1; i<=n; i++) if(g[i].size()&1){
        cout<<"-1\n"; return;
    }

    ans.clear();
    for(int i=1; i<=n; i++){
        dfs(a[i]);
    }

    cout<<ans.size()<<'\n';
    for(int x : ans) cout<<x<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}