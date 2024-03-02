#include "Path.h"
#include <iostream>
/* program przysporzyl mi troche trudnosci ale dzieki pomocy kolegow zrozumialem troche bardziej temat, poznalem nowe funkcje takie jak erase i pop back
szczerze mowiac mysle ze jakbym mial napisac to jeszcze raz samemu bez dostepu do dokumentacji internetu i Pana skryptu to by³by problem. Chêtnie przyjme jakieœ ciekawe materia³ 
na temat przeci¹zeñ operatorów

*/
using namespace std;

Path::Path()
{
	location = "/";

}

Path::Path(const string& rhs)
{
	
	if (rhs[0] != '/')
	{
		location = "";
		return;
	}
	if (rhs == "/")
	{
		location = rhs;
		return;
	}
	for (int i = 0; i < rhs.size() - 1; ++i)
		if (rhs[i] == '/' && rhs[i + 1] == '/')
		{
			cout << "Nie moze byc pustej nazwy katalogu";
			location = "";
			return;
		}
	location = rhs;
	if (!location.empty() && location.back() == '/') {
		location.erase(location.size() - 1,1);//usuwam jeden znak z konca chodzi o /
	}
}

Path::Path(const Path& rhs)
{
	location = rhs.location;
}


void Path::setPath(string rhs)
{
	if (rhs[0] != '/')
	{

		cout << "bledna nazwa sciezki, nie moze zaczynac sie od / ustawiam ja jako "" " << endl;
		location = "";
		return;
	}
	for (int i = 0; i < rhs.size() - 1; ++i)
	{
		if (rhs[i] == '/' && rhs[i + 1] == '/')
		{
			location = ""; //ustawiam "" jezeli nazwa jest bledna tak jak w instrukcji 
			cout << "nazwa katalogu nie moze byc pusta ustawiam ja jako """ << endl;
			return; //sprawdzam czy nazwa katalogu nie jest pusta
		}
	}
	location = rhs;
	if (location[location.size() - 1] == '/')
	{
		string temp;
		for (int i = 0; i < location.size() - 2; ++i)
		{
			temp[i] = location[i];

		}
		location = temp;
	}
}

bool Path::operator<=(const Path& rhs)
{
	bool condition = true;
	if (rhs.location[0] != '/')
	{
		return false;
	}
	if (rhs.location.size() > location.size())
	{
		return true;
	}
	for (int i = 0; i < rhs.location.size(); i++)
	{
		if (rhs.location[i] != location[i])
			condition = false;
		break;
	}
	return condition;
}



string Path::getPath() {

	return location; //metoda zwracania sciezki

}
void Path::operator+=(string rhs)
{
	if (location == "")
		return;
	for (int i = 0; i < rhs.size() - 1; ++i) {
		bool hasConsecutiveSlashes = rhs[i] == '/' && rhs[i + 1] == '/';
		bool isSurroundedBySlashes = i > 0 && i < rhs.size() - 1 &&
			rhs[i - 1] != '/' && rhs[i] == '/' && rhs[i + 1] != '/';

		if (hasConsecutiveSlashes || isSurroundedBySlashes) {
			return;
		}
	}

	if (rhs[0] != '/')
	{
		location += "/";
	}

	location += rhs;

	if (location.back() == '/')
	{
		location.pop_back();
	}
}

Path Path::operator+(string rhs)
{
	if (location == "")
	{
		return location;
	}
	Path kopiujacy;
	kopiujacy = location;
	for (int i = 0; i < rhs.size() - 1; ++i) {
		bool hasConsecutiveSlashes = rhs[i] == '/' && rhs[i + 1] == '/';
		bool isSurroundedBySlashes = (i > 0 && i < rhs.size() - 1) && (rhs[i - 1] != '/' && rhs[i] == '/' && rhs[i + 1] != '/');

		if (hasConsecutiveSlashes || isSurroundedBySlashes) {
			return kopiujacy;
		}
	}
	
	if (rhs[0] != '/')
	{
		kopiujacy.location += "/"; //dokonczyc
	}
	kopiujacy.location += rhs;
	if (!kopiujacy.location.empty() && kopiujacy.location.back() == '/') {
		kopiujacy.location.pop_back();
	}
	return kopiujacy;
}
void Path::operator--()
{
	if (location == "/") {
		cout << "sciezka sklada sie tylko z / nie moge go usunac nic nie zmieniam" << endl;
		return; 
	}
	if (location == "")
	{
		cout << "sciezka jest pusta nie mam co usunac" << endl;
		return;
	}
	if (!location.empty()) {
		size_t lastSlash = location.find_last_of('/'); //size_t find_last_of(const string& str, size_t pos = npos) const noexcept; znalazlem taka funkcje
		if (lastSlash != string::npos) {
			if (lastSlash == 0) {
				location = "/";
			}
			else {
				location.erase(lastSlash);
			}
		}
		else {
			
			location = "/";
		}
	}
}


bool Path::operator==(const Path& rhs)
{

	return location == rhs.location;

}
bool Path::operator!=(const Path& rhs)
{

	return location != rhs.location;

}
ostream& operator<<(ostream& stream, const Path& rhs)
{
	stream << rhs.location;
	return stream;
}