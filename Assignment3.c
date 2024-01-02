
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define NAME_LEN 25

//Node Stucture 
typedef struct part {
  int number;
  char name[NAME_LEN+1];
  int onHand;
  struct part *next;
} Part;

//Function Declarations
Part * insertPart(int, char[], int,Part *);
void print(Part *);
Part *changeQuantity(int, int , Part *);
Part *search(int, Part *);
void bubbleSort(Part *);
void swap(Part *, Part *);

void bubbleSort(Part *start)  
{  
    int swapped;
    Part *ptr1;
    Part *lptr = NULL;

    /* Checking for an empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->number > ptr1->next->number)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void swap(Part *a, Part *b)  
{  
    int temp_number = a->number;
    char temp_name[NAME_LEN+1];
    int temp_onHand;

    temp_number = a->number;
    strcpy(temp_name, a->name);
    temp_onHand = a->onHand;

    a->number = b->number;
    strcpy(a->name, b->name);
    a->onHand = b->onHand;

    b->number = temp_number;
    strcpy(b->name, temp_name);
    b->onHand = temp_onHand;
}

//Add a new part to list
Part * insertPart(int num, char newName[], int numberOnHand, Part *head) {
    Part *new_part;
    new_part = (Part *) malloc(sizeof(Part));
    if (new_part != NULL) {  // Check if malloc was successful.
        new_part->number = num;
        strcpy(new_part->name, newName);
        new_part->onHand = numberOnHand;
        new_part->next = head;
        head = new_part; // Update the head to the new_part.
    }
	bubbleSort(head);
	return head;
}

Part *search(int n, Part *list)
{ 
	Part *p;
	for (p = list; p != NULL; p = p->next)
		if (p->number == n)
			return p;
	return NULL;
}

Part *changeQuantity(int n, int quantity, Part *list)
{ 
	Part *p;
	for (p = list; p != NULL; p = p->next)
		if (p->number == n){
			p->onHand = quantity;
			return p;
		}
	return NULL;
}


//Print all the elements in the linked list
void print(Part *head) {
  Part *current_part = head;
  while ( current_part != NULL) {
    printf("Part number: %d -- Part name: %s -- Amount on hand: %d\n\n",current_part->number, current_part->name, current_part->onHand);
    current_part = current_part->next;
  }
}

//Program main 
int main()
{
   Part *head = NULL;
   int num, quantity, newQuantity, prev_num, next_num;
   char option;
   char name[NAME_LEN+1];
   char * temp;
   char ch;
   //Display Menu
   while(1) {

     printf("\n====================================================\n");
     printf("\nAdd new part...Enter i to add\n");
     printf("\nFind part and quantity...Enter s to find\n");
     printf("\nUpdate quantity on hand...Enter u to update quantity\n");
	 printf("\nDisplay all parts...Enter p to display the inventory\n");
     printf("\nQuit...Press q to quit\n");
     printf("\nEnter your choice: ");
     if (scanf("%c", &option) != 1) {
        printf("Error: Invalid input. Try again.\n");
        while (getchar() != '\n'); //clear input buffer 
        continue;
     }

     switch (option) {
      case 'i':    //Add new part
	  	  printf("Enter a part number : ");
          if (scanf("%d", &num) != 1) {
              printf("Error: Invalid input.\n");
              while (getchar() != '\n');   //clear input buffer 
              continue;
          }
		  
		  printf("Enter a part name : ");
		  scanf("%s", name);
		  
		  
		  printf("Enter quantity of part : ");
		  if(scanf("%d", &quantity) != 1) {
		  	  printf("Error: Invalid input");
			  while (getchar() != '\n');
			  continue;
		  }
		  
          head = insertPart(num, name, quantity, head);
          printf("Part with part number %d added to the inventory", num);
          printf("\nPress any key to continue...");
		  getch();
          while (getchar() != '\n');
          break;

      case 's':    //find part and quantity
	  	  printf("Enter a part number : ");
          if (scanf("%d", &num) != 1) {
              printf("Error: Invalid input.\n");
              while (getchar() != '\n');   //clear input buffer
              continue;
          }
		  
		  Part *part = search(num, head);

		  if (part != NULL) {
		      printf("The part number is %d, the name of the part is %s, and the amount on hand is %d\n", part->number, part->name, part->onHand);
			  printf("\nPress any key to continue...");
			  getch();
			  while (getchar() != '\n');
          	  break;
		  } else {
		      printf("The part %d was not found in the list.\n", num);
			  printf("\nPress any key to continue...");
			  getch();
			  while (getchar() != '\n');
              break;
		  }
		  


	  
      case 'u':    //Change quantity on hand
	      printf(" Enter a part number : ");
          if (scanf("%d", &num) != 1) {
              printf("Error: Invalid input. \n");
              while (getchar() != '\n'); 
              continue;
          }
		  
		  Part *partSearch = search(num, head);
		  
		  printf("Enter the quantity you want to change to: ");
		  if(scanf("%d", &newQuantity) != 1) {
		  	  printf("Error: Invalid input. \n");
			  while (getchar() != '\n');
			  continue;
		  }
		  
		  if (partSearch != NULL) {
		  	  changeQuantity(num, newQuantity, partSearch);
		      printf("The new quantity for part number %d is %d\n", partSearch->number, partSearch->onHand);
			  printf("\nPress any key to continue...");
			  getch();
			  while (getchar() != '\n');
          	  break;
		  } else {
		      printf("The part %d was not found in the list.\n", num);
			  printf("\nPress any key to continue...");
			  getch();
			  while (getchar() != '\n');
              break;
		  }
		  

	  
      case 'p':    //Show list
	  	  printf("\n==============================\n");
          printf("\nList of the parts we have: \n\n ");
          print(head);
          printf("\nPress any key to continue...");
          getch();
		  while (getchar() != '\n');
		  break;


	  case 'q': //Exit
          return(0);
          break;

      default:
          printf("Invalid Option. Please Try again.");
          while (getchar() != '\n');

      } //End of Switch
   } //End of While

return(0);
}

