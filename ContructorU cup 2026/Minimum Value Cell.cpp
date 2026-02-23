#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],X[200005],Y[200005];
void solve() {
    int n,q,x,y;
    cin>>n>>q;
    set<int>sta,stb;
    for(int i=1;  i<=n;  i++){
        cin>>a[i]; sta.insert(a[i]);
    }
    for(int i=1;  i<=n;  i++){
        cin>>b[i]; stb.insert(b[i]);
    }

    for(int i=1; i<=q; i++) cin>>X[i];
    for(int i=1; i<=q; i++) cin>>Y[i];

    int ans;
    for(int i=1; i<=q; i++){
        x=X[i],y=Y[i];
        auto it = stb.lower_bound(a[x]);
        ans = 1e9;
        if(it!=stb.end()){
            ans = min(ans, abs(a[x]-*it));
        }
        if(it!=stb.begin()){
            ans = min(ans, abs(a[x]-*(--it)));
        }

        it = sta.lower_bound(b[y]);
        if(it!=sta.end()){
            ans = min(ans, abs(b[y]-*it));
        }
        if(it!=sta.begin()){
            ans = min(ans, abs(b[y]-*(--it)));
        }
        cout<<ans<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t; cin >> t; while(t--) {
        solve();
    // }
    return 0;
}