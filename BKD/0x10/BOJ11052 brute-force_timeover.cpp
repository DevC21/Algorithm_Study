#include<bits/stdc++.h>
using namespace std;

int n, tot, cards;
int maxpriceidx;
float maxprice;
float P[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for(int i = 1; i <= n; i++){
        float num;
        cin >> num;
        P[i] = num / i;
        if(maxprice < P[i]){
            maxprice = P[i];
            maxpriceidx = i;
        }
    }

    cards += maxpriceidx * (n / maxpriceidx);
    tot += maxprice * maxpriceidx * (n / maxpriceidx);
    P[maxpriceidx] = 0;

    maxprice = 0;
    maxpriceidx = 0;
    while(cards != n){
        if(cards + 1 == n){
            cards++;
            tot += P[1];
            break;
        }
        else{
            for(int i = 1; i <= n; i++){
                if(i + cards <= n){
                    if(maxprice < P[i]){
                        maxprice = P[i];
                        maxpriceidx = i;
                    }
                }
            }
        }

        cards += maxpriceidx * ((n - cards) / maxpriceidx);
        tot += maxprice * maxpriceidx * ((n - cards) / maxpriceidx);
        P[maxpriceidx] = 0;
    }

    cout << tot;
}