#include <bits/stdc++.h>
using namespace std;
int ids[150005],seg[600006],id;
void update(int ind, int st, int nd, int idx, int val){
    if(idx>nd||idx<st) return;
    if(st==nd){seg[ind]=val; return;}
    int mid = (st+nd)/2;
    update(ind+ind,st,mid,idx,val), update(ind+ind+1,mid+1,nd,idx,val);
    seg[ind] = seg[ind+ind]+seg[ind+ind+1];
}
int query(int ind, int st, int nd, int k){
    if(st==nd) {return st; }
    int mid = (st+nd)/2;
    if(seg[ind+ind]>=k) return query(ind+ind, st, mid, k);
    else                return query(ind+ind+1, mid+1, nd, k-seg[ind+ind]);
}
void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=4*(n+q); i++) seg[i] = 0;

    for(int i=1; i<=n; i++){
        cin>>ids[i];
        update(1,1,n+q,i,1);
    }
    id = n;  
    char ch;
    int val,qq=q;
    while(qq--){
        cin>>ch>>val;
        if(ch=='a'){
            ids[++id] = val;
            update(1,1,n+q,id,1);
        }else{
            if(seg[1]<val){
                cout<<"none\n"; continue;
            }
            int idx = query(1,1,n+q,val);
            cout<<ids[idx]<<endl;
            update(1,1,n+q,idx,0);
        }
    }
}

int main() {
    int t,tc=1; cin >> t; while(t--) {
        cout<<"Case "<<tc++<<":\n";
        solve();
    }
    return 0;
}