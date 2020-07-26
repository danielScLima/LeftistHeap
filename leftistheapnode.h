#ifndef LEFTISTHEAPNODE_H
#define LEFTISTHEAPNODE_H

#include <iostream>

/*!
 * \brief The LeftistHeapNode struct
 */
struct LeftistHeapNode
{
    /*!
     * \brief LeftistHeapNode
     * \param data
     * \param father
     */
    LeftistHeapNode(int data, LeftistHeapNode* father);

    /*!
     * \brief calculateStoreAndReturnNPL
     * \return
     */
    int calculateStoreAndReturnNPL();

    /*!
     * \brief search
     * \param data
     * \return
     */
    bool search(int data);

    int data = 0;
    int npl = 0; //null path length
    struct LeftistHeapNode* left = nullptr;
    struct LeftistHeapNode* right = nullptr;
    struct LeftistHeapNode* father = nullptr;
};

#endif // LEFTISTHEAPNODE_H
