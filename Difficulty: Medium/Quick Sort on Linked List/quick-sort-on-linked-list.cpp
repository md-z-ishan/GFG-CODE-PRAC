/* a node of the singly linked list
class node
{
public:
    int data;
    node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */
class Solution {
  public:
  
    struct Node* quickSort(struct Node* head) {
        
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        vector<int> arr;
        
        Node* temp = head;
        
        while(temp != NULL) {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        
        sort(arr.begin(), arr.end());
        
        temp = head;
        int i = 0;
        
        while(temp != NULL) {
            temp->data = arr[i++];
            temp = temp->next;
        }
        
        return head;
    }
};