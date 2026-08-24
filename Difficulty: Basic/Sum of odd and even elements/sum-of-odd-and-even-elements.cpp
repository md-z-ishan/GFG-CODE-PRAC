
class Solution {
  public:
    vector<int> findSum(int n) {
        // Code here
     int o=0;
     int e=0;
     for(int i=0;i<=n;i++){
         if(i%2==0){
             e=e+i;
         }
         else{
             o=o+i;
         }
     }
     return{o,e};
}
};