#include<iostream>
using namespace std;

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generate_names(char*in,char*out,int i,int j){

    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }


    int x = in[i] -'0';

    if(x==0 || x==1){
        generate_names(in,out,i+1,j);
    }

    for(int z=0;z<keypad[x][z]!='\0';z++){
        out[j]=keypad[x][z];
        generate_names(in,out,i+1,j+1);
    } 


    return;
}

int main(){
    char a[]="666";
    char b[1000];

    generate_names(a,b,0,0);

}