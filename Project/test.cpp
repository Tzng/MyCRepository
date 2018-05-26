#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;


class File
{
public:
	File()
	{
	}


	int Judge( bool flag2 );


	int Menu( char a[], bool flag2, bool flag1);

	void Operate( char a[], char op, bool flag2, bool flag1);

	void Read( char a[] );

	void Write( char a[] );

	void Change( char a[], char op );

	int Delete( bool flag1);


private:
	char	op;
	char	ch;
	char	a[1000];
	bool	flag1, flag2;
};

int main()
{
	char	op = '0';
	char	ch;
	char	a[1000] = { 0 };
	bool	flag1	= 0;
    bool    flag2   = 0;
	File	fo;

	/* 判断文件是否存在 */
	flag2 = fo.Judge( flag2 );

	/* 选择进行的操作 */
	fo.Operate( a, op, flag2 ,flag1);
	system( "PAUSE" );
	return(0);
}


int File::Menu( char a[], bool flag2, bool flag1)
{
	flag2 = Judge( flag2 );
	if ( flag2 == 1 && flag1 ==0)
	{
		/* 文件存在 */
		cout << "File already exist!" << endl;
		Read( a );
		cout << "\nMenu:" << endl;
		cout << "2:Delete the file." << endl;
		cout << "3:Change the file." << endl;
	}  else{
		/* 文件不存在 */
		cout << "File does not exist!" << endl;
		cout << "\nWhether to creat new files?" << endl;
		cout << "Menu:" << endl;
		cout << "1:Creat new files." << endl;
	}
	cout << "4:Exit." << endl;
	cout << "Please enter the function to perform:" << endl;
	return(flag2);
}


void File::Operate( char a[], char op, bool flag2, bool flag1 )
{
	while ( op != '4' )
	{
        /* 打开菜单 */
		flag2 = Menu( a, flag2, flag1);
		cin >> op;
		getchar();
		switch ( op )
		{
		case '1':
			if ( flag2 == 0 || flag1 == 1 )
			{
				/* 写数据进文件 */
				Write( a );
			}
            else  
            {
				cout << "\nError operation!" << endl;
			}
			break;
		case '2':
			if ( flag2 == 1 )
			{
				/* 删除文件 */
				flag1 = Delete(flag1);
			}
            else 
            {
				cout << "\nError operation!" << endl;
			}
			break;
		case '3':
			if ( flag2 == 1 )
			{
				/* 修改文件数据 */
				Change( a, op );
			}
            else  
            {
				cout << "\nError operation!" << endl;
			}
			break;
		case '4':
			/* 退出 */
			cout << "\nExit the success!" << endl;
			system( "PAUSE" );
			exit( 0 );
		default:
			cout << "\nUnknown operation!" << endl;
			cout << "please enter again!" << endl;
		}
	}
}


int File::Judge( bool flag2 )
{
	ifstream fin;
    
    /* 打开可读文件 */
	fin.open( "D:\\data.txt", ios::in );
	if ( fin.is_open() )
	{
		flag2 = 1;
	}
    fin.close();
	return(flag2);
}


void File::Read( char a[] )
{
	ifstream fin;
    
    /* 打开可读文件 */
	fin.open( "D:\\data.txt", ios::in );
	cout << "\nFile contents:\n" << endl;

    /* 读出文件内容 */
	while ( fin.get( ch ) )
	{
		cout << ch;
	}
	fin.close();
}


void File::Write( char a[] )
{
	ofstream fout;
	fout.open( "D:\\data.txt", ios::out );
	cout << "Writing to the file:" << endl;
	gets( a );
	fout << a;
	cout << endl;
	fout.close();
}


void File::Change( char a[], char op )
{
	cout << "\n1:Keep the original content changes." << endl;
	cout << "2:Cover the original content changes." << endl;
	cout << "Please enter the function to perform:" << endl;
	cin >> op;
	getchar();
	ofstream	fout;
	ifstream	fin;
	switch ( op )
	{
	/* 保留源文件内容 */
	case '1': fout.open( "D:\\data.txt", ios::app );
		cout << "\nInput char!" << endl;
		gets( a );
		fout << a;
		cout << endl;
		fout.close();
		break;

	/* 不保留源文件内容 */
	case '2': fout.open( "D:\\data.txt", ios::out );
		cout << "\nInput char!" << endl;
		gets( a );
		fout << a;
		cout << endl;
		fout.close();
		break;

	default: cout << "\nError operation!" << endl;
		cout << "please enter again!" << endl;
	}
}


int File::Delete(bool flag1)
{
    /* 删除文件 */
	if ( remove( "D:\\data.txt" ) == 0 )
	{
		cout << "Delete success!" << endl;
        flag1 = 1;
	}
    else  
    {
		perror( "Delete failed" );
	}
    return (flag1);
}