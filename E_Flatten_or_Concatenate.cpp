#include <bits/stdc++.h>
using namespace std;
long long query(int l, int r){
    cout<<"? "<<l<<' '<<r<<endl;
    cout.flush();
    long long ret; cin>>ret;
    return ret;
}
void solve() {
    int n; cin>>n;
    int L=1, R=n;
    while(L<R){
        long long totalsum = query(L,R);
        int l=L, r=R,mid;
        while(l<r){
            mid = (l+r)/2;
            long long sum = query(L,mid);
            if(sum+sum > totalsum){
                r=mid-1;
            }else if(sum+sum < totalsum){
                l=mid+1;
            }else{
                l=r=mid;
            }
        }
        if(l-L > R-l-1) L=l+1;
        else            R=l;
    }
    long long ans = query(L,L);
    cout<<"! "<<ans<<endl;
    cout.flush();
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}