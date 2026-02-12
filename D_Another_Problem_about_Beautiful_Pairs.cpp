#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
vector<int>id[200005];
void solve() {
    cin>>n;
    for(int i=1; i<n; i++){
        id[i].clear();
    }
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]<n) id[a[i]].push_back(i);
    }

    int ans = 0;
    for(int value = n-1; value>0; value--){
        for(int idx : id[value]){
            for(int i=idx+value,  j=1; i<=n && j<=value; i+=value,j++){
                if(a[i]==j) ans++;
            }
            for(int i=idx-value, j=1; i>0 && j<value; i-=value, j++){
                if(a[i]==j) ans++;
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