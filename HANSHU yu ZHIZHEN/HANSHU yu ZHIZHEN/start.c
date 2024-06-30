#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define len 88
char* s_gets(char* st, int n);
void Toupper(char*);
void Tolower(char*);
void Transpose(char*);
void Origin(char*);
void qinli();
void show(void(*fp)(char*), char*str);
char showmenu();

int main(void)
{
	char line[len];
	char copy[len];
	char xuanze;
	void(*pfun)(char*);
	puts("������һ��Ӣ���ַ�����");
	while (s_gets(line, len) != NULL && line[0] != '\0')
	{
		while ((xuanze = showmenu()) != 'n')
		{
			switch (xuanze)
			{
			case 'u':
				pfun = Toupper;
				break;
			case 'l':
				pfun = Tolower;
				break;
			case 'o':
				pfun = Origin;
				break;
			case't':
				pfun = Transpose;
				break;
			}
			strcpy(copy, line);//����һ�ݱ���ԭʼ���ݷ����������
			show(pfun, copy);
		}
		puts("��������һ��Ӣ���ַ��������������˳�����");
	}
	puts("�ټ�");
	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret;
	char* find;
	ret = fgets(st, n, stdin);
	if (ret)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret;
}
char showmenu()
{
	char ret;
	puts("���������ѡ��:");
	puts("u :ȫ����дΪ��д     l :ȫ����д΢΢Сд");
	puts("o :ȫ�������Ͱ�       t :��Сд����ת��");
	puts("n :��һ���ַ���");
	ret = getchar();
	ret = tolower(ret);
	qinli();
	while (strchr("ulotn", ret) == NULL)
	{
		printf("���� u l o t nѡ������\n");
		ret = islower(getchar());
		qinli();
	}
	return ret;
}
void qinli()
{
	while (getchar() != '\n')
		continue;
}
void Toupper(char*st)
{
	while (*st)
	{
		*st = toupper(*st);
		st++;
	}
}
void Tolower(char* st)
{
	while (*st)
	{
		*st = tolower(*st);
		st++;
	}
}
void Transpose(char* st)
{
	while (*st)
	{
		if (islower(*st))
		{
			*st = toupper(*st);
			st++;
		}
		if (isupper(*st))
		{
			*st = tolower(*st);
			st++;
		}
	}
}
void Origin(char* st)
{

}
void show(void(*fp)(char*), char*str)
{
	fp(str);
	puts(str);
}