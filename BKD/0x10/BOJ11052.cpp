#include<bits/stdc++.h>
using namespace std;

/*
D[2]는 P[2]와 D[1]+D[1]중 큰 값이 될 것이고,

D[3]은 P[3]와 D[2]+D[1]중 큰 값이 될 것이고,

D[4]는 P[4]와 D[3]+D[1], D[2]+D[2]중 큰 값이 될 것이다.

D에 들어있는 값은 항상 최대값이기 때문에,

D[a] + D[b]도 항상 최대값이 나와야 하며,

이를 통해 D[i] = D[a] + D[i - a]으로 D를 구할 수 있다.

점화식은 D[i] = max(D[i - j] + P[j], D[i])
*/

int n;
// D[i] = i개의 카드를 갖기 위해 지불할 돈의 최댓값
int D[1001];
int P[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> P[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            D[i] = max(D[i - j] + P[j], D[i]);
        }
    }

    cout << D[n];
}