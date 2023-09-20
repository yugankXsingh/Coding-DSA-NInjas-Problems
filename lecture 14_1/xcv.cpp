#include <iostream>
#include <climits>
using namespace std;

int maxSum(int* arr , int N){
    
    int max = arr[0];
    int secondMax = INT_MIN;
    
    for(int i=0 ;i<N ;i++){
        if(arr[i] > max){
            //update the max
            secondMax = max;
            max = arr[i];
        }else if(arr[i] < max && arr[i] > secondMax){
            //update secondMax
            secondMax = arr[i];
        }else{
            continue;
        }
    }
    
    return max+secondMax;
}

int main() {
	// your code goes here
	int T;
    cin>>T;
	
	for(int i=T ;i>0;i--){
	    int N; //size of array
	    int arr[N];
	    for(int j=0; j<N ; j++){
	        cin>>arr[j];
	    }
	    
	    int ans = maxSum(arr , N);
	    cout<<ans<<endl;
	    
	}
	return 0;
}