#include "treenavigationbartest.h"
#include <QApplication>

#include "treenavigationbar.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TreeNode root;
    root.baseInfo = "root";
    root.extraInfo = "root_exInfo";
    root.foldState = true;
    root.foldStyle = TreeNode::CrossStyle;
    root.level = 0;

    TreeNode* child1 = new TreeNode();
    child1->baseInfo = "child1";
    child1->extraInfo = "child1_exInfo";
    child1->foldState = true;
    child1->foldStyle = TreeNode::CrossStyle;
    child1->level = 1;
    TreeNode* child2 = new TreeNode();
    child2->baseInfo = "child2";
    child2->extraInfo = "child2_exInfo";
    child2->foldState = true;
    child2->foldStyle = TreeNode::CrossStyle;
    child2->level = 1;

    root.child.append(child1);
    root.child.append(child2);



    TreeNavigationBarTest w;
    w.show();

    return a.exec();
}
