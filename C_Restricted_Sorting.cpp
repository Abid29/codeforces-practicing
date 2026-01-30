#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
void solve() {
    int n; cin>>n;
    for(int i=1;  i<=n; i++){
        cin>>a[i]; b[i] = a[i];
    }
    sort(b+1,b+n+1);

    int k=1e9;
    for(int i=1; i<=n; i++){
        if(a[i]!=b[i]) k = min(k, max(b[n]-a[i], a[i]-b[1]));
    }
    if(k==1e9) k=-1;
    cout<<k<<endl;
} 

int main() { 
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}