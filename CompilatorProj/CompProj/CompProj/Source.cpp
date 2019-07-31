#include <iostream>;
#include <fstream>;
#include <string>;
using namespace std;
//textposition 
short lastinline; //����� ���������� ������� � ������� ������
const short MAXLINE = 255; //������������ ������ ����������� ������
const short ERRMAX = 10;
char line[MAXLINE];
char ch;
short ErrInx=0;
bool ErrorOverFlow = false;
struct textposition
{
	unsigned y; /*����� ������ */
	unsigned x; /*����� �������	� ������ */
} pos; //������� ������� �������
struct
{
	struct textposition errorposition;
	unsigned errorcode;
} ErrList[ERRMAX];
void main()
{
	ifstream fi1("input.txt");
	ifstream fi2("err.msg");
	//ifstream fi3("errtbl");
	ofstream fo("output.txt");
	pos.x = 0;
	pos.y = 0;
	//fi1 >> line;
	//cout << line << endl;
	while (!fi1.eof())
	{
		fi1 >> line ;
		cout << line<<endl ;
	}
	getchar();
}
void ListErrors()
{

}
void error(unsigned errorcode, textposition position)
{
	if (ErrInx == ERRMAX)
		ErrorOverFlow = true;
	else
	{
		++ErrInx;
		ErrList[ErrInx].errorcode = errorcode;
		ErrList[ErrInx].errorposition.y = position.y;
		ErrList[ErrInx].errorposition.x = position.x;
	}
}
void nextch(ifstream fi1, ofstream fo)
{
	if (pos.x==lastinline)//��������� ������ ������
	{
		fo << line;//�������� ������
		if (ErrInx) //� ������� ������ ������� ������
		{
			ListErrors();//���������� ��������� �� �������
		}
		fi1 >> line;
		pos.x = 0;
		pos.y++;
	}
	else 
	{
		pos.x++;
	}
	ch = line[pos.x];

	//���������� � �������� ������� ��������� ������ � �������� �� ����������
}