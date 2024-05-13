
#include<iostream>
using namespace std;

char words[][10]={"zero","one","two","three","four","five","six","seven","eigth","nine"};

void printspelling(int n){

    // base case
    if(n==0){
        return;
    }
    // rec case first print the spellings of (204)
    printspelling(n/10);
    int digit=n%10;
    cout<<words[digit]<<" ";
    return;


}

int main(){

printspelling(3783);


return 0;

}