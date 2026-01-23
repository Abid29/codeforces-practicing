#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    if(n&1){
        cout<<n-1;
        for(int i=2; i<n-2; i+=2){
            cout<<' '<<i+1<<' '<<i;
        }
        cout<<' '<<n<<" 1\n";
        return;
    }
    cout<<n;
    for(int i=2; i<=n-2; i+=2){
        cout<<' '<<i+1<<' '<<i;
    }
    cout<<" 1\n";
    return;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}