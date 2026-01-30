#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    int l=1;
    vector<int>ans;
    while(l<n){
        ans.push_back(l++);
        ans.push_back(n--);
    }
    if(l==n) ans.push_back(l);
    reverse(ans.begin(),ans.end());
    for(int x : ans) cout<<x<<' ';
    cout<<'\n';
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}