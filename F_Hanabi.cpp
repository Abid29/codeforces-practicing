#include <bits/stdc++.h>
using namespace std;
int rnk[200005];
void solve() {
    int n,m; cin>>n>>m;
    int N = n*m;

    for(int i=0; i<N; i++) cin>>rnk[i];

    vector<vector<int>>rankByCol(m);
    for(int i=0,color; i<N; i++){
        cin>>color;
        rankByCol[color-1].push_back(rnk[i]);
    }

    vector<int>idx(m);
    int possible = 1, ans = n-1;
    while(n-possible+1 > m){
        int primary = possible;
        while(1){
            for(int col=0; col<m; col++){
                while(rankByCol[col][idx[col]] < possible) idx[col]++;
            }
            int mx = possible;
            for(int col=0; col<m; col++){
                mx = max(mx, rankByCol[col][idx[col]]);
            }
            if(mx==possible){
                if(possible==n){
                    ans -= max(0, possible-primary+1-m);
                    possible = mx+1; break;
                }else possible++;
            }
            else{
                ans -= max(0, possible-primary-m);
                possible = mx; break;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}