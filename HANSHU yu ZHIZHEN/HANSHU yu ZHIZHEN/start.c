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
	puts("请输入一段英文字符串：");
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
			strcpy(copy, line);//拷贝一份保护原始数据方便持续操作
			show(pfun, copy);
		}
		puts("请输入下一个英文字符串：（空输入退出程序）");
	}
	puts("再见");
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
	puts("请输入你的选择:");
	puts("u :全部改写为大写     l :全部改写微微小写");
	puts("o :全部按部就班       t :大小写互相转换");
	puts("n :下一个字符串");
	ret = getchar();
	ret = tolower(ret);
	qinli();
	while (strchr("ulotn", ret) == NULL)
	{
		printf("请在 u l o t n选择输入\n");
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