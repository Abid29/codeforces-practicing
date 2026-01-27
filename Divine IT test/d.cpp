#include <bits/stdc++.h>
using namespace std;
long long int dp[66][66];
void solve() {
    string s; cin>>s;
    int n = s.size();
    for(int i=0; i<n; i++){
        dp[i][i] = 1;
        if(i+1<n) dp[i][i+1] = 2+(s[i]==s[i+1]);
    }
    for(int len=2; len<n; len++){
        for(int i=0; i+len<n; i++){
            dp[i][i+len] = dp[i][i+len-1]+dp[i+1][i+len]-dp[i+1][i+len-1];
            if(s[i] == s[i+len]) dp[i][i+len] += dp[i+1][i+len-1]+1;
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int main() {
    int t,tc=1; cin >> t; while(t--) {
        cout<<"Case "<<tc++<<": ";
        solve();
    }
    return 0;
}