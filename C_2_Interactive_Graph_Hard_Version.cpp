#include <bits/stdc++.h>
using namespace std;
int q,cnt[31],path[31];
void query(int k){
    cout<<"? "<<k<<endl;
    cout.flush();
    cin>>q;
    for(int i=0; i<q; i++) cin>>path[i];
}

void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++) cnt[i] = 0;
    vector<array<int,2>>edges;

    int pathNumber = 1;
    q = 1, path[0] = 1;
    while(q){
        if(q==1) {
            pathNumber += cnt[path[0]]+1;
            
            query(pathNumber);
            continue;
        }
        pathNumber++;
        for(int i=0; i<q-1; i++) cnt[path[i]]++;
        edges.push_back({path[q-2],path[q-1]});

        if(cnt[path[q-1]]){
            pathNumber += cnt[path[q-1]];
            for(int i=0; i<q-1; i++){
                cnt[path[i]] += cnt[path[q-1]];
            }
        }
        
        query(pathNumber);
    }
    cout<<"! "<<edges.size()<<endl;
    cout.flush();
    for(const auto & edge : edges){ cout<<edge[0]<<' '<<edge[1]<<endl; cout.flush();}
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