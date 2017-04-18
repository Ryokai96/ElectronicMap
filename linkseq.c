/*
	文件名：linkseq.c
	描述：单向链表的排序，包括插入排序、冒泡排序、希尔排序、选择排序
*/

#include "linkOp.h"

/*
	函数名：insert_sort
	函数功能：单向链表的插入排序(从小到大)
	参数：需要排序的链表的头节点 head
	返回值：排好序的链表的头节点
*/
ln_t insert_sort(ln_t head)
{
	ln_t node = head->next;	//node表示当前作比较的节点
	ln_t phead = NULL;	//phead为排好序的链表的头节点
	if (node == NULL)
	{
		printf("empty linklist\n");
		return NULL;
	}

	phead = listInit();	//初始化链表

	unloadNode(head, node);	//将node从head后面移除
	phead->next = node;

	ln_t tail;	//tail用于遍历链表

	//不断将head后的节点移出来和phead链表中节点逐个比较，若比某个节点小，则插入到这个节点前
	while (head->next != NULL)
	{
		node = head->next;
		unloadNode(head, node);	//将node从head后面移除
		tail = phead;
		while (tail->next != NULL)
		{
			if (node->data.linkid > tail->next->data.linkid)	//比较node和tail->next的linkid值的大小
			{
				tail->next = tail->next->next;
			}
			else
			{
				insertToList(tail, node);	//将node插到tail后
			}
		}
	}
	free(head);
	return phead;
}