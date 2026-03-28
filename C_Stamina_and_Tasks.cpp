#include <bits/stdc++.h>
using namespace std;
double c[100005],p[100005];
void solve() {
    int n; cin>>n;
    double h=100;
    for(int i=1; i<=n; i++){
        cin>>c[i]>>p[i];
    }
    double mx = c[n];
    for(int i=n-1; i>0; i--){
        mx = max(mx, c[i]+(h-p[i])*mx/h);
    }
    cout<<setprecision(7)<<mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}