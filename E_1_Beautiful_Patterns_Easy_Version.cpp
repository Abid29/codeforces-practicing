#include <bits/stdc++.h>
using namespace std;
long long n,m,p,invpw[2005],cumusum[2005],two=2;
void solve() {
    cin>>n>>m>>p;
    invpw[0] = 1;
    for(int i=1; i<=n; i++){
        invpw[i] = (invpw[i-1]*m)%p;
    }
    long long a=invpw[n], b = p-2;
    invpw[n] = 1;
    while(b){
        if(b&1) invpw[n] = (invpw[n]*a)%p;
        b/=2, a = (a*a)%p;
    }
    for(int i=n-1; i>-1; i--){
        invpw[i] = (invpw[i+1]*m)%p;
    }

    long long ans = 0;
    for(long long len=1; len<=n; len++){
        ans = (ans + (n-len+1) * invpw[len/2])%p;
    }
    long long expected = ans;
    //concentric
    cumusum[1] = 1;
    for(long long len=3,sum=1; len<=n; len+=2, sum++){
        ans = (ans + (n-len+1) * sum % p * invpw[len/2] %p * two)%p;
        cumusum[len] = (cumusum[len-2]+invpw[len/2])%p;
    }
    
    for(long long len=2,sum=0; len<=n; len+=2, sum++){
        ans = (ans + (n-len+1) * sum % p * invpw[len/2] %p * two)%p;
        cumusum[len] = (cumusum[len-2]+invpw[len/2])%p;
    }
    //non-concentric
    //odd
    for(long long i=1; i<=n; i++){
        expected -= cumusum[min(i-1,n-i)*2+1]; 
        expected += p, expected%=p;
        ans = (ans + expected * cumusum[min(i-1,n-i)*2+1] %p * two)%p;
    }
    //even
    for(long long i=2; i<=n; i++){
        expected -= cumusum[min(i-1,n-i+1)*2];
        expected += p, expected%=p;
        ans = (ans + expected * cumusum[min(i-1,n-i+1)*2] %p * two)%p;
    }
    cout<<ans<<endl;    
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}