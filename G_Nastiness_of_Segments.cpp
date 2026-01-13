#include <bits/stdc++.h>
using namespace std;
int a[200005],seg[800005],n;
void build(int idx, int st, int nd){
    if(st==nd){
        seg[idx] = st; return;
    }
    int mid = (st+nd)/2;
    build(idx+idx, st, mid), build(idx+idx+1, mid+1, nd);
    if(a[seg[idx+idx]] <= a[seg[idx+idx+1]]) seg[idx] = seg[idx+idx];
    else                                     seg[idx] = seg[idx+idx+1];
}

void update(int idx, int st, int nd, int pos){
    if(st>pos||nd<pos||st==nd) return;
    int mid = (st+nd)/2;
    update(idx+idx, st, mid, pos), update(idx+idx+1, mid+1, nd, pos);
    if(a[seg[idx+idx]] <= a[seg[idx+idx+1]]) seg[idx] = seg[idx+idx];
    else                                     seg[idx] = seg[idx+idx+1];
}
int query(int idx, int st, int nd, int l, int r){
    if(st>r||nd<l){
        return n+1;
    }
    if(st>=l&&nd<=r) return seg[idx];
    int mid = (st+nd)/2;
    int id1 = query(idx+idx, st, mid,l,r), id2 = query(idx+idx+1, mid+1, nd,l,r);
    if(a[id1] <= a[id2]) return id1;
    else                 return id2;
}
void solve() {
    int q;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];
    a[n+1] = 2e5+1;

    build(1,1,n);

    int idx,x,l,r;
    while(q--){
        cin>>idx;
        if(idx==1){
            cin>>idx>>x;
            a[idx] = x;
            update(1,1,n,idx);
        }else{
            cin>>l>>r;
            int L = l;
            while(l<=r){
                int mid = (l+r)/2;
                int id = query(1,1,n,L,mid);
                if(L+a[id] < id){
                    r = id-1;
                }else{
                    if(L+a[id] > mid){
                        l = mid+1;
                    }else{
                        cout<<"1\n"; break;
                    }
                }
            }
            if(l>r) cout<<"0\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}