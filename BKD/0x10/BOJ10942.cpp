#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[2005];
int D[2005][2005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    for(int i = 1; i <= n; i++){
        D[i][i] = 1;
        if(arr[i - 1] == arr[i])
            D[i - 1][i] = 1;
    }
        
    // 위 구문에서 이미 길이가 1, 2인 경우를 계산했으므로 
    // 길이가 j + i = 3 경우부터 계산한다.
    for(int i = 2; i < n; i++){
        for(int j = 1; j <= n - i; j++){
            int s = j;
            int e = j + i;
            // 양쪽 끝(s, e)이 같고 그 사이에 있는 숫자
            // 즉 s + 1번째 숫자와 e - 1번째 숫자가 팰린드롬이라면 
            // D[s][e]는 팰린드롬이다.
            if(arr[s] == arr[e] && D[s + 1][e - 1]) 
                D[s][e] = 1;
        }
    }

    cin >> m;
    while(m--){
        int s, e;
        cin >> s >> e;
        cout << D[s][e] << '\n';
    }
}