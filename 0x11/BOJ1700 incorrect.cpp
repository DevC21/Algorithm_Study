#include<bits/stdc++.h>
using namespace std;

int MultiTab[105];
int arr[105];
int freq[105];
int cur;
int ans;
bool same = false;

//나중에 쓰는 도구들중 count를 하여 가장 적게 쓰는 기기를 뽑는다 -> 오답
//가장 적게 쓰는 기기를 뽑는것은 최소한으로 멀티탭을 뽑는것을 보장해주지 못한다.
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