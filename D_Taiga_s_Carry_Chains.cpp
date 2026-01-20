#include <bits/stdc++.h>
using namespace std;
int bitsum[32];
void solve() {
    int n,k; cin>>n>>k;
    int sumofgaps = 0, lastone=-1;
    for(int i=0; i<30; i++){
        if(i) bitsum[i] = bitsum[i-1];
        else  bitsum[i] = 0;
        if(n&(1<<i)){
            bitsum[i]++;
            if(lastone==-1) lastone = i;
            else            sumofgaps += i-lastone-1, lastone=i;
        }
    }

    if(sumofgaps < k){
        cout<<k+bitsum[29]-1<<endl; return;
    }
    
    vector<vector<int>>dp(30,  vector<int>(30));
    int ans = 0;
    for(int i=0; i<30; i++){
        if(i) for(int j=0; j<30; j++) dp[i][j] = dp[i-1][j];
        for(int j=i,len=1; j>=0; j--,len++){
            int ones = bitsum[i] - (j>0 ? bitsum[j-1]:0);
            int ops = len - ones + 1;
            for(int ex=0; ex+ops<=k; ex++){
                if(j) dp[i][ops+ex] = max(dp[i][ops+ex], len+dp[j-1][ex]);
                else  dp[i][ops] = max(dp[i][ops], len);
            }
        }
        ans = max(ans, dp[i][k]);
    }

    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
} 