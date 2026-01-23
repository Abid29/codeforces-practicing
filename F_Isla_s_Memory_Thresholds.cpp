#include <bits/stdc++.h>
using namespace std;
int a[150005];
long long sum[150005];
void solve() {
    int n,q; cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
    }

    int l,r,x;
    while(q--){
        cin>>l>>r>>x;
        int tot=0, L=0,R,mid;
        while(sum[r]-sum[l-1]>=x){
            R=r-l+1;
            while(L+1<R){
                mid = (L+R)/2;
                if(sum[l+mid-1]-sum[l-1] >= x) R=mid;
                else                           L=mid;
            }

            int ll = 1, rr = (r-l+1)/R+1, val;
            while(ll+1<rr){
                mid = (ll+rr)/2;
                val = l+R*mid-1;
                if(sum[val] - sum[val-R] >= x) ll=mid;
                else                           rr=mid;
            }

            l += R*ll, tot += ll;
        }

        cout<<tot<<' '<<sum[r]-sum[l-1]<<endl;
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