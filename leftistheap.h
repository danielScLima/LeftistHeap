#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include <iostream>
#include <vector>

#include "leftistheapnode.h"

/*!
 * \brief The LeftistHeap class
 */
class LeftistHeap
{
public:
    /*!
     * \brief LeftistHeap
     */
    LeftistHeap();

    ~LeftistHeap();

    /*!
     * \brief getRoot
     * \return
     */
    LeftistHeapNode* getRoot();

    /*!
     * \brief insert
     * \param data
     */
    void insert(int data);
    /*!
     * \brief removeMin
     * \return
     */
    struct LeftistHeapNode* removeMin();
    /*!
     * \brief search
     * \param data
     * \return
     */
    bool search(int data);

    /*!
     * \brief gitDotFileMode1
     * \return
     */
    const std::string gitDotFileMode1();
    /*!
     * \brief gitDotFileMode2
     * \return
     */
    const std::string gitDotFileMode2();

    /*!
     * \brief preOrder
     * \return
     */
    const std::string preOrder();
    /*!
     * \brief inOrder
     * \return
     */
    const std::string inOrder();
    /*!
     * \brief posOrder
     * \return
     */
    const std::string posOrder();
    /*!
     * \brief InLevelOrder
     * \return
     */
    const std::string InLevelOrder();

    /*!
     * \brief merge
     * \param heapOne
     * \param heapTwo
     */
    void merge(LeftistHeapNode *heapOne, LeftistHeapNode *heapTwo);
    /*!
     * \brief setRoot
     * \param node
     */
    void setRoot(LeftistHeapNode *node);
private:
    struct LeftistHeapNode* root = nullptr;

    /*!
     * \brief exibirSubArvore1
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore1(LeftistHeapNode *n, std::string &content, int& count);
    /*!
     * \brief exibirSubArvore2
     * \param father
     * \param isLeftSon
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore2(LeftistHeapNode *father, bool isLeftSon, LeftistHeapNode *n, std::string &content, int &count);

    /*!
     * \brief preOrder
     * \param node
     * \param content
     */
    void preOrder(LeftistHeapNode *node, std::string &content);
    /*!
     * \brief inOrder
     * \param node
     * \param content
     */
    void inOrder(LeftistHeapNode *node, std::string &content);
    /*!
     * \brief posOrder
     * \param node
     * \param content
     */
    void posOrder(LeftistHeapNode *node, std::string &content);

    /*!
     * \brief checkAndCorrectIfNeeded
     * \param node
     */
    void checkAndCorrectIfNeeded(LeftistHeapNode *node);
    /*!
     * \brief updateNPLToAllHeap
     */
    void updateNPLToAllHeap();

    /*!
     * \brief merge
     * \param heapOne
     * \param heapTwo
     * \param stack
     */
    void merge(LeftistHeapNode* heapOne, LeftistHeapNode* heapTwo, std::vector<LeftistHeapNode*>& stack);
    /*!
     * \brief insertInHeapOfMerge
     * \param node
     * \param stack
     */
    void insertInHeapOfMerge(LeftistHeapNode* node, std::vector<LeftistHeapNode*> &stack);
    /*!
     * \brief dealockSubTree
     * \param node
     */
    void dealockSubTree(LeftistHeapNode *node);
};

#endif // LEFTIST_HEAP_H
