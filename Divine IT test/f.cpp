#include <bits/stdc++.h>
using namespace std;
long long sum[10000];
void solve() {
    int a,b;
    cin>>a>>b;
    long long int ans = 0;
    if(a+20000>=b){
        for(int i=a; i<=b; i++){
            int j=i,val,tot=0;
            while(j){
                int val = j%10;
                j/=10;
                if(val&1) tot+=val;
                else      tot+=val+val;
            }
            ans += tot%10;
        }
        cout<<ans<<endl;
        return;
    }

    for(; a%10000!=0; a++){
        int j=a,val,tot=0;
        while(j){
            int val = j%10;
            j/=10;
            if(val&1) tot+=val;
            else      tot+=val+val;
        }
        ans += tot%10;
    }
    a/=10000;
    for(; (b+1)%10000!=0; b--){
        int j=b,val,tot=0;
        while(j){
            int val = j%10;
            j/=10;
            if(val&1) tot+=val;
            else      tot+=val+val;
        }
        ans += tot%10;
    }
    b/=10000;
    for(int i=a; i<=b; i++){
        int j=i,val,tot=0;
        while(j){
            int val = j%10;
            j/=10;
            if(val&1) tot+=val;
            else      tot+=val+val;
        }
        ans += sum[tot%10];
    }
    cout<<ans<<endl;
}

int main() {
    for(int idx=0; idx<100000; idx+=10000){
        for(int i=idx; i<idx+10000; i++){
            int j=i,val,tot=0;
            while(j){
                int val = j%10;
                j/=10;
                if(val&1) tot+=val;
                else      tot+=val+val;
            }
            sum[idx/10000] += tot%10;
        }
    }

    
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}