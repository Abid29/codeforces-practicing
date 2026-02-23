#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin>>n>>s;
    int bl = 0;
    int id = 0,last;
    bool ind=0;
    while(id<n){
        last = id;
        while(id+1<n && s[id]==s[id+1]) id++;
        ind |= last!=id;
        bl++, id++;
    }
    if(s[0] == s[n-1]) cout<<bl<<endl;
    else{
        if(ind) cout<<bl+1<<endl;
        else    cout<<bl<<endl;
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