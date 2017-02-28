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
