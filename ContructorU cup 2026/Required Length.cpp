#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x,y,z; cin>>x>>y>>z;
    if(max(x,y)==z){
        while(x--) cout<<'1';
        cout<<' ';
        while(y--) cout<<'2';
        cout<<endl;
    }else if(max(x,y)+1==z){
        while(x--) cout<<'9';
        cout<<' ';
        while(y--) cout<<'9';
        cout<<endl;
    }else{
        cout<<"0 0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}