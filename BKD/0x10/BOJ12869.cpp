#include<bits/stdc++.h>
using namespace std;

int n;
int HP[3];
// ü���� ���� x,y,z�� SCV �ı��ϱ� ���� ���� Ƚ���� �ּڰ�
int D[61][61][61];

// ��Ż����ũ�� ������ �� �ִ� ��� ����� ��
vector<vector<int>> attack = {
	{1,3,9},
	{1,9,3},
	{3,1,9},
	{3,9,1},
	{9,1,3},
	{9,3,1}
};

int func(int x, int y, int z){
    //��� SCV�� �ı��� ���
    if (x == 0 && y == 0 && z == 0)
        return 0;

    //�ı��� SCV�� ���� ��� (HP�� ������ �������� 0���� ��ȯ)
    if (x < 0)return func(0, y, z);
    if (y < 0)return func(x, 0, z);
    if (z < 0)return func(x, y, 0);
        
    int &res = D[x][y][z];

	// �̹� ���ص� ���̸� �ٷ� ����
	if (res != -1)
		return res;

    res = INT32_MAX;
    // ��� ����� ���� ���ؼ� ���
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