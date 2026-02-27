#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int md = 998244353;
long long a[200005],sorteda[200005],seg[800005];
unordered_map<long long,int>ord;
long long bigpow(long long a, long long b){
    long long ret = 1;
    while(b){
        if(b&1) ret = (ret*a)%md;
        b/=2, a = (a*a)%md;
    }
    return ret;
}

void update(int ind, int st, int nd, long long int val){
    if(st>ord[val] ||  nd<ord[val]) return;
    if(st==nd){
        seg[ind] = val; return;
    }

    int mid = (st+nd)/2;
    update(ind+ind, st, mid, val), update(ind+ind+1, mid+1, nd, val);
    seg[ind] = seg[ind+ind]+seg[ind+ind+1];
}

long long query(int ind, int st, int nd, int id){
    if(nd<=id) return seg[ind];
    if(st>id) return 0;

    int mid = (st+nd)/2;
    return query(ind+ind, st, mid, id) + query(ind+ind+1, mid+1, nd, id);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long int n, sum=0; cin>>n;
    vector<long long>vec(n);
    
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sorteda[i] = a[i];
    }
    sort(sorteda+1, sorteda+n+1);

    for(int i=1; i<=n; i++) ord[sorteda[i]] = i;    

    indexed_set st;
    cout<<"0\n";

    for(int i=1; i<4; i++){
        sum+=a[i];
        st.insert(ord[a[i]]);
        update(1,1,n,a[i]);
    }

    auto f = [&] (int k, int sz){
        long long fst = sorteda[*st.find_by_order(k-1)];

        long long ret = fst*k - query(1,1,n,ord[fst]);
        if(k+1<sz) {
            long long snd = sorteda[*st.find_by_order(k+1)];
            ret = max(ret,sum - query(1,1,n,ord[snd]) - snd*(sz-1 - (k+1)));
        }

        return ret;
    };
    
    for(int i=4; i<=n; i++){
        sum += a[i];
        st.insert(ord[a[i]]);
        update(1,1,n,a[i]);

        int l=1,r=i-2,mid;
        while(l+1<r){
            mid = (l+r)/2;

            if(f(mid,i) > f(mid+1,i)){
                l = mid+1;
            }else{
                r = mid;
            }
        }

        cout<< min(f(l, i),f(r,i)) %md * bigpow(i-2, md-2) % md<<endl;
    }
    
    return 0;
}