#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string pattern;
    cin >> n >> pattern;
    int staridx = pattern.find('*');
    string front = pattern.substr(0, staridx);
    string rear = pattern.substr(staridx + 1, pattern.size() - staridx);

    while(n--){
        string file;
        cin >> file;

        if(front.size() + rear.size() > file.size()){
            cout << "NE" << '\n';
            continue;
        }

        // file.find(front)�� ����� 0��° ��ġ�� ��ȯ���� ������ ���ϰ� ��ġ���� ����
        if(file.find(front) != 0){
            cout << "NE" << '\n';
            continue;
        }

        // file.find(rear)�� �ڿ������� rear�� ���� ��ŭ �� ��ġ���� 
        // ���� ���� �� ã�� ���ϸ� ���ϰ� ��ġ���� ����
        if((file.find(rear, file.size() - rear.size()) == -1)){
            cout << "NE" << '\n';
            continue;
        }
        
        cout << "DA" << '\n';
    }
}