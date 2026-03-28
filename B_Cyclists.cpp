#include <bits/stdc++.h>
using namespace std;
int a[5005];
void solve() {
    int n,k,p,m;
    cin>>n>>k>>p>>m;

    for(int i=1; i<=n; i++) cin>>a[i];
    if(k==n){
        cout<<m/a[p]<<endl; return;
    }
    priority_queue<pair<int,int>>pq;
    queue<int>q;
    for(int i=1; i<=n; i++){
        if(i!=p && i<=k) pq.push({-a[i],i});
        if(i>k) q.push(i);
    }
    int cnt = 0;
    if(p<=k && m>=a[p]) {q.push(p), m-=a[p], cnt++; pq.push({-a[q.front()],q.front()}),q.pop();}
    while(m>=a[p]){
        int id = pq.top().second;
        if(a[id]>m) break;
        m-=a[id], pq.pop();
        q.push(id);
        id = q.front();
        q.pop();
        if(id==p){
            if(m<a[p]) break;
            m-=a[p], cnt++, q.push(p);
            pq.push({-a[q.front()],q.front()}), q.pop();
        }else{
            pq.push({-a[id],id}); 
        }
    }
    cout<<cnt<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}