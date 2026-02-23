#include <bits/stdc++.h>
using namespace std;
long long n,h,k,a[200005],mx[200005];
void solve() {
    cin>>n>>h>>k;
    long long sum = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i]; sum+= a[i];
    }
    long long int cnt = h/sum, val = h - sum*cnt;
    long long ans = (cnt+(val>0)-1) * k + n*cnt;
    
    if(!val){
        cout<<ans<<endl; return;
    }

    long long int mn = 1e9,tot=0;
    mx[n+1] = 0;
    for(int i=n; i>0; i--) mx[i] = max(mx[i+1], a[i]); 
        
    tot=0;
    for(int i=1; i<=n; i++){
        mn = min(mn, a[i]);
        tot += a[i];

        if(tot-mn+mx[i+1] >= val || tot>=val){
            cout<<ans+i<<endl; return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}