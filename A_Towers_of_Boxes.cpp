#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,d; cin>>n>>m>>d;
    int one = d/m + 1;
    cout<<(n+one-1)/one<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}