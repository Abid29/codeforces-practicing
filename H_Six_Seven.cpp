#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool ispowsix(long long x){
    while(x%6==0) x/=6;
    return x==1;
}
void solve() {
    int n; cin>>n;
    for(int i=1;  i<=n; i++) cin>>a[i];

    sort(a+1, a+n+1);
    long long val=1;
    while(val/6<=1e9){
        if(a[1] > val) {val*=6; continue;}

        long long add = val-a[1],i;
        for(i=2; i<=n; i++){
            if(!ispowsix(a[i]+add)) break;
        }
        if(i>n){cout<<add<<endl; return;}
        val*=6;
    }
    cout<<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}