#include <bits/stdc++.h>
using namespace std;
int a[100005], minpos[365], dp[365][365];
void solve() {
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=0; i<=k+1; i++) minpos[i] = n+1;

    for(int i=n; i>0; i--){
        minpos[a[i]] = i;
    }

    for(int i=k; i>=0; i--){
        minpos[i] = min(minpos[i], minpos[i+1]);
    }
    
    for(int i=0; i<=k+1; i++){ 
        for(int j=0; j<=k+1; j++){
            dp[i][j] = -1;
        }
    }
    dp[k+1][k] = 0;

    int ans = 0;
    for(int i=k+1; i>0; i--){
        for(int j=k; j>=0; j--){
            if(dp[i][j]==-1) continue;
            for(int val=j; val>0; val--){
                if(minpos[val] >= minpos[i]) continue;
                if(dp[val][j-val]==-1) dp[val][j-val] = dp[i][j] + (minpos[i]-minpos[val])*val;
                else dp[val][j-val] = max(dp[val][j-val], dp[i][j] + (minpos[i]-minpos[val])*val);

            }
        }
    }
    for(int i=0; i<=k+1; i++) for(int j=0; j<=k+1; j++) ans = max(ans, dp[i][j]);

    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}