#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    int z=0,o=0;
    for(int i=1,x; i<=n; i++){
        cin>>x; 
        if(x==1) o++;
        if(x==0) z++;
    }

    if(!z){
        cout<<"NO\n";
    }else{
        if(z==1){
            cout<<"YES\n";
        }else{
            if(o) cout<<"YES\n";
            else  cout<<"NO\n";
        }
    }
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}