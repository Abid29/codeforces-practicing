#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
int a[200005];
void solve() {
    int n; cin>>n; 
    for(int i=1; i<=n; i++){
        cin>>a[i]; 
    }
    a[0] = n;
    for(int i=1; i<=n; i++){
        if(a[i]>a[i-1] || n-i>a[i]){
            cout<<"0\n"; return;
        }
    }

    long long ans = 1;
    for(int i=n; i>0; i--){
        if(a[i]==a[i-1]){
            ans = (ans*(a[i]-n+i))%md;
        }else{
            ans = (ans*i)%md;
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