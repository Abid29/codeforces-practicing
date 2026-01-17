#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int>cnt(n+1);
    for(int i=1,x; i<=n; i++){
        cin>>x;
        if(i&1) cnt[x]+=1;
        else    cnt[x]-=1;
    }

    int ind = 0;
    for(int i=1; i<=n; i++){
        if(cnt[i]>1||cnt[i]<-1){
            cout<<"NO\n"; return;
        }
        if(ind==0){
            ind = cnt[i];
        }else if(ind==1){
            if(cnt[i]==1){
                cout<<"NO\n"; return;
            }else if(cnt[i]==-1){
                ind = -1;
            }else{
                ind = 1;
            }
        }else{
            if(cnt[i]==1){
                ind = 1;
            }else if(cnt[i]==-1){
                cout<<"NO\n"; return;
            }else{
                ind = -1;
            }
        }
    }
    cout<<"YES\n";
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}