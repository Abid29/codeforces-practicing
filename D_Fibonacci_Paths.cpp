#include <bits/stdc++.h>
using namespace std;
const int md = 998244353;
set<pair<long long,int>>g[200005];
map<pair<int,long long>,long long>w;
set<pair<long long,int>>curSet;
long long a[200005];
void solve() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i]; 
        g[i].clear();
    }
    curSet.clear(),w.clear();
    long long ans = 0;
    for(int i=1,u,v; i<=m; i++){
        cin>>u>>v;
        g[u].insert({a[v],v});
        w[{v,a[u]+a[v]}]++;
        if(curSet.find({a[u]+a[v],v}) == curSet.end()) curSet.insert({a[u]+a[v],v});
        
        ans++;
    }
    
    while(!curSet.empty()){
        long long val = (*curSet.begin()).first, newval;
        int u = (*curSet.begin()).second,v;
        curSet.erase(curSet.begin());
        long long cnt = w[{u,val}];

        auto it = g[u].lower_bound({val,0});
        while(it!=g[u].end() &&  it->first==val){
            ans = (ans+cnt)%md;
            int v = it->second;
            newval = val + a[u];
            w[{v,newval}] += cnt;
            w[{v,newval}]%=md;
            curSet.insert({newval,v});
            ++it;
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}