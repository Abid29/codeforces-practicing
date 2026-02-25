#include <bits/stdc++.h>
using namespace std;
const int md = 998244353;
long long dp[300005],pwt[300005];
void solve() {
    int n; string s; cin>>n>>s;
    long long last=0, sumofclosed=0, cur=0, ans=0;
    for(long long i=0; i<n; i++){
        if(s[i] == ')'){
            cur--;
            dp[i] = (sumofclosed+1) * pwt[i-last] % md;
            ans = (ans+dp[i])%md;
        }else{
            cur++;
            ans = (ans+pwt[i])%md;
        }

        if(cur<2){
            while(last<=i){
                if(s[last]==')') sumofclosed = (sumofclosed+dp[last])%md;
                last++;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pwt[0] = 1;
    for(int i=1; i<300005; i++){
        pwt[i] = (pwt[i-1]*2)%md;
    }
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}