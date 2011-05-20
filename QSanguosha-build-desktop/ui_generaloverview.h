/********************************************************************************
** Form generated from reading UI file 'generaloverview.ui'
**
** Created: Fri May 20 22:18:04 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALOVERVIEW_H
#define UI_GENERALOVERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QScrollArea>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralOverview
{
public:
    QTableWidget *tableWidget;
    QLabel *skillLabel;
    QTextEdit *skillTextEdit;
    QLabel *generalPhoto;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *designerLabel;
    QLineEdit *designerLineEdit;
    QLabel *cvLabel;
    QLineEdit *cvLineEdit;

    void setupUi(QDialog *GeneralOverview)
    {
        if (GeneralOverview->objectName().isEmpty())
            GeneralOverview->setObjectName(QString::fromUtf8("GeneralOverview"));
        GeneralOverview->setWindowModality(Qt::NonModal);
        GeneralOverview->resize(905, 611);
        tableWidget = new QTableWidget(GeneralOverview);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 411, 581));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        skillLabel = new QLabel(GeneralOverview);
        skillLabel->setObjectName(QString::fromUtf8("skillLabel"));
        skillLabel->setGeometry(QRect(450, 310, 30, 12));
        skillTextEdit = new QTextEdit(GeneralOverview);
        skillTextEdit->setObjectName(QString::fromUtf8("skillTextEdit"));
        skillTextEdit->setGeometry(QRect(440, 330, 211, 261));
        skillTextEdit->setReadOnly(true);
        generalPhoto = new QLabel(GeneralOverview);
        generalPhoto->setObjectName(QString::fromUtf8("generalPhoto"));
        generalPhoto->setGeometry(QRect(450, 10, 200, 290));
        generalPhoto->setPixmap(QPixmap(QString::fromUtf8("../image/generals/card/caocao.jpg")));
        scrollArea = new QScrollArea(GeneralOverview);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(670, 80, 221, 511));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 221, 511));
        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget = new QWidget(GeneralOverview);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(670, 20, 221, 48));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        designerLabel = new QLabel(layoutWidget);
        designerLabel->setObjectName(QString::fromUtf8("designerLabel"));

        gridLayout->addWidget(designerLabel, 0, 0, 1, 1);

        designerLineEdit = new QLineEdit(layoutWidget);
        designerLineEdit->setObjectName(QString::fromUtf8("designerLineEdit"));
        designerLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        designerLineEdit->setReadOnly(true);

        gridLayout->addWidget(designerLineEdit, 0, 1, 1, 1);

        cvLabel = new QLabel(layoutWidget);
        cvLabel->setObjectName(QString::fromUtf8("cvLabel"));

        gridLayout->addWidget(cvLabel, 1, 0, 1, 1);

        cvLineEdit = new QLineEdit(layoutWidget);
        cvLineEdit->setObjectName(QString::fromUtf8("cvLineEdit"));
        cvLineEdit->setFrame(true);
        cvLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cvLineEdit->setReadOnly(true);

        gridLayout->addWidget(cvLineEdit, 1, 1, 1, 1);


        retranslateUi(GeneralOverview);

        QMetaObject::connectSlotsByName(GeneralOverview);
    } // setupUi

    void retranslateUi(QDialog *GeneralOverview)
    {
        GeneralOverview->setWindowTitle(QApplication::translate("GeneralOverview", "General Overview", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GeneralOverview", "General", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GeneralOverview", "Kingdom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GeneralOverview", "Gender", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GeneralOverview", "MaxHP", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("GeneralOverview", "Package", 0, QApplication::UnicodeUTF8));
        skillLabel->setText(QApplication::translate("GeneralOverview", "Skill", 0, QApplication::UnicodeUTF8));
        generalPhoto->setText(QString());
        designerLabel->setText(QApplication::translate("GeneralOverview", "Designer", 0, QApplication::UnicodeUTF8));
        cvLabel->setText(QApplication::translate("GeneralOverview", "CV", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GeneralOverview: public Ui_GeneralOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALOVERVIEW_H
