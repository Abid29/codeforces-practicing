#include <bits/stdc++.h>
using namespace std;
int a[200005],p[200005],pos[200005];
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i];
        pos[p[i]] = i;
    }
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    int last = 0;
    for(int i=1; i<=n; i++){
        if(pos[a[i]] > i){
            if(pos[a[i]] < last){
                cout<<"NO\n"; return;
            }
        }else if(pos[a[i]] < i){
            if(pos[a[i]] < last){
                cout<<"NO\n"; return;
            }
        }else{
            if(last > i){
                cout<<"NO\n"; return;
            }
        }
        last = pos[a[i]];
    }
    cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}