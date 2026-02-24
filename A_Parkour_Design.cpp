#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x,y; cin>>x>>y;
    if(y>0){
        if(x<y+y){
            cout<<"NO\n"; return;
        }
        x-=y+y;
    }else{
        if(x<(y+y+y+y)*(-1)){
            cout<<"NO\n"; return;
        }
        x+=y+y+y+y;
    }
    if(x%3==0) cout<<"YES\n";
    else       cout<<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}