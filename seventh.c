#include<stdio.h>
#include<stdlib.h>
typedef struct n{
char u[25],nm[25],b[25];
int s; long p;
struct n *l;
}*N;
N st=NULL; int c=0;
N cr(){
N t=malloc(sizeof(*t));
if(!t) exit(1);
printf("\nEnter the usn,Name,Branch, sem,PhoneNo of the student:");
scanf(" %s %s %s %d %ld",t->u,t->nm,t->b,&t->s,&t->p);
t->l=NULL; c++;
return t;
}
N ifr(){ N t=cr(); t->l=st; return t;
 }
N dfr(){
if(!st) return printf("\nLinked list is empty"),NULL;
N t=st; st=t->l;
printf("\nThe Student node with usn:%s is deleted",t->u);
free(t); c--; return st;
}
N ien(){
N t=cr(),p=st;
if(!st) return t;
while(p->l) p=p->l;
p->l=t; return st;
}
N den(){
if(!st) return printf("\nLinked List is empty"),NULL;
if(!st->l){
printf("\nThe student node with the usn:%s is deleted",st->u);
free(st); c--; return NULL;
}
N p=st;
while(p->l->l) p=p->l;
printf("\nThe student node with the usn:%s is deleted",p->l->u);
free(p->l); p->l=NULL; c--; return st;
}
void dis(){
if(!st)
    printf("\nNo Contents to display in SLL\n");
printf("\nThe contents of SLL: \n");
int i=1;
for(N p=st;p;p=p->l)
        printf("\n||%d|| USN:%s| Name:%s| Branch:%s| Sem:%d| Ph:%ld|",
               i++,p->u,p->nm,p->b,p->s,p->p);
    printf("\n No of student nodes is %d \n",c);
}

void stk(){
    int ch;
    for(;;){
        printf("\n~~~Stack Demo using SLL~~~\n");
        printf("\n1:Push operation \n2: Pop operation \n3: Display \n4:Exit \n");
        printf("\nEnter your choice for stack demo:");
        scanf(" %d",&ch);
        if(ch==1) st=ifr();
        else if(ch==2) st=dfr();
        else if(ch==3) dis();
        else return;
    }
}

int main(){
int ch,n;
for(;;){
printf("\n~~~Menu~~~\nEnter your choice for SLLoperation \n");
printf("\n1:Create SLL of Student Nodes\n2:DisplayStatus\n3:InsertAtEnd");
printf("\n4:DeleteAtEnd\n5:Stack Demo using SLL(Insertion and Deletion at Front)\n6:Exit \n");
printf("\nEnter your choice:");
scanf(" %d",&ch);
if(ch==1){ printf("\nEnter the no of students: ");
scanf(" %d",&n); while(n--) st=ifr(); }
else if(ch==2) dis();
else if(ch==3) st=ien();
else if(ch==4) st=den();
else if(ch==5) stk();
else if(ch==6) exit(0);
else printf("\nPlease enter the valid choice");
}
}
