#include <iostream>;
#include <fstream>;
#include <string>;
using namespace std;
//textposition 
short lastinline; //номер последнего символа в текущей строке
const short MAXLINE = 255; //максимальная длинна считываемой строки
char line[MAXLINE];
char ch;
struct textposition
{
	unsigned y; /*номер строки */
	unsigned x; /*номер позиции	в строке */
} pos; //текущая позиция символа
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
	if (pos.x==lastinline)//последняя литера строки
	{
		fo << line;
		if (0) //в текущей строке найдены ошибки
		{
			//напечатать сообщения об ошибках
		}
		fi1 >> line;
	}
	else {
		pos.x++;
		ch = line[pos.x];
	}

	//установить в качестве текущей следующую литеру и записать ее координаты
}