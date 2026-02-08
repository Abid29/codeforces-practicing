#include <bits/stdc++.h>
using namespace std;
vector<long long>mat[1000005],pre[1000005],suf[1000005],cmx[1000005],rmx[1000005];
void solve() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++){
        mat[i].resize(m+1);
        pre[i].resize(m+1);
        suf[i].resize(m+1);
        rmx[i].resize(m+1);
        cmx[i].resize(m+1);
        for(int j=1; j<=m; j++) cin>>mat[i][j];
    }
    pre[1][1] = mat[1][1];
    for(int i=2; i<=n; i++) pre[i][1] = mat[i][1] + pre[i-1][1];
    for(int i=2; i<=m; i++) pre[1][i] = mat[1][i] + pre[1][i-1];
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            pre[i][j] = max(pre[i-1][j], pre[i][j-1]) + mat[i][j];
        }
    }

    suf[n][m] = mat[n][m];
    for(int i=n-1; i>0; i--) suf[i][m] = mat[i][m] + suf[i+1][m];
    for(int i=m-1; i>0; i--) suf[n][i] = mat[n][i] + suf[n][i+1];
    for(int i=n-1; i>0; i--){
        for(int j=m-1; j>0; j--){
            suf[i][j] = max(suf[i+1][j],suf[i][j+1])+mat[i][j];
        }
    }

    // cout<<pre[n][m] <<' '<< suf[1][1]<<endl;

    for(int i=1; i<=n; i++) cmx[i][m] = pre[i][m]+suf[i][m]-mat[i][m];
    for(int i=1; i<=m; i++) rmx[n][i] = pre[n][i]+suf[n][i]-mat[n][i];
    
    for(int i=n-1; i>0; i--){
        for(int j=m-1; j>0; j--){
            long long val = pre[i][j]+suf[i][j]-mat[i][j];
            cmx[i][j] = max(cmx[i][j+1], val);
            rmx[i][j] = max(rmx[i+1][j], val);
        }
    }

    long long ans = suf[1][1];
    for(int i=1,j=1; i<n||j<m; ){
        if(mat[i][j]>0){
            long long val = suf[1][1]-mat[i][j]-mat[i][j];
            if(i>1 && j<m) val = max(val, cmx[i-1][j+1]);
            if(j>1 && i<n) val = max(val, rmx[i+1][j-1]);

            ans = min(ans, val); 
        }

        if(i==n) j++;
        else if(j==m) i++;
        else{
            if(pre[i+1][j]+suf[i+1][j]-mat[i+1][j]==suf[1][1]) i++;
            else                                               j++;
        }
    }
        
    cout<<ans<<endl;

    for(int i=1; i<=n; i++){
        mat[i].clear();
        pre[i].clear();
        suf[i].clear();
        cmx[i].clear();
        rmx[i].clear();
    }
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}