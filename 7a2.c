#include <stdio.h>

typedef struct
{
	int ID;
	char* itemName;
	char* description;
	enum {GRAMS, LBS} weightType;
	union Weight {
		int grams;
		float lbs;
	}w;
}package;

void printDetails(package);

int main()
{
	package item1 = { 123, "Evian 500ml", "A 500ml bottle of still Evian water", LBS};

	if (item1.weightType == GRAMS)
		item1.w.grams = 500;
	else if (item1.weightType == LBS)
		item1.w.lbs = 1.11;

	printDetails(item1);

	return 0;

}

void printDetails(package p1)
{
	printf("ID: %d", p1.ID);
	printf("\nItem Name: %s", p1.itemName);
	printf("\nDescription: %s", p1.description);
	if (p1.weightType == GRAMS)
		printf("\nWeight (grams): %d\n", p1.w.grams);
	else if (p1.weightType == LBS)
		printf("\nWeight (lbs): %.2f\n", p1.w.lbs);
}
