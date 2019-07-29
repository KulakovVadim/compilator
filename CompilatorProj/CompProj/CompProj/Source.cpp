#include <iostream>;
#include <fstream>;
#include <string>;
using namespace std;
void main()
{
	string fi1("input.txt");
	string fi2("err.msg");
	string fi3("errtbl");
	string fo("output.txt");
	textposition positionnow;
	positionnow.x = 0;
	positionnow.y = 0;
}
struct textposition
{
	unsigned y; /*номер строки */
	unsigned x; /*номер позиции	в строке */
} ;
void nextch(ifstream fi1)
{
	//short lastinline;
	//const short MAXLINE = 255;
	//char line[MAXLINE];
	if (0)//последняя литера строки
	{
		//печать строки
		if (0) //в текущей строке найдены ошибки
		{
			//напечатать сообщения об ошибках
		}
		//прочитать следующую строку
	}
	//установить в качестве текущей следующую литеру и записать ее координаты
}
void readwrite(string outputname, string inputname, string errtable, string errnames)
{
	while (!fi1.eof)
	{
		pos.y++;
		pos.x = 0;
		char c;
		do
		{
			fi1 >> c;
			pos.x++;
		} while (fi1.end)
	};

}