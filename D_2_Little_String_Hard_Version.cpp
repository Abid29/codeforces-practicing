#include <bits/stdc++.h>
using namespace std;
int md = 1e9+7;
void solve() {
    int n,c; cin>>n>>c;
    string s; cin>>s;
    if(s[0]=='0'||s.back()=='0'){
        cout<<"-1\n"; return;
    }
    s[0] = s[n-1] = '1';
    if(n>2 && s[1]=='?') s[1] = '0';
    s = "7" + s;

    long long ans = 1;
    vector<int>vec;
    for(int i=2; i<=n; i++){
        if(s[i]=='1'||((s[i]=='?') && (i&1))){
            ans = (ans+ans)%md;
            c /= __gcd(c, 2);
        }else if(s[i]=='0'){
            ans = (ans*(i-1))%md;
            c /= __gcd(c, i-1);
        }else{
            vec.push_back(i-1);
        }
    }
    if(c==1) {cout<<"-1\n"; return;}
    sort(vec.begin(), vec.end());
    while(c>2 && !vec.empty()){
        vec.pop_back();
        ans = (ans+ans)%md;
        c /= __gcd(c, 2);
    }
    for(int x : vec){
        ans = (ans*x)%md;
    }
    cout<<ans<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}