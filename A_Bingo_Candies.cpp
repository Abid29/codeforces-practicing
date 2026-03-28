#include <bits/stdc++.h>
using namespace std;
int cnt[10005];
void solve() {
    int n; cin>>n;
    for(int i=0; i<n*n; i++){
        cnt[i+1]=0;
    }
    for(int i=0,col; i<n*n; i++){
        cin>>col; cnt[col]++;
    }
    int mx = 0;
    for(int i=0; i<n*n; i++){
        mx = max(mx, cnt[i+1]);
    }

    if(mx <= n*(n-1)) cout<<"YES\n";
    else              cout<<"NO\n"; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}