#include <bits/stdc++.h>
using namespace std;
int a[200005],s[600005],prefix[600005];

void solve() {
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        s[i] = 1-a[i];
    }
    s[n] = 2;
    for(int i=0; i<n; i++) s[n+i+1] = a[i];
    for(int i=0; i<n; i++) s[n+n+i+1] = a[i];

    for (int i=1; i<=n+n+n; i++) {
        int j = prefix[i-1];

        while (j > 0 && s[i] != s[j]){
            j = prefix[j-1];
        }

        if (s[i] == s[j]) j++;
        prefix[i] = j;
    }

    int mx=-1,id=-1;
    for(int i=n+n+1; i<=n+n+n; i++){
        if(mx<prefix[i]) mx=prefix[i],id=i-prefix[i]+1;
    }

    for(int i=id; i<id+n; i++){
        cout<< (a[i-id]^s[i])<<' ';
    }

    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}