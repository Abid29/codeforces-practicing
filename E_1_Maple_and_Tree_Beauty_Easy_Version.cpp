#include <bits/stdc++.h>
using namespace std;
int cnt[1005],mndep,dp[1005];
vector<int>g[1005];
void dfs(int u, int p, int dep){
    cnt[dep]++;
    if(g[u].empty()) mndep = min(mndep, dep);
    for(int v : g[u]) dfs(v,u,dep+1);
}
void solve() {
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        cnt[i]=0; g[i].clear();
        dp[i] = 0;
    }
    for(int i=2,p; i<=n; i++){
        cin>>p;
        g[p].push_back(i);
    }
    
    mndep=n;
    dfs(1,0,1);
    dp[0] = 1;
    int sum = 0;
    for(int i=1; i<=mndep; i++){
        sum += cnt[i];
        for(int j=k; j>=cnt[i]; j--) dp[j] |= dp[j-cnt[i]];
    }

    n-=k;
    while(!dp[k]) k--;

    if(sum-k <= n) cout<<mndep<<endl;
    else           cout<<mndep-1<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}