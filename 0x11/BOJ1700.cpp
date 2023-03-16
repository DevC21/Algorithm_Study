#include<bits/stdc++.h>
using namespace std;

int MultiTab[105];
int arr[105];
int ans;
bool same = false;

//나중에 쓰는 도구들중 count를 하여 가장 적게 쓰는 기기를 뽑는다 -> 오답
//가장 적게 쓰는 기기를 뽑는것은 최소한으로 멀티탭을 뽑는것을 보장해주지 못한다.
//가장 나중에 쓰는 도구를 현재 멀티탭에서 빼내는 것이 핵심 -> 정답
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for(int i = 0; i < k; i++){
        cin >> arr[i];
    }


}