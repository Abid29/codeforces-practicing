#include <bits/stdc++.h>
using namespace std;
vector<int> tree[200005],components;
int sz[200005];
long long md=998244353;
void components_Cal(int u, int p){
    sz[u] = 1;
    for(int v : tree[u]){
        if(v==p) continue;
        components_Cal(v,u);
        sz[u] += sz[v];
    }
    if(sz[u]%2==0 && u!=1) components.push_back(sz[u]),sz[u] = 0;
}
long long pw(long long a, int b){
    long long ret = 1;
    while(b){
        if(b&1) ret = (ret*a)%md;
        b/=2, a = (a*a)%md;
    }
    return ret;
}
void solve() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) tree[i].clear();

    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    components.clear();
    components_Cal(1,0);

    long long nMinusOneFact=1;
    for(int i=2,m=components.size(); i<m; i++){
        nMinusOneFact = (nMinusOneFact*i)%md;
    }

    long long squaredMultiple=n;
    for(int x : components) squaredMultiple -= x;
    for(long long x : components){
        squaredMultiple = (squaredMultiple*x%md*x)%md;
    }

    long long ans = components.empty();
    for(long long x : components){
        ans = (ans + squaredMultiple * pw(x,md-2) % md * nMinusOneFact)%md;
    }
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}