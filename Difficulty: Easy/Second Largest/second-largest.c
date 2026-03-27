int getSecondLargest(int *arr, int n) {
    // code here
    int largest=-1;
    int second=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>second){
            second=arr[i];
        }
    }
    return second;
}
