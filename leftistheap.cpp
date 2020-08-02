#include "leftistheap.h"
#include <iostream>
#include <queue>
#include <string>

LeftistHeapDS::LeftistHeapDS()
{

}

LeftistHeapDS::~LeftistHeapDS()
{
    if (root != nullptr)
    {
        dealockSubTree(root);
        delete root;
    }
}

void LeftistHeapDS::dealockSubTree(LeftistHeapNode *node)
{
    if (node == nullptr)
        return;

    if (node->left != nullptr)
    {
        dealockSubTree(node->left);
        delete node->left;
    }
    if (node->right != nullptr)
    {
        dealockSubTree(node->right);
        delete node->right;
    }
}

LeftistHeapNode *LeftistHeapDS::getRoot()
{
    return root;
}

void LeftistHeapDS::insert(int data)
{
    if (root == nullptr)
    {
        LeftistHeapNode* toInsert = new LeftistHeapNode(data, nullptr);
        root = toInsert;
    }
    else //root not null
    {
        LeftistHeapNode* tmp = root;
        while (true)
        {
            if (tmp->data <= data) //Inserir no ramo direito
            {
                //Verifica se a direita é null
                //Se sim, já insere lá
                if (tmp->right == nullptr)
                {
                    LeftistHeapNode* toInsert = new LeftistHeapNode(data, tmp);
                    tmp->right = toInsert;
                    toInsert->father = tmp;
                    //Começa a checar, a partir de tmp, se ta tudo ok
                    checkAndCorrectIfNeeded(tmp);
                    break;
                }
                else //Se não, mergulha
                {
                    tmp = tmp->right;
                    //não faz break
                }
            }
            else //o dado a ser inserido é menor que este nó
            {
                if (tmp == root)
                {
                    LeftistHeapNode* toInsert = new LeftistHeapNode(data, nullptr);
                    LeftistHeapNode* backupRoot = root;
                    backupRoot->father = toInsert;
                    root = toInsert;

                    //Mesmo sabendo que vai trocar, coloca na direita
                    toInsert->right = backupRoot;
                    backupRoot->father = toInsert;
                    checkAndCorrectIfNeeded(root);
                }
                else
                {
                    LeftistHeapNode* backupFather = tmp->father;
                    LeftistHeapNode* toInsert = new LeftistHeapNode(data, backupFather);
                    tmp->father = toInsert;
                    toInsert->right = tmp; //o tmp sempre é colocado a direita
                    backupFather->right = toInsert;//No pai, sempre desçe para a direita
                    toInsert->father = backupFather;
                    checkAndCorrectIfNeeded(toInsert);
                }
                break; //faz break, independente da situação
            }
        } //end of while loop
    } //end of root not null
}

void LeftistHeapDS::checkAndCorrectIfNeeded(LeftistHeapNode *node)
{
    if (root == nullptr)
        return;

    //Calcula o npl em toda a heap
    updateNPLToAllHeap();

    //Faz o start do calculo, começando em node
    LeftistHeapNode* tmp = node;
    while (tmp != nullptr)
    {
        if (tmp->left == nullptr && tmp->right != nullptr)
        {
            tmp->left = tmp->right;
            tmp->right = nullptr;
        }
        else if (tmp->left != nullptr && tmp->right != nullptr &&
                 (tmp->left->npl < tmp->right->npl))
        {
            LeftistHeapNode* swapNode = tmp->left;
            tmp->left = tmp->right;
            tmp->right = swapNode;
        }

        tmp = tmp->father;
    }
}

void LeftistHeapDS::updateNPLToAllHeap()
{
    root->calculateStoreAndReturnNPL();
}

LeftistHeapNode *LeftistHeapDS::removeMin()
{
    if (root == nullptr)
        return nullptr;

    LeftistHeapNode* backupRoot = root;
    LeftistHeapNode* left = root->left;
    LeftistHeapNode* right = root->right;
    if (left != nullptr)
    {
        left->father = nullptr;
    }
    if (right != nullptr)
    {
        right->father = nullptr;
    }
    root = nullptr;

    LeftistHeapDS* leftistHeapLeft = new LeftistHeapDS();
    leftistHeapLeft->setRoot(left);

    LeftistHeapDS* leftistHeapRight = new LeftistHeapDS();
    leftistHeapRight->setRoot(right);

    merge(leftistHeapLeft->getRoot(), leftistHeapRight->getRoot());

    leftistHeapLeft->setRoot(nullptr);
    leftistHeapRight->setRoot(nullptr);

    delete leftistHeapLeft;
    delete leftistHeapRight;

    return backupRoot;
}

bool LeftistHeapDS::search(int data)
{
    if (root == nullptr)
        return false;
    else
        return root->search(data);
}

const std::string LeftistHeapDS::gitDotFileMode2()
{
    std::string textToFile = "digraph g{";
    textToFile += "node [shape=record, height=0.1]";

    if (root == nullptr)
    {
        textToFile += "NULL [label = \"<l> | <m> NULL | <r>\"];Root -> NULL;";
    }
    else
    {
        int count = 0;
        exibirSubArvore2(nullptr, true, root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string LeftistHeapDS::gitDotFileMode1()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";

    if (root == nullptr)
    {
        textToFile += "NULL [ fontcolor=red ];Root -> NULL;";
    }
    else
    {
        int count = 0;
        textToFile += "Root->"+std::to_string(root->data)+";";
        exibirSubArvore1(root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string LeftistHeapDS::preOrder()
{
    std::string content;
    preOrder(root, content);
    return content;
}

const std::string LeftistHeapDS::inOrder()
{
    std::string content;
    inOrder(root, content);
    return content;
}

const std::string LeftistHeapDS::posOrder()
{
    std::string content;
    posOrder(root, content);
    return content;
}

const std::string LeftistHeapDS::InLevelOrder()
{
    std::string content;

    std::queue<LeftistHeapNode*> queue;

    if (root != nullptr)
        queue.push(root);

    LeftistHeapNode* node = nullptr;
    while(queue.size() > 0)
    {
        LeftistHeapNode* node = queue.front(); //acessa o primeiro
        queue.pop(); //remove o primeiro

        content += std::to_string(node->data)+" ";

        if (node->left != nullptr)
            queue.push(node->left);

        if (node->right != nullptr)
            queue.push(node->right);
    }

    return content;
}

void LeftistHeapDS::preOrder(struct LeftistHeapNode* node, std::string& content)
{
    if (node != nullptr)
    {
        content += std::to_string(node->data) + " ";
        preOrder(node->left, content);
        preOrder(node->right, content);
    }
}
void LeftistHeapDS::inOrder(struct LeftistHeapNode* node, std::string& content)
{
    if (node != nullptr)
    {
        inOrder(node->left, content);
        content += std::to_string(node->data) + " ";
        inOrder(node->right, content);
    }
}
void LeftistHeapDS::posOrder(struct LeftistHeapNode* node, std::string& content)
{
    if (node != nullptr)
    {
        posOrder(node->left, content);
        posOrder(node->right, content);
        content += std::to_string(node->data) + " ";
    }
}

void LeftistHeapDS::exibirSubArvore1
(
    struct LeftistHeapNode* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data)+";";

    if (n->left == nullptr)
    {
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->left->data)+";";
        exibirSubArvore1
        (
            n->left,
            content,
            count
        );
    }

    if (n->right == nullptr)
    {
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->right->data)+";";
        exibirSubArvore1
        (
            n->right,
            content,
            count
        );
    }
}

void LeftistHeapDS::exibirSubArvore2
(
    struct LeftistHeapNode *father,
    bool isLeftSon,
    struct LeftistHeapNode* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data)+" [label = \"<l> | <m> "+std::to_string(n->data)+" | <r>\"]";

    //desenha a ligação entre o pai e ele
    if (father != nullptr)
    {
        if (isLeftSon)
            content += std::to_string(father->data)+":l->"+std::to_string(n->data)+";";
        else
            content += std::to_string(father->data)+":r->"+std::to_string(n->data)+";";
    }
    else
    {
        //é o root
        content += "ROOT[shape=none fontcolor=blue];";
        content += "ROOT->"+std::to_string(n->data)+";";
    }

    if (n->left != nullptr)
    {
        exibirSubArvore2
        (
            n,
            true, //is left
            n->left,
            content,
            count
        );
    }

    if (n->right != nullptr)
    {
        exibirSubArvore2
        (
            n,
            false, //is not left
            n->right,
            content,
            count
        );
    }
}

void LeftistHeapDS::merge(LeftistHeapNode *heapOne, LeftistHeapNode *heapTwo)
{
    std::vector<LeftistHeapNode*> stack;
    merge(heapOne, heapTwo, stack);
}

void LeftistHeapDS::setRoot(LeftistHeapNode *node)
{
    this->root = node;
}

void LeftistHeapDS::merge(LeftistHeapNode *heapOne, LeftistHeapNode *heapTwo, std::vector<LeftistHeapNode*>& stack)
{
    if (heapOne == nullptr && heapTwo == nullptr)
        return;
    else if (heapOne != nullptr && heapTwo == nullptr)
    {
        insertInHeapOfMerge(heapOne, stack);
        //And this is the end
    }
    else if(heapOne == nullptr && heapTwo != nullptr)
    {
        insertInHeapOfMerge(heapTwo, stack);
        //And this is the end
    }
    else
    {
        if (heapOne->data <= heapTwo->data)
        {
            //Deve inserir heapOne
            LeftistHeapNode *heapOneBackup = heapOne;
            heapOne = heapOne->right;
            heapOneBackup->right = nullptr;
            insertInHeapOfMerge(heapOneBackup, stack);
            merge(heapOne, heapTwo, stack);
        }
        else
        {
            //Deve inserir heapTwo
            LeftistHeapNode *heapTwoBackup = heapTwo;
            heapTwo = heapTwo->right;
            heapTwoBackup->right = nullptr;
            insertInHeapOfMerge(heapTwoBackup, stack);
            merge(heapOne, heapTwo, stack);
        }
    }

    if (stack.size() > 0)
    {
        //updateNPLToAllHeap(); //this is done in checkAndCorrectIfNeeded

        while (stack.size() > 0)
        {
            LeftistHeapNode * back = stack.back();
            stack.pop_back();

            checkAndCorrectIfNeeded(back);
        }
    }
}

void LeftistHeapDS::insertInHeapOfMerge(LeftistHeapNode *node, std::vector<LeftistHeapNode*> &stack)
{
    node->father = nullptr;

    stack.push_back(node);

    if (root == nullptr)
        root = node;
    else
    {
        LeftistHeapNode *tmp = root;
        while (tmp->right != nullptr)
        {
            tmp = tmp->right;
        }

        tmp->right = node;
        node->father = tmp;
    }
}
