#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    string s;  
    cin>>n>>s;
    if(n==1){
        cout<<"1\n"; return;
    }
    int cnt = 0,ans=0;
    vector<int>cnts;
    for(char ch : s){
        if(ch=='0') cnt++;
        else        cnts.push_back(cnt), cnt=0, ans++;
    }
    cnts.push_back(cnt);
    if(!ans){
        cout<<1 + (n-2)/3 + ((n-2)%3==2)<<endl; return;
    }

    int m = cnts.size();

    for(int i=0; i<m; i++){
        ans += cnts[i]/3;
    }
    ans += (cnts[0]%3==2) + (cnts[m-1]%3==2);
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}