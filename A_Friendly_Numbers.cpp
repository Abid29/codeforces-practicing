#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x,ans=0; cin>>x;
    for(int y=x+1; y<x+100; y++){
        int sum = y, val=y;
        while(val){
            sum-=val%10, val/=10;
        }

        if(sum==x) ans++;
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