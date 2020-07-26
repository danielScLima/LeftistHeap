#include "mainwindow.h"
#include <QApplication>

#include "leftistheap.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*BinaryTree binaryTree;
    binaryTree.insert(50);
    binaryTree.insert(40);
    binaryTree.insert(45);
    binaryTree.insert(60);
    binaryTree.insert(55);
    binaryTree.insert(65);*/

    return a.exec();
}
