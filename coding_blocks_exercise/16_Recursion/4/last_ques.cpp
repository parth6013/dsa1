#include<iostream>
using namespace std;

void generate_strings(char*in,char*out,int i,int j){

    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
    }

    // one digit at a time
    int x=in[i]-'0';
    char ch = x +'A'-1;
    out[j]=ch;
    generate_strings(in,out,i+1,j+1);

    // two digit at a time
    if(in[i+1!='\0']){
        int z =in[i+1]-'0';
        int no=x*10 + z;
        if(no<=26){
            ch = no + 'A' -1;
            out[j]=ch;
            generate_strings(in,out,i+2,j+1);
        }
    }

}




int main(){

char in[10]="1234";




}