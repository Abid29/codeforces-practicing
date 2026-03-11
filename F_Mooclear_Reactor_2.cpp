#include <bits/stdc++.h>
using namespace std;
long long pmx[200005];
vector<int>react[200005];
void solve() {
    int n,m; cin>>n>>m;
    for(int i=0; i<=n; i++) react[i].clear();
    for(int i=0,x,y; i<n; i++){
        cin>>x>>y;
        react[y].push_back(x);
    }

    priority_queue<int>pq;
    long long ans = 0, sum=0;
    for(int y=n; y>=0; y--){
        if(pq.size()>y+1) sum+=pq.top(),pq.pop();
        for(int x : react[y]){
            if(pq.size()<y+1) pq.push(-x), sum+=x;
            else if(-pq.top() < x){
                sum += pq.top(); pq.pop();
                sum += x; pq.push(-x);
            }
        } 
        
        ans = max(ans, sum);
        if(pq.size()==y+1) pmx[y] = sum + pq.top();
        else               pmx[y] = sum;
    }

    for(int y=1; y<=n; y++) pmx[y] = max(pmx[y], pmx[y-1]);

    for(int i=0,x,y; i<m; i++){
        cin>>x>>y;
        cout<<max(ans, pmx[y]+x)<<' ';
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