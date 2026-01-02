#include <bits/stdc++.h>
using namespace std;
long long c[62],md=998244353,suf[62],fact[600005],invfact[600005],twop[600005];
long long ncx(int n, int r){
    long long ret = fact[n];
    ret = (fact[n] * ((invfact[r]*invfact[n-r])%md))%md;
    return ret;
}

long long inv(long long a){
    long long ret = 1;
    int b = md-2;
    while(b){
        if(b&1) ret = (ret*a)%md;
        b/=2, a = (a*a)%md;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    for(int i=0,x; i<n; i++){
        cin>>x;
        c[x]++;
    }
    fact[0] = twop[0] = 1;
    for(int i=1; i<=n+m; i++){
        twop[i] = (twop[i-1]+twop[i-1])%md;
        fact[i] = (fact[i-1]*i)%md;
    }
    invfact[n+m] = inv(fact[n+m]);
    for(int i=n+m-1; i>-1; i--){
        invfact[i] = (invfact[i+1]*(i+1))%md;
    }

    long long type,x;
    while(m--){
        cin>>type>>x;
        if(type==1)      c[x]++;
        else if(type==2) c[x]--;
        else{
            long long ans = 0,A=1,B,C;
            suf[0] = c[0];
            for(int i=1; i<=60; i++) suf[i] = suf[i-1]+c[i];
            for(int bit = 60, pos=60, cnt=0; bit>=0; bit--){
                if(!((x>>bit)&1)){
                    C = twop[suf[pos-1]];
                    B = twop[c[pos]];
                    for(int i=0; i<=cnt; i++){
                        B =  (B+md-ncx(c[pos],i))%md;
                    }
                    ans = (ans+((A*B)%md)*C)%md; 
                    A = (A*ncx(c[pos],cnt))%md;
                    pos--,cnt=0;  
                }else{
                    if(c[pos]<=cnt) break;
                    else            cnt++;  
                    x ^= (long long)1<<bit;
                    if(!x){
                        C = twop[suf[pos-1]];
                        B = twop[c[pos]];
                        for(int i=0; i<cnt; i++){
                            B =  (B+md-ncx(c[pos],i))%md;
                        }
                        ans = (ans+((A*B)%md)*C)%md;
                        break;
                    }  
                }
            } 
            cout<<ans<<endl;
        }
    }
}