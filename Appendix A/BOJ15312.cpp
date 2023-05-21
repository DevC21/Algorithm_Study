#include<bits/stdc++.h>
using namespace std;

// 영어 대문자 알파벳 26개의 획수를 미리 저장
int c[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
string A, B;
vector<int> D;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    cin >> A >> B;

    // 입력 받은 문자에 'A' 값을 빼주면 
    // int c 배열에서 각 알파벳의 획수를 뽑아 올 수 있음
    for(int i = 0; i < A.size(); i++){
        // A, B의 같은 인덱스를 순서대로 D에 push_back하면
        // 한 글자씩 번갈아 써놓은 것 처럼 push됨
        D.push_back(c[A[i] - 'A']);
        D.push_back(c[B[i] - 'A']);
    }

    while(true){
        vector<int> tmp;
        // 한 행을 계산
        for (int i = 0; i < D.size() - 1; i++)
            tmp.push_back((D[i] + D[i + 1]) % 10);
        // D를 다음 행으로 바꿔줌
        D = tmp;
        // D의 원소가 2개만 남았다면 계산이 끝남
        if (D.size() == 2) {
            cout << D[0] << D[1] << '\n';
            return 0;
        }
    }
}