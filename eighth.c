#include<stdio.h>
#include<stdlib.h>
typedef struct n{
char s[25],nme[25],d[10],g[25];
int sal; long p;
struct n *l,*r;
}*N;
N f=NULL; int c=0;
N cr(){
N t=malloc(sizeof(*t));
if(!t){printf("\nRunning out of memory");exit(0);}
printf("\nEnter the ssn,Name,Department,Designation,Salary,PhoneNo of the employee: \n");
scanf(" %s %s %s %s %d %ld",t->s,t->nme,t->d,t->g,&t->sal,&t->p);
t->l=t->r=NULL; c++; return t;
}
N ifr(){ N t=cr(); if(f) f->l=t,t->r=f; return t; }
N ien(){
N t=cr(),p=f;
if(!f) return t;
while(p->r) p=p->r;
p->r=t; t->l=p; return f;
}
N dfr(){
if(!f) return printf("\nDoubly Linked List is empty"),NULL;
N t=f; printf("\nThe employee node with the ssn:%s is deleted",t->s);
f=t->r; if(f) f->l=NULL;
free(t); c--; return f;
}
N den(){
if(!f) return printf("\nDoubly Linked List is empty"),NULL;
if(!f->r){
printf("\nThe employee node with the ssn:%s is deleted",f->s);
free(f); c--; return NULL;
}
N p=f; while(p->r->r) p=p->r;
printf("\nThe employee node with the ssn:%s is deleted",p->r->s);
free(p->r); p->r=NULL; c--; return f;
}
void dis(){
if(!f)  printf("\nNo Contents to display in DLL");
int i=1; for(N p=f;p;p=p->r)
printf("\nENode:%d||SSN:%s|Name:%s|Department:%s|Designation:%s|Salary:%d|Phone no:%ld", i++,p->s,p->nme,p->d,p->g,p->sal,p->p);
printf("\nNo of employee nodes is %d",c);
}
void deq(){
    int ch;
    for(;;){
        printf("\nDemo Double Ended Queue Operation");
        printf("\n1:InsertQueueFront\n 2: DeleteQueueFront\n 3:InsertQueueRear\n 4:DeleteQueueRear\n 5:DisplayStatus\n 6: Exit \n");
        scanf(" %d",&ch);
        if(ch==1) f=ifr();
        else if(ch==2) f=dfr();
        else if(ch==3) f=ien();
        else if(ch==4) f=den();
        else if(ch==5) dis();
        else return;
    }
}

int main(){
    int ch,n;
for(;;){
printf("\n\n~~~Menu~~~");
printf("\n1:Create DLL of Employee Nodes\n2:DisplayStatus\n3:InsertAtEnd\n4:DeleteAtEnd");
printf("\n5:InsertAtFront\n6:DeleteAtFront\n7:Double Ended Queue Demo using DLL\n8:Exit \n");
printf("\nPlease enter your choice: ");
scanf(" %d",&ch);
if(ch==1){printf("\nEnter the no of Employees: ");
scanf(" %d",&n);while(n--)f=ien();}
else if(ch==2) dis();
else if(ch==3) f=ien();
else if(ch==4) f=den();
else if(ch==5) f=ifr();
else if(ch==6) f=dfr();
else if(ch==7) deq();
else if(ch==8) exit(0);
else printf("\nPlease Enter the valid choice");
}
}
