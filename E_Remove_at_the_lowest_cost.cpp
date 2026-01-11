#include <bits/stdc++.h>
using namespace std;
int n,a[200005],c[200005],cost[200005];
vector<pair<int,int>>vec;
void solve() {
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>c[i];
    vec.resize(n);
    for(int i=1; i<=n; i++)    vec[i-1] = {c[i],i};

    sort(vec.begin(),vec.end());

    set<int>st;
    for(int i=0; i<n; i++) st.insert(i+1), cost[i+1]=0;

    long long totalcost = 0;
    for(auto it : vec){
        int i = it.second;
        auto iter =  st.lower_bound(i);
        if(iter==st.end()||*iter!=i) continue;
        while(iter!=st.begin() && a[*prev(iter)] <= a[i]){
            cost[*prev(iter)] = c[i], totalcost += c[i];
            st.erase(prev(iter));
        }

        while(next(iter)!=st.end() && a[*next(iter)] <= a[i]){
            cost[*next(iter)] = c[i], totalcost += c[i];
            st.erase(next(iter));
        }
        if(st.size()>1) totalcost += c[i], st.erase(iter);
        cost[i] = c[i];
    }
    cout<<totalcost;
    
    for(int i=1; i<=n; i++) st.insert(i);
    for(int i=1,p; i<=n; i++){
        cin>>p;
        auto iter = st.lower_bound(p);
        if(iter==st.end()||*iter!=p){
            cout<<' '<<totalcost; continue;
        }
        while(iter!=st.begin() && a[*prev(iter)] <= a[p]){
            totalcost -= cost[*prev(iter)];
            st.erase(prev(iter));
        }
        
        while(next(iter)!=st.end() && a[*next(iter)] <= a[p]){
            totalcost -= cost[(*next(iter))];
            st.erase(next(iter));
        }
        if(st.size()>1) totalcost -= cost[p],st.erase(iter);
        cout<<' '<<totalcost;
    }
    cout<<'\n';
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}