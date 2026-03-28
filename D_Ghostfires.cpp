#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<pair<int,int>>rgb(3);
    for(int i=0; i<3; i++){
        cin>>rgb[i].first;
        rgb[i].second=i;
    }
    sort(rgb.begin(), rgb.end());
    vector<int>s, col;
    col.push_back(rgb[1].second);
    col.push_back(rgb[2].second);
    col.push_back(rgb[0].second);
    int id = 0;
    while(rgb[0].first+rgb[1].first > rgb[2].first){
        s.push_back(col[id%3]), s.push_back(col[(id+1)%3]), s.push_back(col[(id+2)%3]);
        rgb[0].first--, rgb[1].first--, rgb[2].first--;
        id++;
    }
    reverse(s.begin(),s.end());
    while(rgb[2].first){
        rgb[2].first--;
        s.push_back(rgb[2].second);
        if(rgb[1].first){
            rgb[1].first--;
            s.push_back(rgb[1].second);
        }else break;
    }

    while(rgb[0].first){
        rgb[0].first--;
        s.push_back(rgb[0].second);
        if(rgb[2].first){
            rgb[2].first--;
            s.push_back(rgb[2].second);
        }else break;
    }

    
    for(int x : s){
        if(x==0) cout<<'R';
        else if(x==1) cout<<'G';
        else cout<<'B';
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