/* LinkedList Node structure
struct Node {
    bool data;   // data is either 0 or 1
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
  
    int decimalValue(Node* head) {
        
        const int MOD = 1000000007;
        
        long long ans = 0;
        
        while(head != NULL) {
            
            ans = (ans * 2 + head->data) % MOD;
            
            head = head->next;
        }
        
        return ans;
    }
};
