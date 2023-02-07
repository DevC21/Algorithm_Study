#include<bits/stdc++.h>
using namespace std;

string str1[1005], str2[1005];

int freq1[26];
int freq2[26];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> str1[i] >> str2[i];
    }
    
    for(int i = 0; i < n; i++){
        fill(freq1, freq1+26, 0);
        fill(freq2, freq2+26, 0);
        for(char a = 'a'; a <= 'z'; a++){
            for(char c : str1[i]){
                if(a == c) freq1[a - 'a']++;
            }
            for(char c : str2[i]){
                if(a == c) freq2[a - 'a']++;
            }
        }
        for(int j = 0; j < 26; j++){
            if(freq1[j] != freq2[j]){
                cout << "Impossible" << '\n';
                break;
            }
            else if( j == 25 && freq1[25] == freq2[25]){
                cout << "Possible" << '\n';
            }
        }
    }
}