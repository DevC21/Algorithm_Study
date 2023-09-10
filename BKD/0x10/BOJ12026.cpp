#include<bits/stdc++.h>
using namespace std;

int n;
string s;
int D[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    fill(D, D+n, 1'000'005);

    D[0] = 0;
    for(int i = 0; i < n; i++){
		if (s[i] == 'B') {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == 'O')
					D[j] = min(D[j], D[i] + (j - i)*(j - i));
			}
		}
		else if (s[i] == 'O') {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == 'J')
					D[j] = min(D[j], D[i] + (j - i)*(j - i));
			}
		}
		else {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == 'B')
					D[j] = min(D[j], D[i] + (j - i)*(j - i));
			}
		}
    }

    if(D[n - 1] != 1'000'005)
        cout << D[n - 1];
    else
        cout << -1;
}