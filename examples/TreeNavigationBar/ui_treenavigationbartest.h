/********************************************************************************
** Form generated from reading UI file 'treenavigationbartest.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREENAVIGATIONBARTEST_H
#define UI_TREENAVIGATIONBARTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeNavigationBarTest
{
public:

    void setupUi(QWidget *TreeNavigationBarTest)
    {
        if (TreeNavigationBarTest->objectName().isEmpty())
            TreeNavigationBarTest->setObjectName(QStringLiteral("TreeNavigationBarTest"));
        TreeNavigationBarTest->resize(400, 300);

        retranslateUi(TreeNavigationBarTest);

        QMetaObject::connectSlotsByName(TreeNavigationBarTest);
    } // setupUi

    void retranslateUi(QWidget *TreeNavigationBarTest)
    {
        TreeNavigationBarTest->setWindowTitle(QApplication::translate("TreeNavigationBarTest", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class TreeNavigationBarTest: public Ui_TreeNavigationBarTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREENAVIGATIONBARTEST_H
