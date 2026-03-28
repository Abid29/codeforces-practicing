#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin>>n>>s;
    int i=1;
    while(s[i]=='R') i++;
    cout<<i+1<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}