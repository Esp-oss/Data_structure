#include <iostream>
#include <string>
using namespace std;

//创建一个数据类型
struct Element_type {
};

/*
typedef--定义一个数据类型的别名
这里定义List_address,是数据类型struct List* 的别名,即List结构体的地址指针
*/
typedef struct List* List_address;

//创建线性表结构体，包含数据和索引，用于指向下一个节点的位置

//线性表的链式存储实现，不要求逻辑上相邻的两个元素物理上也相邻
struct List {
	Element_type data;
	List_address next;
};

//创建空线性表
void List_MakeEmpty() {

}

//根据位序查找相应元素,L作为形参是以地址的形式传输，数组也是
List_address elementFind_of_index(int num, List_address head) {
	List_address p = head;//p指向表的第一个节点
	int cnt = 1;//用来记录当前位序
	while (p != NULL && cnt < num) {
		p = p->next;//p指向当前节点记录的下一个节点的地址
		cnt++;
	}
	if (cnt == num) {
		return p;
	}//直到最后一个节点的后继为空或者找到位序为num的元素，退出循环，返回表长
	else {
		return NULL;//遍历到最后一个节点也没找到位序num
	}
}

//根据元素返回元素的地址,要查找的元素为data_input
List_address indexFind_of_element(Element_type data_input, List_address head) {
	List_address p = head;//p指向表的第一个节点
	while (p != NULL && p->data != data_input) {//element_type含有两个数据类型，不知道比较哪个，会报错，需要重载
		p = p->next;//p指向当前节点记录的下一个节点的地址
	}
	return p;
}

//在位置i处插入一个新元素
List_address Insert(Element_type x, int i, List_address head) {
	//先申请一块空间s,大小储存next和data，即单独创立一个节点s,但暂时没有接入链表中
	//要接入位置i,逻辑上为s的前缀是与节点i-1链接,后继与节点i链接
	//步骤1:创建节点s
	List_address p, s;
	//判断位置i是否为首地址,如果为首地址则没有节点i-1，只需将s的next指向head就行
	if (i == 1) {
		s = new(List);
		s->data = x;
		s->next = head;
		return s;
	}
	//步骤2:找到节点i，用节点s的next指向节点i
	//步骤3:找到节点i-1,用节点i-1的next指向节点s
	p = elementFind_of_index(i - 1, head);
	if (p == NULL) {
		printf("参数i错误");
		return NULL;
	}
	else {
		s = new(List);
		s->data = x;
		s->next = p->next;
		p->next = s;
		printf("插入成功");
		return head;
	}
	//完成插入
	//ps:步骤2和步骤3不可以对调，如果先修改节点i-1的next指向s，那么无法再找到节点i的位置
	//整个结果变为，在位置i-1截断链表,再接入位置s，丢失链表i以后的部分

}

//删除指定位序i的元素
void Delete(int i, List L) {

}

//返回线性表的长度len，遍历地址，时间O（n）
int Length(List_address head) {
	List_address p = head;//p指向表的第一个节点
	int cnt = 0;//用来记录表长
	while (p) {
		p = p->next;//p指向当前节点记录的下一个节点的地址
		cnt++;
	}
	return cnt;//直到最后一个节点的后继为空，退出循环，返回表长
}




