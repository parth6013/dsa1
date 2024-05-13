// Find the repeating and the missing

// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/


// BRUTE FORCE  ount array time O(n), space in O(n)
// #include<bits/stdc++.h>

// using namespace std;

// int main(){

// int n=6; 
// int arr[]={4, 3, 6, 2, 1, 1};

// int cs_arr[n+1]={0};

// for(int i=0;i<n;i++){
//     cs_arr[arr[i]]++;


// }

// for(int i=1;i<=n;i++){
//     if(cs_arr[i]>1){
//         cout<<i<<" repeating"<<endl;
//     }
//     if(cs_arr[i]==0){
//         cout<<i<<"missing";
//     }
// }



// }

// Approach 2 using xor 
// 1 we xor given array item with 1 to n so we will din xor of missing and repeating say x any y
// now there must be a set bit either in x or in y ,we find rightmost set bit 
// now we divide into two set numbers having rightmost set nit and others not having in given array 
// now xor with rightmost bit sets with groups dividen in all 1to n we get x from first and y from second

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n=7;
    int arr[]={ 1, 3, 4, 5, 5, 6, 2};

    int xor1=arr[0];

    // xor with remaining elements in array;

    for(int i=1;i<n;i++){
        xor1=xor1^arr[i];
    }

    // xor with 1 to n

    for(int i=1;i<=n;i++){
        xor1=xor1^i;
    }

    int rightmost_setbit=xor1 & ~(xor1-1);
    // cout<<rightmost_setbit;

    // dividing given array into two groups basis upon rightmost set bit
    int x=0;
    int y=0;

    for(int i=0;i<n;i++){
        if(arr[i] & rightmost_setbit){
            x=x^arr[i];
        }
        else{
            y=y^arr[i];
        }
    }

    // for all 1 to n
    for(int i=1;i<=n;i++){
        if(i & rightmost_setbit){
            x=x^i;
        }else{
            y=y^i;
        }
    }

    cout<<x<<"missing"<<endl;
    cout<<y<<"repeating";



}