#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*
  链表的操作：
    初始化
    长度
    删除链表
    清空链表
    插入节点
    删除节点
    反转链表
  @auth: mackchanges
  refrence:wiki
*/

typedef struct Lnode
{
  int data;
  struct Lnode *next;
}LNode,*Linklist;

void init(Linklist *head)
{
  //初始化链表
  *head = (Linklist)malloc(sizeof(LNode));
  (*head)->next = NULL;
}

int length(Linklist head)
{
  //计算链表的长度
  Linklist p = head->next;
  int i=0;
  while (p) {
    p = p->next;
    i++;
  }
  return i;
}

int insert(Linklist head,int i,int data)
{
  //向链表中插入数据
  int j=0;
  Linklist p,s;
  p = head;
  while (p &&j<i-1)   //找到第i-1个节点
  {
    j++;
    p = p->next;
  }
  if (!p || j>i-1) {       //i小于1或i大于表长
    return 0;             //0即插入出错
  }
  s = (Linklist)malloc(sizeof(LNode));
  s->data = data;
  s->next = p->next;
  p->next = s;
  return 1;
}

int getdata(Linklist head,int i,int *data)
{
  //获取指定位置的数据
  int j = 1;
  Linklist p=head->next;
  while (p && j<i) {
    p = p->next;
    j++;
  }
  if (!p || j>i)
  {
    return 0;
  }
  *data = p->data;
  return 1;
}

void destroylist(Linklist *head)
{
  //将链表清空
  Linklist p;
  while (*head) {
    p = (*head)->next;
    free(*head);
    (*head) = p;
  }
}

void clearlist(Linklist head)
{
  //将链表重置为空表
  Linklist p,q;
  p = head->next;
  while (p) {
    q = p->next;
    free(p);
    p = q;
  }
  head->next = NULL;
}

int deletedata(Linklist head,int i)
{
  //找到i-1节点
  int j=0;
  Linklist temp;
  Linklist p = head->next;
  while (p && j<i-1) {
    p = p->next;
    j++;
  }
  if (!p || j>i-1)
    return 0;
  temp = p->next;
  p->next = temp->next;
  free(temp);
  return 1;
}

Linklist reverselist(Linklist head)
{
  //反转链表
  Linklist p,q;
  p = NULL;
  while (head) {
    q = head->next;
    head->next = p;
    p = head;
    head = q;
  }
  return p;
}

// #include<list.h>

// int main(){
//     ListNode L;
//     int m,i,n,x ;
//     i =init(&L);
//     printf("初始化%d\n", i);
//     for (i=0;i<10;i++){     //i从0开始需要注意到链表的操作
//         n=insert(L,i,i+1); //注意i的值变化
//         printf("插入%d\n",n );
//     }
//     m = length(L);
//     printf("链表长度%d\n ", m);
//     for(i=0;i<listLength(L);i++)
//       {
//         getdata(L,i,&x);
//         printf("元素%d\n", x);
//       }
//     return 0;
// }
