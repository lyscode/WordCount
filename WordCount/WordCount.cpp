#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	//�����ļ�������
	char name[20];
	//����ͳ���ַ����ǵ��ʵ�����
	char str[3];
	//����-w����-c,���ļ��е�ȫ��
	scanf("%s%s", str, name);
	FILE  *f = fopen(name, "r");
	//����txt���鱣���ļ�������
	char txt[100];
	int count = 0, i = 0;
	char c;
	//���ļ���ֱ��ĩβ
	while (!feof(f))
	{
		//���ļ����ݸ�ֵc
		c = fgetc(f);
		//��c��ֵ������
		txt[i] = c;
		i++;
		count++;
	}
	//��Ϊ��β����
	count--;
	int n = 0, flag = 0;
	//ͳ���ַ�
	if (strcmp(str, "-c") == 0)
	{
		printf("�ַ���:%d\n", count);
	}
	//ͳ�Ƶ���
	else
	{
		//�������������
		for (i = 0; i<count; i++)
		{
			//��������ո񣬶���,���߻��зֿ��ģ�����Ϊһ������
			if (txt[i] == ' ' || txt[i] == '\n' || txt[i] == '\t' || txt[i] == ',')
				flag = 0;
			else if (flag == 0)
			{
				flag = 1;
				n++;
			}
		}
		printf("������:%d\n", n);
	}
}
