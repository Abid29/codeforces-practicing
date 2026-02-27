#include <bits/stdc++.h>
using namespace std;
int n, a[500005],suf[500005], pre[500005];
void solve() {
    int n; cin>>n;
    int nid;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }

    auto f = [&](){
        int nid;
        for(int i=1; i<=n; i++) if(a[i]==n) {nid=i; break;}

        int ret = 2;
        stack<int>stk;
        suf[n+1] = 0; stk.push(n+1);
        for(int i=n; i>nid; i--){
            while(stk.top()<a[i]) stk.pop(); 
            suf[a[i]] = suf[stk.top()] + 1;
            stk.push(a[i]);
        }
        while(!stk.empty()) stk.pop();
        pre[n] = 1, stk.push(n);

        for(int i=nid+1; i<=n; i++){
            if(a[i]>a[i-1] && i<n && a[i+1]<a[i]){
                while(stk.top()<a[i]) stk.pop();
                pre[a[i]] = pre[stk.top()] + 1;
                stk.push(a[i]);
                ret = max(ret, pre[a[i]]+suf[a[i]]-1);
            }
            else if(a[i]<a[i-1]){
                pre[a[i]] = pre[a[i-1]]+1; 
                ret = max(ret, pre[a[i]]+suf[a[i]]-1);
                stk.push(a[i]);
            }
        }

        return ret;
    };
    int mx = f();
    for(int i=1; i+i<=n; i++) swap(a[i], a[n+1-i]);
    mx = max(mx, f());

    cout<<n-mx<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}