// m=using minimum no of coin
#include<iostream>
#include<algorithm>
using namespace std;


bool compare(int a ,int b){

    return a <= b;
}

int main(){
    // Indian Money Change
    int coins[] = {1,2,5,10,50,100,200,500,2000};
    int money =168;

    int s= (sizeof(coins)/sizeof(int));

    cout<<s<<endl;

    while(money>0){
        // it give first instance in array which is >= key bit we want <= hence w'll use comparator fn
        auto it = lower_bound(coins,coins + s,money,compare) ;

        int index = it - coins -1;

        cout<<coins[index]<<endl;

        money = money - coins[index];



    }






}