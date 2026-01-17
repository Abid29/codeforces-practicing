#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    vector<int>cnt(n+1,0);
    for(int i=n-1; i>-1; i--){
        cnt[i] = cnt[i+1]+(s[i]=='(');
        // cout<<i<<' '<<cnt[i]<<endl;
    }

    for(int i=2; i<n; i++){
        if(s[i-1]==')'&&s[i]=='('){
            if(cnt[i]>1) cout<<n-2<<endl;
            else         cout<<"-1\n";
            return;
        }
    }
    cout<<"-1\n";
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}