#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a,b,c,m;
    cin>>a>>b>>c>>m;
    long long ab = a*b/__gcd(a,b),ac = a*c/__gcd(a,c), bc = b*c/__gcd(b,c),abc=ab*c/__gcd(ab,c);
    cout<<(m/a)*6 - (m/ab+m/ac-m/abc)*3 - m/abc<<' ';
    cout<<(m/b)*6 - (m/ab+m/bc-m/abc)*3 - m/abc<<' ';
    cout<<(m/c)*6 - (m/ac+m/bc-m/abc)*3 - m/abc<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}