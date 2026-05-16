/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
  public:
    
    bool isCircular(Node *head) {
        
        if(head == NULL) {
            return true;
        }
        
        Node* temp = head->next;
        
        while(temp != NULL && temp != head) {
            temp = temp->next;
        }
        
        if(temp == head) {
            return true;
        }
        
        return false;
    }
};