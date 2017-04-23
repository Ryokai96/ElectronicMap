/*
	�ļ�����linkseq.c
    ������������������򣬰�����������ð������ѡ�����򡢿������򣬶�������������Ӧ�����ĺ���Ҳ��������
*/

#include "linkOp.h"

/*
    ��������link_insert_sort
	�������ܣ���������Ĳ�������(��С����)
	��������Ҫ����������ͷ�ڵ� head
	����ֵ���ź���������ͷ�ڵ�
*/
ln_t link_insert_sort(ln_t head)
{
    if(link_empty(head))    //�п�
    {
        return head;
    }

	ln_t node = head->next;	//node��ʾ��ǰ���ȽϵĽڵ�
    ln_t phead = NULL;	//pheadΪ�ź���������ͷ�ڵ�

	phead = listInit();	//��ʼ������

	unloadNode(head, node);	//��node��head�����Ƴ�
	phead->next = node;

    ln_t tail;	//tail���ڱ�������phead
    ln_t p; //p���ڼ�¼tail����һ���ڵ�

    //���Ͻ�head��Ľڵ��Ƴ�����phead�����нڵ�����Ƚϣ�����ĳ���ڵ�С������뵽����ڵ�ǰ����û�б����Ԫ�ش��Ԫ�أ���嵽phead����ĩβ
	while (head->next != NULL)
	{
		node = head->next;
		unloadNode(head, node);	//��node��head�����Ƴ�
		tail = phead;
        p = tail->next;
        while (1)
        {
            if (node->data.linkid > p->data.linkid)	//�Ƚ�node��tail->next��linkidֵ�Ĵ�С
			{
                tail = tail->next;
			}
			else
			{
                insertToList(tail, node);	//��node�嵽tail�󣬽���ѭ��
                break;
			}
            p = tail->next;
            if(p == NULL)   //���phead������ѭ���꣬�Ҳ�û���ҵ���node���Ԫ�أ���node�ӵ�phead����β��
            {
                insertToList(tail, node);
                break;
            }
		}
    }

    node = NULL;
    tail = NULL;
    p = NULL;

    free(head);

	return phead;
}

/*
    ��������link_bubble_sort
    �������ܣ����������ð������(��С����)
    ��������Ҫ����������ͷ�ڵ� head
    ����ֵ���ź���������ͷ�ڵ�
*/
ln_t link_bubble_sort(ln_t head)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;
    ln_t outl = head->next; //���ڿ������ѭ��
    ln_t inl = head->next;  //���ڿ����ڲ�ѭ��

    //���������ڵ���бȽϣ��ϴ�Ľڵ���ں��棬����len-1�αȽϣ��Ϳɰ����Ľڵ�������
    while(outl->next != NULL)
    {
        while(inl->next != NULL)
        {
            if(node->data.linkid > node->next->data.linkid) //�Ƚ������ڵ�Ĵ�С
            {
                link_swap_node(node, node->next);
            }
            node = node->next;
            inl = inl->next;
        }
        node = head->next;  //ÿ��ѭ���󣬰�nodeָ��������Ԫ��
        outl = outl->next;
        inl = outl;
    }

    node = NULL;
    outl = NULL;
    inl = NULL;


    return head;
}

/*
    ��������link_select_sort
    �������ܣ����������ѡ������(��С����)
    ��������Ҫ����������ͷ�ڵ� head
    ����ֵ���ź���������ͷ�ڵ�
*/
ln_t link_select_sort(ln_t head)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t phead; //phead���ڴ������õ������ͷ���
    phead = listInit(); //��ʼ��phead

    ln_t tail;
    ln_t tnext;    //tnext ָ��tail����һ��Ԫ��
    ln_t thear;          //thear ���tnext����һ��Ԫ��
    ln_t ptail = phead;         //ptail ָ��phead�����ĩβ
    ln_t temp;   //ָ�򱾴�ѭ����С�Ľڵ�

    //��������head���ҵ���СԪ�أ�����ȡ�����phead��Ȼ���ٴ�head����ʣ��Ԫ���м���Ѱ����СԪ�أ�Ȼ��ȡ���ŵ�phead����ĩβ���Դ����ƣ�ֱ������Ԫ�ؾ���headȡ����
    while(head->next != NULL)
    {
        //���ø����
        tail = head;
        tnext = tail->next;
        thear = tail;
        temp = tnext;

        //ѭ��ѡ����С��Ԫ�أ���tempָ����
        while(tnext != NULL)
        {
            if(tnext->data.linkid < temp->data.linkid)
            {
                temp = tnext;
                thear = tail;
            }
            tail = tail->next;
            tnext = tnext->next;
        }

        //��temp�嵽phead��
        unloadNode(thear, temp);    //��temp������������ǰλ���Ƴ�
        insertToList(ptail, temp);  //��temp���뵽phead�����β


        ptail = ptail->next;
    }

    tail = NULL;
    tnext = NULL;
    thear = NULL;
    temp = NULL;
    ptail = NULL;

    free(head);

    return phead;
}

/*
    ��������link_getComVal
    �������ܣ�������ڿ�������Ļ�׼��λ��
    ������Ҫ��ȡ��׼���������ֵ�ͷ head ��β tail
    ����ֵ���䵱��׼���Ľڵ�λ��
*/
ln_t link_getComVal(ln_t head, ln_t tail)
{
    //ѡȡhead��Ϊ��׼��

    //�����ƶ�������ͬ��ָ��
    if(head == NULL)
        return head;
    ln_t phead = head;
    ln_t pnode = phead->next;


    //ָ��pnode����ƶ�����pnode��ֵС�ڻ�׼��ʱ��phead����ƶ�һ�Σ�����phead��pnode��ֵ��ֱ��pnode�ƶ�����tail��λ��
    while(1)
    {
        if(pnode->data.linkid < head->data.linkid)
        {
            phead = phead->next;
            if(phead != pnode)  //���phead��pnodeû���غ�
            {
                link_swap_node(phead, pnode);   //����phead��pnode��ֵ
            }
        }
        if(pnode == tail)
        {
            break;
        }
        pnode = pnode->next;
    }

    link_swap_node(phead, head);    //������׼����phead��ֵ

    pnode = NULL;

    return phead;
}

/*
    ��������link_fast_sort
    �������ܣ���������Ŀ�������(��С����)
    ������Ҫ�����������Ԫ�� head��β�ڵ� tail
    ����ֵ����
*/
void link_fast_sort(ln_t head, ln_t tail)
{
    //�㷨˼·��
    //ѡȡ������Ԫ����Ϊ��׼��������ָ��phead��pnodeһǰһ�󶼴�����ͷ����ʼ����ƶ���
    //���ƶ�pnode�����pnode��ֵ�Ȼ�׼��С����phead����ƶ�һ�Σ�����phead��pnode��ֵ��ֱ��pnode�ƶ�������β��
    //Ȼ�󽻻���׼��(��Ԫ��)��phead��λ�ã�
    //����һ�����̱�֤�˻�׼��ǰ����Ԫ�ض��Ȼ�׼��С����׼��������Ԫ�ض��Ȼ�׼����
    //Ȼ���׼�����߽���������ݹ飬�����������

    if(head != tail)
    {
        ln_t comVal = link_getComVal(head, tail);   //��ȡ��׼��λ��
        if(comVal == NULL)
            return ;
        link_fast_sort(head, comVal);   //��׼��ǰ�Ĳ��ֽ���������ݹ�
        link_fast_sort(comVal->next, tail);   //��׼����Ĳ��ֽ���������ݹ�
        comVal = NULL;
    }
}

/*
    ��������exp_seq_result
    �������ܣ��������Ľ�����������ļ� SortGTBL.dat
    ���������ҽ�������ͷ��� head
    ����ֵ����
*/
void exp_seq_result(ln_t head)
{
    if(link_empty(head))
    {
        return ;
    }

    FILE* fl;   //SortGTBL.dat���ļ�ָ��
    if((fl = fopen(SORTGTBL_PATH,"wb+")) == NULL)
    {
        printf("SortGTBL.dat open error!\n");
        exit(1);
    }
    expLink(head, fl);
    fclose(fl);

    FILE* fp;   //sourcelink.txt���ļ�ָ��
    if((fp = fopen(SOURCELINK_PATH,"wt+")) == NULL)
    {
        printf("sourcelink.txt open error!\n");
        exit(1);
    }
    showLink(head, fp);
    fclose(fp);

    fl = NULL;
}
