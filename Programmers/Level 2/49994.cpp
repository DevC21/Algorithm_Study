#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
set<string> vis;

int solution(string dirs) {
    int answer = 0;

    pair<int, int> cur = {0, 0};
    //양방향을 기록하기 위해서 XY/X'Y' <-> X'Y'/XY 를 모두 저장한다.
    string prev = "";

    for(auto x : dirs){
        // prev는 XY 좌표 저장
        prev = "";
        prev += to_string(cur.X);    
        prev += to_string(cur.Y);
        // 캐릭터가 좌표평면내에서 올바르게 움직였다면
        // prev -> 움직인 좌표와 움직인 좌표 -> prev 양방향 모두 set에 저장한다.
        if(x == 'U' && cur.Y < 5){
            cur.Y++;
            vis.insert(to_string(cur.X) + to_string(cur.Y) + prev);
            vis.insert(prev + to_string(cur.X) + to_string(cur.Y));
        }
        else if(x == 'D' && cur.Y > -5){
            cur.Y--;
            vis.insert(to_string(cur.X) + to_string(cur.Y) + prev);
            vis.insert(prev + to_string(cur.X) + to_string(cur.Y));
        }
        else if(x == 'R' && cur.X < 5){
            cur.X++;
            vis.insert(to_string(cur.X) + to_string(cur.Y) + prev);
            vis.insert(prev + to_string(cur.X) + to_string(cur.Y));            
        }
        else if(x == 'L' && cur.X > -5){
            cur.X--;
            vis.insert(to_string(cur.X) + to_string(cur.Y) + prev);
            vis.insert(prev + to_string(cur.X) + to_string(cur.Y));                     
        }
    }

    // 양방향을 기록하면
    // vis의 길이는 '캐릭터가 처음 걸어본 길의 길이'의 2배가 되므로 2로 나눠준다.
    answer = vis.size() / 2;

    return answer;
}