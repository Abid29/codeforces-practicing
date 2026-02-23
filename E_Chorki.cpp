#include <bits/stdc++.h>
using namespace std;
int a[400005],ord[400005],nord[400005],cls[400005],ncls[400005],cnt[400005],lcp[400005],l,n,sz;
void counting_sort(){
    for(int i=0; i<=n+n; i++){
        cnt[cls[i]]=0;
    }
    for(int i=0; i<=n+n; i++){
        cnt[cls[i]]++;
    }
    for(int i=1; i<=n+n; i++) cnt[i] += cnt[i-1];

    for(int i=n+n; i>=0; i--){
        int idx = (ord[i]-l+sz)%sz;
        nord[--cnt[cls[idx]]] = idx;
    }

    for(int i=0; i<sz; i++) ord[i] = nord[i];
}

void update_class(){
    ncls[ord[0]] = 0;
    for(int i=1; i<sz; i++){
        ncls[ord[i]] = ncls[ord[i-1]];
        if(cls[ord[i]]!=cls[ord[i-1]] || cls[(ord[i]+l)%sz]!=cls[(ord[i-1]+l)%sz]) ncls[ord[i]]++;
    }

    for(int i=0; i<=n+n; i++) cls[i] = ncls[i];
}

void solve() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i+n] = a[i];
    }
    
    a[n+n] = -1;
    cnt[0] = cnt[1] = 0;
    for(int i=0; i<n+n; i++) cnt[a[i]]++;
    cnt[1] += cnt[0];

    ord[0] = n+n;
    for(int i=0; i<n+n; i++){
        ord[cnt[a[i]]--] = i;
    }
    
    cls[ord[0]] = 0;
    for(int i=1; i<=n+n; i++){
        if(a[ord[i]] == a[ord[i-1]]) cls[ord[i]] = cls[ord[i-1]];
        else                         cls[ord[i]] = cls[ord[i-1]]+1;
    }

    l=1, sz = n+n+1;
    while(l<=n+n){
        counting_sort();
        update_class();
        l+=l;
    }

    l=0;
    for(int i=0; i<=n+n;  i++){
        if(cls[i]==n+n) {l=0; continue;}
        
        int j = ord[cls[i]+1];

        while(a[i+l] == a[j+l]) l++;
        lcp[cls[i]] = l; 
        
        l = max(0,l-1);
    }

    int idx=0;
    while(ord[idx] >= n) idx++;

    int mn = lcp[idx], fidx=idx;
    while(idx<sz){
        int id = idx+1;
        while(id<sz && ord[id]>=n){
            mn = min(mn, lcp[id]);
            id++;
        }
        
        if(id<sz){
            if(a[ord[id]+mn]!=a[mn]) fidx= id, mn = lcp[id];
            else                     mn = min(mn, lcp[id]);
        }
        
        idx = id;
    } 

    for(int i=0; i<n; i++){
        cout<<(a[i]^a[ord[fidx]+i])<<' ';
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