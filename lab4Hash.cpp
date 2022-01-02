#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>

// Thầy Bùi Huy Thông
using namespace std;


struct Company
{
	string name;
	string profit_tax;
	string address;
};


vector<Company> readCompanyList(string file_name)
{
	vector<Company> a;
	Company b;
	ifstream fi(file_name, ios::in);
	string c;
	getline(fi, c);
	while (!fi.eof())
	{
		getline(fi, b.name, '|');
		getline(fi, b.profit_tax, '|');
		getline(fi, b.address);
		a.push_back(b);
	}
	return a;
}


long long hashString(string company_name)
{
	string a = company_name;
	const int p = 31;
	const int m = pow(10, 9) + 9;
	long long hashname = 0;
	int x = a.size();
	long long p_pow = 1;
	if (x > 20)
	{
		a = company_name.substr(x - 20, 20);
		x = a.size();
	}
	for (int i = 0; i < x; i++)
	{
		hashname = (hashname + (long long)a[i] * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hashname;
}


Company* createHashTable(vector<Company> list_company)
{
	Company* a = new Company[2000];
	int x = 0;
	for (int i = 0; i < 2000; i++)
	{
		a[i].name = "";
		a[i].address = "";
		a[i].profit_tax = "";
	}
	int hashkey = 0;
	for (int i = 0; i < list_company.size(); i++)
	{
		x = 1;
		hashkey = hashString(list_company[i].name) % 2000;
		while (a[hashkey].name != "")
		{
			hashkey = (hashkey + x) % 2000;
			x++;
		}
		a[hashkey] = list_company[i];
	}
	return a;
}

void insert(Company* hash_table, Company company)
{
	int i = 0;
	int x = 1;
	int hashkey = hashString(company.name) % 2000;
	while (!hash_table[hashkey].name.empty()) {
		hashkey = (hashkey + x) % 2000;
		x++;
	}
	hash_table[hashkey] = company;
}

Company* search(Company* hash_table, string company_name)
{
	int i = 0;
	int hashkey = hashString(company_name) % 2000;
	while (hash_table[hashkey].name != company_name && i < 2000)
	{
		i++;
		++hashkey;
		hashkey = hashkey % 2000;
	}
	if (hash_table[hashkey].name == company_name)
	{
		Company* a = new Company;
		a[0] = hash_table[hashkey];
		return a;
	}
	return NULL;
}


void xuat(Company* a, ostream& os, int n)
{
	for (int i = 0; i < n; i++) {
		if (a[i].name != "")
		{
			os << a[i].name << " " << a[i].profit_tax << " " << a[i].address << endl;
		}
	}
}

void xuat1cty(Company a, ostream& os)
{
	if (a.name != "")
	{
		os << a.name << " " << a.profit_tax << " " << a.address << endl;
	}
}

int main()
{
	int n = 2000;
	string x;
	Company b;
	vector<Company> list_company = readCompanyList("MST.txt");
	Company* a = createHashTable(list_company);
	cout << "finished reading" << endl;
	cout << "Enter the name of company you want to find: " << endl;
	getline(cin, x);
	Company* s = search(a, x);
	if (v == NULL)
	{
		cout << "Can't find the company" << endl;
	}
	else
	{
		cout << "Company exist" << endl;
		cout << s->name << " " << s->profit_tax << " " << s->address << endl;
	}
	cout << "Enter the information of the company to add" << endl;
	cout << "Enter the name: " << endl;
	getline(cin, b.name);
	cout << "Enter the MST: " << endl;
	getline(cin, b.profit_tax);
	cout << "Enter the address: " << endl;
	getline(cin, b.address);
	cout << "Information of company: " << endl;
	xuat1cty(b, cout);
	cout << "Add the company in the list" << endl;
	insert(a, b);
	cout << "Sucessful" << endl;
	return 0;
}

