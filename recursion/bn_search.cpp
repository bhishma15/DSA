#include<bits/stdc++.h>
using namespace std;

int bin_search(int arr[],int key,int left,int right){
	//Element not present
	if(left > right)
		return -1;
	
	int mid=(left+right)/2;
	
	//element found 
	if(arr[mid]==key){
		return mid;
	}
	else if(arr[mid] >key){
		return bin_search(arr,key,left,mid-1);
	}
	else if(arr[mid]<key){
		return bin_search(arr,key,mid+1,right);
	}
}
int main(){
	int arr[]={3,6,8,9,10,15};
	int n=sizeof(arr)/sizeof(int);
	int result=bin_search(arr,10,0,n-1);
	      if(result != -1){
		        cout<<"Element is present at "<<result<<"position"<<endl;
			}
			else{
				cout<<"element is not present in array"<<endl;
			}
	return 0;
} 