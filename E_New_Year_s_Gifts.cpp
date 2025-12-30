#include <bits/stdc++.h>
using namespace std;
int a[200005],x,y,z;
void solve() {
    int n,m;
    long long k;
    cin>>n>>m>>k;
    for(int i=0; i<m; i++)  cin>>a[i];
    vector<pair<int,int>>xz(n);
    for(int i=0; i<n; i++){
        cin>>x>>y>>z;
        k-=y, z-=y;
        xz[i] = {x,z};
    }

    sort(a, a+m);
    sort(xz.begin(),xz.end());

    int id = 0, ans = 0;;
    priority_queue<int>pq,npq;
    for(int i=0; i<m; i++){
        while(id < n && xz[id].first <= a[i]) pq.push(xz[id].second),id++;
        if(pq.empty()==0) pq.pop(),ans++;
    }
    while(!pq.empty()){
        npq.push(-pq.top()), pq.pop();
    }

    for(; id<n; id++) npq.push(-xz[id].second);

    while(!npq.empty() && k+npq.top()>=0){
        ans++, k += npq.top(), npq.pop();
    }
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}