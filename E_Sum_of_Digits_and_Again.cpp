#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin>>s;
    if(s.size()==1){
        cout<<s<<endl; return;
    }
    vector<int>cnt(10);
    for(char ch : s) cnt[ch-'0']++;
    int sum = 0;
    for(int i=0; i<10; i++) sum += cnt[i]*i;
    
    for(int val=0; val<=sum; val++){
        vector<int>can(10);
        int value = val;
        while(value){
            if(value<10){can[value]++; break;}
            int res = 0;
            while(value){
                can[value%10]++;
                res += value%10;
                value/=10;
            }
            value = res;
        }

        int ind = 0;
        value = val;
        for(int i=0; i<10; i++){
            if(cnt[i] < can[i]) {ind=1;break;}
            value -= i*(cnt[i]-can[i]);
        }
        if(!value && !ind){
            for(int i=9; i>=0; i--){
                value = cnt[i]-can[i];
                while(value--) cout<<i;
            }
            value = val;
            while(value){
                cout<<value;
                if(value<10) break;
                int res = 0;
                while(value){
                    res += value%10;
                    value/=10;
                }
                value = res;
            }
            break;
        }
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}