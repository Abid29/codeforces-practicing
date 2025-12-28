#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,m; 
    cin>>n>>m;
    vector<pair<int,int>>vec(n),ans;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        vec[i-1] = {x,i}; 
    }
    sort(vec.begin(),vec.end());

    if(m+m>n){cout<<"-1\n"; return;}
    if(!m){
        long long int val = vec[n-1].first;
        for(int i=0; i<n-1; i++) val -= vec[i].first;
        if(val>0){
            cout<<"-1\n"; return;
        }
        int l=0, health = vec[n-1].first;
        while(vec[l].first < health){
            ans.push_back({vec[l].second, vec[n-1].second});
            health -=  vec[l].first;
            l++;
        }
        for(; l<n-1; l++){
            ans.push_back({vec[l].second, vec[l+1].second});
        }
    }else{
        int extra = n-m-m+2;
        for(int i=1; i<extra; i++){
            ans.push_back({vec[i].second, vec[i-1].second});
        }
        for(int i=extra+1; i<n; i+=2){
            ans.push_back({vec[i].second, vec[i-1].second});
        }
    }
     

    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it.first<<' '<<it.second<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}