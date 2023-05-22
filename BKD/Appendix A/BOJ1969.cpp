#include<bits/stdc++.h>
using namespace std;

enum DNA{
    A,
    C,
    G,
    T
};

int minhd = 0;
string dna[1005];
int idx[51][4];
string ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        dna[i] = s;
    }

    for(int i = 0; i < n; i++){
        // 각 문자열을 돌면서 각 자리에 나오는 DNA의 빈도를 기록한다.
        for(int j = 0; j < m; j++){
            if(dna[i][j] == 'A') idx[j][A]++;
            else if(dna[i][j] == 'C') idx[j][C]++;
            else if(dna[i][j] == 'G') idx[j][G]++;
            else if(dna[i][j] == 'T') idx[j][T]++;
        }
    }

    for(int i = 0; i < m; i++){
        int dnacode = 0;
        int maxfreq = 0;
        for(int j = 0; j < 4; j++){
            int freq = idx[i][j];
            // Hamming Distance의 합이 가장 작으려면 
            // 각 자리의 최빈값을 가지는 DNA를 선택해야한다.
            if(maxfreq < freq){
                maxfreq = freq;
                dnacode = j;
            }
        }
        minhd += (n - maxfreq);
        // dnacode 코드의 값에 따라 ans에 DNA 문자를 더해준다.
        // if-else문의 DNA 문자를 미리 알파벳순으로 배치하면
        // 항상 사전순으로 가장 앞서는 DNA 문자열이 된다.
        if(dnacode == A) ans += 'A';
        else if(dnacode == C) ans += 'C';
        else if(dnacode == G) ans += 'G';
        else if(dnacode == T) ans += 'T';
    }

    cout << ans << '\n' << minhd;
}