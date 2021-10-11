#include <iostream>
using namespace std;
int heap_ornot(int A[],int n){
    for (int i=0; i<=(n-2)/2; i++)
    {
        // Checking if left child is greater
        if (A[2*i +1] > A[i])
            return -1;
        // Checking if right child is greater
        if (2*i+2 < n && A[2*i+2] > A[i])
            return -1;
    }
    return 1;
}
int main(){
    int n;
    cout<<"Enter the size"<<endl;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int ans= heap_ornot(A,n);
    if(ans==1){
    	cout<<"entered array is a max heap";
	}
    else if(ans==-1){
    	cout<<"entered array is not a max heap";
	}
}

