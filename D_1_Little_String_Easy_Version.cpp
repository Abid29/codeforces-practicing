#include <bits/stdc++.h>
using namespace std;
int md = 1e9+7;
void solve() {
    int n,c; cin>>n>>c;
    string s; cin>>s;
    if(s[0]=='0'||s.back()=='0'){
        cout<<"-1\n"; return;
    }
    long long ans = 1;
    for(int i=1; i<n; i++){
        if(s[i]=='1'){
            ans = (ans+ans)%md;
            c /= __gcd(c, 2);
        }else{
            ans = (ans*i)%md;
            c /= __gcd(c, i);
        }
    }
    if(c>1) cout<<ans<<endl;
    else    cout<<"-1\n";
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}