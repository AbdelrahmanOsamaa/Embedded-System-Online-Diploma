#include "stdio.h"
#include "string.h"

struct Semployee
{
	char *name;
	int id;
};



int main()
{
	
	//program 1
	printf("Write a program in C to demonstrate how to handle the pointers "
			"in the program\n\n");
	int m;
	int *ab=NULL;
	m=29;
	printf("Address of m : 0x%p\n",&m);
	printf("Value of m : %d\n\n",m);
	ab=&m;
	printf("now ab assigned to address of m\n");
	printf("Address of pointer ab : 0x%p\n",ab);
	printf("Value of pointer ab : %d\n\n",*ab);

	printf("Value of m assigned to 34 now.\n");
	m=34;
	printf("Address of pointer ab : 0x%p\n",ab);
	printf("Value of pointer ab : %d\n\n",*ab);
	*ab=7;
	printf("the pointer variable ab is now assigned to 7.\n");

	printf("Address of m : 0x%p\n",&m);
	printf("Value of m : %d\n\n",m);


	// program 2
	 printf("Write a program in C to print all the alphabets using a pointer.\n\n");
	char Alph[]={'A', 'B', 'C', 'D', 'E','F','G','H','I','J','K','L',
		'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','/0'};
	char *ptr=NULL;
	int i;
	ptr=Alph;

	for(i=0;i<26;i++)
	{
		printf("%c\n",*ptr+i);
	}

	// ################################################
	//program 3
	printf("Write a C program to print a string in reverse using a pointer.\n\n");

	char sentence[100];
	char *ptr=NULL;
	int i=0;
	ptr=sentence;
	printf("enter a string :");
	fflush(stdin);fflush(stdout);
	gets(sentence);
	while(*ptr!=0)
	{
		i++;
		ptr++;
	}
	printf("Reverse of string is : ");
	while(i>=0)
	{
		printf("%c",*ptr--);
		i--;
	}

	// ################################################
	//program 4

	printf("##Write a program in C to print the elements of an array in reverse "
			"order##\n\n");

	int num[15],i,n,*ptr;
	ptr=num;
	printf("enter number of elements to store in array (max 15): ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("element-%d :",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",ptr+i);
	}
	printf("\nThe elements of array in reverse order are :\n");
	for (i=n;i>0;i--)
	{
		printf("element-%d :%d\n",i,*ptr+i-1);
	}

	// ################################################
	//program 5
	printf("Write a program in C to show a pointer to an array which "
			"contents are pointer to structure.\n\n");

    struct SEmployee emp1 = {"Alex", 1002};
    struct SEmployee emp2 = {"Mohamed", 1003};

    struct SEmployee *Ptr1 = &emp1;
    struct SEmployee *Ptr2 = &emp2;

    struct SEmployee *arrPtr[] = {Ptr1, Ptr2};


    for (int i=0;i<2;i++)
    {
        printf("Employee Name: %s\n", arrPtr[i]->name);
        printf("Employee ID: %d\n", arrPtr[i]->ID);
    }
    printf("\n\n");

    return 0;
}

}


