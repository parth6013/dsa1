#include<iostream>
using namespace std;
// i for rows ,j for column , and because elements are same that of column number thats why we using j
int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1-i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}