#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s,t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> cnt(26, 0);
    for(char c : t) cnt[c - 'a']++;
    for(char c : s) {
        if(cnt[c - 'a'] > 0) {
            cnt[c- 'a']--;
        }else{
            cout<<"Impossible\n";
            return;
        }
    }
    string ans = "";
    int i,j;
    for(i = 0,j=0; i < 26 && j<n;) {
        if(s[j]-'a' <= i){
            ans += s[j++];
        }else{
            while(cnt[i] > 0){
                ans += (char)(i + 'a');
                cnt[i]--;
            }
            i++;
        }
    }
    while(i<26){
        while(cnt[i] > 0){
            ans += (char)(i + 'a');
            cnt[i]--;
        }
        i++;
    }
    while(j < n){
        ans += s[j++];
    }
    cout<<ans<<"\n";
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}