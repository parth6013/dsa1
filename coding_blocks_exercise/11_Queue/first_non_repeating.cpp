#include<iostream>
#include<queue>
using namespace std;

int main(){

queue<char> q1;
int arr[27]={0};

char ch;
cin>>ch;
while(ch!='z'){
    q1.push(ch);
    arr[ch-'a']++;
    while(q1.size()!=0 ){

        if(arr[q1.front()-'a']>1){
                q1.pop();
        }
        else{
            cout<<q1.front()<<'x'<<endl;
            exit;
        }
        
    }
    if(q1.empty()){
        cout<<-1<<'x'<<endl;
    
    }
    cout<<ch<<"$";
    cin>>ch;
    
}


}