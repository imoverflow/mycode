#include <stdio.h>
#include <stdlib.h>

 struct node
   {
       char age;
       struct node *next;
       struct node *pre;
   }*head,*tail;
destroy(struct node *h)
{
    struct node *p,*t;
    p=h;
    while(p!=0)
    {
        t=p;
        p=p->next;
        free(t);
    }
}
    main()
{
char tc;
struct node *tp;
head=tail=0;
   while((tc=getchar())!='.')
    {
        tp=(struct node*)(malloc(sizeof(struct node)));
        tp->age=tc;
        tp->next=0;
        if(head==0)
            {
                head=tp;
                head->pre=0;
                tail=tp;
            }else{
                tp->pre=tail;
                tail->next=tp;            //µ¼³öÖ¸Õë
                tail=tp;
            }
    }
    destroy(struct node *h);
    destroy(head);
}
