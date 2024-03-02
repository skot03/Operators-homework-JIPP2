#include <string>
#pragma once
using namespace std;
class Path
{
private:
	string location;
public:
	Path(); //zrobione
	Path(const string&);  //zrobione
	Path(const Path&); //kopiujacy wykorzystuje w innych metodach

	void setPath(string); //zrobione
	string getPath(); //zrobione
	Path operator+(string);//zeby potem moc wykorzystac zwracam obiekt
	void operator+=(string);
	void operator--(); //zrobione
	bool operator==(const Path&);//zrobione
	bool operator!=(const Path&);//zrobione
	bool operator<=(const Path&); //zrobione
	friend ostream& operator<<(ostream&, const Path&);//zrobione

};

