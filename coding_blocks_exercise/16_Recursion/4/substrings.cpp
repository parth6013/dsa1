#include<iostream>
using namespace std;

void substring(char *in,char*out,int i,int j){

    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    out[j]=in[i];

    // take the element
    substring(in,out, i+1,j+1);

  
    // don't take the element although j is something but it will be overwriiten as we have not move it
    substring(in,out,i+1,j);



}


int main(){

    char a[]="abc";
    char b[10];

    substring(a,b,0,0);

}