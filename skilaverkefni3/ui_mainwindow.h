/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionCreate_Person;
    QAction *actionCreate_Computer;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QHBoxLayout *middle_group;
    QGroupBox *people_group;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *filter_group_p;
    QVBoxLayout *filter_name_p_g;
    QLabel *label_4;
    QLineEdit *filter_name_p;
    QVBoxLayout *filter_gender_p_g;
    QLabel *label_3;
    QComboBox *filter_gender_p;
    QVBoxLayout *filter_birth_p_g;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QCheckBox *filter_birth_c_p;
    QDateEdit *date_birth_p;
    QVBoxLayout *filter_death_p_g;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QCheckBox *filter_death_c_p;
    QDateEdit *date_death_p;
    QTableView *people_list;
    QPushButton *pushButton_delete_person;
    QPushButton *pushButton_modify_person;
    QGroupBox *computer_group;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *filter_group_c;
    QVBoxLayout *filter_group_name_c_g;
    QLabel *label_5;
    QLineEdit *filter_name_c;
    QVBoxLayout *filter_group_type_c_g;
    QLabel *label_6;
    QLineEdit *filter_type_c;
    QVBoxLayout *filter_group_year_c_g;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QCheckBox *filter_date_c_c;
    QDateEdit *date_date_c;
    QVBoxLayout *filter_group_built_c_g;
    QLabel *label_8;
    QComboBox *filter_built_c;
    QTableView *computer_list;
    QPushButton *pushButton_delete_computer;
    QPushButton *pushButton_modify_computer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEntry;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(937, 575);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionCreate_Person = new QAction(MainWindow);
        actionCreate_Person->setObjectName(QStringLiteral("actionCreate_Person"));
        actionCreate_Computer = new QAction(MainWindow);
        actionCreate_Computer->setObjectName(QStringLiteral("actionCreate_Computer"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_7->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_7->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_7);

        middle_group = new QHBoxLayout();
        middle_group->setSpacing(6);
        middle_group->setObjectName(QStringLiteral("middle_group"));
        people_group = new QGroupBox(centralWidget);
        people_group->setObjectName(QStringLiteral("people_group"));
        verticalLayout_4 = new QVBoxLayout(people_group);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        filter_group_p = new QHBoxLayout();
        filter_group_p->setSpacing(6);
        filter_group_p->setObjectName(QStringLiteral("filter_group_p"));
        filter_name_p_g = new QVBoxLayout();
        filter_name_p_g->setSpacing(6);
        filter_name_p_g->setObjectName(QStringLiteral("filter_name_p_g"));
        label_4 = new QLabel(people_group);
        label_4->setObjectName(QStringLiteral("label_4"));

        filter_name_p_g->addWidget(label_4);

        filter_name_p = new QLineEdit(people_group);
        filter_name_p->setObjectName(QStringLiteral("filter_name_p"));

        filter_name_p_g->addWidget(filter_name_p);


        filter_group_p->addLayout(filter_name_p_g);

        filter_gender_p_g = new QVBoxLayout();
        filter_gender_p_g->setSpacing(6);
        filter_gender_p_g->setObjectName(QStringLiteral("filter_gender_p_g"));
        label_3 = new QLabel(people_group);
        label_3->setObjectName(QStringLiteral("label_3"));

        filter_gender_p_g->addWidget(label_3);

        filter_gender_p = new QComboBox(people_group);
        filter_gender_p->setObjectName(QStringLiteral("filter_gender_p"));

        filter_gender_p_g->addWidget(filter_gender_p);


        filter_group_p->addLayout(filter_gender_p_g);

        filter_birth_p_g = new QVBoxLayout();
        filter_birth_p_g->setSpacing(6);
        filter_birth_p_g->setObjectName(QStringLiteral("filter_birth_p_g"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(people_group);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        filter_birth_c_p = new QCheckBox(people_group);
        filter_birth_c_p->setObjectName(QStringLiteral("filter_birth_c_p"));

        horizontalLayout->addWidget(filter_birth_c_p);


        filter_birth_p_g->addLayout(horizontalLayout);

        date_birth_p = new QDateEdit(people_group);
        date_birth_p->setObjectName(QStringLiteral("date_birth_p"));

        filter_birth_p_g->addWidget(date_birth_p);


        filter_group_p->addLayout(filter_birth_p_g);

        filter_death_p_g = new QVBoxLayout();
        filter_death_p_g->setSpacing(6);
        filter_death_p_g->setObjectName(QStringLiteral("filter_death_p_g"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(people_group);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        filter_death_c_p = new QCheckBox(people_group);
        filter_death_c_p->setObjectName(QStringLiteral("filter_death_c_p"));

        horizontalLayout_3->addWidget(filter_death_c_p);


        filter_death_p_g->addLayout(horizontalLayout_3);

        date_death_p = new QDateEdit(people_group);
        date_death_p->setObjectName(QStringLiteral("date_death_p"));

        filter_death_p_g->addWidget(date_death_p);


        filter_group_p->addLayout(filter_death_p_g);


        verticalLayout_4->addLayout(filter_group_p);

        people_list = new QTableView(people_group);
        people_list->setObjectName(QStringLiteral("people_list"));

        verticalLayout_4->addWidget(people_list);

        pushButton_delete_person = new QPushButton(people_group);
        pushButton_delete_person->setObjectName(QStringLiteral("pushButton_delete_person"));

        verticalLayout_4->addWidget(pushButton_delete_person);

        pushButton_modify_person = new QPushButton(people_group);
        pushButton_modify_person->setObjectName(QStringLiteral("pushButton_modify_person"));

        verticalLayout_4->addWidget(pushButton_modify_person);


        middle_group->addWidget(people_group);

        computer_group = new QGroupBox(centralWidget);
        computer_group->setObjectName(QStringLiteral("computer_group"));
        verticalLayout_5 = new QVBoxLayout(computer_group);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        filter_group_c = new QHBoxLayout();
        filter_group_c->setSpacing(6);
        filter_group_c->setObjectName(QStringLiteral("filter_group_c"));
        filter_group_name_c_g = new QVBoxLayout();
        filter_group_name_c_g->setSpacing(6);
        filter_group_name_c_g->setObjectName(QStringLiteral("filter_group_name_c_g"));
        label_5 = new QLabel(computer_group);
        label_5->setObjectName(QStringLiteral("label_5"));

        filter_group_name_c_g->addWidget(label_5);

        filter_name_c = new QLineEdit(computer_group);
        filter_name_c->setObjectName(QStringLiteral("filter_name_c"));

        filter_group_name_c_g->addWidget(filter_name_c);


        filter_group_c->addLayout(filter_group_name_c_g);

        filter_group_type_c_g = new QVBoxLayout();
        filter_group_type_c_g->setSpacing(6);
        filter_group_type_c_g->setObjectName(QStringLiteral("filter_group_type_c_g"));
        label_6 = new QLabel(computer_group);
        label_6->setObjectName(QStringLiteral("label_6"));

        filter_group_type_c_g->addWidget(label_6);

        filter_type_c = new QLineEdit(computer_group);
        filter_type_c->setObjectName(QStringLiteral("filter_type_c"));

        filter_group_type_c_g->addWidget(filter_type_c);


        filter_group_c->addLayout(filter_group_type_c_g);

        filter_group_year_c_g = new QVBoxLayout();
        filter_group_year_c_g->setSpacing(6);
        filter_group_year_c_g->setObjectName(QStringLiteral("filter_group_year_c_g"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(computer_group);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        filter_date_c_c = new QCheckBox(computer_group);
        filter_date_c_c->setObjectName(QStringLiteral("filter_date_c_c"));

        horizontalLayout_4->addWidget(filter_date_c_c);


        filter_group_year_c_g->addLayout(horizontalLayout_4);

        date_date_c = new QDateEdit(computer_group);
        date_date_c->setObjectName(QStringLiteral("date_date_c"));

        filter_group_year_c_g->addWidget(date_date_c);


        filter_group_c->addLayout(filter_group_year_c_g);

        filter_group_built_c_g = new QVBoxLayout();
        filter_group_built_c_g->setSpacing(6);
        filter_group_built_c_g->setObjectName(QStringLiteral("filter_group_built_c_g"));
        label_8 = new QLabel(computer_group);
        label_8->setObjectName(QStringLiteral("label_8"));

        filter_group_built_c_g->addWidget(label_8);

        filter_built_c = new QComboBox(computer_group);
        filter_built_c->setObjectName(QStringLiteral("filter_built_c"));

        filter_group_built_c_g->addWidget(filter_built_c);


        filter_group_c->addLayout(filter_group_built_c_g);


        verticalLayout_5->addLayout(filter_group_c);

        computer_list = new QTableView(computer_group);
        computer_list->setObjectName(QStringLiteral("computer_list"));

        verticalLayout_5->addWidget(computer_list);

        pushButton_delete_computer = new QPushButton(computer_group);
        pushButton_delete_computer->setObjectName(QStringLiteral("pushButton_delete_computer"));

        verticalLayout_5->addWidget(pushButton_delete_computer);

        pushButton_modify_computer = new QPushButton(computer_group);
        pushButton_modify_computer->setObjectName(QStringLiteral("pushButton_modify_computer"));

        verticalLayout_5->addWidget(pushButton_modify_computer);


        middle_group->addWidget(computer_group);


        verticalLayout->addLayout(middle_group);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 937, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEntry = new QMenu(menuBar);
        menuEntry->setObjectName(QStringLiteral("menuEntry"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEntry->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuEntry->addAction(actionCreate_Person);
        menuEntry->addAction(actionCreate_Computer);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionCreate_Person->setText(QApplication::translate("MainWindow", "Person", 0));
        actionCreate_Computer->setText(QApplication::translate("MainWindow", "Computer", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Create Person ( Debug )", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Create Computer ( Debug )", 0));
        people_group->setTitle(QApplication::translate("MainWindow", "People", 0));
        label_4->setText(QApplication::translate("MainWindow", "Filter by name:", 0));
        filter_name_p->setPlaceholderText(QApplication::translate("MainWindow", "Filter name", 0));
        label_3->setText(QApplication::translate("MainWindow", "Filter by gender:", 0));
        filter_gender_p->setCurrentText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Filter by birth:", 0));
        filter_birth_c_p->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Filter by death:", 0));
        filter_death_c_p->setText(QString());
        pushButton_delete_person->setText(QApplication::translate("MainWindow", "Delete Selected", 0));
        pushButton_modify_person->setText(QApplication::translate("MainWindow", "Modify Selected", 0));
        computer_group->setTitle(QApplication::translate("MainWindow", "Computers", 0));
        label_5->setText(QApplication::translate("MainWindow", "Filter by name:", 0));
        filter_name_c->setPlaceholderText(QApplication::translate("MainWindow", "Filter name", 0));
        label_6->setText(QApplication::translate("MainWindow", "Filter by type:", 0));
        filter_type_c->setPlaceholderText(QApplication::translate("MainWindow", "Filter type", 0));
        label_7->setText(QApplication::translate("MainWindow", "Filter by year:", 0));
        filter_date_c_c->setText(QString());
        date_date_c->setDisplayFormat(QApplication::translate("MainWindow", "yyyy", 0));
        label_8->setText(QApplication::translate("MainWindow", "Filter by built:", 0));
        pushButton_delete_computer->setText(QApplication::translate("MainWindow", "Delete Selected", 0));
        pushButton_modify_computer->setText(QApplication::translate("MainWindow", "Modify Selected", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEntry->setTitle(QApplication::translate("MainWindow", "Create", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
