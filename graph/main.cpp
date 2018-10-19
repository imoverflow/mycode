#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
using namespace std;
int inip1[2000][2]={{100,100},{110,100},{120,100},{130,100},{140,100},{150,100},{160,100},{170,100}};
int inip2[2000][2]={{110,110},{120,110},{130,110},{140,110},{150,110},{160,110},{170,110},{180,110}};
int len=7;
struct snake
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct snake *pre;
    struct snake *next;
};
struct snake * Creat()
{
    struct snake *L,*p,*r;
    L = (struct snake *)malloc(sizeof(struct snake));
    L->next = L;
    L->pre = L;
    r = L;
    r->next = NULL;
    int i;
    for(i=0;i<7;i++)
    {
        p = (struct snake *)malloc(sizeof(struct snake));
        p->x1 = inip1[i][0];
        p->y1 = inip1[i][1];
        p->x2 = inip2[i][0];
        p->y2 = inip2[i][1];
        r->next = p;
        p->pre = r;
        p->next=L;
        L->pre=p;
        r = p;
    }
    return L;
}
struct snake *Insert(struct snake *head,struct snake *tail,char ch) //i==length
{
    struct snake * p,*s;                          //s为要插入的结点
    tail=tail->pre;
    free(tail->next);
    tail->next=NULL;
    p=(struct snake *)malloc(sizeof(struct snake));
    switch (ch)
    {
        case 'w':
            p->x1=head->x1;
            p->y1=head->y1-10;
            p->x2=head->x2;
            p->y1=head->y2-10;

            break;
        case 'a':
            break;
        case 's':
            break;
        case 'd':
            break;
    }
//    p = L->next;                         //从第一个结点位置开始查找
//    int tempi;
//    for(tempi = 1;tempi < i-1; tempi++)
//        p = p->next;
//    s =  (struct snake *)malloc(sizeof(struct snake));
//    s->x1 = x;                         //将x赋值到s的数据域
//    s->next = p->next;                        //将结点插入
//    p->next->pre = s;
//    s->pre = p;
//    p->next = s;

    return L;

}
struct snake * Delete(struct snake* L,int i)
{
    int tempi = 1;
    struct snake* p;                        //p为查找结点。
    p = L->next;
    while((tempi++) != i && p != NULL)
    {
        p = p->next;
    }
    if(p->next == NULL)         //最后一个结点特殊处理，原因最后一个结点p->next没有prior
    {
        p->pre->next = NULL;
        free(p);
    }
    else                                //进行删除操作
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
    }
}
int main()
{
    struct snake* head,*tail;
    head=Creat();
    tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    char ch='w';
    while(1){                                         //die
        for(;kbhit();) ch=getch();
        switch (ch)
        {
            case 'w':
                break;
        }
    }
    return 0;
}
