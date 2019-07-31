#include <iostream>;
#include <fstream>;
#include <string>;
using namespace std;
//textposition 
short lastinline; //номер последнего символа в текущей строке
const short MAXLINE = 255; //максимальная длинна считываемой строки
const short ERRMAX = 10;
char line[MAXLINE];
char ch;
short ErrInx=0;
bool ErrorOverFlow = false;
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