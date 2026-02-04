#include <bits/stdc++.h>
using namespace std;
int seg[800005];
void update(int ind, int st, int nd, int idx, int val){
    if(st>idx || nd<idx) return;
    if(st==nd){seg[ind] = max(seg[ind], val); return;}

    int mid = (st+nd)/2;
    update(ind+ind, st, mid, idx, val), update(ind+ind+1, mid+1, nd, idx, val);
    seg[ind] = max(seg[ind+ind], seg[ind+ind+1]);
}

int query(int ind, int st, int nd, int r){
    if(st>r) return 0;
    if(nd<=r) return seg[ind];

    int mid = (st+nd)/2;
    return max(query(ind+ind, st, mid, r),query(ind+ind+1, mid+1, nd, r));
}
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1; i<m+m+m+m-n-n-n-n+5; i++) seg[i] = 0;

    stack<pair<int,int>>st;
    for(int i=2; i<=n; i++){
        for(long long j=i,cnt=1; j<=m-(n-i); j*=i,cnt++){
            for(int k=j; k<=m-(n-i); k+=j){
                st.push({k-i, cnt+query(1,0,m-n,k-i)});
            }
        }
        while(!st.empty()){
            int idx = st.top().first, val = st.top().second;
            update(1,0,m-n,st.top().first, st.top().second);
            st.pop();
        }
    }
    cout<<seg[1]<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}