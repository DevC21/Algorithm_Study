#include<bits/stdc++.h>
using namespace std;

int k;

void func(int n){
    if(n > 0)
        func(n-1);
    int underbar = n * 4;
    for(int i = 0; i < underbar; i++){
        cout << '_';
    }
    cout << "\"����Լ��� ������?\"" << '\n';;
    if(n == k){
        for(int i = 0; i < underbar; i++){
            cout << '_';
        }
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
        return;
    }
    for(int i = 0; i < underbar; i++){
        cout << '_';
    }
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';;
    for(int i = 0; i < underbar; i++){
        cout << '_';
    }
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';;
    for(int i = 0; i < underbar; i++){
        cout << '_';
    }
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';



}

void func2(int n){

    int underbar = n * 4;
    for(int i = 0; i < underbar; i++){
        cout << '_';
    }
    cout << "��� �亯�Ͽ���." << '\n';;
    if(n > 0)
        func2(n-1);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
    func(k);
    func2(k);
}