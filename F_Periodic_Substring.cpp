#include <bits/stdc++.h>
using namespace std;
const int sz = 400005;
int cls[sz], scls[sz], ord[sz], aux[sz], cnt[sz], lcp[sz][20], slcp[sz][20], n, len;
string s;

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

void computeSuffixArrayAndLCP(){
    s += (char)0;
    for(int i=0; i<128; i++) cnt[i] = 0;
    for(char ch : s) cnt[ch]++;
    for(int i=1; i<128; i++) cnt[i] += cnt[i-1];       

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
        while(s[i+ len] == s[j+len]) len++;

        lcp[cls[i]][0] = len;
        len = max(0, len-1);
    }

    // sparse table construction
    // lcp[idx][bit] will give lcp of idx to idx+(1<<bit) 
    for(int bit=1; bit<20; bit++){
        for(int i=0; i+(1<<bit)-1<n; i++){
            lcp[i][bit] = min(lcp[i][bit-1], lcp[i+(1<<(bit-1))][bit-1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s; 
    computeSuffixArrayAndLCP();
    for(int i=0; i<n; i++){
        scls[i] = cls[i];
        for(int bit=0; bit<20; bit++) slcp[i][bit] = lcp[i][bit];
    }

    //reverse string's lcp computation
    s.pop_back();
    reverse(s.begin(), s.end());
    
    computeSuffixArrayAndLCP();

    long long int k=1,tot;
    for(len=1; len<n; len++){
        for(int j=0,id1,id2; j+k*len<n-1; j+=k*len){
            id1 = scls[j], id2 = scls[j+len];
            if(id1 > id2) swap(id1, id2);
            int bit = log2(id2-id1);
            tot = min(slcp[id1][bit], slcp[id2-(1<<bit)][bit]);

            id1 = cls[n-1-j-1], id2 = cls[n-1-j-1-len];
            if(id1 > id2) swap(id1, id2);
            bit = log2(id2-id1);
            tot += min(lcp[id1][bit], lcp[id2-(1<<bit)][bit]);
            k = max(k, (tot+len-1)/len); 
        }
    }
    cout<<k;
}