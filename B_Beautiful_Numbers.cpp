#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin>>n;
    multiset<int>st;
    while(n>=10){
        if(n%10) st.insert(n%10); 
        n/=10;
    }
    int ans = st.size(), ans2=1+ans;
    int val=n, val2=1;
    for(int x : st){
        if(x+val <=9) ans--, val+=x;
        if(x+val2 <=9) ans2--, val2+=x;
    }
    
    cout<<min(ans,ans2)<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}