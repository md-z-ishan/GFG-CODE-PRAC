// class Solution {
//   public:
//     int kthSmallest(vector<int> &arr, int k) {
//         // code here
//         int temp;
//         for(int i=0;i<arr.size();i++){
//             for(int j=0;j<arr.size();j++){
//                 if(arr[i]>arr[j]){
//                     temp=arr[i];
//                     arr[i]=arr[j];
//                     arr[j]=temp;
//                 }
//             }
//             return arr[k-1];
//         }
//     }
// };

// optimal code
class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
        return arr[k-1];
    }
};