#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long s,m; cin>>s>>m;
    long long n = 0,ss=s;

    for(int bit=60; bit>=0; bit--){
        if((m>>bit)&1){
            long long val = s/((long long)1<<bit);
            n = max(n, val);
            s -= val * ((long long)1<<bit);
        }
    }
    if(s) {cout<<"-1\n"; return;}
    
    
    long long l=0, r=n;
    while(l+1<r){
        long long mid = (l+r)/2;
        s=ss;
        for(int bit=60; bit>=0; bit--){
            if((m>>bit)&1){
                long long val = s/((long long)1<<bit);
                s -= min(val,mid) * ((long long)1<<bit);
            }
        }
        if(!s) r=mid;
        else   l=mid;
    }
    cout<<r<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}