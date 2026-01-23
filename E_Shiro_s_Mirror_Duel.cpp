#include <bits/stdc++.h>
using namespace std;
int p[4004],pos[4004];
void query(int a, int b){
    cout<<"? "<<a<<' '<<b<<endl;
    cout.flush();
}
void solve() {
    int n; cin>>n; 
    for(int i=1; i<=n; i++) {cin>>p[i]; pos[p[i]] = i;}

    if((n&1) && p[(n+1)/2] != (n+1)/2){
        query((n+1)/2, pos[(n+1)/2]);
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        swap(p[x],p[y]);
        pos[p[x]] = x, pos[p[y]] = y;
        while(x!=pos[(n+1)/2] && y!=pos[(n+1)/2]){
            query((n+1)/2, pos[(n+1)/2]);
            cin>>x>>y;
            if(x>y) swap(x,y);
            swap(p[x],p[y]);
            pos[p[x]]=x;
            pos[p[y]]=y;
        }
    }

    for(int i=1; i<=n/2; i++){
        while(p[i]+p[n-i+1]!=n+1){
            query(i,n-pos[n+1-p[i]]+1);
            int x,y; cin>>x>>y;
            if(x>y) swap(x,y);
            swap(p[x],p[y]);
            pos[p[x]]=x;
            pos[p[y]]=y;
        }
    }

    int x,y;
    for(int i=1; i<=n; i++){
        if(pos[i] == n-i+1 && i!=n-i+1){
            query(i, n-i+1);
            cin>>x>>y;
            if(x>y) swap(x,y);
            swap(p[i],p[pos[i]]);
            pos[i]== i;
            pos[n-i+1] = n-i+1;
        }
        while(p[i]!=i){
            int x1,x2,y1,y2;
            query(i,pos[i]);
            cin>>x1>>y1;
            if(x1>y1) swap(x1,y1);
            query(i,pos[i]);
            cin>>x2>>y2;
            if(x2>y2) swap(x2,y2);
            if(x1==x2) continue;

            swap(p[x1],p[y1]);
            pos[p[x1]] = x1, pos[p[y1]] = y1;
            swap(p[x2],p[y2]);
            pos[p[x2]] = x2, pos[p[y2]] = y2;

            break;
        }
    }

    cout<<'!'<<endl;
    cout.flush();
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}