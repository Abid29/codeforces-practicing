#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
long long fact[1000005],md=1000003;
long long bigpow(long long a, long long b){
    long long ret = 1;
    while(b){
        if(b&1) ret = (ret*a)%md;
        b/=2, a = (a*a)%md;
    }
    return ret;
}
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    long long mn = 1<<20;
    for(int i=1; i<=n; i++){
        cin>>b[i];
        while(mn*a[i] > b[i]) mn/=2;
    }
    for(int i=1; i<=n; i++){
        b[i] -= mn*a[i];
    }

    long long int total_op=0, ways=1, sum = 0, mul = 1;
    while(mn>=1){
        for(int i=1; i<=n; i++){
            if(b[i]>=mn) sum += b[i]/mn, mul = (mul*fact[b[i]/mn])%md;
            b[i] %= mn;
        }
        total_op += sum+1;
        if(sum >= md) ways = 0;
        else          ways = ways * fact[sum] % md * bigpow(mul, md-2) % md;
        sum = 0, mul = 1;
        mn/=2;
    }

    cout<<total_op-1<<' '<<ways<<endl;
}

int main() {
    fact[0] = 1;
    for(int i=1; i<1000004; i++){
        fact[i] = (fact[i-1]*i)%md;
    }
    int t; cin >> t; while(t--){
        solve();
    }
    return 0;
}