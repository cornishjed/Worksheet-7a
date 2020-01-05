#include <stdio.h>

typedef struct {
	int feet;
	int inches;
}Measure;

Measure addMeasures(Measure, Measure);

int main()
{
	Measure measure1;
	Measure measure2;

	measure1.feet = 5;
	measure1.inches = 11;
	measure2.feet = 6;
	measure2.inches = 2;

	printf("Measure1\nFeet: %d   Inches: %d\n", measure1.feet, measure1.inches);
	printf("Measure2\nFeet: %d   Inches: %d\n", measure2.feet, measure2.inches);

	Measure returnedStruct = addMeasures(measure1, measure2);

	printf("ReturnedStruct\nFeet: %d   Inches: %d\n", returnedStruct.feet, returnedStruct.inches);

	return 0;

}

Measure addMeasures(Measure x, Measure y)
{
	Measure result;
	result.feet = x.feet + y.feet;
	result.inches = x.inches + y.inches;

	return result;
}
