#include<bits/stdc++.h>
using namespace std;

int arr[1005][1005];

vector<int> solution(int n) {
    vector<int> answer;

    // 시작 지점
    int x = -1, y = 0;
    int num = 1;

    for (int i = 0; i < n; i++) {
        // 각 동작을 하는 횟수가 1씩 줄어든다
        for (int j = i; j < n; j++) {
            // 동작은 3개이므로 i를 3으로 나눈 나머지로 구분해 동작을 실행
            // 예) i = 0일때 % 3은 0이므로 배열의 세로 방향으로 움직이며 값을 채운다
            if (i % 3 == 0) 
                x++; // 세로
            // 예) i = 1일때 % 3은 1이므로 배열의 가로 방향으로 움직이며 값을 채운다                
            else if (i % 3 == 1)
                y++; // 가로
            // 예) 예) i = 1일때 % 3은 2이므로 배열의 왼쪽 위 대각선 방향으로 움직이며 값을 채운다                
            else if (i % 3 == 2) {
                // 왼쪽 위 대각선
                x--;
                y--;
            }
            arr[x][y] = num++;
        }
    }

    // 배열의 각 열은 n + 1개의 값만을 가진다.
    // 0번은 1개의 값 1번은 2개의 값 ········ n번은 n + 1개의 값
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);

    return answer;
}