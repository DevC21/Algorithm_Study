#include<bits/stdc++.h>
using namespace std;

// 그림 출처 : https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence

string a, b;
int ans;
int D[4005][4005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    a = "0" + a;
    b = "0" + b;

    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b.size(); j++){
            if(a[i] == b[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            ans = max(D[i][j], ans);
        }
    }

    cout << ans;
}