#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int mxlen[65];
vector<int>listofmxbit[65];
int dfs(int ubit){
    if(mxlen[ubit]) return mxlen[ubit];
    mxlen[ubit] = 1;
    for(int vbit = 60; vbit>ubit; vbit--){
        for(int v : listofmxbit[vbit]){
            if((a[v]>>ubit)&1) {mxlen[ubit] = max(mxlen[ubit], 1+dfs(vbit)); break;}
        }
    }
    return mxlen[ubit];
}
void solve() {
    int n; cin>>n;
    for(int bit=0; bit<=60; bit++) {listofmxbit[bit].clear(); mxlen[bit] = 0;}
    for(int i=1; i<=n; i++){
        cin>>a[i]; 
        
        for(int bit=60; bit>=0; bit--){
            if((a[i]>>bit)&1){
                listofmxbit[bit].push_back(i);
                break;
            }
        }
    }

    int ans = 1;
    for(int bit=0; bit<=60; bit++){
        if(!listofmxbit[bit].empty()) ans = max(ans, dfs(bit));
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}