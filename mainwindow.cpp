#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <QDir>
#include <QMessageBox>

LeftistHeap* MainWindow::getSelectedLeftistHeap()
{
    if (ui->radioButtonHeapOne->isChecked())
    {
        return leftistHeapOne;
    }
    else
    {
        return leftistHeapTwo;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    leftistHeapOne = new LeftistHeap();
    leftistHeapTwo = new LeftistHeap();

    updateDotGenerateImageAndRender();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotGenerateImageAndRender()
{
    updateDotFile();
    updateImage();
    renderImage();
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    myFile.open
    (
        "file.dot"
    );

    std::string textToFile;
    LeftistHeap* leftistHeap = getSelectedLeftistHeap();
    if (ui->radioButtonTrad->isChecked())
        textToFile = leftistHeap->gitDotFileMode1();
    else
        textToFile = leftistHeap->gitDotFileMode2();

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->labelOfImage->setPixmap(image);
    ui->labelOfImage->show();
}

void MainWindow::on_pushButtonOfInsert_clicked()
{
    int toInsert = ui->lineEditOfInsert->text().toInt();

    LeftistHeap* leftistHeap = getSelectedLeftistHeap();
    leftistHeap->insert(toInsert);

    updateDotGenerateImageAndRender();
}

void MainWindow::on_pushButtonOfSearch_clicked()
{
    int toSearch = ui->lineEditOfSearch->text().toInt();
    LeftistHeap* leftistHeap = getSelectedLeftistHeap();
    bool ret = leftistHeap->search(toSearch);

    QMessageBox msgBox;

    if (ret)
        msgBox.setText("Existe esse nó");
    else
        msgBox.setText("NÃO existe esse nó");

    msgBox.exec();
}

void MainWindow::on_pushButtonPreOrdem_clicked()
{
    //Eu, esq, direita

    LeftistHeap* leftistHeap = getSelectedLeftistHeap();
    std::string ret = leftistHeap->preOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonEmOrdem_clicked()
{
    //esq, eu, dir

    LeftistHeap* leftistHeap = getSelectedLeftistHeap();
    std::string ret = leftistHeap->inOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonPosOrdem_clicked()
{
    //esq, dir, eu

    LeftistHeap* leftistHeap = getSelectedLeftistHeap();
    std::string ret = leftistHeap->posOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonEmNivel_clicked()
{
    //eu, filhos, netos, bisnetos

    LeftistHeap* leftistHeap = getSelectedLeftistHeap();
    std::string ret = leftistHeap->InLevelOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_radioButtonTrad_toggled(bool checked)
{
    updateDotGenerateImageAndRender();
}

void MainWindow::on_radioButtonHeapOne_toggled(bool checked)
{
    updateDotGenerateImageAndRender();
}

void MainWindow::on_pushButtonOfMerge_clicked()
{
    LeftistHeap* leftistHeap = new LeftistHeap();
    leftistHeap->merge(leftistHeapOne->getRoot(), leftistHeapTwo->getRoot());

    delete leftistHeapOne;
    delete leftistHeapTwo;

    leftistHeapOne = leftistHeap;
    leftistHeapTwo = new LeftistHeap();

    ui->radioButtonHeapTwo->setChecked(false);
    ui->radioButtonHeapOne->setChecked(true);

    updateDotGenerateImageAndRender();
}

template <class Container>
void MainWindow::split3(const std::string& str, Container& cont,
              char delim)
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

void MainWindow::on_pushButtonInsertAsVector_clicked()
{
    std::vector<std::string> numbersAsString;
    std::string numbers = ui->lineEditOfInsertAsVector->text().toStdString();
    split3(numbers, numbersAsString);

    std::vector<LeftistHeapNode*> nodes;
    LeftistHeapNode* tmp = nullptr;
    int number = 0;
    for (int index=0;index<numbersAsString.size();++index)
    {
        if (numbersAsString.at(index).compare("-1") == 0)
        {
            //se não, nullptr
            tmp = nullptr;
        }
        else
        {
            //se for diferente de -1, cria node
            number = std::atoi(numbersAsString.at(index).c_str());
            tmp = new LeftistHeapNode(number, nullptr);
        }

        //insere
        nodes.push_back(tmp);
    }

    for (int index=0;index<nodes.size();++index)
    {
        //se tiver pai, faz a ligação
        tmp = nodes.at(index);
        if (tmp == nullptr)
            continue;

        if (2*index+1 < nodes.size())
        {
            tmp->left = nodes.at(2*index+1);

            if (nodes.at(2*index+1) != nullptr)
                nodes.at(2*index+1)->father = tmp;
        }

        if (2*index+2 < nodes.size())
        {
            tmp->right = nodes.at(2*index+2);

            if (nodes.at(2*index+2) != nullptr)
                nodes.at(2*index+2)->father = tmp;
        }
    }

    getSelectedLeftistHeap()->setRoot(nodes[0]);

    updateDotGenerateImageAndRender();
}

void MainWindow::on_pushButtonOfRemoveMin_clicked()
{
    LeftistHeap* leftistHeap = getSelectedLeftistHeap();
    LeftistHeapNode* removedNode = leftistHeap->removeMin();

    updateDotGenerateImageAndRender();

    QMessageBox msgBox;

    if (removedNode != nullptr)
    {
        msgBox.setText("Nó removido");
        delete removedNode;
    }
    else
        msgBox.setText("NÃO existe nó a ser removido");

    msgBox.exec();
}
