#include <bits/stdc++.h>
using namespace std;
int a[300005],n,ans;

void f(int k){
    int x,y,mx=-1,mxid,mxdif=0;
    for(int i=1; i<=n; i++){
        if(!a[i]) continue;
        if(mx < a[i]) mx = a[i], mxid = i;
        if(mxdif < mx-a[i]){
            mxdif = mx-a[i];
            x = mxid, y=i;
        }
    }
    if(!k||!mxdif){
        ans = min(ans, mxdif); return;
    }

    int val = a[x];
    a[x] = 0;
    f(k-1);
    a[x] = val;
    val = a[y];
    a[y] = 0;
    f(k-1);
    a[y] = val;
}

void solve() {
    int k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    ans = 1e9;
    
    f(k);
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}