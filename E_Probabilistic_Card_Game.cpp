#include <bits/stdc++.h>
using namespace std;
const int md = 998244353;
long long a[200005],ans[200005];
long long bigpow(long long a, long long b){
    long long ret = 1;
    while(b){
        if(b&1) ret = (ret*a)%md;
        b/=2, a = (a*a)%md;
    }
    return ret;
}
void solve() {
    int n; cin>>n;
    vector<long long>vec(n);
    long long sum=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        vec[i-1] = a[i];
        sum += a[i];
    }
    sort(vec.begin(),vec.end());

    long long presum=vec[0], sufsum=sum-vec[0]-vec[1],val=vec[1]; 
    set<long long>pst, sst;
    pst.insert(vec[0]);
    for(int i=2; i<n; i++) sst.insert(vec[i]);

    for(long long int id=n; id>3; id--){
        long long mx = max(*pst.rbegin()*(pst.size()) - presum, sufsum - *sst.begin()*(sst.size()));
        while(pst.size()>1 && mx > max(*next(pst.rbegin())*(pst.size()-1)-(presum-*pst.rbegin()), sufsum - val*sst.size())){
            sst.insert(val), sufsum += val;
            val = *pst.rbegin();
            pst.erase(prev(pst.end()));
            presum -= val;
            mx = max(*pst.rbegin()*(pst.size()) - presum, sufsum - *sst.begin()*(sst.size()));
        }

        while(sst.size()>1 && mx > max(sufsum-*sst.begin()-(*next(sst.begin())*(sst.size()-1)), val*pst.size()-presum)){
            pst.insert(val), presum += val;
            val = *sst.begin(), sufsum-=val;
            sst.erase(sst.begin());
            mx = max(*pst.rbegin()*(pst.size()) - presum, sufsum - *sst.begin()*(sst.size()));
        } 

        ans[id] = mx %md * bigpow(id-2, md-2) %md;

        if(a[id] > val){
            sufsum -= a[id], sst.erase(sst.find(a[id]));
        }else if(a[id]<val){
            presum -= a[id], pst.erase(pst.find(a[id]));
        }else{
            val = *sst.begin();
            sufsum -= val;
            sst.erase(sst.begin());
        }

        if(pst.empty()){
            pst.insert(val), presum += val;
            val = *sst.begin(), sufsum-=val;
            sst.erase(sst.begin());
        }else if(sst.empty()){
            sst.insert(val), sufsum += val;
            val = *pst.rbegin(), presum -= val;
            pst.erase(prev(pst.end()));
        }
    }

    for(int i=3; i<=n; i++) cout<<ans[i]<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1; while(t--) {
        solve();
    }
    return 0;
}