#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
using namespace std;



struct slovnuk
{
	map <string, list<string>> lib;
	void add(string en, list<string> ru)
	{
		lib.emplace(pair<string, list<string>>(en, ru));
	}
	void print()
	{
		for (auto it = lib.begin(); it != lib.end(); ++it)
		{
			cout << it->first << " : ";
			for (string ou : it->second)
			{
				cout << "\n\t\t  " << ou << endl;
			}
		}
		cout << endl;
	}
	void addValue(string en, string ru)
	{
		for (auto it = lib.begin(); it != lib.end(); ++it)
		{
			if (it->first == en)
			{
				it->second.push_back(ru);
			}
		}
	}
	void addMine()
	{
		list<string> sd;
		string qw = "";
		string qe = "";

		cout << "Add eng word _"; cin >> qw;
		while (qe != "0")
		{
			cout << "Add ru value _"; cin >> qe;
			sd.push_back(qe);
			cout << "Что бы выйти введите 0" << endl;
		}
		lib.insert(pair<string, list<string>>(qw, sd));
	}
	void del(string en)
	{
		auto ii = lib.end();
		for (auto it = lib.begin(); it != lib.end(); ++it)
		{
			if (it->first == en)
			{
				ii = it;
			}
		}
		if (ii != lib.end())
			lib.erase(ii);
		else
			cout << "not found";
	}
	void editEn(string en, string ennew)
	{
		for (auto it = lib.begin(); it != lib.end(); ++it)
		{
			if (it->first == en)
			{
				lib.emplace(pair<string, list<string>>(ennew, it->second));
			}
		}
		if (lib.find(ennew) != lib.end())
			this->del(en);
	}
	void editRu(string en, string ru, string runew)
	{
		bool success = false;
		list<string> sd;
		for (auto it = lib.begin(); it != lib.end(); ++it)
		{
			if (it->first == en)
			{
				for (string s : it->second)
				{
					if(s!=ru)
						sd.push_back(s);
				}
				sd.push_back(runew);
				lib.emplace(pair<string, list<string>>("111", sd));
				success = true;
			}
		}
		if (success)
		{ 
			this->del(en);
			this->editEn("111", en);
		}
	}
};



int main()
{
	setlocale(LC_ALL, "rus");
	slovnuk sl;
	//добавляю немного слов
	list<string> def;
	def.push_back("утро");
	sl.add("morning", def);
	def.clear();
	def.push_back("день");
	sl.add("day", def);
	def.clear();
	def.push_back("луна");
	sl.add("moon", def);
	def.clear();
	def.push_back("солнце");
	sl.add("sun", def);
	def.clear();

	//вывод
	sl.print();

	//добавление слова
	sl.addMine();
	sl.print();

	//добавление значения
	string w = "";
	string e = "";
	cout << "Choose eng word _"; cin >> w;
	cout << "Add ru value _"; cin >> e;
	sl.addValue(w,e);
	sl.print();
	
	//удаление слова
	string ee = "";
	cout << "Choose eng word _"; cin >> ee;
	sl.del(ee);
	sl.print();


	//изменение англ слова
	string w1 = "";
	string w2 = "";
	cout << "Choose eng word _"; cin >> w1;
	cout << "Add updated value _"; cin >> w2;
	sl.editEn(w1, w2);
	sl.print();


	//изменение русского слова
	string q1 = "";
	string q2 = "";
	string q3 = "";
	cout << "Choose eng word _"; cin >> q1;
	cout << "Choose ru value _"; cin >> q2;
	cout << "Add updated value _"; cin >> q3;
	sl.editRu(q1, q2, q3);
	sl.print();

	
	system("pause");
	return 0;
}