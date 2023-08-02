#include<bits/stdc++.h>
using namespace std;

int n;
int HP[3];
// 체력이 각각 x,y,z인 SCV 파괴하기 위한 공격 횟수의 최솟값
int D[61][61][61];

// 뮤탈리스크가 공격할 수 있는 모든 경우의 수
vector<vector<int>> attack = {
	{1,3,9},
	{1,9,3},
	{3,1,9},
	{3,9,1},
	{9,1,3},
	{9,3,1}
};

int func(int x, int y, int z){
    //모든 SCV가 파괴된 경우
    if (x == 0 && y == 0 && z == 0)
        return 0;

    //파괴된 SCV가 있을 경우 (HP가 음수로 떨어지면 0으로 반환)
    if (x < 0)return func(0, y, z);
    if (y < 0)return func(x, 0, z);
    if (z < 0)return func(x, y, 0);
        
    int &res = D[x][y][z];

	// 이미 구해둔 값이면 바로 리턴
	if (res != -1)
		return res;

    res = INT32_MAX;
    // 모든 경우의 수에 대해서 재귀
    for (int i = 0; i < 6; i++)
		res = min(res, func(x - attack[i][0], y - attack[i][1], z - attack[i][2]) + 1); 

	return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    memset(D, -1, sizeof(D));

    for(int i = 0; i < n; i++)
        cin >> HP[i];

    cout << func(HP[0], HP[1], HP[2]);
}