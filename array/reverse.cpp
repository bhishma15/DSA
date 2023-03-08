/*Given an array (or string), 
the task is to reverse the array/string.*/

#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cout<<"Enter Size of Input"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Array Values"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<"Array After reverse"<<endl;

	for(int i=0;i<n/2;i++){
		int t=arr[i];
		arr[i]=arr[n-i-1];
		arr[n-i-1]=t;
	}

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}