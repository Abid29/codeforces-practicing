#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k,m;
    cin>>n>>k>>m;

    string moves; cin>>moves;

    deque<pair<int,int>>snake;
    map<pair<int,int>,int>isSnake;

    queue<pair<int,int>>fp;
    for(int i=0,x,y; i<m; i++){
        cin>>x>>y;
        fp.push({x,y});
    }

    snake.push_back({1,1});
    isSnake[{1,1}] = 1;

    int l=1;
    pair<int,int> pos = {1,1};

    for(char move : moves){
        if(move == 'L') pos.second = pos.second == 1 ? n : pos.second-1;
        else if(move == 'R') pos.second = pos.second == n ? 1 : pos.second+1;
        else if(move == 'D') pos.first = pos.first == n ? 1 : pos.first+1;
        else pos.first = pos.first == 1 ? n : pos.first-1;

        if(isSnake[pos] && (pos!=snake.back() || pos==fp.back())){
            cout<<"DEAD\n"; return 0;
        }
        if(!fp.empty() && fp.front() == pos){
            fp.pop();
            snake.push_front(pos);
            isSnake[pos]=1;
            l++;
        }else{
            isSnake[snake.back()] = 0;
            snake.pop_back();
            snake.push_front(pos);
            isSnake[pos] = 1;
        }
    }
    
    cout<<"ALIVE "<<l<<endl;
}