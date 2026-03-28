#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int>inc;
    for(int i=0,a; i<n; i++){
        cin>>a;
        if(inc.empty() || inc.back()<=a) inc.push_back(a);
    }
    cout<<inc.size()<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}