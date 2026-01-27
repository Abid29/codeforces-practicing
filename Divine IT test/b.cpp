#include <bits/stdc++.h>
using namespace std;
int n,m,ids[404];
queue<int>nt[404];
void solve() {
    cin>>n>>m;
    for(int i=1; i<=400; i++){
        while(!nt[i].empty()) nt[i].pop();
    }
    for(int i=1; i<=m; i++){
        cin>>ids[i];
        nt[ids[i]].push(i);
    }
    for(int i=1; i<=m; i++){
        nt[ids[i]].push(m+1);
    }
    set<pair<int,int>>st;

    int ans = 0;
    for(int i=1; i<=m; i++){
        if(st.find({i,ids[i]})!=st.end()){
            st.erase(st.find({nt[ids[i]].front(),ids[i]}));
            nt[ids[i]].pop();
            st.insert({nt[ids[i]].front(),ids[i]});
            continue;
        }
        if(st.size()<n){
            nt[ids[i]].pop();
            st.insert({nt[ids[i]].front(),ids[i]});
            ans++;
        }else{
            st.erase(prev(st.end()));
            nt[ids[i]].pop();
            st.insert({nt[ids[i]].front(),ids[i]});
            ans++;
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