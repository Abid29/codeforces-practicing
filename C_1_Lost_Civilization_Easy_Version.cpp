#include <bits/stdc++.h>
using namespace std;
int a[300005];
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    int mn=a[1],cur=a[1],ans=n;
    for(int i=2;  i<=n; i++){
        if(a[i]>mn && a[i]<=cur+1){
            cur = a[i]; ans--;
        }else{
            mn = cur = a[i];
        }
    }
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