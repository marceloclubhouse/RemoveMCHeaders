/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_location;
    QLineEdit *lineEdit_location;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_browse;
    QPushButton *pushButton_remove;
    QLabel *label_status;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(259, 137);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMaximumSize(QSize(261, 137));
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_location = new QLabel(Dialog);
        label_location->setObjectName(QString::fromUtf8("label_location"));

        verticalLayout->addWidget(label_location);

        lineEdit_location = new QLineEdit(Dialog);
        lineEdit_location->setObjectName(QString::fromUtf8("lineEdit_location"));

        verticalLayout->addWidget(lineEdit_location);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_browse = new QPushButton(Dialog);
        pushButton_browse->setObjectName(QString::fromUtf8("pushButton_browse"));

        horizontalLayout->addWidget(pushButton_browse);

        pushButton_remove = new QPushButton(Dialog);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));

        horizontalLayout->addWidget(pushButton_remove);


        verticalLayout->addLayout(horizontalLayout);

        label_status = new QLabel(Dialog);
        label_status->setObjectName(QString::fromUtf8("label_status"));

        verticalLayout->addWidget(label_status);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Remove MC Headers", nullptr));
        label_location->setText(QCoreApplication::translate("Dialog", "File Location", nullptr));
        pushButton_browse->setText(QCoreApplication::translate("Dialog", "Browse", nullptr));
        pushButton_remove->setText(QCoreApplication::translate("Dialog", "Remove Headers", nullptr));
        label_status->setText(QCoreApplication::translate("Dialog", "Select file to remove MC headers from.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_WINDOW_H
