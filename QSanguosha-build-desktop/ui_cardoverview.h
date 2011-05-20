/********************************************************************************
** Form generated from reading UI file 'cardoverview.ui'
**
** Created: Fri May 20 22:18:04 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDOVERVIEW_H
#define UI_CARDOVERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CardOverview
{
public:
    QTableWidget *tableWidget;
    QTextEdit *cardDescriptionBox;
    QLabel *cardLabel;
    QPushButton *getCardButton;
    QPushButton *malePlayButton;
    QPushButton *femalePlayButton;

    void setupUi(QDialog *CardOverview)
    {
        if (CardOverview->objectName().isEmpty())
            CardOverview->setObjectName(QString::fromUtf8("CardOverview"));
        CardOverview->resize(752, 561);
        tableWidget = new QTableWidget(CardOverview);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 491, 521));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        cardDescriptionBox = new QTextEdit(CardOverview);
        cardDescriptionBox->setObjectName(QString::fromUtf8("cardDescriptionBox"));
        cardDescriptionBox->setGeometry(QRect(520, 320, 211, 141));
        cardDescriptionBox->setReadOnly(true);
        cardLabel = new QLabel(CardOverview);
        cardLabel->setObjectName(QString::fromUtf8("cardLabel"));
        cardLabel->setGeometry(QRect(520, 10, 211, 301));
        getCardButton = new QPushButton(CardOverview);
        getCardButton->setObjectName(QString::fromUtf8("getCardButton"));
        getCardButton->setGeometry(QRect(600, 510, 131, 23));
        malePlayButton = new QPushButton(CardOverview);
        malePlayButton->setObjectName(QString::fromUtf8("malePlayButton"));
        malePlayButton->setGeometry(QRect(520, 470, 91, 23));
        femalePlayButton = new QPushButton(CardOverview);
        femalePlayButton->setObjectName(QString::fromUtf8("femalePlayButton"));
        femalePlayButton->setGeometry(QRect(634, 470, 91, 23));

        retranslateUi(CardOverview);

        QMetaObject::connectSlotsByName(CardOverview);
    } // setupUi

    void retranslateUi(QDialog *CardOverview)
    {
        CardOverview->setWindowTitle(QApplication::translate("CardOverview", "Card Overvew", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CardOverview", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CardOverview", "Suit", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CardOverview", "Point", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CardOverview", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CardOverview", "Subtype", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("CardOverview", "Package", 0, QApplication::UnicodeUTF8));
        cardLabel->setText(QString());
        getCardButton->setText(QApplication::translate("CardOverview", "Get this card", 0, QApplication::UnicodeUTF8));
        malePlayButton->setText(QApplication::translate("CardOverview", "Play (male)", 0, QApplication::UnicodeUTF8));
        femalePlayButton->setText(QApplication::translate("CardOverview", "Play (female)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CardOverview: public Ui_CardOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDOVERVIEW_H
