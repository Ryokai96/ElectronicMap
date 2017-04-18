/*
	�ļ�����linkseq.c
	������������������򣬰�����������ð������ϣ������ѡ������
*/

#include "linkOp.h"

/*
	��������insert_sort
	�������ܣ���������Ĳ�������(��С����)
	��������Ҫ����������ͷ�ڵ� head
	����ֵ���ź���������ͷ�ڵ�
*/
ln_t insert_sort(ln_t head)
{
	ln_t node = head->next;	//node��ʾ��ǰ���ȽϵĽڵ�
	ln_t phead = NULL;	//pheadΪ�ź���������ͷ�ڵ�
	if (node == NULL)
	{
		printf("empty linklist\n");
		return NULL;
	}

	phead = listInit();	//��ʼ������

	unloadNode(head, node);	//��node��head�����Ƴ�
	phead->next = node;

	ln_t tail;	//tail���ڱ�������

	//���Ͻ�head��Ľڵ��Ƴ�����phead�����нڵ�����Ƚϣ�����ĳ���ڵ�С������뵽����ڵ�ǰ
	while (head->next != NULL)
	{
		node = head->next;
		unloadNode(head, node);	//��node��head�����Ƴ�
		tail = phead;
		while (tail->next != NULL)
		{
			if (node->data.linkid > tail->next->data.linkid)	//�Ƚ�node��tail->next��linkidֵ�Ĵ�С
			{
				tail->next = tail->next->next;
			}
			else
			{
				insertToList(tail, node);	//��node�嵽tail��
			}
		}
	}
	free(head);
	return phead;
}