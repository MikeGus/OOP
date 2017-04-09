/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *movX;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *movBtn;
    QLineEdit *movZ;
    QLineEdit *movY;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *rotX;
    QLineEdit *rotY;
    QLabel *label_7;
    QLineEdit *rotZ;
    QPushButton *rotBtn;
    QLabel *label_8;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *scaleK;
    QPushButton *scaleBtn;
    QPushButton *loadBtn;
    QPushButton *delBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(616, 457);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        movX = new QLineEdit(centralWidget);
        movX->setObjectName(QStringLiteral("movX"));

        gridLayout->addWidget(movX, 1, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        movBtn = new QPushButton(centralWidget);
        movBtn->setObjectName(QStringLiteral("movBtn"));

        gridLayout->addWidget(movBtn, 4, 0, 1, 2);

        movZ = new QLineEdit(centralWidget);
        movZ->setObjectName(QStringLiteral("movZ"));

        gridLayout->addWidget(movZ, 3, 1, 1, 1);

        movY = new QLineEdit(centralWidget);
        movY->setObjectName(QStringLiteral("movY"));

        gridLayout->addWidget(movY, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        rotX = new QLineEdit(centralWidget);
        rotX->setObjectName(QStringLiteral("rotX"));

        gridLayout_2->addWidget(rotX, 1, 1, 1, 1);

        rotY = new QLineEdit(centralWidget);
        rotY->setObjectName(QStringLiteral("rotY"));

        gridLayout_2->addWidget(rotY, 2, 1, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        rotZ = new QLineEdit(centralWidget);
        rotZ->setObjectName(QStringLiteral("rotZ"));

        gridLayout_2->addWidget(rotZ, 3, 1, 1, 1);

        rotBtn = new QPushButton(centralWidget);
        rotBtn->setObjectName(QStringLiteral("rotBtn"));

        gridLayout_2->addWidget(rotBtn, 4, 0, 1, 2);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 0, 1, 2);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);

        verticalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_9, 0, 0, 1, 2);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        scaleK = new QLineEdit(centralWidget);
        scaleK->setObjectName(QStringLiteral("scaleK"));

        gridLayout_3->addWidget(scaleK, 1, 1, 1, 1);

        scaleBtn = new QPushButton(centralWidget);
        scaleBtn->setObjectName(QStringLiteral("scaleBtn"));

        gridLayout_3->addWidget(scaleBtn, 2, 0, 1, 2);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 2);

        verticalLayout->addLayout(gridLayout_3);

        loadBtn = new QPushButton(centralWidget);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));

        verticalLayout->addWidget(loadBtn);

        delBtn = new QPushButton(centralWidget);
        delBtn->setObjectName(QStringLiteral("delBtn"));

        verticalLayout->addWidget(delBtn);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 616, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Model viewer", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y", 0));
        movX->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "X", 0));
        label_4->setText(QApplication::translate("MainWindow", "Z", 0));
        movBtn->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        movZ->setText(QApplication::translate("MainWindow", "0", 0));
        movY->setText(QApplication::translate("MainWindow", "0", 0));
        label->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", 0));
        label_6->setText(QApplication::translate("MainWindow", "Y", 0));
        label_5->setText(QApplication::translate("MainWindow", "X", 0));
        rotX->setText(QApplication::translate("MainWindow", "0", 0));
        rotY->setText(QApplication::translate("MainWindow", "0", 0));
        label_7->setText(QApplication::translate("MainWindow", "Z", 0));
        rotZ->setText(QApplication::translate("MainWindow", "0", 0));
        rotBtn->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", 0));
        label_9->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        label_10->setText(QApplication::translate("MainWindow", "K", 0));
        scaleK->setText(QApplication::translate("MainWindow", "1", 0));
        scaleBtn->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        loadBtn->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", 0));
        delBtn->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
