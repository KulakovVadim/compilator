#include <iostream>;
#include <fstream>;
#include <string>;
#include "iomanip";
using namespace std;
//textposition 
short lastinline; //номер последнего символа в текущей строке
const short MAXLINE = 255; //максимальная длинна считываемой строки
const short ERRMAX = 10; //наибольшее количество ошибок в строке, о которых будет получать информацию пользователь
char line[MAXLINE];
char ch;
short ErrInx=0;//кол-во обнаруженных ошибок в текущей строке
bool ErrorOverFlow = false; //количество ошибок, обнаруженных в текущей строке, превышает ERRMAX
struct textposition
{
	unsigned y; /*номер строки */
	unsigned x; /*номер позиции	в строке */
} pos; //текущая позиция символа
struct
{
	struct textposition errorposition;
	unsigned errorcode;
} ErrList[ERRMAX];
void initerrors()
{
	ErrList[0].errorcode = 3;
	ErrList[0].errorposition.y = 2;
	ErrList[0].errorposition.x = 0;

	ErrList[1].errorcode = 4;
	ErrList[1].errorposition.y = 2;
	ErrList[1].errorposition.x = 7;

	ErrList[2].errorcode = 31;
	ErrList[2].errorposition.y = 5;
	ErrList[2].errorposition.x = 1;
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
	//cout << d << endl;
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
				s += "_";
			s += "^ "; 
			cout << s << ErrList[CurErr].errorcode<< endl;
			CurErr++;
		}
	}
	getchar();
}
void ListErrors()//печать сообщений об ошибках
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
	if (pos.x==lastinline)//последняя литера строки
	{
		fo << line;//Печатаем строку
		if (ErrInx) //в текущей строке найдены ошибки
		{
			ListErrors();//напечатать сообщения об ошибках
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

	//установить в качестве текущей следующую литеру и записать ее координаты
}