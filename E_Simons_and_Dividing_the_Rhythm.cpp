#include <bits/stdc++.h>
using namespace std;
const int md = 998244353;
long long dp[8005], a[8005];
int prefix[8005][8005];

void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<n; i++){
        for(int j=i+1,len=0; j<=n; j++){
            while(len>0 && a[i+len]!=a[j]){
                len = prefix[i][i+len-1]; 
            }
            if(a[i+len]==a[j]) len++;
            prefix[i][j] = len;
        }
    }

    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1];
        for(int j=i-1; j>0; j--){
            if(!prefix[j][i]) dp[i] = (dp[i]+dp[j-1])%md;
        }
    }

    cout<<dp[n]<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}