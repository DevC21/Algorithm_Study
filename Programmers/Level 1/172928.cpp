#include<bits/stdc++.h>
using namespace std;
#define Y first
#define X second

// result [0,0]
vector<string> park = {"OSO", "OOO", "OXO", "OOO"};
vector<string> routes = {"E 2", "S 3", "W 1"};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    pair<int, int> curPos;

    for(int i = 0; i < park.size(); i++){
        bool found = false;
        for(int j = 0; j < park[i].size(); j++){
            if(park[i][j] == 'S'){
                curPos.Y = i;
                curPos.X = j;
                found = true;
                break;
            }
        }
        if(found)
            break;
    }

    for(auto x : routes){
        bool wall = false;
        char dir = x[0];
        int dist = x[2] - '0';

        int idir;
        switch(dir){
            case 'E':
                idir = 0;
                break;
            case 'W':
                idir = 1;
                break;
            case 'N':
                idir = 2;
                break;
            case 'S':
                idir = 3;
                break;
        }
        int nx = curPos.X + dx[idir] * dist;
        int ny = curPos.Y + dy[idir] * dist;
        if(nx < 0 || nx >= park[0].size() || ny < 0 || ny >= park.size())
            continue;
        nx = curPos.X;
        ny = curPos.Y;
        for(int i = 0; i < dist; i++){
            nx += dx[idir];
            ny += dy[idir];
            if(park[ny][nx] == 'X'){
                wall = true;
                break;
            }        
        }

        if(wall)
            continue;
        else{
            curPos.X = nx;
            curPos.Y = ny;
        }
    }

    answer.push_back(curPos.Y);
    answer.push_back(curPos.X);
    return answer;
}

int main(){
    vector<int> ans = solution(park, routes);
    for(auto x : ans)
        cout << x << ' ';
}