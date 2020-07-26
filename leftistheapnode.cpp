#include <iostream>
#include "leftistheapnode.h"
#include <algorithm>

LeftistHeapNode::LeftistHeapNode(int data, LeftistHeapNode* father):
    data(data), left(nullptr), right(nullptr), father(father), npl(0)
{
}

int LeftistHeapNode::calculateStoreAndReturnNPL()
{
    if (left != nullptr)
        left->calculateStoreAndReturnNPL();
    if (right != nullptr)
        right->calculateStoreAndReturnNPL();

    if (left == nullptr || right == nullptr)
    {
        npl = 0;
        return npl;
    }
    else
    {
        npl = 1 + std::min
                  (
                      left->npl,
                      right->npl
                  );
        return npl;
    }
}

bool LeftistHeapNode::search(int data)
{
    if (this->data == data)
        return true;
    if (left != nullptr)
    {
        bool leftret = left->search(data);
        if (leftret)
            return true;
    }
    if (right != nullptr)
    {
        bool rightret = right->search(data);
        if (rightret)
            return true;
    }
    return false;
}


