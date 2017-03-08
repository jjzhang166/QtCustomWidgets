EMEditor注册码
DMAZM-WHY52-AX222-ZQJXN-79JXH 


//每个导航默认使用20*20的大小进行绘制
TreeNavigationBar
结构体数据
enum FoldShapeStyle
{
	加减,
	三角形,
	圆形
}
struct Node
{
	QString infoStr;//当前信息
	QString extraInfo;//额外信息
	bool foldState;//折叠状态
	FoldShapeStyle foldStyle;//折叠类型
	int level;//当前层级
	QList<Node*> child;
}


model用来存储数据和读取数据,保存了数据的一些属性(文本,字体,颜色,是否选中等等)继承QStandardItemModel或者具体的预定义的model(QAbstractTableModel等)
  如果是只读模型,只需要重载
  int rowCount(const QModelIndex &parent = QModelIndex())
  int columnCount(const QModelIndex &parent = QModelIndex())
  QVariant data(const QModelIndex &index, int role)
有表头的话需要重载
  QVariant headerData(int section, Qt::Orientation orientation, int role)

delegate对数据进行特殊的表现和编辑,继承QStyledItemDelegate
  如果是只读的话,只需要重载
  void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index)
  QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index)

view用来进行特殊的表现,如果不想要表格的变现的话,需要重新继承QAbstractItemView