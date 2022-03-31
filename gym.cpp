#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Client
{
    int rollnumber;
    char name[100];
    char phone[100];
    char gender[6];
    struct Client *next;

}* head;

void insert(int rollnumber, char* name, char* phone, char* gender)
{

    struct Client * client = (struct Client *) malloc(sizeof(struct Client));
	client->rollnumber = rollnumber;
	strcpy(client->name, name);
	strcpy(client->phone, phone);
	strcpy(client->gender, gender);
	client->next = NULL;

	if(head==NULL){
		// if head is NULL
		// set client as the new head
		head = client;
	}
	else{
		// if list is not empty
		// insert client in beginning of head
		client->next = head;
		head = client;
	}

}

void search(int rollnumber)
{
    struct Client * temp = head;
	while(temp!=NULL){
		if(temp->rollnumber==rollnumber){
			printf("Roll Number: %d\n", temp->rollnumber);
			printf("Name: %s\n", temp->name);
			printf("Phone: %s\n", temp->phone);
			printf("Gender(M/F): %s\n", temp->gender);
			return;
		}
		temp = temp->next;
	}
	printf("Client with roll number %d is not found !!!\n", rollnumber);
}

void update(int rollnumber)
{

    struct Client * temp = head;
	while(temp!=NULL){

		if(temp->rollnumber==rollnumber){
			printf("Record with roll number %d Found !!!\n", rollnumber);
			printf("Enter new name: ");
			scanf("%s", temp->name);
			printf("Enter new phone number: ");
			scanf("%s", temp->phone);
			printf("Enter new gender(M/F): ");
			scanf("%s",&temp->gender);
			printf("\nUpdation Successful!!!\n");
			return;
		}
		temp = temp->next;

	}
	printf("Client with roll number %d is not found !!!\n", rollnumber);

}

void Delete(int rollnumber)
{

    struct Client * temp1 = head;
	struct Client * temp2 = head;
	while(temp1!=NULL){

		if(temp1->rollnumber==rollnumber){

			printf("Record with roll number %d Found !!!\n", rollnumber);

			if(temp1==temp2){
				// this condition will run if
				// the record that we need to delete is the first node
				// of the linked list
				head = head->next;
				free(temp1);
			}
			else{
				// temp1 is the node we need to delete
				// temp2 is the node previous to temp1
				temp2->next = temp1->next;
				free(temp1);
			}

			printf("Record Successfully Deleted !!!\n");
			return;

		}
		temp2 = temp1;
		temp1 = temp1->next;

	}
	printf("Client with roll number %d is not found !!!\n", rollnumber);

}

void display()
{
    struct Client * temp = head;
	while(temp!=NULL){

		printf("Roll Number: %d\n", temp->rollnumber);
		printf("Name: %s\n", temp->name);
		printf("Phone: %s\n", temp->phone);
		printf("Gender(M/F): %s\n\n", temp->gender);
		temp = temp->next;

	}
}


int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    char gender[6];
    int rollnumber;

printf("\n\n\n\t\t ********************************* \t\t\t");
printf("\n\t\t ****  GYM MANAGEMENT SYSTEM  **** \t\t\t");
printf("\n\t\t ********************************* \t\t\t");

    printf("\n\n1 to add new client\n2 to search for client details\n3 to delete client details\n4 to update client details\n5 to display all client details\n6 to monitor attendance\n7 to gym schedule\n8 to diet schedule");
    do
    {
        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter gender(M/F): ");
                scanf("%s", gender);
                insert(rollnumber, name, phone, gender);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(rollnumber);
                break;
            case 5:
                display();
                break;
            case 6:
                display();
                break;
            case 7:

                break;
            case 8:
                display();
                break;
        }

    } while (choice != 0);

}
