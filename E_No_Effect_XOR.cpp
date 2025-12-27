#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long l,r;
    cin>>l>>r;
    if(l==r){
        cout<<"0\n"; return;
    }
    int mxbit = 60;

    while(mxbit>=0){
        if(((l>>mxbit)&1)&((r>>mxbit)&1)){
            l -= ((long long)1<<mxbit), r -= ((long long)1<<mxbit);
        }else if(((l>>mxbit)&1)!=((r>>mxbit)&1)) break;
        mxbit--; 
    }

    if(l==0){
        int cnt=0;
        while(!(((r+1)>>cnt)&1)) cnt++;
        cout<<((long long)1<<cnt)-1<<endl;
        return;
    }

    long long ans;
    int cnt=0;
    while(!((l>>cnt)&1)) cnt++;
    ans = ((long long)1<<cnt)-1;
    cnt=0;
    while(!(((r+1)>>cnt)&1)) cnt++;
    ans = min(ans, ((long long)1<<cnt)-1);

    if(l==((long long)1<<(mxbit+1))-1-r){
        ans += ans+1;
    }

    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}