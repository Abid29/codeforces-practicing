#include <bits/stdc++.h>
using namespace std;
long long a[2005], ans;
long long f(int l, int r, int h, long long gained){
    if(l+1>=r){
        long long ret = h-a[l];
        if(l<r) ret += h-a[r];
        ans = max(ans, gained+ret);
        return ret;
    }

    long long int mx = 0;
    for(int i=l; i<=r; i++) mx = max(mx, a[i]);
    long long extra = h-mx;
    extra *= r-l+1;

    vector<long long>vec;

    while(l<=r){
        while(l<=r && a[l]==mx) l++;
        if(l>r) break;
        int ll=l+1;
        while(ll<=r && a[ll]<mx) ll++;
        vec.push_back(f(l,ll-1,mx,gained+extra));
        l=ll;
    }

    if(vec.empty()){
        ans = max(ans, gained+extra);
        return extra;
    }
    else if(vec.size()==1){
        ans = max(ans, gained+extra+vec[0]);
    }
    else{
        sort(vec.begin(), vec.end(),[](long long x, long long y){
            return x>y;
        });

        ans = max(ans, gained+extra+vec[0]+vec[1]);
    }
    return extra+vec[0];
}
void solve() {
    int n,h; cin>>n>>h;
    for(int i=1; i<=n; i++) cin>>a[i];

    ans = 0;

    f(1,n,h,0);

    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}