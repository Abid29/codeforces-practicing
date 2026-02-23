#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin>>n>>s;
    int ones=0; for(char ch : s) ones+= ch=='1';

    if(ones&1){
        if((n>ones &&((n-ones)&1))){
            cout<<n-ones<<endl;
            for(int i=1; i<=n; i++){
                if(s[i-1]=='0') cout<<i<<' ';
            }
            cout<<endl;
        }
        else cout<<"-1\n"; 
        return;
    }

    cout<<ones<<endl;
    for(int i=1; i<=n; i++){
        if(s[i-1]=='1') cout<<i<<' ';
    }
    if(ones) cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}