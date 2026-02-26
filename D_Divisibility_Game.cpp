#include <bits/stdc++.h>
using namespace std;
int a[2000006],b[1000006],cnt[2000006];
void solve() {
    int n,m; cin>>n>>m;
    for(int i=1; i<=n+m; i++) cnt[i] = a[i] = 0;
    for(int i=1,x; i<=n; i++){
        cin>>x; 
        a[x]=1;
    }

    int sz=0;
    for(int i=1; i<=n+m; i++){
        if(!a[i]) continue;
        sz++;
        for(int j=i; j<=n+m; j+=i){
            cnt[j]++;
        }
    }

    int all=0,none=0;
    for(int i=1; i<=m; i++){
        cin>>b[i];
        if(cnt[b[i]]==sz) all++;
        else if(!cnt[b[i]]) none++;
    }

    if((m-all-none)&1){
        if(none>all) cout<<"Bob\n";
        else         cout<<"Alice\n";
    }else{
        if(none>=all) cout<<"Bob\n";
        else          cout<<"Alice\n";
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