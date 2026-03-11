#include <bits/stdc++.h>
using namespace std;
int a[200005];
void solve() {
    int n; cin>>n; 
    set<int>st;
    for(int i=1; i<=n; i++){
        cin>>a[i]; st.insert(a[i]);
    }
    if(a[1]>n || a[1]<n-1){cout<<"NO\n"; return;}

    vector<int>ans;
    int cur = n-1;
    a[0] = n;
    for(int i=1; i<=n; i++){
        if(a[i]==a[i-1]){
            while(st.find(cur)!=st.end()) cur--;
            ans.push_back(cur--);
        }else if(a[i]<a[i-1]&& a[i]>=n-i){
            ans.push_back(n+1);
        }else{
            cout<<"NO\n"; return;
        }
    }

    cout<<"YES\n";
    for(int x : ans) cout<<x<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}