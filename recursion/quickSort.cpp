#include<bits/stdc++.h>
using namespace std;

//pivot element is first element
int part(int arr[],int s,int e){
	int i,j,pivot;
	pivot=arr[s];
	i=e+1;
	for(int j=e;j>s;j--){
		if(arr[j]>=pivot){
			i--;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i-1],arr[s]);
	return i-1;
}

//pivot element is last element
int partition(int arr[],int s,int e){
	int i,j,pivot;
	pivot=arr[e];
	i=s-1;
	for(int j=s;j<e;j++){
		if(arr[j]<=pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[e]);
	return i+1;
}

void quickSort(int arr[],int s,int e){
	//BASE CONDITION
	if(s>=e){
		return;
	}
	//RECURSIVE CALL
	int p=part(arr,s,e);
	quickSort(arr,s,p-1);
	quickSort(arr,p+1,e);
	return;
}

int main(){
		int arr[]={4,1,3,7,2,6,5};
	int n=sizeof(arr)/sizeof(int);
	quickSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
} 