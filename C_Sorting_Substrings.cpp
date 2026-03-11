#include <bits/stdc++.h>
using namespace std;
const int sz = 400005;
int cls[sz], ord[sz], aux[sz], cnt[sz], lcp[sz][20],n, len;

// ord[i] - suffix array - starting of ith smallest suffix
void countingSort(){
    for(int i=0; i<n; i++) cnt[i] = 0;
    for(int i=0; i<n; i++) cnt[cls[i]]++;
    for(int i=1; i<n; i++) cnt[i] += cnt[i-1];

    for(int i=n-1; i>=0; i--){
        int idx = (ord[i] - len + n)%n;
        aux[--cnt[cls[idx]]] = idx;
    }

    for(int i=0; i<n; i++) ord[i] = aux[i];
}

// cls[i] - how many suffix from 1....i-1 are smaller than suffix i 
void updateClass(){
    aux[ord[0]] = 0;
    for(int i=1; i<n; i++){
        aux[ord[i]] = aux[ord[i-1]] + (cls[ord[i]]!=cls[ord[i-1]] || cls[(ord[i]+len)%n]!=cls[(ord[i-1]+len)%n]);
    }

    for(int i=0; i<n; i++) cls[i] = aux[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin>>s; s += (char)32;

    for(char ch : s) cnt[ch]++;
    for(int i=33; i<128; i++) cnt[i] += cnt[i-1];

    n = s.size();
    for(int i=0; i<n; i++){
        ord[--cnt[s[i]]] = i;
    }

    cls[ord[0]] = 0;
    for(int i=1;  i<n; i++){
        cls[ord[i]] = cls[ord[i-1]] + (s[ord[i]]!=s[ord[i-1]]);
    }

    len = 1; 
    while(len < n){
        countingSort();
        updateClass();
        len += len;
    }

    
    // lcp array construction : Kasai's Algorithm
    len = 0;
    for(int i=0; i<n; i++){
        if(cls[i]==n-1) {len=0; continue;}

        int j = ord[cls[i]+1];
        while(s[i+len] == s[j+len]) len++;

        lcp[cls[i]][0] = len;
        len = max(0, len-1);
    }

    //sparse table construction
    // lcp[idx][bit] will give lcp of idx to idx+(1<<bit)
    for(int bit=1; bit<20; bit++){
        for(int i=0; i+(1<<bit)-1<n; i++){
            lcp[i][bit] = min(lcp[i][bit-1], lcp[i+(1<<(bit-1))][bit-1]);
        }
    }

    int m; cin>>m;
    vector<pair<int,int>>vec(m);
    for(int i=0; i<m; i++) {
        cin>>vec[i].first>>vec[i].second;
        vec[i].first--, vec[i].second--;
    }

    sort(vec.begin(), vec.end(), [&](pair<int,int> a, pair<int,int> b) -> bool {
        if(a.first == b.first) return a.second<b.second;
        int ida = cls[a.first], idb = cls[b.first];

        bool swapped = false;
        if(ida > idb) {swap(ida,idb), swap(a, b), swapped = true; }

        int lena = a.second-a.first+1, lenb = b.second-b.first+1;

        // ida to idb  
        // int mn = n; 
        // for(int bit=19; bit>=0; bit--) if(ida+(1<<bit)<=idb) {mn = min(mn, lcp[ida][bit]), ida += (1<<bit);}

        //nlog^2n to nlogn 
        int bit = floor(log2(idb-ida+0.9));
        int mn = min(lcp[ida][bit], lcp[idb-(1<<bit)][bit]);

        if(mn >= min(lena,lenb)) return ((lena < lenb || (lena==lenb && a.first < b.first)) ^ swapped);
        else return ((s[a.first+mn] < s[b.first+mn]) ^ swapped); 
    });
  
    for(auto it : vec) cout<<it.first+1<<' '<<it.second+1<<'\n';
}