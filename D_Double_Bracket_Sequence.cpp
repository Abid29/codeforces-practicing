#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s, newS="";
    cin>>n>>s;
    int order=0;
    vector<int>openR, openS;
    set<pair<int,int>>st;
    for(char ch : s){
        if(ch=='('){
            openR.push_back(order);
            st.insert({order++, 1});
        }
        else if(ch==')'){
            if(!openR.empty()){
                st.erase(st.find({openR.back(), 1}));
                openR.pop_back();
            }
            else{
                st.insert({order++, 3});
            }
        }
        else if(ch=='['){
            openS.push_back(order);
            st.insert({order++, 2});
        }else{ 
            if(!openS.empty()){
                st.erase(st.find({openS.back(), 2}));
                openS.pop_back();
            }
            else{
                st.insert({order++, 4});
            }
        }
    }

    for(auto & it : st){
        if(it.second == 1) newS += '(';
        else if(it.second==2) newS += '[';
        else if(it.second==3) newS += ')';
        else newS += ']';
    }
    
    int opening = 0, id=0;
    n=newS.size();
    
    while(id<n && newS[id]!='(' && newS[id]!='[') id++;
    while(id<n){
        if(newS[id]==')'||newS[id]==']') {cout<<n/2<<endl; return;}
        else opening++;
        id++;
    }
    cout<<n/2+(opening&1)<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}