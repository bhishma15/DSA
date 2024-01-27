#include<bits/stdc++.h>
using namespace std;


void reverse_print_n(int n){

    //base case
    if(n==1){
        cout<<n<<" ";
        return;
    }

    //Induction
    cout<<n<<" ";

    // hypothesis
    reverse_print_n(n-1);


}

void print_n(int n){

    //base case
    if(n==1){
        cout<<n<<" ";
        return;
    }
    // hypothesis
    print_n(n-1);

    //Induction
    cout<<n<<" ";
}
int main() {

    cout<< "Give an input"<<endl;
    int n;
    cin>>n;
    reverse_print_n(n);
    return 0;
}