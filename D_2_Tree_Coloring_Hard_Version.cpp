#include <bits/stdc++.h>
using namespace std;
vector<int>g[200005],dep[200005];

void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        g[i].clear();
    }  
    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

     
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}