#include <bits/stdc++.h>
using namespace std;
long long a[200005],sum[200005];
void solve() {
    int n,k; cin>>n>>k;
    vector<int>ids;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(sum[i-1]<a[i]) ids.push_back(i);
        sum[i] = sum[i-1] + a[i];
    }
    sum[n+1] = sum[n]+1;
    reverse(ids.begin(),ids.end());

    for(int i=1; i<=n; i++){
        int ki = k, zeroid=n+1;
        for(int id : ids){
            if(sum[id-1]+((id<=i)*a[i]) < a[id]){
                ki--;
                if(!ki) zeroid=id;
            }
        }
        // cout<<"id="<<zeroid<<endl;
        if(ki>0){
            cout<<n<<' ';
        }else if (!ki){
            int l=0,r=n+1;
            while(l+1<r){
                int mid = (l+r)/2;
                if(sum[mid]-(i<=mid)*a[i]<a[i]) l=mid;
                else              r=mid;
                // cout<<"mid"<<mid<<l<<r<<a[i]<<sum[mid]<<endl;
            }
            // cout<<"l="<<l<<endl;
            if(l>=zeroid-1) cout<<n<<' ';
            else         cout<<(l+1-(i<=l)) + n-zeroid+1-(i>zeroid)<<' ';
        }else{
            cout<<n-zeroid+1-(i>zeroid)<<' ';
        }
    }
    cout<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}