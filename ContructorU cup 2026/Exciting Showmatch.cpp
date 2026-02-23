#include <bits/stdc++.h>
using namespace std;
long long fact[300005],invfact[300005],a[300005],md=998244353;
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n+n; i++) cin>>a[i];
    long long ans=0, ways = 1, cnt=0;
    for(int i=1; i<=n+n; ){
        int j=i+1; 
        while(j<=n+n && a[i]+j-i == a[j]) j++;
        ans += j-i-1;
        cnt += (j-i)%2;
        if((j-i)%2==0) ways = (ways*2)%md;
        i=j;
    }
    ways = ways*fact[cnt]%md*invfact[cnt/2]%md*invfact[cnt/2]%md;
    cout<<ans<<' '<<ways<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for(int i=1; i<=300000; i++) fact[i] = (fact[i-1]*i)%md; 
    int b=md-2;
    long long val = fact[300000];
    invfact[300000] = 1;
    while(b){
        if(b&1) invfact[300000] = (invfact[300000]*val)%md;
        b/=2, val = (val*val)%md;
    }
    for(int i=300000-1; i>=0; i--) invfact[i] = (invfact[i+1]*(i+1))%md;
    // cout<<invfact[0]<<endl;
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}