#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin>>s;
    int cnt=0,have=0,n=s.size();
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch=='u'){
            if(have==0||(i==n-1)) cnt++;
            have^=1;
        }else have=1;
    }
    cout<<cnt<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}