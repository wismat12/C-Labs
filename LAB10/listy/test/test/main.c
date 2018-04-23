#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char *fname;
    char *lname;
}Data;

typedef struct STUDENT Student;

struct STUDENT
{
    Data data;
    Student* next;
};

Student* new_student()
{
	Student* student;
	char bufor[60];
	char *fname, *lname;

	system("clear");
	printf("Firstname: ");
	if(gets(bufor) != NULL)
    {
        fname = (char*)malloc(sizeof(char)* (strlen(bufor)));
	    strcpy(fname, bufor);
    }

	printf("Lastname: ");
	if(gets(bufor) != NULL)
    {
	    lname = (char*)malloc(sizeof(char)* (strlen(bufor)));
	    strcpy(lname, bufor);
    }

	student = (Student*)malloc(sizeof(Student));
	student->next = NULL;
	student->data.fname = fname;
	student->data.lname = lname;

	return student;
}

void add_to_list(Student **head)
{
	Student *tmp = new_student();

	if (*head != NULL)
		tmp->next = *head;
	*head = tmp;
}

void print_list(Student *head)
{
	Student *tmp;

	system("clear");
	tmp = head;
	if (tmp == NULL)
		printf("List is empty");
	else
	{
		while (tmp != NULL)
		{
			printf("%s %s\n", tmp->data.fname, tmp->data.lname);
			tmp = tmp->next;
		}
	}
	getchar();
}

void delete_list(Student **head)
{
	Student *tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		if (tmp->data.fname)
			free(tmp->data.fname);
		if (tmp->data.lname)
			free(tmp->data.lname);
		free(tmp);
	}
}

void menu(Student *head){
	char i;

	do
	{
		system("clear");
		printf("1. Add student to list\n");
		printf("2. Print list\n");
		printf("3. Delete list\n");
		printf("0. Exit\n\n");
		printf("Choose an option (0-3): ");
		i = getchar();
		getchar();
		if (i == '1') add_to_list(&head);
		else if (i == '2') print_list(head);
		else if (i == '3') delete_list(&head);
	} while (i != '0');
}

int main()
{
    Student *head = NULL;

    menu(head);

    return 0;
}
