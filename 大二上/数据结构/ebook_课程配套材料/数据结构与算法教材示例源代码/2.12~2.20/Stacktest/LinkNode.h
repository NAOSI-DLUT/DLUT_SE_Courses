template<class T>
class LinkNode
{
	public:
		T data;							//数据域
		LinkNode<T>*link;				//指向后继指针的结点

		LinkNode(const T&el, LinkNode<T>*ptr = 0){	//构造函数
			data=el;
			link=ptr;
	}
};
