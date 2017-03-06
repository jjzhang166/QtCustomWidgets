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
    return PaintingScaleFactor * QSize(1, 1);
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
    Init();
    m_foldShape = FoldShape(FoldShape::CrossStyle, QColor(24, 189, 155, 150), QColor(52, 73, 94));
}

TreeNode::TreeNode(FoldShape foldShape, const QString &baseInfo, const QString &extraInfo)
{
    m_foldShape = foldShape;
    m_baseInfo = baseInfo;
    m_extraInfo = extraInfo;
    Init();
}

TreeNode::~TreeNode()
{
    for(QList<TreeNode*>::iterator it=child.begin(); it!=child.end(); ++it)
    {
        delete(*it);
        child.erase(it);
    }
}

void TreeNode::Init()
{
    m_level = 0;
    m_normalColorBg = QColor(52, 73, 94);
    m_hoverColorBg = QColor(24, 189, 155);
    m_selectedColorBg = QColor(24, 189, 155, 150);
    m_normalColorText = QColor(254, 255, 255);
    m_hoverColorText = QColor(252, 252, 252);
    m_selectedColorText = QColor(0, 0, 0);
}

void TreeNode::addChild(TreeNode *node)
{
    if(node)
    {
        node->m_level = m_level+1;
        child.append(node);
    }
}

void TreeNode::setFoldShape(FoldShape shape)
{
    m_foldShape = shape;
}

void TreeNode::setBaseInfo(QString baseInfo)
{
    m_baseInfo = baseInfo;
}

void TreeNode::setExtraInfo(QString extraInfo)
{
    m_extraInfo = extraInfo;
}

void TreeNode::setNormalColorBg(QColor color)
{
    m_normalColorBg = color;
}

void TreeNode::setHoverColorBg(QColor color)
{
    m_hoverColorBg = color;
}

void TreeNode::setSelectedColorBg(QColor color)
{
    m_selectedColorBg = color;
}

void TreeNode::setNomalColorText(QColor color)
{
    m_normalColorText = color;
}

void TreeNode::setHoverColorText(QColor color)
{
    m_hoverColorText = color;
}

void TreeNode::setSelectedColorText(QColor color)
{
    m_selectedColorText = color;
}

void TreeNodeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    if (index.data().canConvert<TreeNode>()) {
        TreeNode node = qvariant_cast<TreeNode>(index.data());
        //填充背景色
        QColor bgColor = node.normalColorBg();
        if (option.state & QStyle::State_Selected)
            bgColor = node.selectedColorBg();
        else if(option.state & QStyle::State_MouseOver)
            bgColor = node.hoverColorBg();
        painter->fillRect(option.rect, bgColor);
        //画折叠图标
        int dx = PaintingScaleFactor;
        QRect foldRect = option.rect;
        foldRect.setWidth(PaintingScaleFactor);
        node.foldShape().paint(painter, foldRect);
        //画文字
        QColor textColor = node.normalColorText();
        if (option.state & QStyle::State_Selected)
            textColor = node.selectedColorText();
        else if(option.state & QStyle::State_MouseOver)
            textColor = node.hoverColorText();
        painter->setPen(textColor);
        QRect baseInfoRect = option.rect;
        baseInfoRect.setLeft(dx);
        QFontMetrics fm = painter->fontMetrics();
        int baseTextWidth = fm.width(node.baseInfo());
        baseTextWidth += TreeNodeExtraSpace;
        baseInfoRect.setWidth(baseTextWidth);
        painter->drawText(baseInfoRect, Qt::AlignLeft, node.baseInfo());
        dx += baseTextWidth;
        QRect extraInfoRect = option.rect;
        extraInfoRect.setLeft(dx);
        int extraTextWidth = fm.width(node.extraInfo());
        extraInfoRect.setWidth(extraTextWidth);
        painter->drawText(extraInfoRect, Qt::AlignLeft, node.extraInfo());
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize TreeNodeDelegate::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    if (index.data().canConvert<TreeNode>()) {
        return QSize(50, 30);
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


