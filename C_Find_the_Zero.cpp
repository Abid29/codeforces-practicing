 #include <bits/stdc++.h>
 using namespace std;
 int query(int i, int j){
    cout<<"? "<<i<<' '<<j<<endl;
    cout.flush();
    int ret; cin>>ret;
    return ret;
 }
 
 void solve() {
    int n; cin>>n;
    for(int i=1; i<n; i++){
        if(query(i+i-1, i+i)){
            cout<<"! "<<i+i<<endl;
            cout.flush(); return;
        }
    }
    n+=n;
    if(query(n,n-2)){
        cout<<"! "<<n<<endl;
        cout.flush(); return;
    }
    if(query(n,n-3)){
        cout<<"! "<<n<<endl;
        cout.flush(); return;
    }
    cout<<"! "<<n-1<<endl;
    cout.flush();
 }
 
 int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
 }