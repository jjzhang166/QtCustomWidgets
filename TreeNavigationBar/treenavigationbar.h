#ifndef TREENAVIGATIONBAR_H
#define TREENAVIGATIONBAR_H

#include <QWidget>
#include <QMetaType>
#include <QStyledItemDelegate>

//折叠图标
class FoldShape
{
public:
    //折叠图形类型
    enum FoldShapeStyle
    {
        CrossStyle,//十字形
        TriangleStyle,//三角形
    };
    FoldShape();
    FoldShape(FoldShapeStyle style, const QColor& normal_color, const QColor& select_color);
    void paint(QPainter *painter, const QRect &rect) const;
    QSize sizeHient() const;
    void setFoldState(bool is_fold);
    bool isFold() const;

private:
    void Init();

    FoldShapeStyle m_style;
    QColor m_normalColor;
    QColor m_selectedColor;
    bool m_isFold;//折叠状态
    bool m_isSelected;//选中

    QPolygonF m_crossPolygon;
};
Q_DECLARE_METATYPE(FoldShape)

class TreeNode
{
public:
    TreeNode();
    TreeNode(FoldShape foldShape, const QString& baseInfo, const QString& extraInfo);
    ~TreeNode();
    void Init();
    void addChild(TreeNode* node);
    QColor normalColorBg() const { return m_normalColorBg; }
    QColor hoverColorBg() const { return m_hoverColorBg; }
    QColor selectedColorBg() const { return m_selectedColorBg; }
    QColor normalColorText() const { return m_normalColorText; }
    QColor hoverColorText() const { return m_hoverColorText; }
    QColor selectedColorText() const { return m_selectedColorText; }
    FoldShape foldShape() const { return m_foldShape; }
    QString baseInfo() const { return m_baseInfo; }
    QString extraInfo() const { return m_extraInfo; }
    void setFoldShape(FoldShape shape);
    void setBaseInfo(QString baseInfo);
    void setExtraInfo(QString extraInfo);
    void setNormalColorBg(QColor color);
    void setHoverColorBg(QColor color);
    void setSelectedColorBg(QColor color);
    void setNomalColorText(QColor color);
    void setHoverColorText(QColor color);
    void setSelectedColorText(QColor color);

private:
    FoldShape m_foldShape;//折叠形状
    QString m_baseInfo;//基础信息
    QString m_extraInfo;//额外信息

    QColor m_normalColorBg;
    QColor m_hoverColorBg;
    QColor m_selectedColorBg;
    QColor m_normalColorText;
    QColor m_hoverColorText;
    QColor m_selectedColorText;
    int m_level;//当前层级
    QList<TreeNode*> child;//子元素

};
Q_DECLARE_METATYPE(TreeNode)

class TreeNodeDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    TreeNodeDelegate(QWidget *parent = 0) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QSize m_size;
};



class TreeNavigationBar : public QWidget
{
    Q_OBJECT

public:
    TreeNavigationBar(QWidget *parent = 0);
    ~TreeNavigationBar();
};

#endif // TREENAVIGATIONBAR_H
