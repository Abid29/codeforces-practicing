#include <bits/stdc++.h>
using namespace std;
vector<int>g[200005],nodesofdep[200005];
int indofnode[200005];
void solve() {
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        g[i].clear(),nodesofdep[i].clear(); 
        indofnode[i] = -1;
    }  
    for(int i=1,u,v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>>operations;
    set<pair<int,int>>setofoperations;
    
    nodesofdep[1].push_back(1);
    setofoperations.insert({1,1});
    operations.push_back({1});
    indofnode[1] = 0;

    int depth = 1,taken;
    while(!nodesofdep[depth].empty()){
        vector<pair<int,int>>vp;
        for(int node : nodesofdep[depth]){
            taken = 0;
            for(int des : g[node]){
                if(indofnode[des]!=-1) continue;
                if(!taken) taken=1, vp.push_back({node,des});
                nodesofdep[depth+1].push_back(des);
            }
        }

        if(vp.size()==1){
            setofoperations.erase(setofoperations.find({depth,vp[0].first}));
            setofoperations.insert({depth+1, vp[0].first});
        }else if(!vp.empty()){
            vp.push_back(vp[0]);
            int sz = vp.size();
            for(int i=1; i<sz; i++){
                setofoperations.erase(setofoperations.find({depth, vp[i].first}));
                setofoperations.insert({depth+1, vp[i-1].second});
                indofnode[vp[i-1].second] = indofnode[vp[i].first];
                operations[indofnode[vp[i].first]].push_back(vp[i-1].second);
            }
        }

        for(int node : nodesofdep[depth+1]){
            if(indofnode[node]!=-1) continue;
            if(setofoperations.begin()->first<=depth){
                int prevnode = setofoperations.begin()->second;
                setofoperations.erase(setofoperations.begin());
                setofoperations.insert({depth+1, node});
                indofnode[node] = indofnode[prevnode];
                operations[indofnode[node]].push_back(node);
            }else{
                indofnode[node] = setofoperations.size();
                operations.push_back({node});
                setofoperations.insert({depth+1,node});
            }
        }
        depth++;
    }
    
    cout<<operations.size()<<endl;
    for(auto it : operations){
        cout<<it.size();
        for(int ele : it){
            cout<<' '<<ele;
        }
        cout<<'\n';
    }
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}