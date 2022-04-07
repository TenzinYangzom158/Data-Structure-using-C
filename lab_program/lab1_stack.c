#include <stdio.h>			//header files
#include <stdlib.h>

int array();		// prototype's
void linkedlist();

//array
void push(void);
void pop(void);
void display(void);

int stack[100],choice,n,top,x,i;	//variables
int count = 0;
struct node                         //struct used in linked list
{
    int info;
    struct node *ptr;
}*ltop,*top1,*temp;

//linked list
int topelement();
void lpush(int data);
void lpop();
void empty();
void ldisplay();
void destroy();
void stack_count();
void create();

void main()
{
	main_menu();
}

void main_menu()  // main menu
{
    char choice = ' ' ; //local variable

  printf("               IMPLEMENTING STACK USING ARRAY AND LINKED LIST         \n ");
  printf("             +=================================================+          \n\n");
  printf("  +== ENTER YOUR CHOICE TO IMPLEMENT STACK ==+ \n\n");
  printf("\t\t      [A] USING ARRAY\n");
  printf("\t\t      [B] USING LINKED LIST\n");
  printf("\t\t      [C] Exit\n\n");
  printf("ENTER YOUR CHOICE : ");
  scanf("%c", &choice);
  system("cls");

    {
		if (toupper(choice) == 'A' )
		  array();
		  else if (toupper(choice) == 'B')
            linkedlist();
                else if (toupper(choice) == 'C')
                exit(0);
                    else if (toupper(choice) != 'A' , 'B' , 'C')
                    {
                        main_menu();
                    }
	}


}

//STACK IMPLEMENTATION USING ARRAY
int array()
{
    //clrscr();
    top=-1;
    printf("\n ENTER THE SIZE OF STACK [MAX=100] : ");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t [1]PUSH\n\t [2]POP\n\t [3]DISPLAY\n\t [4]EXIT \n");
    do
    {
        printf("\n ENTER YOUR CHOICE :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                main_menu();
                break;
            }
            default:
            {
                printf ("\n ENTER VALID CHOICE [ 1 | 2 | 3 | 4 ] \n");
            }

        }
    }
    while(choice!=4);
    return 0;
}

void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK IS OVER FLOW!!");

    }
    else
    {
        printf(" ENTER A VALUE TO BE PUSHED:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t STACK IS UNDER FLOW!!");
    }
    else
    {
        printf("\n\t THE POPPED ELEMENT IS %d \n",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n THE ELEMENT IN STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n PRESS NEXT CHOICE ");
    }
    else
    {
        printf("\n THE STACK IS EMPTY!");
    }

}


//STACK IMPLEMENTATION USING LINKED LIST
void linkedlist()
{
    int no, ch, e;

    printf("\n 1 - PUSH");
    printf("\n 2 - POP");
    printf("\n 3 - TOP");
    printf("\n 4 - EMPTY");
    printf("\n 5 - EXIT");
    printf("\n 6 - DISPLAY");
    printf("\n 7 - STACK COUNT");
    printf("\n 8 - DESTROY STACK");

    create();

    while (1)
    {
        printf("\n ENTER YOUR CHOICE : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("ENTER DATA : ");
            scanf("%d", &no);
            lpush(no);
            break;
        case 2:
            lpop();
            break;
        case 3:
            if (ltop == NULL)
                printf("STACK IS EMPTY");
            else
            {
                e = topelement();
                printf("\n TOP ELEMENT IS : %d", e);
            }
            break;
        case 4:
            empty();
            break;
        case 5:
            main_menu();
        case 6:
            ldisplay();
            break;
        case 7:
            stack_count();
            break;
        case 8:
            destroy();
            break;
        default :
            printf(" ENTER VALID CHOICE ");
            break;
        }
    }
}

/* Create empty stack */
void create()
{
    ltop = NULL;
}

/* Count stack elements */
void stack_count()
{
    printf("\n NO. OF ELEMENTS IN THE STACK : %d", count);
}

/* Push data into stack */
void lpush(int data)
{
    if (ltop == NULL)
    {
        ltop =(struct node *)malloc(1*sizeof(struct node));  //allocating node
        ltop->ptr = NULL;
        ltop->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = ltop;
        temp->info = data;
        ltop = temp;
    }
    count++;
}

/* Display stack elements */
void ldisplay()
{
    top1 = ltop;

    if (top1 == NULL)
    {
        printf("STACK IS EMPTY");
        return;
    }

    while (top1 != NULL)
    {
        printf("\n%d ", top1->info);
        top1 = top1->ptr;
    }
 }

/* Pop Operation on stack */
void lpop()
{
    top1 = ltop;

    if (top1 == NULL)
    {
        printf("\n ERROR : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->ptr;
    printf("\n THE POPPED ELEMENT IS : %d", ltop->info);
    free(ltop);
    ltop = top1;
    count--;
}

/* Return top element */
int topelement()
{
    return(ltop->info);
}

/* Check if stack is empty or not */
void empty()
{
    if (ltop == NULL)
        printf("\n STACK IS EMPTY!!");
    else
        printf("\n STACK IS NOT EMPTY, CONTAINS %d ELEMENTS", count);
}

/* Destroy entire stack */
void destroy()
{
    top1 = ltop;

    while (top1 != NULL)
    {
        top1 = ltop->ptr;
        free(ltop);
        ltop = top1;
        top1 = top1->ptr;
    }
    free(top1);
    ltop = NULL;

    printf("\n ALL STACK ELEMENTS ARE DESTROYED !");
    count = 0;
}



