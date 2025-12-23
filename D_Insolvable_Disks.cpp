#include <bits/stdc++.h>
using namespace std;
int less_than[2000005], greater_than[2000005], x[2000005];
void solve() {
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>x[i];

    if(n == 1){
        cout<<"0\n";  return;
    }

    less_than[0] = x[1]-x[0];
    greater_than[0] = 0;

    int ans = 1;
    for(int i=1; i<n-1; i++){
        if(less_than[i-1] + x[i+1]-x[i] > x[i] - x[i-1]){
            ans++;
            greater_than[i] = x[i]-x[i-1]-less_than[i-1];
            less_than[i] = min(x[i+1]-x[i], x[i]-x[i-1]-greater_than[i-1]);
        }else{
            less_than[i] = min(x[i+1]-x[i], x[i]-x[i-1]-greater_than[i-1]);
            greater_than[i] = 0;
        }
    }

    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}