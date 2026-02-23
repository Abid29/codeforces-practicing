#include <bits/stdc++.h>
using namespace std;
long long n,f[300005], g[300005], ans[300005];
void solve() {
    cin>>n;
    for(int i=1; i<=n; i++) cin>>f[i];
    for(int i=1; i<n; i++) g[i] = f[i] - f[i+1];

    for(int i=2; i<n; i++){
        ans[i] = (g[i-1]-g[i])/2;
    }

    ans[n] = g[1] + ans[1];
    for(int i=2; i<n-1; i++) ans[n] -= ans[i];

    long long a=f[1], b=f[n];
    for(int i=2; i<n; i++) a -= ans[i]*(i-1);
    for(int i=n-1; i>1; i--) b -= ans[i]*(n-i);
    
    ans[n] = a/(n-1);
    ans[1] = b/(n-1);

    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
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