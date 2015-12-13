/********************************************************************************
** Form generated from reading UI file 'computerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTERWINDOW_H
#define UI_COMPUTERWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ComputerWindow
{
public:
    QFrame *frame;
    QVBoxLayout *verticalLayout_computer;
    QLabel *label_new_person;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_computer_name;
    QLabel *label_computer_type;
    QLabel *label_computer_date;
    QLabel *label_computer_ifBuilt;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_computer_name;
    QLabel *label_name_error_star;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_computer_type;
    QLabel *label_type_error_star;
    QHBoxLayout *horizontalLayout_5;
    QDateEdit *dateEdit_year_built;
    QLabel *label_date_error_star;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_yes;
    QRadioButton *radioButton_no;
    QLabel *label_built_error_star;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_computer_save;
    QPushButton *pushButton_computer_addRelation;
    QPushButton *pushButton_computer_cancel;
    QLabel *label_computer_error;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *ComputerWindow)
    {
        if (ComputerWindow->objectName().isEmpty())
            ComputerWindow->setObjectName(QStringLiteral("ComputerWindow"));
        ComputerWindow->resize(300, 260);
        ComputerWindow->setMinimumSize(QSize(300, 220));
        ComputerWindow->setMaximumSize(QSize(300, 260));
        frame = new QFrame(ComputerWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 280, 230));
        frame->setMinimumSize(QSize(280, 230));
        frame->setMaximumSize(QSize(280, 230));
        verticalLayout_computer = new QVBoxLayout(frame);
        verticalLayout_computer->setObjectName(QStringLiteral("verticalLayout_computer"));
        verticalLayout_computer->setSizeConstraint(QLayout::SetFixedSize);
        label_new_person = new QLabel(frame);
        label_new_person->setObjectName(QStringLiteral("label_new_person"));

        verticalLayout_computer->addWidget(label_new_person, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_computer_name = new QLabel(frame);
        label_computer_name->setObjectName(QStringLiteral("label_computer_name"));

        verticalLayout->addWidget(label_computer_name, 0, Qt::AlignRight);

        label_computer_type = new QLabel(frame);
        label_computer_type->setObjectName(QStringLiteral("label_computer_type"));

        verticalLayout->addWidget(label_computer_type, 0, Qt::AlignRight);

        label_computer_date = new QLabel(frame);
        label_computer_date->setObjectName(QStringLiteral("label_computer_date"));

        verticalLayout->addWidget(label_computer_date, 0, Qt::AlignRight);

        label_computer_ifBuilt = new QLabel(frame);
        label_computer_ifBuilt->setObjectName(QStringLiteral("label_computer_ifBuilt"));

        verticalLayout->addWidget(label_computer_ifBuilt);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 2, -1, -1);
        lineEdit_computer_name = new QLineEdit(frame);
        lineEdit_computer_name->setObjectName(QStringLiteral("lineEdit_computer_name"));
        lineEdit_computer_name->setMinimumSize(QSize(0, 0));

        horizontalLayout_6->addWidget(lineEdit_computer_name);

        label_name_error_star = new QLabel(frame);
        label_name_error_star->setObjectName(QStringLiteral("label_name_error_star"));

        horizontalLayout_6->addWidget(label_name_error_star);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 3, -1, -1);
        lineEdit_computer_type = new QLineEdit(frame);
        lineEdit_computer_type->setObjectName(QStringLiteral("lineEdit_computer_type"));
        lineEdit_computer_type->setMinimumSize(QSize(0, 0));

        horizontalLayout_7->addWidget(lineEdit_computer_type);

        label_type_error_star = new QLabel(frame);
        label_type_error_star->setObjectName(QStringLiteral("label_type_error_star"));

        horizontalLayout_7->addWidget(label_type_error_star);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_5->setContentsMargins(-1, 2, -1, -1);
        dateEdit_year_built = new QDateEdit(frame);
        dateEdit_year_built->setObjectName(QStringLiteral("dateEdit_year_built"));
        dateEdit_year_built->setMinimumSize(QSize(90, 24));
        dateEdit_year_built->setMaximumSize(QSize(90, 24));
        dateEdit_year_built->setAlignment(Qt::AlignCenter);
        dateEdit_year_built->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        dateEdit_year_built->setMaximumDate(QDate(7920, 12, 31));
        dateEdit_year_built->setCurrentSection(QDateTimeEdit::YearSection);
        dateEdit_year_built->setDisplayFormat(QStringLiteral("yyyy"));
        dateEdit_year_built->setCalendarPopup(false);

        horizontalLayout_5->addWidget(dateEdit_year_built);

        label_date_error_star = new QLabel(frame);
        label_date_error_star->setObjectName(QStringLiteral("label_date_error_star"));
        label_date_error_star->setTextFormat(Qt::AutoText);

        horizontalLayout_5->addWidget(label_date_error_star);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        radioButton_yes = new QRadioButton(frame);
        buttonGroup = new QButtonGroup(ComputerWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_yes);
        radioButton_yes->setObjectName(QStringLiteral("radioButton_yes"));
        radioButton_yes->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(radioButton_yes, 0, Qt::AlignLeft);

        radioButton_no = new QRadioButton(frame);
        buttonGroup->addButton(radioButton_no);
        radioButton_no->setObjectName(QStringLiteral("radioButton_no"));
        radioButton_no->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(radioButton_no);

        label_built_error_star = new QLabel(frame);
        label_built_error_star->setObjectName(QStringLiteral("label_built_error_star"));
        label_built_error_star->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(label_built_error_star);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_computer->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_computer_save = new QPushButton(frame);
        pushButton_computer_save->setObjectName(QStringLiteral("pushButton_computer_save"));

        horizontalLayout_3->addWidget(pushButton_computer_save);

        pushButton_computer_addRelation = new QPushButton(frame);
        pushButton_computer_addRelation->setObjectName(QStringLiteral("pushButton_computer_addRelation"));

        horizontalLayout_3->addWidget(pushButton_computer_addRelation);

        pushButton_computer_cancel = new QPushButton(frame);
        pushButton_computer_cancel->setObjectName(QStringLiteral("pushButton_computer_cancel"));

        horizontalLayout_3->addWidget(pushButton_computer_cancel);


        verticalLayout_computer->addLayout(horizontalLayout_3);

        label_computer_error = new QLabel(ComputerWindow);
        label_computer_error->setObjectName(QStringLiteral("label_computer_error"));
        label_computer_error->setGeometry(QRect(10, 220, 271, 31));

        retranslateUi(ComputerWindow);

        QMetaObject::connectSlotsByName(ComputerWindow);
    } // setupUi

    void retranslateUi(QDialog *ComputerWindow)
    {
        ComputerWindow->setWindowTitle(QApplication::translate("ComputerWindow", "Computer", 0));
        label_new_person->setText(QApplication::translate("ComputerWindow", "<font size=\"5\">New Computer</font>", 0));
        label_computer_name->setText(QApplication::translate("ComputerWindow", "Name:", 0));
        label_computer_type->setText(QApplication::translate("ComputerWindow", "Type:", 0));
        label_computer_date->setText(QApplication::translate("ComputerWindow", "Date:", 0));
        label_computer_ifBuilt->setText(QApplication::translate("ComputerWindow", "Was it built:", 0));
        label_name_error_star->setText(QApplication::translate("ComputerWindow", "*", 0));
        label_type_error_star->setText(QApplication::translate("ComputerWindow", "*", 0));
        label_date_error_star->setText(QApplication::translate("ComputerWindow", "<font color=\"white\"> Error </font>", 0));
        radioButton_yes->setText(QApplication::translate("ComputerWindow", "Yes", 0));
        radioButton_no->setText(QApplication::translate("ComputerWindow", "No", 0));
        label_built_error_star->setText(QApplication::translate("ComputerWindow", "<font color=\"white\"> Error </font>", 0));
        pushButton_computer_save->setText(QApplication::translate("ComputerWindow", "Save", 0));
        pushButton_computer_addRelation->setText(QApplication::translate("ComputerWindow", "Add relation", 0));
        pushButton_computer_cancel->setText(QApplication::translate("ComputerWindow", "Cancel", 0));
        label_computer_error->setText(QApplication::translate("ComputerWindow", "<font color='red'>*All textboxes and buttons must be filled in<br>or checked</font>", 0));
    } // retranslateUi

};

namespace Ui {
    class ComputerWindow: public Ui_ComputerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTERWINDOW_H
