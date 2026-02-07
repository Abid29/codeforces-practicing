#include <bits/stdc++.h>
using namespace std;
long long md = 998244353, dp[5005][5005][2],cnt[5005];
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cnt[i]= 0;
        for(int j=0; j<=n; j++) dp[i][j][0] = dp[i][j][1] = 0;
    }
    for(int i=1,x; i<=n; i++){cin>>x; cnt[x]++;}
    vector<int>vcnt = {0};
    for(int i=1; i<=n; i++) if(cnt[i]) vcnt.push_back(cnt[i]);
    sort(vcnt.begin(),vcnt.end());
    int m = vcnt.size(), mx = vcnt.back();
       
    dp[0][0][0] = 1;
    long long ans=0,sum=0,id;
    for(id=1; vcnt[id]<mx; id++){
        for(int val=0; val<=sum; val++){
            dp[id][val+vcnt[id]][0] = (dp[id][val+vcnt[id]][0]+dp[id-1][val][0]*vcnt[id])%md;
            dp[id][val][0] = (dp[id][val][0] + dp[id-1][val][0])%md;
        }
        sum+=vcnt[id];
    }
    if(id>1){
        for(int val=mx; val<=sum; val++) ans = (ans+dp[id-1][val][0])%md;
    }
    for(; id<m; id++){
        for(int val=0; val<=sum; val++){
            dp[id][val+vcnt[id]][1] = (dp[id][val+vcnt[id]][1]+(dp[id-1][val][0]+dp[id-1][val][1])*vcnt[id])%md;
            dp[id][val][1] = (dp[id][val][1]+dp[id-1][val][1])%md;
            dp[id][val][0] = (dp[id][val][0]+dp[id-1][val][0])%md;
        }
        sum+=vcnt[id];
    }
    for(int val=0; val<=n; val++) ans = (ans+dp[m-1][val][1])%md;
    
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}