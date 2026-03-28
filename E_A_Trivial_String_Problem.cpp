#include <bits/stdc++.h>
using namespace std;
int pi[1000005],dp[1000005];
void solve() {
    int n,q; cin>>n>>q;
    string s; cin>>s;
    s = "2"+s;
    while(q--){
        int l,r; cin>>l>>r;
        for(int i=l; i<=r; i++){
            dp[i] = 1, pi[i] = 0;
        }
        for(int i=l+1,len; i<=r; i++){
            len = pi[i-1];
            while(len>0 && s[l+len]!=s[i]) len = pi[l+len-1];
            if(s[i] == s[l+len]) len++;
            pi[i] = len;
        }

        long long ans = 1;
        for(int i=l+1; i<=r; i++){
            if(!pi[i]) pi[i] = 0;
            else if(pi[l+pi[i]-1]) pi[i] = pi[l+pi[i]-1];
            else if(s[i]==s[l]) pi[i] = 1;

            if(pi[i]) dp[i] = 1 + dp[i-pi[i]];    
            ans += dp[i];
        }        
        cout<<ans<<endl;
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