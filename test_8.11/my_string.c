#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* e1, const void* e2, size_t n)
{
	assert(e1 && e2);
	int i = 0;
	void* ret = e1;
	for (i = 0 ; i < n; i++)
	{
		*(char*)e1 = *(char*)e2;
		e1 = (char*)e1 + 1;
		e2 = (char*)e2 + 1;
	}
	return ret;
}

void* my_mommove(void* e1, const void* e2, size_t n)
{


}

int main()
{
	char arr[20] = "hello world";
	int des[10] = { 0 };
	int sour[10] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memcpy(des, sour, 20);

	return 0;
}