#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	//定义文件的数组
	char name[20];
	//定义统计字符还是单词的数组
	char str[3];
	//输入-w或者-c,和文件夹的全名
	scanf("%s%s", str, name);
	FILE  *f = fopen(name, "r");
	//定义txt数组保存文件的数据
	char txt[100];
	int count = 0, i = 0;
	char c;
	//读文件，直到末尾
	while (!feof(f))
	{
		//将文件内容赋值c
		c = fgetc(f);
		//将c赋值给数组
		txt[i] = c;
		i++;
		count++;
	}
	//因为结尾不算
	count--;
	int n = 0, flag = 0;
	//统计字符
	if (strcmp(str, "-c") == 0)
	{
		printf("字符数:%d\n", count);
	}
	//统计单词
	else
	{
		//遍历保存的数据
		for (i = 0; i<count; i++)
		{
			//如果遇到空格，逗号,或者换行分开的，都视为一个单词
			if (txt[i] == ' ' || txt[i] == '\n' || txt[i] == '\t' || txt[i] == ',')
				flag = 0;
			else if (flag == 0)
			{
				flag = 1;
				n++;
			}
		}
		printf("单词数:%d\n", n);
	}
}
