#include <bits/stdc++.h>
using namespace std;
int p[200005],id[200005];
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i]; id[p[i]] = i;
    }
    
    int idx = n+1,mx=0;
    vector<pair<int,int>>g;
    for(int i=1; i<=n; i++){
        if(idx > id[i]){
            if(i>1){
                if(mx > i) g.push_back({i,mx});
                else{cout<<"No\n"; return;}
            }
            idx--;
            while(idx>id[i]) g.push_back({i, p[idx]}), mx = max(mx, p[idx--]);
        }
    }
    cout<<"Yes\n";
    for(auto it : g) cout<<it.first<<' '<<it.second<<'\n';
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}