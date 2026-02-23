#include <bits/stdc++.h>
using namespace std;
long long ans[300005],toit[300005],l[300005],r[300005],md=1000000007;
void dfs1(int u){
    if(l[u]){
        dfs1(l[u]);
        toit[u] += 2+toit[l[u]];
    }
    if(r[u]){
        dfs1(r[u]);
        toit[u] += 2+toit[r[u]];
    }
    toit[u] %= md;
}

void dfs2(int u, int par=0){
    ans[u] = (toit[u]+1+ans[par])%md;
    if(l[u]){
        dfs2(l[u],u);
    }
    if(r[u]){
        dfs2(r[u],u);
    }
}

void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>l[i]>>r[i];
        toit[i] = ans[i] = 0;
    }

    dfs1(1);
    dfs2(1);
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