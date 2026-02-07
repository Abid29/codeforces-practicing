#include <bits/stdc++.h>
using namespace std;
int a[500005];
void solve() {
    int n,q; cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    
    priority_queue<int>pq;
    while(q--){
        int c,id=n,ans=0;
        while(pq.empty()==0)pq.pop();
        cin>>c;
        for(int bit=29; bit>=0; bit--){
            if(!((c>>bit)&1)) continue;
            if(pq.empty()||(id>0 && pq.top()<=a[id])){
                ans += max(0, (1<<bit)-a[id]);
                pq.push((1<<bit) < a[id]? a[id]-(1<<bit) : 0);
                id--;
            }else{
                int val = pq.top();
                pq.pop();
                ans += max(0, (1<<bit)-val);
                pq.push((1<<bit) < val? val-(1<<bit) : 0);
            }
        }
        cout<<ans<<endl;
    }
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}