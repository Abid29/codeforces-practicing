#include <bits/stdc++.h>
using namespace std;
long long int a[300005],nxt[300005],ans[300005];
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    
    nxt[n] = n+1;
    ans[n+1] = 0;
    a[n+1] = 0;
    long long tot=0;
    for(int i=n; i>0; i--){
        if(a[i]+1==a[i+1]){
            int id=i+1;
            while(a[id] == a[i]+1) id= nxt[id];

            nxt[i] = id;
            ans[i] = n-i+1+ans[id];
        }else{
            nxt[i] = i+1;
            ans[i] = n-i+1+ans[i+1];
        }
        tot+= ans[i];

        // cout<<i<<' '<<nxt[i]<<' '<<ans[i]<<endl;
    }

    cout<<tot<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
} 