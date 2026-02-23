#include <bits/stdc++.h>
using namespace std;
int sum[5005];
int f(int l, int r){
    if(l>r) return 0;
    int val = sum[r]-sum[l-1];
    return max(val, r-l+1-val);
}
void solve() {
    int n; cin>>n;
    string s; cin>>s;
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + (s[i-1]=='1');
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            ans = max(ans, f(i,n)+f(j,i-1)+f(1,j-1));
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