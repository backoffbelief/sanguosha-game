/********************************************************************************
** Form generated from reading UI file 'distanceviewdialog.ui'
**
** Created: Fri May 20 22:18:04 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISTANCEVIEWDIALOG_H
#define UI_DISTANCEVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DistanceViewDialog
{
public:
    QGroupBox *groupBox;
    QLabel *ohorseYicongLabel;
    QLabel *dhorseYicongLabel;
    QLineEdit *ohorseLineEdit;
    QLineEdit *mashuLineEdit;
    QLineEdit *ohorseYicongLineEdit;
    QLineEdit *dhorseLineEdit;
    QLineEdit *feiyingLineEdit;
    QLineEdit *dhorseYicongLineEdit;
    QLabel *offensiveHorseLabel;
    QLabel *mashuLabel;
    QLabel *feiyingLabel;
    QLabel *defensiveHorseLabel;
    QLabel *leftDistanceLabel;
    QLineEdit *rightDistanceLineEdit;
    QLineEdit *leftDistanceLineEdit;
    QLabel *rightDistanceLabel;
    QLabel *finalResultLabel;
    QLineEdit *finalResultLineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *seatLabel;
    QLineEdit *fromSeatLineEdit;
    QLineEdit *toSeatLineEdit;
    QLabel *attackRangeLabel;
    QLineEdit *attackRangeLineEdit;
    QLabel *inAttackRangeLabel;
    QLineEdit *inAttackRangeLineEdit;
    QComboBox *fromCombobox;
    QLabel *fromLabel;
    QLabel *label_2;
    QComboBox *toCombobox;
    QLabel *minorValueLabel;
    QLineEdit *minorValueLineEdit;

    void setupUi(QDialog *DistanceViewDialog)
    {
        if (DistanceViewDialog->objectName().isEmpty())
            DistanceViewDialog->setObjectName(QString::fromUtf8("DistanceViewDialog"));
        DistanceViewDialog->resize(418, 252);
        groupBox = new QGroupBox(DistanceViewDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 130, 391, 81));
        ohorseYicongLabel = new QLabel(groupBox);
        ohorseYicongLabel->setObjectName(QString::fromUtf8("ohorseYicongLabel"));
        ohorseYicongLabel->setGeometry(QRect(260, 20, 54, 12));
        dhorseYicongLabel = new QLabel(groupBox);
        dhorseYicongLabel->setObjectName(QString::fromUtf8("dhorseYicongLabel"));
        dhorseYicongLabel->setGeometry(QRect(260, 50, 54, 12));
        ohorseLineEdit = new QLineEdit(groupBox);
        ohorseLineEdit->setObjectName(QString::fromUtf8("ohorseLineEdit"));
        ohorseLineEdit->setGeometry(QRect(80, 20, 51, 20));
        mashuLineEdit = new QLineEdit(groupBox);
        mashuLineEdit->setObjectName(QString::fromUtf8("mashuLineEdit"));
        mashuLineEdit->setGeometry(QRect(190, 20, 51, 20));
        ohorseYicongLineEdit = new QLineEdit(groupBox);
        ohorseYicongLineEdit->setObjectName(QString::fromUtf8("ohorseYicongLineEdit"));
        ohorseYicongLineEdit->setGeometry(QRect(330, 20, 51, 20));
        dhorseLineEdit = new QLineEdit(groupBox);
        dhorseLineEdit->setObjectName(QString::fromUtf8("dhorseLineEdit"));
        dhorseLineEdit->setGeometry(QRect(80, 50, 51, 20));
        feiyingLineEdit = new QLineEdit(groupBox);
        feiyingLineEdit->setObjectName(QString::fromUtf8("feiyingLineEdit"));
        feiyingLineEdit->setGeometry(QRect(190, 50, 51, 20));
        dhorseYicongLineEdit = new QLineEdit(groupBox);
        dhorseYicongLineEdit->setObjectName(QString::fromUtf8("dhorseYicongLineEdit"));
        dhorseYicongLineEdit->setGeometry(QRect(330, 50, 51, 20));
        offensiveHorseLabel = new QLabel(groupBox);
        offensiveHorseLabel->setObjectName(QString::fromUtf8("offensiveHorseLabel"));
        offensiveHorseLabel->setGeometry(QRect(20, 20, 48, 16));
        mashuLabel = new QLabel(groupBox);
        mashuLabel->setObjectName(QString::fromUtf8("mashuLabel"));
        mashuLabel->setGeometry(QRect(150, 20, 30, 16));
        feiyingLabel = new QLabel(groupBox);
        feiyingLabel->setObjectName(QString::fromUtf8("feiyingLabel"));
        feiyingLabel->setGeometry(QRect(140, 50, 42, 16));
        defensiveHorseLabel = new QLabel(groupBox);
        defensiveHorseLabel->setObjectName(QString::fromUtf8("defensiveHorseLabel"));
        defensiveHorseLabel->setGeometry(QRect(20, 50, 48, 16));
        leftDistanceLabel = new QLabel(DistanceViewDialog);
        leftDistanceLabel->setObjectName(QString::fromUtf8("leftDistanceLabel"));
        leftDistanceLabel->setGeometry(QRect(20, 80, 78, 16));
        rightDistanceLineEdit = new QLineEdit(DistanceViewDialog);
        rightDistanceLineEdit->setObjectName(QString::fromUtf8("rightDistanceLineEdit"));
        rightDistanceLineEdit->setGeometry(QRect(140, 100, 51, 20));
        rightDistanceLineEdit->setReadOnly(true);
        leftDistanceLineEdit = new QLineEdit(DistanceViewDialog);
        leftDistanceLineEdit->setObjectName(QString::fromUtf8("leftDistanceLineEdit"));
        leftDistanceLineEdit->setGeometry(QRect(30, 100, 51, 20));
        leftDistanceLineEdit->setReadOnly(true);
        rightDistanceLabel = new QLabel(DistanceViewDialog);
        rightDistanceLabel->setObjectName(QString::fromUtf8("rightDistanceLabel"));
        rightDistanceLabel->setGeometry(QRect(120, 80, 84, 16));
        finalResultLabel = new QLabel(DistanceViewDialog);
        finalResultLabel->setObjectName(QString::fromUtf8("finalResultLabel"));
        finalResultLabel->setGeometry(QRect(30, 220, 72, 12));
        finalResultLineEdit = new QLineEdit(DistanceViewDialog);
        finalResultLineEdit->setObjectName(QString::fromUtf8("finalResultLineEdit"));
        finalResultLineEdit->setGeometry(QRect(120, 220, 51, 20));
        finalResultLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        finalResultLineEdit->setReadOnly(true);
        layoutWidget = new QWidget(DistanceViewDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 221, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        seatLabel = new QLabel(layoutWidget);
        seatLabel->setObjectName(QString::fromUtf8("seatLabel"));

        horizontalLayout_3->addWidget(seatLabel);

        fromSeatLineEdit = new QLineEdit(layoutWidget);
        fromSeatLineEdit->setObjectName(QString::fromUtf8("fromSeatLineEdit"));
        fromSeatLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fromSeatLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(fromSeatLineEdit);

        toSeatLineEdit = new QLineEdit(layoutWidget);
        toSeatLineEdit->setObjectName(QString::fromUtf8("toSeatLineEdit"));
        toSeatLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        toSeatLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(toSeatLineEdit);

        attackRangeLabel = new QLabel(DistanceViewDialog);
        attackRangeLabel->setObjectName(QString::fromUtf8("attackRangeLabel"));
        attackRangeLabel->setGeometry(QRect(240, 20, 141, 16));
        attackRangeLineEdit = new QLineEdit(DistanceViewDialog);
        attackRangeLineEdit->setObjectName(QString::fromUtf8("attackRangeLineEdit"));
        attackRangeLineEdit->setGeometry(QRect(240, 50, 121, 20));
        attackRangeLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        attackRangeLineEdit->setReadOnly(true);
        inAttackRangeLabel = new QLabel(DistanceViewDialog);
        inAttackRangeLabel->setObjectName(QString::fromUtf8("inAttackRangeLabel"));
        inAttackRangeLabel->setGeometry(QRect(210, 220, 90, 12));
        inAttackRangeLineEdit = new QLineEdit(DistanceViewDialog);
        inAttackRangeLineEdit->setObjectName(QString::fromUtf8("inAttackRangeLineEdit"));
        inAttackRangeLineEdit->setGeometry(QRect(330, 220, 61, 20));
        fromCombobox = new QComboBox(DistanceViewDialog);
        fromCombobox->setObjectName(QString::fromUtf8("fromCombobox"));
        fromCombobox->setGeometry(QRect(50, 20, 69, 20));
        fromLabel = new QLabel(DistanceViewDialog);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));
        fromLabel->setGeometry(QRect(11, 21, 24, 16));
        label_2 = new QLabel(DistanceViewDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 20, 16, 16));
        toCombobox = new QComboBox(DistanceViewDialog);
        toCombobox->setObjectName(QString::fromUtf8("toCombobox"));
        toCombobox->setGeometry(QRect(160, 20, 69, 20));
        minorValueLabel = new QLabel(DistanceViewDialog);
        minorValueLabel->setObjectName(QString::fromUtf8("minorValueLabel"));
        minorValueLabel->setGeometry(QRect(230, 80, 66, 12));
        minorValueLineEdit = new QLineEdit(DistanceViewDialog);
        minorValueLineEdit->setObjectName(QString::fromUtf8("minorValueLineEdit"));
        minorValueLineEdit->setGeometry(QRect(240, 100, 51, 20));

        retranslateUi(DistanceViewDialog);

        QMetaObject::connectSlotsByName(DistanceViewDialog);
    } // setupUi

    void retranslateUi(QDialog *DistanceViewDialog)
    {
        DistanceViewDialog->setWindowTitle(QApplication::translate("DistanceViewDialog", "View distance", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DistanceViewDialog", "Correct value", 0, QApplication::UnicodeUTF8));
        ohorseYicongLabel->setText(QApplication::translate("DistanceViewDialog", "-1 Yicong", 0, QApplication::UnicodeUTF8));
        dhorseYicongLabel->setText(QApplication::translate("DistanceViewDialog", "+1 Yicong", 0, QApplication::UnicodeUTF8));
        offensiveHorseLabel->setText(QApplication::translate("DistanceViewDialog", "-1 Horse", 0, QApplication::UnicodeUTF8));
        mashuLabel->setText(QApplication::translate("DistanceViewDialog", "Mashu", 0, QApplication::UnicodeUTF8));
        feiyingLabel->setText(QApplication::translate("DistanceViewDialog", "Feiying", 0, QApplication::UnicodeUTF8));
        defensiveHorseLabel->setText(QApplication::translate("DistanceViewDialog", "+1 Horse", 0, QApplication::UnicodeUTF8));
        leftDistanceLabel->setText(QApplication::translate("DistanceViewDialog", "Left distance", 0, QApplication::UnicodeUTF8));
        rightDistanceLabel->setText(QApplication::translate("DistanceViewDialog", "Right distance", 0, QApplication::UnicodeUTF8));
        finalResultLabel->setText(QApplication::translate("DistanceViewDialog", "Final result", 0, QApplication::UnicodeUTF8));
        seatLabel->setText(QApplication::translate("DistanceViewDialog", "Seat", 0, QApplication::UnicodeUTF8));
        attackRangeLabel->setText(QApplication::translate("DistanceViewDialog", "Attack Range of Source", 0, QApplication::UnicodeUTF8));
        inAttackRangeLabel->setText(QApplication::translate("DistanceViewDialog", "In Attack Range", 0, QApplication::UnicodeUTF8));
        fromLabel->setText(QApplication::translate("DistanceViewDialog", "From", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DistanceViewDialog", "to", 0, QApplication::UnicodeUTF8));
        minorValueLabel->setText(QApplication::translate("DistanceViewDialog", "Minor value", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DistanceViewDialog: public Ui_DistanceViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISTANCEVIEWDIALOG_H
