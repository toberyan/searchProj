#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void workingOnSearch();
    ~MainWindow();

private slots:
    void onMatched(const QString &id);
    void onSearchCompleted(const QString &id);
    void onSearchStoped(const QString &id);

private:
    QString taskId;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
