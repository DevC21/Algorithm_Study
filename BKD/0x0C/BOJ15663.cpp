#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec;
int arr[8];
bool isused[8];

void func(int cur){
    if(cur == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++){
        if(!isused[i]){
/*
    i >= 1 && vec[i - 1] == vec[i]은 바로 이전 항목과 현재 항목의 숫자가 일치하는 경우를 의미한다.
    같은 숫자는 1번만 탐색하기 위함이다.
    예제 입력
    4 2
    9 7 9 1 에서 1 9, 7 9가 중복으로 나오는걸 방지한다.

    !isused[i - 1]는 이전 항목의 숫자가 전 단계에쓰였는지 확인한다.
    isused[i - 1]는 전 단계에서 쓰였는지를 의미하므로 
    이것이 true라면 이전 항목을 이번 단계에서 사용한 것이 아니므로 이 항목은 사용가능하다.
    예제 입력
    4 2
    9 7 9 1 에서 9 9를 출력할 수 있게
    같은 숫자라도 이전 단계에서 사용했다면 또 사용할 수 있게 한다.
*/
            if(i >= 1 && vec[i - 1] == vec[i] && !isused[i - 1])
                continue;
            isused[i] = 1;
            arr[cur] = vec[i];
            func(cur + 1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    func(0);
}