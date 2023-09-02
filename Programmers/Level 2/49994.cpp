#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
set<string> vis;

int solution(string dirs) {
    int answer = 0;

    pair<int, int> cur = {0, 0};
    //������� ����ϱ� ���ؼ� XY/X'Y' <-> X'Y'/XY �� ��� �����Ѵ�.
    string prev = "";

    for(auto x : dirs){
        // prev�� XY ��ǥ ����
        prev = "";
        prev += to_string(cur.X);    
        prev += to_string(cur.Y);
        // ĳ���Ͱ� ��ǥ��鳻���� �ùٸ��� �������ٸ�
        // prev -> ������ ��ǥ�� ������ ��ǥ -> prev ����� ��� set�� �����Ѵ�.
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

    // ������� ����ϸ�
    // vis�� ���̴� 'ĳ���Ͱ� ó�� �ɾ ���� ����'�� 2�谡 �ǹǷ� 2�� �����ش�.
    answer = vis.size() / 2;

    return answer;
}