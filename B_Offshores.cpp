#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    long long sum=0, ans=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[i] = (a[i]/x)*y;
        sum+=b[i];
    }

    for(int i=1; i<=n; i++){
        ans = max(ans, sum-b[i]+a[i]);
    }
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}