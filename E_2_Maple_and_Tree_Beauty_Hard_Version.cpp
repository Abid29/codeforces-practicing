#include <bits/stdc++.h>
using namespace std;
int cnt[200005],mndep,dp[200005],ndp[200005];
vector<int>g[200005];
void dfs(int u, int p, int dep){
    cnt[dep]++;
    if(g[u].empty()) mndep = min(mndep, dep);
    for(int v : g[u]) dfs(v,u,dep+1);
}
void solve() {
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        cnt[i]=0; g[i].clear();
        dp[i] = ndp[i] = 0;
    }
    for(int i=2,p; i<=n; i++){
        cin>>p;
        g[p].push_back(i);
    }
    
    mndep=n;
    dfs(1,0,1);
    unordered_map<int,int>ump;
    int sum = 0;
    for(int i=1; i<=mndep; i++){
        sum += cnt[i];
        ump[cnt[i]]++;
    }

    dp[0] = 1;
    for(const auto& it : ump){
        int w = it.first, f = it.second;
        for(int rem=0; rem<w; rem++){
            int ways=0;
            for(int val=rem; val+w<=k; val+=w){
                ways += dp[val];
                if(f*w<=val) ways -= dp[val-f*w];

                ndp[val+w] |= (ways>0);
            }
        }
        for(int val=1; val<=k; val++) dp[val] |= ndp[val];
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