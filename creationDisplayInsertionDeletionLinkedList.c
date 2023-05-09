// Online C compiler to create a linked list
#include <stdio.h>
#include<stdlib.h>
struct node *start=NULL;
struct node
{
    int data;
    struct node *next;
};
struct node *create_new(struct node*);
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *insert_after(struct node*);
struct node *insert_before(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_after(struct node*);
struct node *delete_before(struct node*);
struct node *delete_node(struct node*);
int main()
{
    int choice;
    do
    {
        printf("1.To Create a list\n");
        printf("2.To display a list\n");
        printf("3.To add at Biggining of list\n");
        printf("4.To add at End of list\n");
        printf("5.To add After a number in list\n");
        printf("6.To add before a number in list\n");
        printf("7.To delete at beggining of list\n");
        printf("8.To delete at end of list\n");
        printf("9.To delete after a number of list\n");
        printf("10.To delete before a number of list\n");
        printf("11.To delete a particular node of list\n");
        printf("15.To Exit\n-----------\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("----------------------------------------\n");
        switch(choice)
        {
        case 1:
            start=create_new(start);
            printf("======List Created=====\n----------------------------------------\n");
            break;
        case 2:
            start=display(start);
            printf("\n----------------------------------------\n");
            break;
        case 3:
            start=insert_beg(start);
            break;
        case 4:
            start=insert_end(start);
            break;
        case 5:
            start=insert_after(start);
            break;
        case 6:
            start=insert_before(start);
            break;
        case 7:
            start=delete_beg(start);
            break;
        case 8:
            start=delete_end(start);
            break;
        case 9:
            start=delete_after(start);
            break;
        case 10:
            start=delete_before(start);
            break;
        case 11:
            start=delete_node(start);
            break;
        case 15:
            exit (0);
        default:
            printf("-------Invalid Key-------\n==Pleasse Try again with right Input==\n");
        }
    }
    while(1);
}
struct node *create_new(struct node* start)
{
    int value;
    struct node *ptr,*new_node;
    printf("Enter the value:");
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
        fflush(stdin);
        printf("Enter the value:");
        scanf("%d",&value);
    }
    return start;
};
struct node *display(struct node* start)
{
    struct node *ptr;
    printf("The linked list is:");
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    return start;
};
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int value;
    printf("Enter the value:");
    scanf("%d",&value);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=start;
    start=new_node;
    return start;
}
struct node *insert_end(struct node* start)
{
    int value;
    printf("Enter the Value:");
    scanf("%d",&value);
    struct node *new_node,*ptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;

    }
    ptr->next=new_node;
return start;
};
struct node *insert_after(struct node* start)
{
    int value,num;
    printf("Enter the number after which you want to insert:");
    scanf("%d",&num);
    printf("Enter the Value:");
    scanf("%d",&value);
    struct node *new_node,*ptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    ptr=start;
    while(ptr->data!=num)
    {
        ptr=ptr->next;
    }
    new_node->next=ptr->next;
    ptr->next=new_node;
return start;
};
struct node *insert_before(struct node* start)
{
    int value,num;
    printf("Enter the number before which you want to insert:");
    scanf("%d",&num);
    printf("Enter the Value:");
    scanf("%d",&value);
    struct node *new_node,*ptr,*preptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    ptr=start;
    preptr=start;
    while(ptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    new_node->next=ptr;
    preptr->next=new_node;
return start;
};
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
};
struct node *delete_end(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    free(ptr);
    preptr->next=NULL;
    return start;
};
struct node *delete_after(struct node *start)
{
    int num;
    printf("Enter the Number after which you want to delete :");
    scanf("%d",&num);
    struct node *ptr,*temp;
    ptr=start;
    while(ptr->data!=num)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    return start;
};
struct node *delete_before(struct node *start)
{
  int num;
    printf("Enter the Number before which you want to delete :");
    scanf("%d",&num);
    struct node *ptr,*preptr,*ppreptr;
    ptr=start;
    preptr=start;
    ppreptr=start;
    while(ptr->data!=num)
    {
        ppreptr=preptr;
        preptr=ptr;
        ptr=ptr->next;
    }
    ppreptr->next=ptr;
    free(preptr);
    return start;
};
struct node *delete_node(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    int value;
    printf("Enter the number which you want to delete:");
    scanf("%d",&value);
    if(start->data==value)
    {
        start=start->next;
        free(ptr);
    }
    else
    {
        while(ptr->data!=value)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    }
    return start;
};
