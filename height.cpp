#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    
    int n1=m-l+1;
    int n2=r-m;

    int *L=new int[n1];  int *R=new int[n2];

    for(int i=0;i<n1;i++)L[i]=arr[l+i];
    for(int i=0;i<n2;i++)R[i]=arr[m+i+1];

    int i=0,j=0,k=l;

    while(i<n1 &&  j<n2 ){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;

        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        
        merge(arr,l,m,r);
    }
}

int main(){
   int n;   cin>>n; int count=0;
   int *temp=new int[n];
   int *arr=new int[n];
   for(int i=0;i<n;i++)cin>>arr[i];
   for(int i=0;i<n;i++)temp[i]=arr[i];
   mergesort(temp,0,n-1);

   for(int i=0;i<n;i++)
   if(temp[i]!=arr[i])count++;

   cout<<"wrong place "<<count;


}