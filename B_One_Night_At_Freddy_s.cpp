#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,m,l;
    cin>>n>>m>>l;

    vector<int>buckets;
    int last = 0;
    for(int i=0,a; i<n; i++){
        cin>>a;
        while(min(n-i+1,m) > buckets.size()) buckets.push_back(0);
        sort(buckets.begin(),buckets.end());
        last = a-last;
        while(last){
            buckets[0]++, last--;
            for(int i=1; last>0 && i<buckets.size() && buckets[i]<buckets[i-1]; i++, last--){
                buckets[i]++;
            }
        }
        sort(buckets.begin(),buckets.end());
        buckets.pop_back();

        last = a;
    }
    if(m>1) cout<<buckets[0]+l-last<<endl;
    else    cout<<l-last<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}