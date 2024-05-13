#include<iostream>
#include<vector>
using namespace std;

bool is_sorted(vector<int> a,int n,int &f){
    if(n==1){
        return true;
    }

    is_sorted(a,n-1,f);
    if(f!=1){
        return false;
    }
    bool m;
    if(a[n-1]>=a[n-2]){
        return true;
    }
    else{
        f=0;
        return false;}



}


int main(){
    vector<int> a={8,2,3,4,5,6,7};
    int n= a.size();
    int f=1;
    bool m=is_sorted(a,n,f);
    if(m){
        cout<<"Yes";
    }else{
        cout<<"No";
    }


}