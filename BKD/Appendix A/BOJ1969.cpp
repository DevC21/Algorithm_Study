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
        // �� ���ڿ��� ���鼭 �� �ڸ��� ������ DNA�� �󵵸� ����Ѵ�.
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
            // Hamming Distance�� ���� ���� �������� 
            // �� �ڸ��� �ֺ��� ������ DNA�� �����ؾ��Ѵ�.
            if(maxfreq < freq){
                maxfreq = freq;
                dnacode = j;
            }
        }
        minhd += (n - maxfreq);
        // dnacode �ڵ��� ���� ���� ans�� DNA ���ڸ� �����ش�.
        // if-else���� DNA ���ڸ� �̸� ���ĺ������� ��ġ�ϸ�
        // �׻� ���������� ���� �ռ��� DNA ���ڿ��� �ȴ�.
        if(dnacode == A) ans += 'A';
        else if(dnacode == C) ans += 'C';
        else if(dnacode == G) ans += 'G';
        else if(dnacode == T) ans += 'T';
    }

    cout << ans << '\n' << minhd;
}