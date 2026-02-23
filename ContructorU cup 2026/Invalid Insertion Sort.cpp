#include <bits/stdc++.h>
using namespace std;
int a[300005];
void solve() {
    long long int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    long long sum = 0,mn=a[1],mx=a[1], ans=0;

    for(int i=2; i<=n; i++){
        if(a[i]>mn && a[i]<mx) sum += n-1;
        else if(a[i]<mn) sum += (a[i]-1) + (n-mn), mn = a[i];
        else sum += (n-a[i]) + (mx-1), mx = a[i];

        ans += sum;
    }

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