#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,k; cin>>n>>k;

    if(k&1){
        for(int i=0;  i<k; i++) cout<<n<<' ';
        cout<<endl;
        return;
    }

    long long cnt=0;
    vector<int>elements;
    for(int i=30; i>-1; i--){
        if((n>>i)&1){
            if(elements.size()<k) elements.push_back(n^(1<<i));
            else  elements.back()^=(1<<i);
            cnt++;
        }   
        else if(cnt>=2){
            int m = elements.size();
            m -= m&1;
            for(int j=0; j<m; j++) elements[j]|=(1<<i);
        }
    }
    for(int x : elements) cout<<x<<' ';
    
    k-=elements.size();
    while(k--)  cout<<n<<' ';
    cout<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}