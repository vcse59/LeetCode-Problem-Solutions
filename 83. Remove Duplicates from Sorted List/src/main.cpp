#include <iostream>
#include <memory>

/**
 * Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Solution class
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        // Check for input
        if (head == nullptr)
            return head;

        // Create new list without duplicates
        ListNode *distinctLinkedList = nullptr;
        ListNode *recentUniqueValNode = nullptr;
        ListNode *tempHead = head;

        // Traverse the list and keep track of recent unique node
        while (tempHead != nullptr)
        {

            // if recentUniqueValNode is null
            if (recentUniqueValNode == nullptr)
            {
                recentUniqueValNode = tempHead;
                distinctLinkedList = tempHead;
            }
            else
            {
                // Check if current node val == recent unique value node
                if (recentUniqueValNode->val != tempHead->val)
                {
                    // Update recentUniqueValNode to point to new node
                    // and advance to next node for future node insertion
                    recentUniqueValNode->next = tempHead;
                    recentUniqueValNode = recentUniqueValNode->next;
                }
                else
                {
                    // Do nothing and let the traversal continue
                }
            }

            // Advanced the current iterator to next node in linked list
            tempHead = tempHead->next;
        }

        // Make sure that last node in distinctLinkedList node is pointing to null
        recentUniqueValNode->next = nullptr;

        // Return the new Linked List without any duplicates in sorted order
        return distinctLinkedList;
    }

    void print(ListNode* head)
    {
        ListNode* currentNode = head;

        while(currentNode != nullptr){
            std::cout << currentNode->val << " ";
            currentNode = currentNode->next;
        }
    }
};

int main(int argc, char *argv[])
{
    // Create a solution object
    std::shared_ptr<Solution> solSharedPtr = std::make_shared<Solution>();

    // Create dummy LinkedList for input
    ListNode head(1);
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(2);
    ListNode node4(3);
    ListNode node5(3);

    // Link the nodes
    head.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    // Print the ListNode
    std::cout << "Input list : ";
    solSharedPtr->print(&head);
    std::cout << std::endl;

    // Call the function to remove duplicates
    ListNode* newListNode = solSharedPtr->deleteDuplicates(&head);

    // Print the ListNode
    std::cout << "Output list after removing duplicates : ";
    solSharedPtr->print(newListNode);
    std::cout << std::endl;
}
