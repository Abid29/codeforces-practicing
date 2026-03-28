#include <bits/stdc++.h>
using namespace std;
const int md = 998244353;
long long ways[500005],a[500005],lft[500005];
long long bigpow(int aa, int bb){
    long long ret = 1;
    while(bb){
        if(bb&1) ret = (ret * aa)%md;
        aa = (aa*aa)%md, bb/=2;
    }
    return ret;
}
void solve() {
    int n,m; cin>>n>>m;
    vector<pair<long long, long long>>va;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        va.push_back({a[i],i});
    }
    sort(va.begin(),va.end());
    set<long long>rs;
    rs.insert(n), lft[n] = 1;
    for(int i=0; i<n; i++){
        long long int r = *rs.lower_bound(va[i].second);
        long long int l = lft[r];
        rs.erase(rs.lower_bound(va[i].second));
        ways[i] = (va[i].second-l+1)*(r-va[i].second+1)%md;
        if(r!=va[i].second) lft[r]=va[i].second+1, rs.insert(r);
        if(l!=va[i].second) lft[va[i].second-1]=l, rs.insert(va[i].second-1);
    }

    vector<long long>suf(n),sufsum(n+1);
    long long ans = 0;
    for(int i=n-1,id; i>=0;  i--){
        id = va[i].second;
        suf[i] = ways[i]*bigpow(a[id],md-2)%md;
        sufsum[i] = (sufsum[i+1] + suf[i])%md;
        ans = (ans + (id*(n-id+1)-ways[i]+md)%md * bigpow(a[id],md-2))%md;
    }

    int k,id=0,prv=0;
    long long tot=0;
    ans=(ans+sufsum[0])%md;
    while(m--){
        cin>>k;
        ans = (ans + tot*(k-prv))%md;
        ans = (ans - sufsum[id]*(prv+1)%md + md)%md;
        while(id<n && va[id].first <= k+1){
            ans = (ans + ways[id]*(k+1-va[id].first))%md;
            tot = (tot + ways[id])%md;
            id++;
        }
        ans = (ans + sufsum[id]*(k+1))%md;
        cout<<ans<<endl;
        prv=k;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}