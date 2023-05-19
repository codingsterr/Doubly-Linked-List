#include<stdio.h>
#include<stdlib.h>
 struct node
 {
    int data;
    struct node *next,*prev;
 };
 typedef struct node NODE;
 struct node *temp,*last,*start,*p;

 void insertAtFirstDLL(int ele)
 {
    temp=(NODE*)malloc(sizeof(NODE*));
    temp->data=ele;
    if(start==NULL)
    {
        temp->next=NULL;
        last=temp;
    }
    else
    {
     temp->next=start;
     start->prev=temp;
    }
     temp->prev=NULL;
     start=temp;
 }


 void insertAtLastDLL(int ele)
 {
    temp=(NODE *)malloc(sizeof(NODE*));
    temp->data=ele;
    temp->next=NULL;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        last->next=temp;
        temp->prev=last;
    }
    last=temp;
 }


 void deleteAtFirstDLL()
 {
    if(start==NULL)
    {
        printf("LIST IS EMPTY ");
    }
    else
    {
        p=start;
        printf("DELETED ELEMENT IS %d",p->data);
        start=start->next;
        start->prev=NULL;
        free(p);
    }
 }


 void deleteAtLastDLL()
 {
     if(start==NULL)
    {
        printf("LIST IS EMPTY ");
    }
    else
    {
        p=last;
        printf("DELETED ELEMENT IS %d ",p->data);
        last=last->prev;
        last->next=NULL;
        free(p);
    }
 }


 void forwardTraversal()
 {
    if(start==NULL)
    {
        printf("LIST IS EMPTY ");
    }
    else
    {
        p=start;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
 }


 void backwardTraversal()
 {
    if(start==NULL)
    {
        printf("LIST IS EMPTY ");
    }
    else
    {
        p=last;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->prev;
        }
    }
 }


void search(int ele)
{
    int i=1,flag=0;
    if(start==NULL)
    {
        printf("\nLIST IS EMPTY");
    }
    p=start;
    while(p!=NULL)
    {
        if(p->data==ele)
        {
            flag=1;
            break;
        }
        p=p->next;
        i++;
    }
    if(flag==0)
    {
        printf("ELEMENT NOT FOUND ");
    }
    else
    {
        printf("ELEMENT FOUND AT %d POSITION",i);
    }
}


int main()
{
    int n,choice,subchoice;
    start=NULL;
    do
    {
        printf("\n----------MENU----------");
        printf("\n1.INSERTION");
        printf("\n2.DELETION");
        printf("\n3.TRAVERSAL");
        printf("\n4.SEARCH");
        printf("\n5.EXIT");
        printf("\n------------------------");
        printf("\nEnter your choice");
        scanf("%d",&choice);

      switch(choice)
      {
        case 1: printf("Enter the element\n");
                scanf("%d",&n); 
                printf("\n1.Insertion At First");
                printf("\n2.Insertion At Last");
                printf("\nEnter your Sub Choice ");
                scanf("%d",&subchoice);
              switch(subchoice)
              {
                case 1: insertAtFirstDLL(n);
                            break;

                case 2: insertAtLastDLL(n);
                            break;

                default: printf("\nInvalid Choice");
              }  
                break;

        case 2: printf("\n1.Deletion At First");
                printf("\n2.Deletion At Last");
                printf("\nEnter your Sub Choice ");
                scanf("%d",&subchoice);
              switch(subchoice)
              {
                 case 1:deleteAtFirstDLL();
                            break;

                case 2: deleteAtLastDLL();
                            break;

                default: printf("\nInvalid Choice");
              }  
                break;

        case 3: printf("\n1.Forward Traversal");
                printf("\n2.Backward Traversal");
                printf("\nEnter your Sub Choice ");
                scanf("%d",&subchoice);
              switch(subchoice)
              {
                 case 1:forwardTraversal();
                            break;

                case 2: backwardTraversal();
                            break;

                default: printf("\nInvalid Choice");
              }    
                break;

        case 4: printf("Enter the element ");
                scanf("%d",&n); 
                search(n);
                break;

        case 5: break;

        default: printf("Invalid Choice");

      }
    } while (choice!=5);
    return 0;
}
