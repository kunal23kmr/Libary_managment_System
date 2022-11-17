#include <Stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{
	char name[20];
	int age;
	int dateofjoining;
	int month;
	int year;
} e1, e2, e3, e4, e5;
void display(struct employee st)
{
	printf("NAME : %s\n", st.name);
	printf("AGE : %d\n", st.age);
	printf("DATE OF JOINING : %d/%d/%d\n", st.dateofjoining, st.month, st.year);
}
int main()
{
	int num;
	strcpy(e1.name, "Ron");
	strcpy(e2.name, "James");
	strcpy(e3.name, "Jack");
	strcpy(e4.name, "Ash");
	strcpy(e5.name, "Bob");
	e1.age = 30;
	e2.age = 23;
	e3.age = 25;
	e4.age = 28;
	e5.age = 32;
	e1.dateofjoining = 6;
	e2.dateofjoining = 12;
	e3.dateofjoining = 18;
	e4.dateofjoining = 24;
	e5.dateofjoining = 30;
	e1.month = 2;
	e2.month = 4;
	e3.month = 6;
	e4.month = 8;
	e5.month = 10;
	e1.year = 2015;
	e2.year = 2016;
	e3.year = 2017;
	e4.year = 2018;
	e5.year = 2019;
	printf("Enter employee number to access record of him: ");
	scanf("%d", &num);
	if (num == 1)
	{
		display(e1);
	}
	else if (num == 2)
	{
		display(e2);
	}
	else if (num == 3)
	{
		display(e3);
	}
	else if (num == 4)
	{
		display(e4);
	}
	else if (num == 5)
	{
		display(e5);
	}
	return 0;
}