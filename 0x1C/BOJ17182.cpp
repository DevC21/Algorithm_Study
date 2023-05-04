/*
- 각 행성간의 거리를 입력 받은 후, 
  플로이드 와샬 알고리즘을 사용하여 각 행성간 최단시간를 구한다
- 시작하는 행성의 vis[]값을 true로 바꾼후, DFS()를 수행한다
- DFS(int idx, int time, int cnt) 함수는 
  각각 현재 방문한 행성의 번호, 지금까지 걸린 시간, 방문한 행성의 수를 매개변수로 받는다
- 지금까지 걸린 시간이 이미 구한 최단시간인 ans보다 크다면 return해서 불필요한 연산을 줄인다.
- 모든 행성을 방문했다면, 지금까지 걸린 시간과 ans를 비교하여 작은 값을 ans에 저장
- 아직 방문하지 않은 행성이라면 방문처리후, DFS를 수행한다.
- 간선에 음수가 없기 때문에 최단경로는 중복방문하지 않은 경로가 된다
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
