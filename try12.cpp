#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(int &a,int&b){
    int temp=a;
    a=b;
    b=temp;
}

void print(vector<int>& arr){

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// idea is heaviest element gets to bootom in each pass(towars right)
// and aray gets  
void bublle_sort(vector<int> &arr){

    for(int i=0;i<arr.size();i++){
        for(int j=1;j<arr.size()-i;j++){

            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }

        }
    }


}

// here  we take sorted array in the left and then try to find what can be the position 
// of the element in unsorted array in the sorted array


void insertion_sort(vector<int> &arr){

    for(int i=1;i<arr.size();i++){

        int temp=arr[i];

        int j=i-1;
        int k=i;
        while(j>=0 &&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;

    }

}

// selection sort 
// here we take the  minimum from the unsorted and swap it

void selection_sort(vector<int> &arr){

    for(int i=0;i<arr.size()-1;i++){
            int min1=i;          

        for(int j=i+1;j<arr.size();j++){

                if(arr[j]<arr[min1]){
                    min1=j;
                }

        }
        cout<<arr[i];
        swap(arr[i],arr[min1]);
        cout<<arr[arr.size()-1-i]<<endl;

    }
}

// quick sort idea is that respective to pivot all other element is less than and greater than 
// partition and then send left part and right part to recursion hence nlogn in best case and 
// n^2 in worst case when array is already sorted 

int partition(vector<int> arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
 
void quickSort(vector<int> arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
 

void merge(vector<int> &arr,int begin,int mid,int  end){

    int i=0;
    int j=mid+1;

    


}

void merge_sort(vector<int> &arr,int begin ,int end ){

    if(begin>=end){
        return;
    }

    int mid=(end+begin)/2;

    merge_sort(arr,begin,mid);
    merge_sort(arr,mid+1,end);

    merge(arr,begin,mid,end); 

}


void merge_sort(vector<int>){


}


int main(){

    vector<int> arr={9,8,7,6,5,};

    print(arr);

    selection_sort(arr);

    print(arr);

    cout<<"sd";
    return 0;
}