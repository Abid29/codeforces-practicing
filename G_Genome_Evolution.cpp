#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,t; 
    cin>>a>>b>>t;
    if(t==1) cout<<a<<endl;
    else if(t==2) cout<<b<<endl;
    else cout<<(a&b)<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}