/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *divide(Node *head) {
        
        if(!head || !head->next) return head;
        
        Node *evenHead = nullptr, *evenTail = nullptr;
        Node *oddHead = nullptr, *oddTail = nullptr;
        
        Node *curr = head;
        
        while(curr) {
            
            if(curr->data % 2 == 0) {
                
                if(!evenHead) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            }
            else {
                
                if(!oddHead) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            }
            
            curr = curr->next;
        }
        
        if(evenTail) evenTail->next = oddHead;
        if(oddTail) oddTail->next = nullptr;
        
        return evenHead ? evenHead : oddHead;
    }
};