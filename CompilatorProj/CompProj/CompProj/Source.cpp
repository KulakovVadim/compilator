#include <iostream>;
#include <fstream>;
#include <string>;
using namespace std;
//textposition 
short lastinline; //����� ���������� ������� � ������� ������
const short MAXLINE = 255; //������������ ������ ����������� ������
char line[MAXLINE];
char ch;
struct textposition
{
	unsigned y; /*����� ������ */
	unsigned x; /*����� �������	� ������ */
} pos; //������� ������� �������
void main()
{
	ifstream fi1("input.txt");
	ifstream fi2("err.msg");
	ifstream fi3("errtbl");
	ofstream fo("output.txt");
	pos.x = 0;
	pos.y = 0;
	fi1 >> line;
	//cout << line << endl;
	do ()
	{

	}
	getchar();
}
void nextch(ifstream fi1, ofstream fo)
{
	if (pos.x==lastinline)//��������� ������ ������
	{
		fo << line;
		if (0) //� ������� ������ ������� ������
		{
			//���������� ��������� �� �������
		}
		fi1 >> line;
	}
	else {
		pos.x++;
		ch = line[pos.x];
	}

	//���������� � �������� ������� ��������� ������ � �������� �� ����������
}