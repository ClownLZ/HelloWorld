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
							<�����Ӻ�������>
	
	push_front(Ԫ��):����ǰ�����
	push_back(Ԫ��):����������
	pop_front():ɾ����ǰ���һ��Ԫ��
	pop_back():ɾ��������һ��Ԫ��
	back():��ȡ���һ��Ԫ��
	front():��ȡ��һ��Ԫ��
	clear():���Ԫ��
	size():��ȡʵʱԪ�ظ���
	count();��ȡ��ͬԪ�صĸ���
	remove(object):��list�����еĶ����Ƴ���
	erase(begin(),end()):������Ҫɾ�������������� ��������һ��λ�õĵ�����
	insert(������ + n,Ԫ�س�ʼ��);ָ��λ�ò���Ԫ�� ����ʼ��
	emplace_front(Ԫ��);��ǰ����� ��ʵ�ֱ��ģ�������ת��
	emplace_back(Ԫ��);�ں������ ��ʵ�ֱ��ģ�������ת��
	emplace(������ + n,Ԫ��):��insert����һ�� ��ʵ�ֱ��ģ�������ת��
		���ģ��:����д���� ֱ������Ϣ
		����ת��:˽����ִ�й�����һ����

	��list������ʹ�ò��뺯��ʱ ������ (������ + n)
	��set/multiset������set insert()���뺯�� ����һ��pair�ĵ�����
		Ҫ�����ʱ�贴�� pair��������
		first:���س����ĵ�����  ������ �ɶ�ȡ����
		second:�Ƿ�ɹ� 

	��set/multiser �� map/multimap �еĲ����㷨
		find(Ԫ��||��ֵ)���ز�ѯ���ĵ����� ����ָ��end() ��map/multimap�з���pair��
		lower_bound(Ԫ��||��ֵ)���ص������ĵ�һ��Ԫ��,���û�ҵ� ��ָ��end()
		upper_bound(Ԫ��||��ֵ)���ش������ĵ�һ��Ԫ��,���û�ҵ� ��ָ��end()
		
		ser �� map�е�equal_range()
				equal_range(Ԫ��||����)����һ��pair<������,������>��
				����ҵ���Ԫ�ػ��ֵ ��������:
				��һ��������ָ����Ԫ�ػ��ֵ �ڶ���������ָ�� ��Ԫ�ص���һ��λ��
				���û�ҵ���Ԫ�ػ��ֵ ��������:
				���������� ͣ�ڴ��ڸ�Ԫ�ػ��ֵ����һ��λ��
				������滹��Ԫ�ػ��ֵ��ôͣ�ڸ�Ԫ�ص�λ�� ����ͣ��end()λ��
				first:ָ���һ��������
				second:ָ��ڶ���������

		��multiser �� multimap�е�equal_range()
				equal_range(Ԫ��||����)����һ��pair<������,������>��
				����ҵ���Ԫ�ػ��ֵ ��������:
				��һ��������ָ����Ԫ�ػ��ֵ �ڶ���������ָ�� ���һ����ͬԪ�ص���һ��λ��
				���û�ҵ���Ԫ�ػ��ֵ ��������:
				���������� ͣ�ڸ�Ԫ�ػ��ֵ����һ��λ��
				������滹��Ԫ�ػ��ֵ��ôͣ�ڸ�Ԫ�ص�λ�� ����ͣ��end()λ��
				first:ָ���һ��������
				second:ָ��ڶ���������
			
			
	assgin(ָ��Ԫ������,Ԫ�س�ʼ��)��С �Ŵ�
	��Сʱ:���ж϶������Ԫ�� ����ʼ��
	�Ŵ�ʱ:��ȫ����ʼ��

	resize(ָ��Ԫ������,Ԫ�س�ʼ��)�ɲ�ָ��Ԫ�س�ʼ�� 
	ָ������С������Ԫ�ظ���ʱ,Ϊ��С ����Ϊ�Ŵ�
	��Сʱ:���ж϶������Ԫ�� ��Ԫ�س�ʼ��
	�Ŵ�ʱ:�ܿ�����Ԫ��(���ָ��Ԫ��������)��������ȫ����ʼ��


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
	
	//ͷ�ļ�:
	//TeseVector();			//ͷ�ļ�:vector
	//TestDeque();			//ͷ�ļ�:deque
	//TestList();			//ͷ�ļ�:list
	TestSetAndMultiset(); //ͷ�ļ�:set/multiset
	//TestMapAndMultimap();	//ͷ�ļ�:map/multimap
	//Testqueue();			//ͷ�ļ�:queue
	//TestPriority_Queue();	//ͷ�ļ�:queue
	//TestStack();			//ͷ�ļ�:stack
	return 0;
}

//����vector����			������
void TeseVector() {
	vector<My_B> v(10);
	//v.erase(Boy(6, "������"));
	cout << v.capacity() << endl;
	v.assign(5,My_B());
	cout << v.size() << endl;
	//v.clear(); //�������Ԫ��
	//v.earse();//ָ��ɾ����Ԫ��

}

//����deque����				�������
void TestDeque() {
	deque<My_B> d;
	d.resize(2);
	
	cout << d.size() << endl;
}

//����list����				��ʽ
void TestList() {
	list<My_B> l;
	//l.assign(2, My_B(1,"a"));
	l.insert(l.begin(),10,My_B(1, "a"));
	cout << "����Ԫ�ظ���" << l.size() << endl;
	
	Push_ADD<list<My_B>> temp;
	temp(l);
}

//����set and multiset����	�����
void TestSetAndMultiset() {
	set<My_B, Functor<My_B>> s; //���ɴ���ͬ��Ԫ��
	
	s.erase(Boy(6, "������"));
	
	Push_ADD<set<My_B, Functor<My_B>>>* temp =
		new Set_Multiser_Push_Front<set<My_B, Functor<My_B>>, My_B>();
	(*temp)(s,"������",5);
	--s.begin();
	cout << *(++s.begin()) << endl;
	cout << *s.begin() << endl;
	cout << "------------" << endl;
	//auto t = s.find(Boy(55, "������_3")); //��ѯ�Ƿ������ ����о�ָ���Ԫ�� �޵Ļ� ָ��end()
	//cout << (*--t) << endl;

	//int t = s.count(Boy(2, "������_3")); //��ѯ�ж��ٸ���Ԫ�� ����һ��NUMBEI���� multiset�з�����ͬ����
	//cout << t << endl;
	cout << "------------------------" << endl;
	/*
	auto t = s.lower_bound(Boy(4, "������_3")); 
	//����һ������ ����Ԫ�� ����˵���Լ�����
	//���û�ҵ� ��ָ��end()
	if (t != s.end()) {
		cout << (*t) << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	*/
	auto t = s.upper_bound(Boy(2, "������_3"));
	//���ش������ĵ�һ��Ԫ��
	//���û�ҵ� ��ָ��end()
	if (t != s.end()) {
		cout << (*t) << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
	/*
	auto t = s.equal_range(Boy(8, "������_3"));
	//����ҵ�����ȵ� ��firstָ���� 
	//secondָ����һλ������first��ָ���Ԫ�ص�λ�� 
	//�����һλΪ�� ��ôָ��end()
	//�����û ��ô������������ָ��end()
	cout << (*t.first) << endl;

	cout << (*t.second) << endl;
	*/
	//pair<set<My_B, Functor<My_B>>::iterator,bool>test = s.insert(Boy(0, "������_1"));
	//cout << (*test.first) << endl;
	//cout << "�Ƿ����ɹ�:" << test.second << endl;

	(*temp)(s);
	if (temp) {
		delete temp;
		temp = NULL;
	}
	/*
	cout << "------------------------" << endl;
	
	Push_ADD<multiset<My_B>>* temp1 =
		new Set_Multiser_Push_Front<multiset<My_B>, My_B>();
	multiset<My_B> m;  //�ɴ���ͬ��Ԫ��

	(*temp1)(m, "������", 5);

	
	(*temp1)(m);
	if (temp1) {
		delete temp1;
		temp1 = NULL;
	}
	*/
}

//����map and multimap����  ������ �ص�(��ֵ��)�ɴ���������� 
void TestMapAndMultimap()
{
	map<int, string> m;
	m.insert(pair<int, string>(102, "����ʦ"));
	m.insert(pair<int, string>(102, "����ʦ"));
	m.insert(pair<int, string>(104, "����ʦ"));
	m.insert(pair<int, string>(104, "����ʦ"));

	pair<map<int, string>::iterator, map<int, string>::iterator>
		a = m.equal_range(104);

	while (!(a.first == a.second)) {
		cout << (*(a.first)).second << endl;
		a.first++;
	}
	cout << "------------------------" << endl;

	multimap<int, string> mm;
	mm.insert(pair<int, string>(102, "����ʦ"));
	mm.insert(pair<int, string>(102, "����ʦ"));
	mm.insert(pair<int, string>(104, "����ʦ"));
	mm.insert(pair<int, string>(104, "����ʦ"));

	int tempCound = mm.count(102);
	multimap<int, string>::iterator it = mm.find(102);
	/*
	while (1) {
		if (!tempCound--) {
			break;
		}
		cout << "�༶:" << (*it).first << " " << (*it).second << endl;
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
		cout << "û�ҵ�" << endl;
	}
}

//����queue				    �����Ƚ��ȳ�
void Testqueue(){
	//������� �Ƚ��ȳ�
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

//����priority_queue		���ȶ��� �����Զ����С����� Ĭ���Ǵ������
void TestPriority_Queue() {
	//���ȶ��� ����ָ������ʽ���� Ĭ���ǴӴ�С��
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

//����stack					�����Ƚ���� ������
void TestStack(){
	// ���� �Ƚ���� ����ȳ�
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
