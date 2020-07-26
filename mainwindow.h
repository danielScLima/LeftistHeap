#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "leftistheap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow
     * \param parent
     */
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    /*!
     * \brief updateDotGenerateImageAndRender
     */
    void updateDotGenerateImageAndRender();
private slots:
    /*!
     * \brief on_pushButtonOfInsert_clicked
     */
    void on_pushButtonOfInsert_clicked();

    /*!
     * \brief on_pushButtonOfSearch_clicked
     */
    void on_pushButtonOfSearch_clicked();

    /*!
     * \brief on_pushButtonPreOrdem_clicked
     */
    void on_pushButtonPreOrdem_clicked();

    /*!
     * \brief on_pushButtonEmOrdem_clicked
     */
    void on_pushButtonEmOrdem_clicked();

    /*!
     * \brief on_pushButtonPosOrdem_clicked
     */
    void on_pushButtonPosOrdem_clicked();

    /*!
     * \brief on_pushButtonEmNivel_clicked
     */
    void on_pushButtonEmNivel_clicked();

    /*!
     * \brief on_radioButtonTrad_toggled
     * \param checked
     */
    void on_radioButtonTrad_toggled(bool checked);

    /*!
     * \brief on_radioButtonHeapOne_toggled
     * \param checked
     */
    void on_radioButtonHeapOne_toggled(bool checked);

    /*!
     * \brief on_pushButtonOfMerge_clicked
     */
    void on_pushButtonOfMerge_clicked();

    /*!
     * \brief on_pushButtonInsertAsVector_clicked
     */
    void on_pushButtonInsertAsVector_clicked();

    /*!
     * \brief on_pushButtonOfRemoveMin_clicked
     */
    void on_pushButtonOfRemoveMin_clicked();

private:
    Ui::MainWindow *ui;

    LeftistHeap* leftistHeapOne = nullptr;
    LeftistHeap* leftistHeapTwo = nullptr;

    /*!
     * \brief updateDotFile
     */
    void updateDotFile();

    /*!
     * \brief updateImage
     */
    void updateImage();

    /*!
     * \brief renderImage
     */
    void renderImage();

    /*!
     * \brief getSelectedLeftistHeap
     * \return
     */
    LeftistHeap *getSelectedLeftistHeap();

    template<class Container>
    void split3(const std::string &str, Container &cont, char delim = ',');
};
#endif // MAINWINDOW_H
