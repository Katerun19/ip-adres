#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main()/*В сети интернет каждому компьютеру присваивается четырехбайтовый код, 
			который принято записывать в виде четырех чисел, каждое из которых может принимать значения от 0 до 255,
			разделенных точками. Вот примеры правильных IP-адресов: 
			127.0.0.0
			192.168.0.1
			255.0.255.255
			Напишите программу, которая определяет, является ли заданная строка правильным IP - адресом.*/
{
	setlocale(LC_ALL, "ru");
	string address;
	int a, b, c, k = 0, m = 0, Celoe1, Celoe2, Celoe3, Celoe4, A = 0;
	char e[4], f[4], h[4], g[4];
	string E = "", F = "", H = "", G = "";
	getline(cin, address);
	int Size = address.size();
	int B = Size;
	for (int i = 0; i < Size; i++)
	{
		if (address[i] == '.') { k++; }
		if ((address[i] >= '0' && address[i] <= '9') || address[i] == '.') { B--; }
	}
	if (B == 0)
	{
		if (Size >= 7 && Size <= 15)
		{
			if (k == 3)
			{
				a = address.find(".");
				b = address.find(".", a + 1);
				c = address.find(".", b + 1);
				int Z1 = b - a;
				int Z2 = c - b;
				if (Z1 != 1 && Z2 != 1)
				{
					for (int j = 0; j < a; j++, m++)
					{
						e[j] = address[m];
						E = E + e[j];

					}
					Celoe1 = stoi(E);
					if (Celoe1 >= 0 && Celoe1 <= 255) { A++; }
					m++;
					for (int j = 0; j < b - a - 1; j++, m++)
					{
						f[j] = address[m];
						F = F + f[j];

					}
					Celoe2 = stoi(F);
					if (Celoe2 >= 0 && Celoe2 <= 255) { A++; }
					m++;
					for (int j = 0; j < c - b - 1; j++, m++)
					{
						g[j] = address[m];
						G = G + g[j];
					}
					Celoe3 = stoi(G);
					if (Celoe3 >= 0 && Celoe3 <= 255) { A++; }
					m++;
					for (int j = 0; j < Size - c - 1; j++, m++)
					{
						h[j] = address[m];
						H = H + h[j];

					}
					Celoe4 = stoi(H);
					if (Celoe4 >= 0 && Celoe4 <= 255) { A++; }
					if (A == 4) { cout << "YES"; }
					else { cout << "NO"; }
				}
				else { cout << "NO"; }
			}
			else { cout << "NO"; }
		}
		else { cout << "NO"; }
	}
	else { cout << "NO"; }
	
	
    return 0;
}

