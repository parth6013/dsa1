#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


class Car{

public:
string name;
int x,y;

Car(){

} 

Car(string n,int x,int y){

    name=n;
    this->x = x;
    this->y = y;
}
int dist(){
    return x*x + y*y ;
}


};


bool compare(Car a,Car b){

int d1 = a.dist();
int d2 = b.dist();

if(d1==d2){
    return a.name.length()< b.name.length();
}

return d1<d2;

}

int main(){

int n;
cin>>n;

vector<Car> v;
 

for(int i=0;i<n;i++){

int x,y;

string name;
cin>>name>>x>>y;

Car temp(name,x,y);
v.push_back(temp);


}

sort(v.begin(),v.end(),compare);

// for each loop

for(auto p : v){

    cout<<"Car "<<p.name<<" , "<<p.x<<","<<p.y;
}




}