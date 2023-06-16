#include<bits/stdc++.h>
using namespace std;

int l, c;
char ch[15];
char arr[15];
bool isused[15];

void make_password(int cur){
    if(cur == l){
        int v = 0;
        int c = 0;
        for(int i = 0; i < l; i++){
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') 
                v++;
            else
                c++;
        }
        if(v >= 1 && c >= 2){
            for(int i = 0; i < l; i++){
                cout << arr[i];
            }
            cout << '\n';
        }
        return;
    }

    for(int i = 0; i < c; i++){
        if(!isused[i]){
            if(cur > 0){
                if(arr[cur - 1] > ch[i])
                    continue;
            }
            isused[i] = 1;
            arr[cur] = ch[i];
            make_password(cur + 1);
            isused[i] = 0;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;

    for(int i = 0; i < c; i++){
        cin >> ch[i];
    }

    sort(ch, ch+c);

    make_password(0);
}