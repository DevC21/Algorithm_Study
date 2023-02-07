#include<bits/stdc++.h>
using namespace std;

int freq1[26];
int freq2[26];
int cnt;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;


    cin >> s1 >> s2;

    for(char a = 'a'; a <= 'z'; a++){
        for(char c : s1)
            if( c == a ) freq1[a - 'a']++;
        for(char c : s2)
            if( c == a ) freq2[a - 'a']++;
    }

    for(char a = 'a'; a <= 'z'; a++){
        if( freq1[a - 'a'] > freq2[a - 'a'] ){
            cnt += freq1[a - 'a'] - freq2[a - 'a'];
        }
        else if( freq1[a - 'a'] < freq2[a - 'a'] ){
            cnt += freq2[a - 'a'] - freq1[a - 'a'];
        }
    }

    cout << cnt;
}