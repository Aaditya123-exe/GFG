//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/


class Solution
{
public:
    Node *insertionSort(struct Node *head)
    {
        Node *sorted = NULL;
        Node *current = head;
        while (current)
        {
            Node *nxt = current->next;
            if (sorted == NULL || sorted->data > current->data)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                Node *nextsmall = sorted;
                while (nextsmall->next && nextsmall->next->data < current->data)
                {
                    nextsmall = nextsmall->next;
                }
                current->next = nextsmall->next;
                nextsmall->next = current;
            }
            current = nxt;
        }
        return sorted;
    }
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends