#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,w;
    cin>>n>>w;
    if(w==1){
        cout<<"0\n"; return;
    }
    cout<<n-((n+w)/w - 1)<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}