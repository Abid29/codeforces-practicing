#include <bits/stdc++.h>
using namespace std;
int is[50005][26];
void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=0; j<26; j++) is[i][j] = 0;
    }

    for(int i=1; i<=k; i++){
        string s; cin>>s;
        for(int j=0; j<n; j++){
            is[j+1][s[j]-'a'] = 1;
        }
    }
    
    int root = sqrt(n+1), ans = n;
    for(int len=1; len<=root; len++){
        if(n%len!=0) continue;
        int val = len, done=0;
        for(int i=1; i<=val; i++){
            int valid=false;
            for(int k=0; k<26; k++){
                bool ind = true;
                for(int j=i; j<=n; j+=val){
                    ind&= is[j][k];
                }
                if(ind) {valid=true; break;}
            }
            if(!valid) {break;}
            done = i==val;
        }
        if(done) {ans = val; break;}

        val = n/len, done=0;
        for(int i=1; i<=val; i++){
            int valid=false;
            for(int k=0; k<26; k++){
                bool ind = true;
                for(int j=i; j<=n; j+=val){
                    ind&= is[j][k];
                }
                if(ind) {valid=true; break;}
            }
            if(!valid) {break;}
            done = i==val;
        }
        if(done) ans = min(ans, val);
    }
    string t="";
    for(int i=1; i<=ans; i++){
        for(int k=0; k<26; k++){
            bool ind = true;
            for(int j=i; j<=n; j+=ans){
                ind&= is[j][k];
            }
            if(ind) {t+=(char)('a'+k); break;}
        }
    }
    while(n) {cout<<t;n-=ans;}
    cout<<endl;
    
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}