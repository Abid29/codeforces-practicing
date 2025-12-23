#include<bits/stdc++.h>
using namespace std;
long long int a[100005];
void solve(){
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    long long int mn=0,mx=0;
    for(long long i=1,b; i<=n; i++){
        cin>>b;
        long long new_mn = min(mn-a[i],b-mx);
        mx = max(mx-a[i], b-mn), mn = new_mn;
    }

    cout<<mx<<endl;
}
int main(){
    int t; cin>>t; 
    while(t--){
        solve();
    }
}