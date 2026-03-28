#include <bits/stdc++.h>
using namespace std;

void query(int k){
    cout<<"? "<<k<<endl;
    cout.flush();
}

void solve() {
    int n; cin>>n;
    vector<int>cnt(n+1),path(n);
    vector<array<int,2>>edges;

    int pathNumber = 1, q, firstNumber=0;
    query(pathNumber);
    cin>>q;
    while(q){
        for(int i=0; i<q; i++){
            cin>>path[i];
        }
        if(q==1) {pathNumber++; 
            query(pathNumber);
            cin>>q;
            continue;}
        if(firstNumber!=path[0] && cnt[path[0]]){
            pathNumber += cnt[path[0]];
            firstNumber = path[0];
            
            query(pathNumber);
            cin>>q;
            continue;
        }
        firstNumber = path[0];
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
        cin>>q;
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