#include <iostream>;
#include <fstream>;
#include <string>;
#include "iomanip";
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
void initerrors()
{
	ErrList[0].errorcode = 3;
	ErrList[0].errorposition.y = 2;
	ErrList[0].errorposition.x = 4;
	ErrList[1].errorcode = 4;
	ErrList[1].errorposition.y = 2;
	ErrList[1].errorposition.x = 7;
	ErrList[4].errorcode = 31;
	ErrList[4].errorposition.y = 5;
	ErrList[4].errorposition.x = 0;
}
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
	int i = 0;
	int CurErr = 0;
	initerrors();
	cout << d << endl;
	while (!fi1.eof())
	{
		i++;
		fi1 >> line ;
		cout << setfill(' ')<<setw(4)<< i <<"    "<< line<<endl ;
		while (i == ErrList[CurErr].errorposition.y)
		{
			cout << setfill('*') << setw(4) << CurErr << "**  ";
			string s = "";
			for (int k = 0; k < ErrList[CurErr].errorposition.x; k++)
				s += " ";
			s += "^ " + ErrList[CurErr].errorcode;
			cout << s << endl;
			CurErr++;
		}
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