#include<bits/stdc++.h>
using namespace std;

int arr[1001];
int D[1001];
int pre[1001];
stack<int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int maxlen = 1;
    int maxlen_idx = -1;
    fill(D, D+n, 1);
    fill(pre, pre+n, -1);

    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && D[i] <= D[j]){
                D[i] = D[j] + 1;
                pre[i] = j;
            }
        }

		if (maxlen < D[i]) {
			maxlen = D[i];
			maxlen_idx  = i;
		}
    }

    while(pre[maxlen_idx] != -1){
        ans.push(arr[maxlen_idx]);
        maxlen_idx = pre[maxlen_idx];
    }
    ans.push(arr[maxlen_idx]);

    cout << maxlen << '\n';

    for(int i = 0; i < maxlen; i++){
        int num = ans.top();
        ans.pop();
        cout << num << ' ';
    }
        
}