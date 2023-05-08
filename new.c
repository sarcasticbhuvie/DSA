#include<stdio.h>
struct node{
    int data;
    struct node *next;
    };
    struct node *start=NULL;
    void main()
    {
        struct node *new_node,*ptr;
        int value;
        printf("Enter -1 to eit");
        printf("enter value:");
        scanf("%d",&value);
        while(value!=-1)
        {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=value;
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("enter value:");
        scanf("%d",&value);
        }
        ptr=start;
        printf("The Given Linked List is:");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }

