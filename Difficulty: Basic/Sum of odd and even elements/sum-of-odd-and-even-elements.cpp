
class Solution {
  public:
    vector<int> findSum(int n) {
        // Code here
        int oddSum=0;
        int evenSum=0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                evenSum=evenSum+i;
        
            }
            else{
                oddSum=oddSum+i;
            }
            
        }
        return{oddSum,evenSum};
    }
};