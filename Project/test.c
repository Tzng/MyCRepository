#include <stdio.h>
#include <stdlib.h>

int Judge(bool flag, FILE *fp);

int Menu(char a[], bool flag2, FILE *fp);

void Operate(char a[], char op, bool flag2, bool flag1, FILE *fp);

void Read(char a[], FILE *fp);

void Write(char a[], FILE *fp);

void Change(char a[], char op, FILE *fp);

int Delete(bool flag1);

int main()
{   
    FILE	*fp;
    char	op = '0';
	char	a[1000] = { 0 };
    bool    flag1   = 0;
	bool	flag2	= 0;

	flag2 = Judge(flag2, fp);

	/* 选择进行的操作 */
	Operate(a, op, flag2, flag1, fp);

	/* 关闭文件 */
	fclose (fp);
	system ("PAUSE");
	return(0);
}


int Menu(char a[], bool flag2, bool flag1, FILE *fp)
{
    flag2 = Judge(flag2, fp);
	if (flag2 == 1 && flag1 == 0)
	{
        /* 文件存在 */
        printf ("File already exist!\n");
		Read(a, fp);
		printf ("\nMenu:\n");
		printf ("2:Delete the file.\n");
		printf ("3:Change the file.\n");
	}
    else 
    {
        /* 文件不存在 */
        printf ("File does not exist!\n");
		printf ("\nWhether to creat new files?\n");
		printf ("Menu:\n");
		printf ("1:Creat new files.\n");
	}
	printf ("4:Exit.\n");
	printf ("Please enter the function to perform:\n");
    return (flag2);
}


void Operate(char a[], char op, bool flag2, bool flag1, FILE *fp)
{
	while (op != '4')
	{
		flag2 = Menu(a, flag2, flag1, fp);
		scanf ("%c", &op);
		getchar ();
		switch (op)
		{
		case '1':
			if (flag2 == 0 || flag1 == 1)
			{
				/* 写数据进文件 */
				Write(a, fp);
			}
			else  
			{
				printf ("\nError operation!\n");
			}
			break;
		case '2':
			if (flag2 == 1)
			{
				/* 删除文件 */
				flag1 = Delete(flag1);
			}
			else  
			{
				printf ("\nError operation!\n");
			}
			break;
		case '3':
			if (flag2 == 1)
			{
				/* 修改文件数据 */
				Change(a, op, fp);
			}
			else  
			{
				printf ("\nError operation!\n");
			}
			break;
		case '4':
			/* 退出 */
			printf ("\nExit the success!\n");
			system ("PAUSE");
			exit (0);
		default:
			printf ("\nUnknown operation!\n");
			printf ("please enter again!\n");
		}
	}
}


int Judge(bool flag2, FILE *fp)
{
	if ((fp = fopen ("D:\\data.txt", "r")) != NULL)
	{
		flag2 = 1;
	}
    fclose(fp);
	return(flag2);
}


void Read(char a[], FILE *fp)
{
	fp = fopen ("D:\\data.txt", "r");
	*fgets (a, 1000, fp);
	printf ("\nFile contents:\n%s\n", a);
    fclose(fp);
}


void Write(char a[], FILE *fp)
{
	fp = fopen ("D:\\data.txt", "w");
	printf ("\nInput char!\n");
	gets (a);
	fputs (a, fp);
    printf("\n");
    fclose(fp);
}


void Change(char a[], char op, FILE *fp )
{
	printf ("\n1:Keep the original content changes.\n");
	printf ("2:Cover the original content changes.\n");
	printf ("Please enter the function to perform:\n");
	scanf ("%c", &op);
	getchar ();
	switch (op)
	{
	/* 保留源文件内容 */
	case '1': fp = fopen ("D:\\data.txt", "a");
		printf ("\nInput char!\n");
		gets (a);
		fputs (a, fp);
        fclose(fp);
		break;

	/* 不保留源文件内容 */
	case '2': fp = fopen ("D:\\data.txt", "w");
		printf ("\nInput char!\n");
		gets (a);
		fputs (a, fp);
        fclose(fp);
		break;

	default: printf ("\nError operation!\n");
		printf ("please enter again!\n");
	}
}


int Delete(bool flag1)
{
	if (remove ("D:\\data.txt") == 0)
	{
		printf ("Delete success!\n");
        flag1 = 1;
	}
	else
	{
		perror ("Delete failed");
	}
    return (flag1);
}