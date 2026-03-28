#include <bits/stdc++.h>
using namespace std;
int a[101];
void solve() {
    long long int n,c,k; cin>>n>>c>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0; i<n; i++){
        if(a[i]>c) break;
        int val = min(c-a[i],k);
        c += a[i]+val,k-=val;
    }
    cout<<c<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}