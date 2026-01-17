#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int ones = 0;
    for(char ch : s){
        ones += ch-'0';
    }  
    
    vector<int>ans;
    for(int i=0; i<n; i++){
        if(s[i]=='1' && i<n-ones){
            ans.push_back(i+1);
        }
        if(s[i]=='0' && i>=n-ones){
            ans.push_back(i+1);
        }
    }

    if(ans.empty()){
        cout<<"Bob\n"; return;
    }
    cout<<"Alice\n";
    cout<<ans.size()<<endl;
    for(int x : ans) cout<<x<<' ';
    cout<<'\n';
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}