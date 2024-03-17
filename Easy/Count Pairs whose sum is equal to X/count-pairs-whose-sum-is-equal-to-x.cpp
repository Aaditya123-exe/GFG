//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
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
class Solution{
  public:
    // your task is to complete this function
     int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        vector<int>v1;
        vector<int>v2;
        int count=0;
        Node*temp1=head1;
        Node*temp2=head2;
        if(temp1==NULL) return 0;
        if(temp2==NULL) return 0;
      
       while(temp1!=NULL){
           v1.push_back(temp1->data);
           temp1=temp1->next;
       }
       while(temp2!=NULL){
           v2.push_back(temp2->data);
           temp2=temp2->next;
       }
       sort(v1.begin(),v1.end());
       sort(v2.begin(),v2.end());
       int leftptr=0;
       int rightptr=v2.size()-1;
       while((leftptr<v1.size()) && (rightptr>=0)){
       if(v1[leftptr]+v2[rightptr]==x){
           count++;
           rightptr--;
           leftptr++;
       }
       else if(v1[leftptr]+v2[rightptr]>x){
           rightptr--;
       }
      else{
          leftptr++;
      }
      
    }
    return count;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
// } Driver Code Ends