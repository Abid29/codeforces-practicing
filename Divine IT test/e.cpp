#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s; 
    cin>>n>>s;
    int a=0,b=0;
    for(char ch : s){
        if(ch=='A'){
            if(b) b--,a++;
            else  a++;
        }else{
            if(a) a--,b++;
            else  b++;
        }
    }
    cout<<a+b<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}