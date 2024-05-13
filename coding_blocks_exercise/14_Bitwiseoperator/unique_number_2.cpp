#include<iostream>
using namespace std;
int main() {


	int n;

    cin>>n;

	int a[n];

	int x=0;

	for(int i=0;i<n;i++){
		cin>>a[i];

		x=x^a[i];
	}

    cout<<x;

    int temp=x;

    

	int p1=0;
	int m=1;
	cout<<"ok";
	// cause two numbers are different hence they must have 1 bit different
	while( (x&m) == 0){
		cout<<"x";
		p1++;
        m = m<<1; 
       

	}

	cout<<p1<<endl;


    int mask = 1<<p1;

    int x2=0;

    for(int i=0;i<n;i++){
        if((a[i]&mask) > 0){
            x2=x2^a[i];
        }
    }

    cout<<x2<<endl;

    cout<< (x^x2) ;

	return 0;
}