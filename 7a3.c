#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int id;
	char *fullName;
	int finalMark;
}Student;

typedef struct {
	Student students[20];
	char* className;
	int classCode;
}Class;

int findAverageMark(Class);

int main()
{
	int choice = 0;

	Class class1;

	class1.className = "CLASS1";

	class1.classCode = 12345;

	//case1
	char fClassName[25]; //set max length of string
	int fClassCode;

	//case2
	int ID = 0;
	int finalMark = 0;
	char *name[2][50] = { '\0' };
	char *halfName = { '\0' };
	char *mFullName = { '\0' };
	char *nameCopy = { '\0' };
	int count = 0;

	//case5
	int searchID = 0;

	for (int x = 0; x < 20; x++)
	{
		class1.students[x].id = 0;
		class1.students[x].fullName = "\0";
		class1.students[x].finalMark = 0;
	}

	while (choice != 6) {
		printf("1 - Set class name and code\n2 - Add a new student to the class\n3 - Print class details\n4 - Find the average class mark\n5 - Print student details given ID\n6 - Exit\n ");
		printf("\nMake a selection: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			//1.enter class name and code
			printf("\n\nEnter class name: ");
			scanf("%s", fClassName); //scanf string doesn't require '&' operator
			class1.className = fClassName;

			printf("\nEnter class code: ");
			scanf("%d", &fClassCode);
			class1.classCode = fClassCode;
			printf("\n----------------------------------\n");
			break;

		case 2:
			//2.add new student
			printf("\n\nEnter student ID: ");
			scanf("%d", &ID);

			printf("\nEnter first name: ");
			scanf("%s", name[0]);
			printf("\nEnter last name: ");
			scanf("%s", name[1]);

			printf("\nEnter final mark: ");
			scanf("%d", &finalMark);

			halfName = strcat(name[0], " ");
			mFullName = strcat(halfName, name[1]);
			nameCopy = strdup(mFullName); //so student.fullName[x] does not get overwritten

			class1.students[count].id = ID;
			class1.students[count].fullName = nameCopy;
			class1.students[count].finalMark = finalMark;

			count++;

			printf("\n----------------------------------\n");
			break;

		case 3:
			//3.Get class details
			printf("\n\nClass Name: %s", class1.className);
			printf("\tClass Code: %d\n\n", class1.classCode);

			for (int x = 0; x < 20; x++)
			{
				printf("Student ID: %d", class1.students[x].id);
				printf("\tFull Name: %s", class1.students[x].fullName);
				printf("\tFinal Mark: %d\n", class1.students[x].finalMark);
			}
			printf("\n----------------------------------\n");
			break;

		case 4:
			//4. Find average mark
			printf("\n\nThe average mark is: %d", findAverageMark(class1));
			printf("\n----------------------------------\n");
			break;

		case 5:
			//5. Get student details given ID
			printf("\n\nEnter student ID: ");
			scanf("%d", &searchID);

			for (int x = 0; x < 20; x++)
			{
				if (class1.students[x].id == searchID)
				{
					printf("\n\nStudent ID: %d", class1.students[x].id);
					printf("\nFull Name: %s", class1.students[x].fullName);
					printf("\nFinal Mark: %d", class1.students[x].finalMark);
					printf("\n");
					break;
				}
				else if (x == 19)
				{
					printf("\nID not found\n");
				}
			}
			printf("\n----------------------------------\n");
			break;
		}
	}

	free(nameCopy);

	return 0;
}

int findAverageMark(Class c1)
{
	int total = 0;
	int average = 0;
	for (int x = 0; x < 20; x++)
	{
		total += c1.students[x].finalMark;
	}
	average = total / 20;
}
