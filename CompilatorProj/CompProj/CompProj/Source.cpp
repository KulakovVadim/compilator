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
	unsigned y; /*����� ������ */
	unsigned x; /*����� �������	� ������ */
} ;
void nextch(ifstream fi1)
{
	//short lastinline;
	//const short MAXLINE = 255;
	//char line[MAXLINE];
	if (0)//��������� ������ ������
	{
		//������ ������
		if (0) //� ������� ������ ������� ������
		{
			//���������� ��������� �� �������
		}
		//��������� ��������� ������
	}
	//���������� � �������� ������� ��������� ������ � �������� �� ����������
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