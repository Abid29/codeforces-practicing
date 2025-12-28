#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin>>s;
    int cnt = 0;
    for(char ch : s) cnt+= (ch=='Y');

    if(cnt<2) cout<<"YES\n";
    else      cout<<"NO\n";
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}