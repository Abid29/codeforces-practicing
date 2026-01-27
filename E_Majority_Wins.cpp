#include <bits/stdc++.h>
using namespace std;
int suf[500005];
void solve() {
    int n; string s;
    cin>>n>>s;
    int sum = 0;
    for(char ch : s) sum += ch=='0' ? 1 : -1;

    //impossible
    if(sum == n){ cout<<"-1\n"; return;}

    //0
    if(n==1){cout<<"0\n"; return;}

    //n
    if(sum <= 0){ cout<<n<<endl; return;}

    //n+1
    if(sum==1 || s[0]=='1' || s[n-1]=='1'){ cout<<n+1<<endl; return;}

    suf[n+1] = 0;
    int cur = 0;
    for(int i=n; i>0; i--){
        cur += s[i-1]=='0' ? 1:-1;
        if(cur<0) cur = 0;
        else if(cur>sum){ cout<<n+1<<endl; return;}
        suf[i] = max(suf[i+1],cur);
    }

    //n+2
    if(sum==2 || s[1]=='1'||s[n-2]=='1'){ cout<<n+2<<endl; return;}
    cur=0;
    for(int i=1; i<=n; i++){
        cur += s[i-1]=='0' ? 1:-1;
        if(cur<0) cur = 0;
        else if(cur + suf[i+1] > sum+1){ cout<<n+2<<endl; return;}
    }

    //n+3
    cout<<n+3<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}