/*
	文件名：linkseq.c
    描述：单向链表的排序，包括插入排序、冒泡排序、选择排序、快速排序，对排序结果进行相应操作的函数也包括在内
*/

#include "linkOp.h"

/*
    函数名：link_insert_sort
	函数功能：单向链表的插入排序(从小到大)
	参数：需要排序的链表的头节点 head
	返回值：排好序的链表的头节点
*/
ln_t link_insert_sort(ln_t head)
{
    if(link_empty(head))    //判空
    {
        return head;
    }

	ln_t node = head->next;	//node表示当前作比较的节点
    ln_t phead = NULL;	//phead为排好序的链表的头节点

	phead = listInit();	//初始化链表

	unloadNode(head, node);	//将node从head后面移除
	phead->next = node;

    ln_t tail;	//tail用于遍历链表phead
    ln_t p; //p用于记录tail的下一个节点

    //不断将head后的节点移出来和phead链表中节点逐个比较，若比某个节点小，则插入到这个节点前，若没有比这个元素大的元素，则插到phead链表末尾
	while (head->next != NULL)
	{
		node = head->next;
		unloadNode(head, node);	//将node从head后面移除
		tail = phead;
        p = tail->next;
        while (1)
        {
            if (node->data.linkid > p->data.linkid)	//比较node和tail->next的linkid值的大小
			{
                tail = tail->next;
			}
			else
			{
                insertToList(tail, node);	//将node插到tail后，结束循环
                break;
			}
            p = tail->next;
            if(p == NULL)   //如果phead链表已循环完，且并没有找到比node大的元素，将node接到phead链表尾部
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
    函数名：link_bubble_sort
    函数功能：单向链表的冒泡排序(从小到大)
    参数：需要排序的链表的头节点 head
    返回值：排好序的链表的头节点
*/
ln_t link_bubble_sort(ln_t head)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t node = head->next;
    ln_t outl = head->next; //用于控制外层循环
    ln_t inl = head->next;  //用于控制内层循环

    //两个两个节点进行比较，较大的节点放在后面，进行len-1次比较，就可把最大的节点放在最后
    while(outl->next != NULL)
    {
        while(inl->next != NULL)
        {
            if(node->data.linkid > node->next->data.linkid) //比较两个节点的大小
            {
                link_swap_node(node, node->next);
            }
            node = node->next;
            inl = inl->next;
        }
        node = head->next;  //每次循环后，把node指向链表首元素
        outl = outl->next;
        inl = outl;
    }

    node = NULL;
    outl = NULL;
    inl = NULL;


    return head;
}

/*
    函数名：link_select_sort
    函数功能：单向链表的选择排序(从小到大)
    参数：需要排序的链表的头节点 head
    返回值：排好序的链表的头节点
*/
ln_t link_select_sort(ln_t head)
{
    if(link_empty(head))
    {
        return head;
    }

    ln_t phead; //phead用于存放排序好的链表的头结点
    phead = listInit(); //初始化phead

    ln_t tail;
    ln_t tnext;    //tnext 指向tail的下一个元素
    ln_t thear;          //thear 标记tnext的上一个元素
    ln_t ptail = phead;         //ptail 指向phead链表的末尾
    ln_t temp;   //指向本次循环最小的节点

    //排序链表head中找到最小元素，将其取出存放phead后，然后，再从head链表剩余元素中继续寻找最小元素，然后取出放到phead链表末尾。以此类推，直到所有元素均从head取出。
    while(head->next != NULL)
    {
        //重置各标记
        tail = head;
        tnext = tail->next;
        thear = tail;
        temp = tnext;

        //循环选出最小的元素，让temp指向它
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

        //将temp插到phead后
        unloadNode(thear, temp);    //将temp从其所在链表当前位置移除
        insertToList(ptail, temp);  //将temp插入到phead链表结尾


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
    函数名：link_getComVal
    函数功能：获得用于快速排序的基准数位置
    参数：要获取基准数的链表部分的头 head 和尾 tail
    返回值：充当基准数的节点位置
*/
ln_t link_getComVal(ln_t head, ln_t tail)
{
    //选取head作为基准数

    //两个移动方向相同的指针
    if(head == NULL)
        return head;
    ln_t phead = head;
    ln_t pnode = phead->next;


    //指针pnode向后移动，当pnode的值小于基准数时，phead向后移动一次，交换phead和pnode的值，直到pnode移动到了tail的位置
    while(1)
    {
        if(pnode->data.linkid < head->data.linkid)
        {
            phead = phead->next;
            if(phead != pnode)  //如果phead和pnode没有重合
            {
                link_swap_node(phead, pnode);   //交换phead和pnode的值
            }
        }
        if(pnode == tail)
        {
            break;
        }
        pnode = pnode->next;
    }

    link_swap_node(phead, head);    //交换基准数和phead的值

    pnode = NULL;

    return phead;
}

/*
    函数名：link_fast_sort
    函数功能：单向链表的快速排序(从小到大)
    参数：要排序链表的首元素 head，尾节点 tail
    返回值：无
*/
void link_fast_sort(ln_t head, ln_t tail)
{
    //算法思路：
    //选取链表首元素作为基准数，两个指针phead和pnode一前一后都从链表头部开始向后移动，
    //先移动pnode，如果pnode的值比基准数小，则phead向后移动一次，交换phead和pnode的值，直到pnode移动到链表尾，
    //然后交换基准数(首元素)和phead的位置，
    //这样一个过程保证了基准数前所有元素都比基准数小，基准数后所有元素都比基准数大
    //然后基准数两边进行子问题递归，即完成了排序

    if(head != tail)
    {
        ln_t comVal = link_getComVal(head, tail);   //获取基准数位置
        if(comVal == NULL)
            return ;
        link_fast_sort(head, comVal);   //基准数前的部分进行子问题递归
        link_fast_sort(comVal->next, tail);   //基准数后的部分进行子问题递归
        comVal = NULL;
    }
}

/*
    函数名：exp_seq_result
    函数功能：输出排序的结果到二进制文件 SortGTBL.dat
    参数：查找结果链表的头结点 head
    返回值：无
*/
void exp_seq_result(ln_t head)
{
    if(link_empty(head))
    {
        return ;
    }

    FILE* fl;   //SortGTBL.dat的文件指针
    if((fl = fopen(SORTGTBL_PATH,"wb+")) == NULL)
    {
        printf("SortGTBL.dat open error!\n");
        exit(1);
    }
    expLink(head, fl);
    fclose(fl);

    FILE* fp;   //sourcelink.txt的文件指针
    if((fp = fopen(SOURCELINK_PATH,"wt+")) == NULL)
    {
        printf("sourcelink.txt open error!\n");
        exit(1);
    }
    showLink(head, fp);
    fclose(fp);

    fl = NULL;
}
