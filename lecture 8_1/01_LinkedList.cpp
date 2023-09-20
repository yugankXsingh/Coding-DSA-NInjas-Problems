
#include <iostream>
using namespace std;
#include "Node_class.cpp"

Node *takeInput()
{
    int data;
    cin >> data;
    Node *Head = NULL;
    Node *Tail = NULL;

    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (Head == NULL)
        {
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            // Node *temp = Head;
            // while (temp->next != NULL)  // Using this loop it will have the time complexity of O(n^2).
            // {
            //     temp = temp->next;
            // }
            // temp->next = newNode;

            Tail->next = newNode; // Now it has the Time complexity of O(n).
            Tail = newNode;
            // or
            // Tail = Tail->next;
        }
        cin >> data;
    }
    return Head;
}

// *******************************************************************************************************

Node *get_mid(Node *Head)
{
    if (Head == NULL && Head->next == NULL)
    {
        return Head;
    }
    Node *slow = Head;
    Node *fast = Head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// *******************************************************************************************************

Node *remove_duplicates(Node *Head)
{
    // Empty list
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    // Non empty list
    Node *curr = Head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;
        }
        else
        {
            curr = curr->next;
        }
    }
    return Head;
}
//**************************************************************************************************
Node *deleteNode(Node *Head, int pos)
{
    Node *temp = Head;
    int count = 0;

    if (Head == NULL)
    {
        return Head;
    }

    if (pos == 0)
    {
        Head = temp->next;
        delete temp;
        return Head;
    }

    while (count < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    // At this line temp has the address of i-1th node
    if (temp->next != NULL)
    {
        Node *a = temp->next;
        Node *b = a->next;
        delete a;
        temp->next = b;
    }
    return Head;
}
// ****************************************************************************************************

Node *InsertNode(Node *Head, int i, int data)
{
    Node *temp = Head;
    int count = 0;
    Node *newNode = new Node(data);

    if (i == 0)
    {
        newNode->next = Head;
        Head = newNode;
        return Head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // At this line temp has the address of i-1th node
    if (temp->next != NULL)
    {
        // Node *current = temp->next; // saving the address of the next node so that its not lost
        // temp->next = newNode;       // go at the node stored
        //                             // address stored in temp -> then in the "next" of that particular node store the address of newNode.
        // newNode->next = current;

        // OR

        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        cout << "Invalid Index" << endl;
    }

    return Head;
}

// *************************************************************************************************

Node *Merge2sorted_list(Node *head1, Node *head2)
{
    Node *final_head = NULL;
    Node *final_tail = NULL;

    if (head1 == NULL && head2 == NULL)
    {
        return final_head;
    }
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data >= head2->data)
    {
        final_head = head2;
        final_tail = head2;
        head2 = head2->next;
    }
    else if (head1->data < head2->data)
    {
        final_head = head1;
        final_tail = head1;
        head1 = head1->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data >= head2->data)
        {
            final_tail->next = head2;
            final_tail = head2;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
        {
            final_tail->next = head1;
            final_tail = head1;
            head1 = head1->next;
        }
    }

    while (head1 != NULL)
    {
        final_tail->next = head1;
        final_tail = head1;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        final_tail->next = head2;
        final_tail = head2;
        head2 = head2->next;
    }

    final_tail = NULL;
    return final_head;
}

// *************************************************************************************************
Node *mergeSort(Node *head)
{
    // BASE CASE
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *head1 = head;
    Node *mid = get_mid(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    // Recursive call
    Node *small_list_1 = mergeSort(head1);
    Node *small_list_2 = mergeSort(head2);

    // Merging both sorted linked list
    Node *mergedNode = Merge2sorted_list(small_list_1, small_list_2);

    return mergedNode;
}
//**************************************************************************************************

Node *reverse_LinkedList(Node *head)
{
    // Base Case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // recursive call
    Node *small_list = reverse_LinkedList(head->next);

    Node *temp = small_list;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;

    return small_list;
}
//***********************************************************************************************************

int FindNode(Node *Head, int data)
{
    Node *temp = Head;
    int index = 0;
    if (Head == NULL)
    {
        return -1;
    }

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return index;
        }
        else
        {
            temp = temp->next;
            index++;
        }
    }
    cout << "Data not found !" << endl;
    return -1;
}

void Print_LinkedList(Node *Head)
{
    Node *temp = Head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // the address of the next Node is now stored in Head
    }
}

// *************************************************************************************************

int main()
{
    Node *Head = takeInput();
    int i, data;
    cout << "Enter the index to be inserted :" << endl;
    cin >> i;
    cout << "Enter Data :" << endl;
    cin >> data;

    Head = InsertNode(Head, i, data);
    cout << "Updated Lsit: " << endl;
    Print_LinkedList(Head);
    cout << endl
         << "After deleting inserted data:" << endl;
    Head = deleteNode(Head, i);
    Print_LinkedList(Head);

    cout << endl;

    bool search = true;

    int yes = -1;
    cout << "Want to search ?" << endl;
    cin >> yes;
    if (yes == 0)
    {
        search = true;
    }
    else
    {
        search = false;
    }

    if (search)
    {
        int n;
        cout << "Enter Data :" << endl;
        cin >> n;
        int result = FindNode(Head, n);
        cout << "Data index is : " << result << endl;
    }
    cout << endl
         << "Mid point of the node is : " << get_mid(Head)->data << endl;

    cout << "Enter 2nd Linked List :" << endl;
    Node *Head2 = takeInput();

    cout << endl
         << "sorting both the lists :" << endl;
    Head = mergeSort(Head);
    cout << endl;
    Head2 = mergeSort(Head2);

    Print_LinkedList(Head);
    cout << endl;
    Print_LinkedList(Head2);
    cout << endl;
    cout << endl
         << "Merging 1st and 2nd linked list :" << endl;
    Node *MergedHead = Merge2sorted_list(Head, Head2);
    Print_LinkedList(MergedHead);

    cout << endl
         << "Reversed linked list is :" << endl;

    Node *smallAns = reverse_LinkedList(MergedHead);
    Print_LinkedList(smallAns);
    return 0;
}
