#include<iostream>
#include<string>
using namespace std;

void substrings(string s,int n){

    for(int i=0;i< (1<<n);i++){

        int j=i;

        if(j==0){
            cout<<" "<<endl;
        }
            int p=0;
        // cout<<j<<"#"<<endl;    
        while(j>0){
            if((j&1)==1){
                // cout<<p<<"@"<<endl;
                cout<<s[p];
            }
            p++;
            j=j>>1;
        }
        cout<<endl;
        p=0;

    }

}


int main(){

    string s1="abc";

    int n= s1.length(); 

    substrings(s1,n);
    // cout<<s1[1];

}