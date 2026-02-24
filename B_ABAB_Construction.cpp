#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s; cin>>n>>s;
    char f='a',l='b';
    if(n&1) l = f;

    for(int i=0; i<n; i++){
        if(s[i]=='?'){
            if(f==l){
                f = f=='a'?'b':'a';
            }else{
                if(s[i+1]==f){
                    l = l=='a'?'b':'a';
                }else{
                    f = f=='a'?'b':'a';
                }
            }
        }else{
            if(f==s[i]){
                f = f=='a'?'b':'a';
            }else if(l==s[i]){
                l = l=='a'?'b':'a';
            }else{
                cout<<"NO\n"; return;
            }
        }
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