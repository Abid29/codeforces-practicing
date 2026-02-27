#include <bits/stdc++.h>
using namespace std;
int n,a[555]; 
void solve() {
    cin>>n; 
    for(int i=1; i<=n; i++) cin>>a[i];
    int val = a[1];
    cout<<n;
    for(int i=2; i<=n; i++){
        if(a[i]==n) cout<<' '<<val;
        else        cout<<' '<<a[i];
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}