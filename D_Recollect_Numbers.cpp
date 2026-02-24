#include <bits/stdc++.h>
using namespace std;
int a[300005];
void solve() {
    int n,k; cin>>n>>k;
    if(k<n || k>=n+n){
        cout<<"NO\n"; return;
    }

    cout<<"YES\n";

    k-=n;
    int val;
    for(int i=2,j=k; j>0; j--, i++){
        cout<<i<<' '<<i-1<<' ';
    }
    cout<<"1 "<<k+1<<' ';
    for(int i=k+2; i<=n; i++) cout<<i<<' '<<i<<' ';
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