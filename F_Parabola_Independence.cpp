#include <bits/stdc++.h>
using namespace std;
int a[3003],b[3003],c[3003],dpf[3003],dpb[3003],indeg[3003];
vector<int>g[3003];
void solve() {
    int n; 
    cin>>n;
    for(int i=1; i<=n; i++){
        indeg[i]  = 0;
        dpf[i] = dpb[i] = 1;
        g[i].clear();
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(i==j) continue;
            long long int aa = a[j] - a[i];
            long long int bb = b[j] - b[i];
            long long int cc = c[j] - c[i];
            if(!aa && !bb){
                if(cc<0) g[j].push_back(i),indeg[i]++;
                else     g[i].push_back(j),indeg[j]++;
                continue;
            }
            if(bb*bb >= aa*cc*4) continue;

            if(aa > 0)    g[i].push_back(j),indeg[j]++;
            else if(aa<0) g[j].push_back(i),indeg[i]++;
        }
    }

    queue<int>q;
    for(int i=1; i<=n; i++){
        if(!indeg[i]) {q.push(i);}
    }

    vector<int>nodes;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v : g[u]){
            dpf[v] = max(dpf[v],dpf[u]+1);
            indeg[v]--;
            if(!indeg[v]) q.push(v);
        }
        nodes.push_back(u);
    }

    for(int i=nodes.size()-2; i>=0; i--){
        int u = nodes[i];
        for(int v : g[u]){
            dpb[u] = max(dpb[u], dpb[v]+1);
        }
    }

    for(int i=1; i<=n; i++) cout<<dpf[i]+dpb[i]-1<<' ';
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