/*
- �� �༺���� �Ÿ��� �Է� ���� ��, 
  �÷��̵� �ͼ� �˰����� ����Ͽ� �� �༺�� �ִܽð��� ���Ѵ�
- �����ϴ� �༺�� vis[]���� true�� �ٲ���, DFS()�� �����Ѵ�
- DFS(int idx, int time, int cnt) �Լ��� 
  ���� ���� �湮�� �༺�� ��ȣ, ���ݱ��� �ɸ� �ð�, �湮�� �༺�� ���� �Ű������� �޴´�
- ���ݱ��� �ɸ� �ð��� �̹� ���� �ִܽð��� ans���� ũ�ٸ� return�ؼ� ���ʿ��� ������ ���δ�.
- ��� �༺�� �湮�ߴٸ�, ���ݱ��� �ɸ� �ð��� ans�� ���Ͽ� ���� ���� ans�� ����
- ���� �湮���� ���� �༺�̶�� �湮ó����, DFS�� �����Ѵ�.
- ������ ������ ���� ������ �ִܰ�δ� �ߺ��湮���� ���� ��ΰ� �ȴ�
*/
#include<bits/stdc++.h>
using namespace std;

int n, k;
int INF = INT32_MAX / 2;
int ans = INF;
int D[11][11];
bool vis[11];

void dfs(int idx, int time, int cnt) {
	if (ans < time) return;
	if (cnt == n) {
		ans = min(ans, time);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		dfs(i, time + D[idx][i], cnt + 1);
		vis[i] = false;
	}
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vis[k] = true;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> D[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if(D[j][k] > D[j][i] + D[i][k])
                    D[j][k] = D[j][i] + D[i][k];

    dfs(k, 0, 1);

    cout << ans;
}
