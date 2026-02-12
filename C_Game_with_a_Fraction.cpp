#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long p,q; cin>>p>>q;
    if(p==1){
        cout<<"Alice\n";
    }else if(q>p && q+q<=p+p+p) cout<<"Bob\n";
    else cout<<"Alice\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}