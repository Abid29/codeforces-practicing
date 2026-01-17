#include <bits/stdc++.h>
using namespace std;
long long md=998244353;
long long cnt[4][105][105][105]; 
void solve() {
    int n; string s; 
    cin>>n>>s;
    s = "a"+s;
    
    cnt[0][0][0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            for(int len=0; len<=i; len++){
                for(int k=0; k<4; k++){
                    cnt[k][i][j][len] = cnt[k][i-1][j][len];
                }
                if(s[i]=='(' && j && len){
                    cnt[0][i][j][len] = (cnt[0][i][j][len]+cnt[0][i-1][j-1][len-1])%md;
                    cnt[2][i][j][len] = (cnt[2][i][j][len]+cnt[1][i-1][j-1][len-1])%md;
                    cnt[3][i][j][len] = (cnt[3][i][j][len]+cnt[2][i-1][j-1][len-1])%md;
                    cnt[3][i][j][len] = (cnt[3][i][j][len]+cnt[3][i-1][j-1][len-1])%md;
                }else if(s[i]==')' && len){
                    cnt[1][i][j][len] = (cnt[1][i][j][len]+cnt[1][i-1][j+1][len-1])%md;
                    cnt[1][i][j][len] = (cnt[1][i][j][len]+cnt[0][i-1][j+1][len-1])%md;
                    cnt[2][i][j][len] = (cnt[2][i][j][len]+cnt[2][i-1][j+1][len-1])%md;
                    cnt[3][i][j][len] = (cnt[3][i][j][len]+cnt[3][i-1][j+1][len-1])%md;
                }
            }
        }
    }
    long long ans = 0;
    for(long long len=4; len<=n; len++){
        ans = (ans + (len-2) * cnt[3][n][0][len])%md;
    }
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}