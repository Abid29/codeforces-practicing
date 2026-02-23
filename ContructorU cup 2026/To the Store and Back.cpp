#include <bits/stdc++.h>
using namespace std;
int x[200005],y[200005],dp1[200005],dp2[200005];
vector<int>g[200005];
void solve() {
    int n,m,root; cin>>n>>m;
    string s;
    for(int i=1; i<=m; i++) cin>>x[i];
    for(int i=1; i<=m; i++) cin>>y[i];
    cin>>s>>root;

    for(int i=1; i<=n; i++){
        g[i].clear();
        dp1[i] = -1;
    }
    for(int i=1; i<=m; i++){
        g[x[i]].push_back(y[i]);
    }

    queue<int>q;
    q.push(root);
    dp1[root] = 0;
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v : g[u]){
            if(dp1[v]==-1) {dp1[v] = dp1[u]+1; q.push(v);}
        }
    }

    for(int i=1; i<=n; i++){
        g[i].clear();
        dp2[i] = -1;
    }
    for(int i=1; i<=m; i++){
        g[y[i]].push_back(x[i]);
    }

    while(!q.empty()) q.pop();
    q.push(root);
    dp2[root] = 0;
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v : g[u]){
            if(dp2[v]==-1) {dp2[v] = dp2[u]+1; q.push(v);}
        }
    }
    int ans = n+n;
    for(int i=1; i<=n; i++){
        if(s[i-1]=='1' && dp1[i]!=-1 && dp2[i]!=-1){
            ans = min(ans, dp1[i]+dp2[i]);
        }
    }
    if(ans>=n+n) ans = -1;
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t; cin >> t; while(t--) {
        solve();
    // }
    return 0;
}