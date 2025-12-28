#include <bits/stdc++.h>
using namespace std;
long long a[200005],suf[200005];
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    suf[n+1] = 0;
    for(int i=n; i>1; i--){
        suf[i] = suf[i+1]-a[i];
    }

    long long ans = suf[2], cur = 0, val=a[1];
    for(int i=2; i<=n; i++){
        ans = max(ans, cur+val+suf[i+1]);
        if(a[i] < 0){
            cur -= a[i];
        }else{
            cur += val;
            val = a[i];
        }
    }

    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}