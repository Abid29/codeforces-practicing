#include <bits/stdc++.h>
using namespace std;
vector<int>mat[300005];
void solve() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++){
        mat[i].resize(m+1);
        for(int j=1; j<=m; j++) cin>>mat[i][j];
    }
    long long int sum = 0;
    for(int i=1; i<=n; i++){
        for(int j=m-1; j>0; j--){
            mat[i][j] += mat[i][j+1];
        }
        sum += mat[i][1];
    }

    cout<<(sum/2)*(sum-sum/2)<<endl;

    int x=1,y=1, val=0;
    while(x<=n || y<=m){
        if(x>n){
            cout<<'R'; y++;
        }
        else if(y>m){
            cout<<'D'; x++;
        }else{
            if(val+mat[x][y] <= sum/2) {
                val+=mat[x][y];
                cout<<'D'; x++;
            }else{
                cout<<'R'; y++;
            }
        }
    }
    cout<<endl;

    for(int i=1; i<=n; i++) mat[i].clear();
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}