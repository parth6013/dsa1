#include<iostream>
#include<cstring>
using namespace std;

void char_delete(char a[]){
    int j;
    j=0;
    char b[1000];
    for(int i=0;i<strlen(a);i++){
        if(a[i]!=a[i-1]){
            b[j]=a[i];
            j=j+1;
        }
    
    }
    cout<<b;
}

int main(){

    char a[1000];
    cin>>a;
    cout<<a<<endl;
    char_delete(a);

}
