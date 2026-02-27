#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<vector<int>>l(n);
    for(int i=0; i<n; i++){
        int m; cin>>m;
        l[i].resize(m);
        for(int j=0; j<m; j++){
            cin>>l[i][j];
        }
    }

    map<int,int>mp;
    vector<int>ans;
    vector<pair<int,int>>vec,nvec;
    while(1){
        vec.clear();
        for(int i=0; i<n; i++){
            while(l[i].empty()==0 && mp[l[i].back()]==-1) l[i].pop_back();
            if(l[i].empty()==0) vec.push_back({l[i].back(),i});
        }
        if(vec.empty()) break;

        while(vec.empty()==0){
            sort(vec.begin(),vec.end());

            while(vec[0].first != vec.back().first) vec.pop_back();
            mp[vec[0].first] = -1;
            ans.push_back(vec[0].first);

            int ind=0;
            for(auto it : vec){
                while(l[it.second].empty()==0 && mp[l[it.second].back()]==-1) l[it.second].pop_back();
                if(l[it.second].empty()) ind=1;
            }
            if(ind) break;
            
            nvec.clear();
            for(auto it : vec){
                if(l[it.second].empty()==0) nvec.push_back({l[it.second].back(),it.second});
            }
            vec = nvec;
        }
    }
    for(int x : ans) cout<<x<<' ';
    cout<<'\n'; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}