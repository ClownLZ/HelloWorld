#include "Boy.h"
#include "BuildAndPrintf.h"
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <Stack>

/******************************************************************************
							<容器子函数描述>
	
	push_front(元素):在最前面插入
	push_back(元素):在最后面插入
	pop_front():删除最前面的一个元素
	pop_back():删除最后面的一个元素
	back():获取最后一个元素
	front():获取第一个元素
	clear():清空元素
	size():获取实时元素个数
	count();获取相同元素的个数
	remove(object):将list链表中的对象移除掉
	erase(begin(),end()):根据需要删除单个数或区域 并返回下一个位置的迭代器
	insert(迭代器 + n,元素初始化);指定位置插入元素 并初始化
	emplace_front(元素);在前面插入 可实现变成模板和完美转发
	emplace_back(元素);在后面插入 可实现变成模板和完美转发
	emplace(迭代器 + n,元素):与insert基本一致 可实现变成模板和完美转发
		变成模板:不用写类名 直接填信息
		完美转发:私底下执行构建了一个类

	在list容器下使用插入函数时 不允许 (迭代器 + n)
	在set/multiset容器下set insert()插入函数 返回一个pair的迭代器
		要想访问时需创建 pair迭代器类
		first:返回出来的迭代器  接引后 可读取内容
		second:是否成功 

	在set/multiser 和 map/multimap 中的查找算法
		find(元素||键值)返回查询到的迭代器 否则指向end() 在map/multimap中返回pair类
		lower_bound(元素||键值)返回等于它的第一个元素,如果没找到 即指向end()
		upper_bound(元素||键值)返回大于它的第一个元素,如果没找到 即指向end()
		
		ser 和 map中的equal_range()
				equal_range(元素||键键)返回一个pair<迭代器,迭代器>类
				如果找到该元素或键值 返回区间:
				第一个迭代器指向首元素或键值 第二个迭代器指向 该元素的下一个位置
				如果没找到该元素或键值 返回区间:
				两个迭代器 停在大于该元素或键值的下一个位置
				如果后面还有元素或键值那么停在该元素的位置 否则停在end()位置
				first:指向第一个迭代器
				second:指向第二个迭代器

		在multiser 和 multimap中的equal_range()
				equal_range(元素||键键)返回一个pair<迭代器,迭代器>类
				如果找到该元素或键值 返回区间:
				第一个迭代器指向首元素或键值 第二个迭代器指向 最后一个相同元素的下一个位置
				如果没找到该元素或键值 返回区间:
				两个迭代器 停在该元素或键值的下一个位置
				如果后面还有元素或键值那么停在该元素的位置 否则停在end()位置
				first:指向第一个迭代器
				second:指向第二个迭代器
			
			
	assgin(指定元数个数,元素初始化)缩小 放大
	缩小时:即切断多出来的元素 并初始化
	放大时:将全部初始化

	resize(指定元数个数,元素初始化)可不指定元素初始化 
	指定个数小于现有元素个数时,为缩小 否则为放大
	缩小时:即切断多出来的元素 并元素初始化
	放大时:避开已有元素(算进指定元数个数里)并将后面全部初始化


******************************************************************************/

void TeseVector();
void TestDeque();
void TestList();
void TestSetAndMultiset();
void TestMapAndMultimap();
void Testqueue();
void TestPriority_Queue();
void TestStack();

int main() {
	
	//头文件:
	//TeseVector();			//头文件:vector
	//TestDeque();			//头文件:deque
	//TestList();			//头文件:list
	TestSetAndMultiset(); //头文件:set/multiset
	//TestMapAndMultimap();	//头文件:map/multimap
	//Testqueue();			//头文件:queue
	//TestPriority_Queue();	//头文件:queue
	//TestStack();			//头文件:stack
	return 0;
}

//测试vector容器			单数组
void TeseVector() {
	vector<My_B> v(10);
	//v.erase(Boy(6, "王大仙"));
	cout << v.capacity() << endl;
	v.assign(5,My_B());
	cout << v.size() << endl;
	//v.clear(); //清空容器元素
	//v.earse();//指定删除的元素

}

//测试deque容器				多个数组
void TestDeque() {
	deque<My_B> d;
	d.resize(2);
	
	cout << d.size() << endl;
}

//测试list容器				链式
void TestList() {
	list<My_B> l;
	//l.assign(2, My_B(1,"a"));
	l.insert(l.begin(),10,My_B(1, "a"));
	cout << "容器元素个数" << l.size() << endl;
	
	Push_ADD<list<My_B>> temp;
	temp(l);
}

//测试set and multiset容器	红黑树
void TestSetAndMultiset() {
	set<My_B, Functor<My_B>> s; //不可存相同的元素
	
	s.erase(Boy(6, "王大仙"));
	
	Push_ADD<set<My_B, Functor<My_B>>>* temp =
		new Set_Multiser_Push_Front<set<My_B, Functor<My_B>>, My_B>();
	(*temp)(s,"王大仙",5);
	--s.begin();
	cout << *(++s.begin()) << endl;
	cout << *s.begin() << endl;
	cout << "------------" << endl;
	//auto t = s.find(Boy(55, "王大仙_3")); //查询是否有这个 如果有就指向此元素 无的话 指向end()
	//cout << (*--t) << endl;

	//int t = s.count(Boy(2, "王大仙_3")); //查询有多少个此元素 返回一个NUMBEI数据 multiset中返回相同个数
	//cout << t << endl;
	cout << "------------------------" << endl;
	/*
	auto t = s.lower_bound(Boy(4, "王大仙_3")); 
	//返回一个等于 它的元素 可以说是自己本身
	//如果没找到 即指向end()
	if (t != s.end()) {
		cout << (*t) << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	*/
	auto t = s.upper_bound(Boy(2, "王大仙_3"));
	//返回大于它的第一个元素
	//如果没找到 即指向end()
	if (t != s.end()) {
		cout << (*t) << endl;
	}
	else {
		cout << "未找到" << endl;
	}
	/*
	auto t = s.equal_range(Boy(8, "王大仙_3"));
	//如果找到有相等的 即first指向它 
	//second指向下一位不等于first所指向的元素的位置 
	//如果下一位为空 那么指向end()
	//如果都没 那么两个迭代器都指向end()
	cout << (*t.first) << endl;

	cout << (*t.second) << endl;
	*/
	//pair<set<My_B, Functor<My_B>>::iterator,bool>test = s.insert(Boy(0, "王大仙_1"));
	//cout << (*test.first) << endl;
	//cout << "是否插入成功:" << test.second << endl;

	(*temp)(s);
	if (temp) {
		delete temp;
		temp = NULL;
	}
	/*
	cout << "------------------------" << endl;
	
	Push_ADD<multiset<My_B>>* temp1 =
		new Set_Multiser_Push_Front<multiset<My_B>, My_B>();
	multiset<My_B> m;  //可存相同的元素

	(*temp1)(m, "王大仙", 5);

	
	(*temp1)(m);
	if (temp1) {
		delete temp1;
		temp1 = NULL;
	}
	*/
}

//测试map and multimap容器  二叉树 特点(键值对)可存放两个类型 
void TestMapAndMultimap()
{
	map<int, string> m;
	m.insert(pair<int, string>(102, "李老师"));
	m.insert(pair<int, string>(102, "王老师"));
	m.insert(pair<int, string>(104, "周老师"));
	m.insert(pair<int, string>(104, "孙老师"));

	pair<map<int, string>::iterator, map<int, string>::iterator>
		a = m.equal_range(104);

	while (!(a.first == a.second)) {
		cout << (*(a.first)).second << endl;
		a.first++;
	}
	cout << "------------------------" << endl;

	multimap<int, string> mm;
	mm.insert(pair<int, string>(102, "李老师"));
	mm.insert(pair<int, string>(102, "王老师"));
	mm.insert(pair<int, string>(104, "周老师"));
	mm.insert(pair<int, string>(104, "孙老师"));

	int tempCound = mm.count(102);
	multimap<int, string>::iterator it = mm.find(102);
	/*
	while (1) {
		if (!tempCound--) {
			break;
		}
		cout << "班级:" << (*it).first << " " << (*it).second << endl;
		it++;
	}

	while ((*it).first == 102) {
		cout << (*it).first << endl;
		cout << (*it).second << endl;
		it++;
	}
		*/
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator>
		b = mm.equal_range(102);

	if (!(b.first == b.second)) {
		for (; b.first != b.second;) {
			cout << (*(b.first)).first << endl;
			cout << (*(b.first)).second << endl;
			b.first++;
		}
	}
	else {
		cout << "没找到" << endl;
	}
}

//测试queue				    队列先进先出
void Testqueue(){
	//单向队列 先进先出
	queue<int> q;

	q.push(1);
	q.push(3);
	q.push(2);
	q.push(5);
	q.push(3);
	q.push(1);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}

//测试priority_queue		优先队列 根据自定义大小排序出 默认是大的优先
void TestPriority_Queue() {
	//优先队列 根据指定排序方式进出 默认是从大到小出
	priority_queue<int, vector<int>, greater<int>> p_q;

	p_q.push(1);
	p_q.push(3);
	p_q.push(56);
	p_q.push(12);
	p_q.push(2);

	while (!p_q.empty()) {
		cout << p_q.top() << endl;
		p_q.pop();
	}
}

//测试stack					队列先进后出 后进后出
void TestStack(){
	// 队列 先进后出 后进先出
	stack<int> s;

	s.push(1);
	s.push(3);
	s.push(2);
	s.push(5);
	s.push(6);
	s.push(1);

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.size() << endl;
}
