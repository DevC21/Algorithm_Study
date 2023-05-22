#include<bits/stdc++.h>
using namespace std;

int MultiTab[105];
int arr[105];
int freq[105];
int cur;
int ans;
bool same = false;

//���߿� ���� �������� count�� �Ͽ� ���� ���� ���� ��⸦ �̴´� -> ����
//���� ���� ���� ��⸦ �̴°��� �ּ������� ��Ƽ���� �̴°��� ���������� ���Ѵ�.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for(int i = 0; i < k; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        MultiTab[i] = arr[i];
    }

    for(int i = n; i < k; i++){
        same = false;
        for(int j = 0; j < n; j++){
            if(MultiTab[j] == arr[i]){
                same = true;
                break;
            }

            if(j == 0){
                cur = j;
                continue;
            }

            if(freq[MultiTab[cur]] > freq[MultiTab[j]]){
                cur = j;
            }
        }
        if(same == true)
            continue;
        
        MultiTab[cur] = arr[i];
        ans++;
    }

    std::cout << ans;
}