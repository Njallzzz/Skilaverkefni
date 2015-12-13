/********************************************************************************
** Form generated from reading UI file 'personwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONWINDOW_H
#define UI_PERSONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonWindow
{
public:
    QLabel *label;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *nameInput;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_4;
    QDateEdit *deathInput;
    QDateEdit *birthInput;
    QComboBox *genderInput;
    QCheckBox *isAliveCheckBox;
    QLabel *label_6;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QPushButton *addRelationButton;

    void setupUi(QDialog *PersonWindow)
    {
        if (PersonWindow->objectName().isEmpty())
            PersonWindow->setObjectName(QStringLiteral("PersonWindow"));
        PersonWindow->resize(350, 280);
        PersonWindow->setMinimumSize(QSize(350, 280));
        PersonWindow->setMaximumSize(QSize(350, 280));
        label = new QLabel(PersonWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 171, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        gridLayoutWidget_2 = new QWidget(PersonWindow);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 50, 301, 161));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        nameInput = new QLineEdit(gridLayoutWidget_2);
        nameInput->setObjectName(QStringLiteral("nameInput"));

        gridLayout_2->addWidget(nameInput, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        deathInput = new QDateEdit(gridLayoutWidget_2);
        deathInput->setObjectName(QStringLiteral("deathInput"));

        gridLayout_2->addWidget(deathInput, 4, 1, 1, 1);

        birthInput = new QDateEdit(gridLayoutWidget_2);
        birthInput->setObjectName(QStringLiteral("birthInput"));

        gridLayout_2->addWidget(birthInput, 2, 1, 1, 1);

        genderInput = new QComboBox(gridLayoutWidget_2);
        genderInput->setObjectName(QStringLiteral("genderInput"));

        gridLayout_2->addWidget(genderInput, 1, 1, 1, 1);

        isAliveCheckBox = new QCheckBox(gridLayoutWidget_2);
        isAliveCheckBox->setObjectName(QStringLiteral("isAliveCheckBox"));

        gridLayout_2->addWidget(isAliveCheckBox, 3, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        gridLayoutWidget = new QWidget(PersonWindow);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 210, 309, 33));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(gridLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        QFont font2;
        font2.setPointSize(10);
        cancelButton->setFont(font2);

        gridLayout->addWidget(cancelButton, 0, 2, 1, 1);

        saveButton = new QPushButton(gridLayoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setFont(font2);

        gridLayout->addWidget(saveButton, 0, 0, 1, 1);

        addRelationButton = new QPushButton(gridLayoutWidget);
        addRelationButton->setObjectName(QStringLiteral("addRelationButton"));
        addRelationButton->setFont(font2);

        gridLayout->addWidget(addRelationButton, 0, 1, 1, 1);


        retranslateUi(PersonWindow);

        QMetaObject::connectSlotsByName(PersonWindow);
    } // setupUi

    void retranslateUi(QDialog *PersonWindow)
    {
        PersonWindow->setWindowTitle(QApplication::translate("PersonWindow", "Dialog", 0));
        label->setText(QApplication::translate("PersonWindow", "New person", 0));
        label_3->setText(QApplication::translate("PersonWindow", "Gender", 0));
        label_5->setText(QApplication::translate("PersonWindow", "Death", 0));
        label_2->setText(QApplication::translate("PersonWindow", "Name", 0));
        label_4->setText(QApplication::translate("PersonWindow", "Birth", 0));
        isAliveCheckBox->setText(QString());
        label_6->setText(QApplication::translate("PersonWindow", "Alive", 0));
        cancelButton->setText(QApplication::translate("PersonWindow", "Cancel", 0));
        saveButton->setText(QApplication::translate("PersonWindow", "Save", 0));
        addRelationButton->setText(QApplication::translate("PersonWindow", "Add relation", 0));
    } // retranslateUi

};

namespace Ui {
    class PersonWindow: public Ui_PersonWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONWINDOW_H
