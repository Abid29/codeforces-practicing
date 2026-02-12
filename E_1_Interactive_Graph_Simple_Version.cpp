#include <bits/stdc++.h>
using namespace std;
set<int>g[40];
void solve() {
    int n,len,u,v; cin>>n;
    for(int i=1; i<=n; i++) g[i].clear();

    for(int i=1,k=1; i<=n; i++){
        if(g[i].empty()){
            while(1){
                cout<<"? "<<k<<endl;
                cout.flush();
                cin>>len;
                if(len==1){
                    cin>>u;
                    if(u>i) break;
                }else if(len==0){
                    i=n+1; break;
                }else{
                    u=v=-1;
                    while(len--){
                        u=v; cin>>v;
                    }
                    g[u].insert(v);
                }
                k++;
            }
        }else k += g[i].size();
    }
    int ans = 0;
    for(int i=1; i<=n; i++) ans += g[i].size();
    cout<<"! "<<ans<<endl;
    for(int i=1; i<=n; i++){
        for(int v : g[i]) cout<<i<<' '<<v<<endl;
    }
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}