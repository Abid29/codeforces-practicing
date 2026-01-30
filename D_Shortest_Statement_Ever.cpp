#include <bits/stdc++.h>
using namespace std;
long long mx,p,q,x,y;
void check(int a, int b){
    if(mx>abs(x-a)+abs(y-b)){
        mx = abs(x-a)+abs(y-b);
        p=a, q=b;
    }
}
void cal(int bit, int pp, int qq){
    if(bit==-1){
        check(pp,qq); return;
    }

    if((x&(1<<bit))&&(y&(1<<bit))){
        check(pp|((1<<bit)-1), qq|(1<<bit));
        check(pp|(1<<bit), qq|((1<<bit)-1));
    }
    else if(x&(1<<bit)){
        check(pp|((1<<bit)-1), qq|(1<<bit));
        cal(bit-1,pp|(1<<bit), qq);
    }
    else if(y&(1<<bit)){
        check(pp|(1<<bit), qq|((1<<bit)-1));
        cal(bit-1,pp, qq|(1<<bit));
    }
    else{
        check(x, qq|(1<<bit));
        check(pp|(1<<bit), y);
        cal(bit-1,pp,qq);
    }

}
void solve() {
    cin>>x>>y;
    mx = x+y;
    p=q=0;
    cal(30,0,0);
    cout<<p<<' '<<q<<endl;
}

int main() {
    int t; cin >> t; while(t--) {
        solve();
    }
    return 0;
}