#include <iostream>

class node
{
public:
    int mVal;
    node *next;
};

class CustomStack
{
public:
    CustomStack(int maxSize)
    {
        mMaxSize = maxSize;
        mCurrentSize = 0;
        mHead = nullptr;
    }

    ~CustomStack()
    {
        node* currentNode = mHead;

        while (currentNode != nullptr)
        {
            node* tempNode = currentNode;
            currentNode = currentNode->next;
            delete tempNode;
        }
        mHead = nullptr;
    }

    void push(int x)
    {

        // Max Size reached
        if (mCurrentSize >= mMaxSize)
            return;

        node *newNode = new node();
        newNode->mVal = x;
        newNode->next = nullptr;

        node *currentNode = mHead;
        if (mHead == nullptr)
        {
            mHead = newNode;
        }
        else
        {
            newNode->next = mHead;
            mHead = newNode;
        }
        mCurrentSize++;
    }

    int pop()
    {
        if (mCurrentSize <= 0 || mHead == nullptr)
            return -1;

        node *tempHead = mHead;
        mHead = mHead->next;

        int retVal = tempHead->mVal;
        delete tempHead;

        mCurrentSize--;

        if (mCurrentSize <= 0)
        {
            mHead = nullptr;
            mCurrentSize = 0;
        }

        return retVal;
    }

    void increment(int k, int val)
    {

        if (mCurrentSize <= 0 || mHead == nullptr)
            return;

        int valCountToIncrement = mMaxSize;

        // Check if k > maxSize
        if (mMaxSize <= k)
        {
            // Increment all the values
            valCountToIncrement = mCurrentSize;
        }
        else
        {
            valCountToIncrement = k;
        }

        int nodeToTraverseWithoutUpdate = mCurrentSize - valCountToIncrement;
        node *tempHead = mHead;

        for (int i = 0; i < nodeToTraverseWithoutUpdate; ++i)
        {
            tempHead = tempHead->next;
        }

        while (tempHead != nullptr)
        {
            tempHead->mVal += val;
            tempHead = tempHead->next;
        }
    }

    node *mHead;
    int mCurrentSize;
    int mMaxSize;
};

/*["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
*/


int main(int argc, char *argv[])
{
    int maxSize = 3;
    
    CustomStack obj(maxSize);
    obj.push(1);
    obj.push(2);
    int val = obj.pop();
    std::cout << "Popped Value : " << val << std::endl;
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.increment(5, 100);
    obj.increment(2, 100);
    val = obj.pop();
    std::cout << "Popped Value : " << val << std::endl;
    val = obj.pop();
    std::cout << "Popped Value : " << val << std::endl;
    val = obj.pop();
    std::cout << "Popped Value : " << val << std::endl;
    val = obj.pop();
    std::cout << "Popped Value : " << val << std::endl;

    return 0;
}
