#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char *gen[] = { "남", "여" };

typedef enum gndr
{
	남,
	여
} gndr;

typedef struct date
{
	int year;
	int month;
	int day;
} date;

typedef struct identity
{
	char name[20];
	date bdate;
	gndr gender;
	char address[30];
	long long int phonenum;
} identity;

void sort(int size, int mode);
int structtoi(date data);
void inputdata(int index);
void printdata(int size);

identity set[10];

int main()
{
	int size;
	printf("데이터의 개수를 입력하여 주세요 (5이상 10미만)>> ");
	scanf("%d", &size);
	for (int iter = 0; iter < size; iter++)
	{
		inputdata(iter);
	}
	printdata(size);
	for (int mode = 1; mode < 3; mode++)
	{
		sort(size, mode);
		printdata(size);
	}
	return 0;
}

void sort(int size, int mode)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && (mode == 1 ? strcmp(set[j - 1].name, set[j].name) == 1 : structtoi(set[j - 1].bdate) > structtoi(set[j].bdate)); j--)
		{
			identity swapbuffer = set[j - 1];
			set[j - 1] = set[j];
			set[j] = swapbuffer;
		}
	}
}

int structtoi(date data)
{
	return (data.year * 100 + data.month) * 100 + data.day;
}

void inputdata(int index)
{
	char name[20], address[30];
	int year, month, day, gen;
	long long int phonenum;
	printf("이름을 입력하여 주세요>> ");
	scanf("%s", name);
	while (getchar() != '\n');
	printf("생일을 년, 월, 일 순으로 입력하여 주세요 (예: 2018 10 31)>> ");
	scanf("%d %d %d", &year, &month, &day);
	while (getchar() != '\n');
	printf("성별을 입력하여 주세요 (남(0)/여(1))>> ");
	scanf("%d", &gen);
	while (getchar() != '\n');
	printf("주소를 입력하여 주세요>> ");
	gets_s(address, 30);
	printf("전화번호를 하이픈 없이 입력하여 주세요>> ");
	scanf("%lld", &phonenum);
	while (getchar() != '\n');
	date bdate = { year, month, day };
	strcpy(set[index].name, name);
	set[index].bdate = bdate;
	set[index].gender = gen;
	strcpy(set[index].address, address);
	set[index].phonenum = phonenum;
}

void printdata(int size)
{
	printf("\n");
	printf("이름\t생년월일\t\t성별\t주소\t\t\t\t\t전화번호\n");
	for (int i = 0; i < size; i++)
	{
		printf(
			"%s\t%4d년 %2d월 %2d일\t%s\t%s\t\t\t0%lld-%lld-%lld\n",
			set[i].name, set[i].bdate.year, set[i].bdate.month, set[i].bdate.day, gen[set[i].gender], set[i].address, set[i].phonenum / 100000000, (set[i].phonenum / 10000) % 10000, set[i].phonenum % 10000
		);
	}
}
