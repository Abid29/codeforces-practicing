#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    string a,b; cin>>a>>b;
    
    int za = 0;
    while(za<n && a[za]=='1') za++;

    if(za<n && (za&1)) {cout<<"NO\n"; return;}

    int i=n-1; 
    while(i>za){  
        if(a[i]=='1'){cout<<"NO\n"; return;}
        i--;
    }

    if(b[0]!=a[0]) {cout<<"NO\n"; return;} 

    int zb=0;
    if(a[0]=='1'){
        zb=n;
        for(i=1; i<n; i++){
            if(b[i]=='0'){
                if(i%2==0) {cout<<"NO\n"; return;}
                if(i>=za-1) {zb=i; break;}
            } 
        }
    }

    while(zb<n) if(b[zb++]=='1') {cout<<"NO\n"; return;}

    
    cout<<"YES\n";
    for(i=1; i<=n; i++){
        if(a[i-1]=='1'){
            if(i&1) cout<<'+';
            else    cout<<'-';
        }else cout<<'-';
    }
    cout<<endl; 

    for(i=1; i<=n; i++){
        if(b[i-1]=='1'){
            if(i&1) cout<<'-';
            else    cout<<'+';
        }else cout<<'-';
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}