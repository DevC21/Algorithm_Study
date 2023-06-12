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
    i >= 1 && vec[i - 1] == vec[i]�� �ٷ� ���� �׸�� ���� �׸��� ���ڰ� ��ġ�ϴ� ��츦 �ǹ��Ѵ�.
    ���� ���ڴ� 1���� Ž���ϱ� �����̴�.
    ���� �Է�
    4 2
    9 7 9 1 ���� 1 9, 7 9�� �ߺ����� �����°� �����Ѵ�.

    !isused[i - 1]�� ���� �׸��� ���ڰ� �� �ܰ迡�������� Ȯ���Ѵ�.
    isused[i - 1]�� �� �ܰ迡�� ���������� �ǹ��ϹǷ� 
    �̰��� true��� ���� �׸��� �̹� �ܰ迡�� ����� ���� �ƴϹǷ� �� �׸��� ��밡���ϴ�.
    ���� �Է�
    4 2
    9 7 9 1 ���� 9 9�� ����� �� �ְ�
    ���� ���ڶ� ���� �ܰ迡�� ����ߴٸ� �� ����� �� �ְ� �Ѵ�.
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