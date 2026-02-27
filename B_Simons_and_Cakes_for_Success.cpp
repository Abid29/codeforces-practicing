#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    int root = sqrt(n+1), val=1;

    for(int i=2; i<=root; i++){
        if(n%i==0){
            val *=i, n/=i;
            while(n%i==0) n/=i;
        }
    }
    val *= n;

    cout<<val<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}