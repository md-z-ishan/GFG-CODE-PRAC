/*

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* makeUnion(Node* head1, Node* head2) {
        
        unordered_set<int> seen;
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while(head1) {
            if(seen.find(head1->data) == seen.end()) {
                seen.insert(head1->data);
                tail->next = new Node(head1->data);
                tail = tail->next;
            }
            head1 = head1->next;
        }
        
        while(head2) {
            if(seen.find(head2->data) == seen.end()) {
                seen.insert(head2->data);
                tail->next = new Node(head2->data);
                tail = tail->next;
            }
            head2 = head2->next;
        }
        
        return dummy->next;
    }
};