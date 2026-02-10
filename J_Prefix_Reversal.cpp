#include <bits/stdc++.h>
using namespace std;
long long a[200005],sufsum[200005];
void solve() {
    long long int n; cin>>n;
    for(long long int i=1; i<=n; i++) cin>>a[i];
    sufsum[n+1] = 0;
    for(int i=n;  i>0; i--) sufsum[i] = sufsum[i+1]+a[i]*i;

    vector<pair<long long,int>>vp;

    long long sum=0, totsum=0;
    for(int i=1; i<=n; i++){
        sum += a[i];
        totsum += sum;
        vp.push_back({totsum+sufsum[i+1], i});
    }
    sort(vp.begin(), vp.end());

    for(auto it : vp) cout<<it.second<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}