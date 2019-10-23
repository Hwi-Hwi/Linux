#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20	//이름 최대 길이

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct _Student Student;

struct  _Student
{
	char name[MAX_NAME_LEN];
	int middle;
	int final;
	int* left;
	int* right;
};

void postorder(Student *a)
{
	if (a->left != NULL)
		postorder(a->left); //왼쪽
	if (a->right != NULL)
		postorder(a->right);//오른쪽
		printf("%-8s %3d %3d \n",
			a->name, a->middle, a->final);
}

void add(Student* a, Student* b, BOOL chk) {
	if (chk) {//왼쪽 자식이 없으면 
		a->left = b;
	}
	else {
		a->right = b;
	}
}

void main()
{
	int n = 0;
	Student *base = 0;
	int i = 0;

	printf("Enter a number of student : ");
	scanf("%d", &n);//학생 수 입력

	base = (Student *)calloc(n, sizeof(Student));//학생 수 * 학생 구조체 크기의 메모리 할당

	for (i = 0; i < n; i++)//학생 정보 입력
	{
		printf("Enter a student info : num, name, mid score, final score\n");
		scanf("%s %d %d",
			base[i].name, MAX_NAME_LEN, &base[i].middle, &base[i].final);
		base[i].left = NULL;
		base[i].right = NULL;
	}

	/* 트리만드는거만 고치면 됨 */
	for (int i = 0; i < n-2; i +=2) {

		if(base[i].left == NULL) add(&base[i], &base[i+1], TRUE);
		if(base[i].right == NULL) add(&base[i], &base[i+2], FALSE);
	}

	for (i = 0; i < n; i++)//학생 정보 입력
	{
		printf("Entered a student info : num, name, mid score, final score, right, left\n");
		printf("%s %d %d %d %d \n", base[i].name, 
			base[i].middle,	base[i].final,	
			base[i].left, base[i].right);
		printf("학생 %d의 포인터 주소 : %d\n\n", i, &base[i]);
	}

	printf("후위순회 : \n");
	postorder(base);//출력
	free(base);//동적 할당받은 메모리 해제

	system("pause");
}
