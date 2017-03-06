#include "treenavigationbar.h"
#include <QPainter>

const int PaintingScaleFactor = 20;//折叠图形缩放比例
const int TreeNodeExtraSpace = 50;//节点额外空间
FoldShape::FoldShape()
{
    m_style = CrossStyle;
    m_normalColor = Qt::black;
    m_selectedColor = Qt::white;
    Init();
}

FoldShape::FoldShape(FoldShape::FoldShapeStyle style, const QColor& normal_color, const QColor& select_color)
{
    m_style = style;
    m_normalColor = normal_color;
    m_selectedColor = select_color;
    Init();
}

void FoldShape::paint(QPainter *painter, const QRect &rect) const
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_isSelected?m_selectedColor:m_normalColor);

    int yOffset = (rect.height() - PaintingScaleFactor) / 2;
    painter->translate(rect.x(), rect.y() + yOffset);
    painter->scale(PaintingScaleFactor, PaintingScaleFactor);
    switch(m_style)
    {
    case CrossStyle:
        painter->drawPolygon(m_crossPolygon, Qt::WindingFill);
        break;
    default:
        break;
    }

    painter->restore();
}

QSize FoldShape::sizeHient() const
{
    return PaintingScaleFactor * QSize(myMaxStarCount, 1);
}

void FoldShape::setFoldState(bool is_fold)
{
    m_isFold = is_fold;
}

bool FoldShape::isFold() const
{
    return m_isFold;
}

void FoldShape::Init()
{
    m_isFold = true;
    m_isSelected = false;
    m_crossPolygon << QPointF(0.2, 0.4) << QPointF(0.4, 0.4) << QPointF(0.4, 0.2)
                   << QPointF(0.6, 0.2) << QPointF(0.6, 0.4) << QPointF(0.8, 0.4)
                   << QPointF(0.8, 0.6) << QPointF(0.6, 0.6) << QPointF(0.6, 0.8)
                   << QPointF(0.4, 0.8) << QPointF(0.4, 0.6) << QPointF(0.2, 0.6)
                   << QPointF(0.2, 0.4);
}

TreeNode::TreeNode()
{
    m_level = 0;
}

TreeNode::TreeNode(FoldShape foldShape, const QString &baseInfo, const QString &extraInfo)
{
    m_foldShape = foldShape;
    m_baseInfo = baseInfo;
    m_extraInfo = extraInfo;
    m_level = 0;
}

TreeNode::~TreeNode()
{
    for(QList<TreeNode*>::iterator it=child.begin(); it!=child.end(); ++it)
    {
        delete(*it);
        child.erase(it);
    }
}

void TreeNode::addChild(TreeNode *node)
{
    if(node)
    {
        node->level = level+1;
        child.append(node);
    }
}

void TreeNodeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    if (index.data().canConvert<TreeNode>()) {
        TreeNode node = qvariant_cast<TreeNode>(index.data());
        //填充背景色
        QColor bgColor = node.normalColor();
        if (option.state & QStyle::State_Selected)
            bgColor = node.selectedColor();
        else if(option.state & QStyle::State_MouseOver)
            bgColor = node.hoverColor();
        painter->fillRect(option.rect, bgColor);
        //画折叠图标
        QRect foldRect = option.rect;
        foldRect.setWidth(PaintingScaleFactor);
        node.foldShape().paint(painter, foldRect);
        //画文字
        QRect baseInfoRect =option.rect;
        baseInfoRect.setLeft(PaintingScaleFactor);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize TreeNodeDelegate::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    if (index.data().canConvert<StarRating>()) {
        StarRating starRating = qvariant_cast<StarRating>(index.data());
        return starRating.sizeHint();
    } else {
        return QStyledItemDelegate::sizeHint(option, index);
    }
}



TreeNavigationBar::TreeNavigationBar(QWidget *parent)
    : QWidget(parent)
{
}

TreeNavigationBar::~TreeNavigationBar()
{

}


