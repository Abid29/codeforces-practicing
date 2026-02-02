#include <bits/stdc++.h>
using namespace std;
int nxt[200005],sz[200005];
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=2; i<=n; i++){
        nxt[i-1] = i, sz[i-1]=0;
    }

    for(int i=1,u,v; i<=m; i++){
        cin>>u>>v;
        nxt[u] = max(nxt[u], v);
    }

    long long ans = 0;
    vector<vector<pair<long long, long long>>>sbtr(n+1);
    for(int i=1; i<n; i++){
        sz[i]++;
        int p = nxt[i];
        sbtr[i].push_back({int64_t(1),int64_t(sz[i])});
        sz[p] += sz[i];

        if(sbtr[i].size() > sbtr[p].size()) swap(sbtr[i], sbtr[p]);
        
        for(int depth=1;  depth<=sbtr[i].size(); depth++){
            auto& a = sbtr[p].end()[-depth];
            auto& b = sbtr[i].end()[-depth];

            ans += (a.first * b.second * depth) + (a.second * b.first * depth);

            a.first += b.first, a.second += b.second;
        }

        sbtr[i] = {};
    }
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}