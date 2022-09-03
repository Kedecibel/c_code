#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct stu
{
	char name[20];
	int age;
};

void print_arr(int* p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", *p++);
	printf("\n");
}
void print_str(struct stu* p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", (p++)->age);
	}
	printf("\n");
}

void swap(char* left, char* right, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right++;
	}
}

int com_int(const void* x, const void* y)
{
	return *(int*)x - *(int*)y;
}

int com_str(const void* x, const void* y)
{
	return ((struct stu*)x)->age - ((struct stu*)y)->age;
}

void bubble_sort(void* p, int num, int se, int(*comp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			int ret = comp((char*)p + j * se, (char*)p + (j + 1) * se);
			if (ret > 0)
			{
				 swap((char* )p + j * se, (char* ) p + (j + 1) * se,se);

			}
		}
	}
}

//void bubble_sort(int* p, int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (p[j] > p[j + 1])
//			{
//				int temp = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = temp;
//			}
//		}
//	}
//}

test1()
{
	int arr[10] = { 1,6,5,4,3,2,8,7,9,10 };
	
	bubble_sort(arr, sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),com_int);
	print_arr(arr, sizeof(arr)/sizeof(arr[0]));
}

test2()
{
	struct stu a[4] = { {"zhangsan",23},{"lisi",22},{"wangwu",26},{"liuer",20} };
	bubble_sort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), com_str);
	print_str(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	test1();
	test2();

	return 0;
}