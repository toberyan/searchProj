#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchservice.h"
#include <QUuid>
#include <QDir>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(searchServ, &SearchService::matched, this, &MainWindow::onMatched);
    connect(searchServ, &SearchService::searchCompleted, this, &MainWindow::onSearchCompleted);
    connect(searchServ, &SearchService::searchStoped, this, &MainWindow::onSearchStoped);

    searchServ->createFullTextIndex();
    workingOnSearch();
}

void MainWindow::workingOnSearch()
{
    taskId = QUuid::createUuid().toString(QUuid::WithoutBraces);
    searchServ->search(taskId, QDir::homePath(), "test");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMatched(const QString &id)
{
    if (taskId == id) {
        auto results = searchServ->matchedResults(taskId);
        for (const auto &result : results) {
            qDebug()<<"the result file is:"<<result;
        }
    }
}

void MainWindow::onSearchCompleted(const QString &id)
{
    if (taskId == id) {
        qInfo() << "taskId: " << taskId << "search completed!";
    }
}

void MainWindow::onSearchStoped(const QString &id)
{
    if (taskId == id) {
        qInfo() << "taskId: " << taskId << "search stoped!";
    }
}
