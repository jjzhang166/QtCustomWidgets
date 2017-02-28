#ifndef TREENAVIGATIONBAR_H
#define TREENAVIGATIONBAR_H

#include <QWidget>



struct TreeNode : public QObject
{
    enum FoldShapeStyle
    {
        CrossStyle,//十字形
        TriangleStyle,//三角形
    };

    QString baseInfo;//基础信息
    QString extraInfo;//额外信息
    bool foldState;//折叠状态
    FoldShapeStyle foldStyle;//折叠类型
    int level;//当前层级
    QList<Node*> child;
    TreeNode(QObject *parent = 0);
    TreeNode(const QString& info, const QString& extraInfo, QObject *parent = 0);
    ~TreeNode();
    void addChild(Node* child);
};

class TreeNavigationBar : public QWidget
{
    Q_OBJECT

public:
    TreeNavigationBar(QWidget *parent = 0);
    ~TreeNavigationBar();
};

#endif // TREENAVIGATIONBAR_H
