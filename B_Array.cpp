#include <bits/stdc++.h>
using namespace std;
int a[5005];
void solve() {
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++){
        int chuto=0, boro=0;
        for(int j=i+1; j<n; j++){
            if(a[j]>a[i]) chuto++;
            else if(a[j]<a[i]) boro++;
        }
        cout<<max(chuto,boro)<<' ';
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}