#include<iostream>
using namespace std;

void move(int n,char src,char helper,char dest){

    // base case
    if(n==0){
        return;
    }
    // rec case
    // move n-1 disk from src to helper
    move(n-1,src,dest,helper);
    cout<<"Shift disk : "<<n<<"from "<<src<<" to "<<dest<<endl;
    move(n-1,helper ,src,dest);


}


int main(){





}