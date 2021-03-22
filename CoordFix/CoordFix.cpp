// CoordFix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
	/*
		Для эффективности можно было использовать нормальные типы и массивы, типа line_coordinate[4][2], 
		за счёт чего код программы мог сократиться путём использования циклов для одних и тех же итераций,
		но на данный момент используется обозначение каждой точки отдельно, т.к. может потребоваться в дальнейшем их преобразование.
	*/
	ifstream fromFile;
	fromFile.open("Coordinates.txt", ios::in);
	ofstream fromNewFile;
	fromNewFile.open("NewCoord.txt", ios::app);

	//считать в переменную fromFile >> переменная
	//соответственно в файл fromFile << значение

	/*  Хочу порядок 
		LeftDown -> LeftUp -> RightUp -> RightDown
	*/

	int a[2], b[2], c[2], d[2],
		center[2],
		ld[2],/*->*/ lu[2],/*->*/ ru[2],/*->*/ rd[2];

	for (int u = 0; u < 44; u++) {
		fromFile >> a[0];	fromFile >> a[1];
		fromFile >> b[0];	fromFile >> b[1];
		fromFile >> c[0];	fromFile >> c[1];
		fromFile >> d[0];	fromFile >> d[1];

		for (int i = 0; i < 2; i++) {
			center[i] = (a[i] + b[i] + c[i] + d[i]) / 4;
		}
		cout << "Center Coordinate x = " << center[0] << ", y = " << center[1] << "." << endl;

		if ((a[0] < center[0]) && (a[1] > center[1])) {
			ld[0] = a[0];		ld[1] = a[1];
		}
		else if ((a[0] < center[0]) && (a[1] < center[1])) {
			lu[0] = a[0];		lu[1] = a[1];
		}
		else if ((a[0] > center[0]) && (a[1] < center[1])) {
			ru[0] = a[0];		ru[1] = a[1];
		}
		else if ((a[0] > center[0]) && (a[1] > center[1])) {
			rd[0] = a[0];		rd[1] = a[1];
		} // Как же это ужасно выглядит((( Главное не забудь переделать!

		if ((b[0] < center[0]) && (b[1] > center[1])) {
			ld[0] = b[0];		ld[1] = b[1];
		}
		else if ((b[0] < center[0]) && (b[1] < center[1])) {
			lu[0] = b[0];		lu[1] = b[1];
		}
		else if ((b[0] > center[0]) && (b[1] < center[1])) {
			ru[0] = b[0];		ru[1] = b[1];
		}
		else if ((b[0] > center[0]) && (b[1] > center[1])) {
			rd[0] = b[0];		rd[1] = b[1];
		}

		if ((c[0] < center[0]) && (c[1] > center[1])) {
			ld[0] = c[0];		ld[1] = c[1];
		}
		else if ((c[0] < center[0]) && (c[1] < center[1])) {
			lu[0] = c[0];		lu[1] = c[1];
		}
		else if ((c[0] > center[0]) && (c[1] < center[1])) {
			ru[0] = c[0];		ru[1] = c[1];
		}
		else if ((c[0] > center[0]) && (c[1] > center[1])) {
			rd[0] = c[0];		rd[1] = c[1];
		}

		if ((d[0] < center[0]) && (d[1] > center[1])) {
			ld[0] = d[0];		ld[1] = d[1];
		}
		else if ((d[0] < center[0]) && (d[1] < center[1])) {
			lu[0] = d[0];		lu[1] = d[1];
		}
		else if ((d[0] > center[0]) && (d[1] < center[1])) {
			ru[0] = d[0];		ru[1] = d[1];
		}
		else if ((d[0] > center[0]) && (d[1] > center[1])) {
			rd[0] = d[0];		rd[1] = d[1];
		}

		cout << "String: " << u + 1 << endl;
		cout << "Left Down Coordinate x = " << ld[0] << ", y = " << ld[1] << "." << endl;
		cout << "Left Up Coordinate x = " << lu[0] << ", y = " << lu[1] << "." << endl;
		cout << "Right Up Coordinate x = " << ru[0] << ", y = " << ru[1] << "." << endl;
		cout << "Right Down Coordinate x = " << rd[0] << ", y = " << rd[1] << "." << endl;
		cout << endl;

		fromNewFile << ld[0]; fromNewFile << " "; fromNewFile << ld[1]; fromNewFile << " ";
		fromNewFile << lu[0]; fromNewFile << " "; fromNewFile << lu[1]; fromNewFile << " ";
		fromNewFile << ru[0]; fromNewFile << " "; fromNewFile << ru[1]; fromNewFile << " ";
		fromNewFile << rd[0]; fromNewFile << " "; fromNewFile << rd[1]; fromNewFile << " ";
		fromNewFile << endl;
	}

	fromFile.close();
	fromNewFile.close();

	cout << endl;		cout << endl;		cout << endl;		cout << endl;		cout << endl;
	
	ifstream fromFFile;
	fromFFile.open("NewCoord.txt", ios::in);

	int cent[44][2];
	for (int z = 0; z < 44; z++) {
		fromFFile >> a[0];	fromFFile >> a[1];
		fromFFile >> b[0];	fromFFile >> b[1];
		fromFFile >> c[0];	fromFFile >> c[1];
		fromFFile >> d[0];	fromFFile >> d[1];

		cent[z][0] = (a[0] + b[0] + c[0] + d[0]) / 4;
		cent[z][1] = (a[1] + b[1] + c[1] + d[1]) / 4;

		cout << "Center Coordinate x = " << cent[z][0] << ", y = " << cent[z][1] << "." << endl;
	}

	cout << endl;		cout << endl;		cout << endl;		cout << endl;		cout << endl;
	int y1, y2, y3, y4;

	int temp[2];
	for (int n = 0; n < 43; n++) {
		for (int l = 0; l < 43; l++) {
			if (cent[l][1] > cent[l + 1][1]) {
				temp[0] = cent[l][0]; temp[1] = cent[l][1];
				cent[l][0] = cent[l + 1][0]; cent[l][1] = cent[l + 1][1];
				cent[l + 1][0] = temp[0]; cent[l + 1][1] = temp[1];
			}
		}
	}
	for (int n = 0; n < 44; n++) {
		cout << "Center Coordinate x = " << cent[n][0] << ", y = " << cent[n][1] << "." << endl;
	}

	int ttemp[2];
	int size = 44;
	int bred, bred_curt;
	for (int m = 0; m < 44; m = m + 4) {
		bred = m;
		bred_curt = bred + 3;
		cout << "TUTA: " << m << endl;
		for (int n = bred; n < bred_curt; n++) {
			for (int l = bred; l < bred_curt; l++) {
				if (cent[l][0] > cent[l + 1][0]) {
					ttemp[0] = cent[l][0]; ttemp[1] = cent[l][1];
					cent[l][0] = cent[l + 1][0]; cent[l][1] = cent[l + 1][1];
					cent[l + 1][0] = ttemp[0]; cent[l + 1][1] = ttemp[1];
				}
			}
		}
	}
	for (int n = 0; n < 44; n++) {
		cout << "Center Coordinate x = " << cent[n][0] << ", y = " << cent[n][1] << "." << endl;
	}
	ofstream dotecord;
	dotecord.open("DoteCord.txt", ios::app);
	for (int n = 0; n < 44; n++) {
		dotecord << cent[n][0] << " " << cent[n][1] << endl;
	}
	dotecord.close();

	cout << endl;		cout << endl;		cout << endl;		cout << endl;		cout << endl;

	fromFFile.close();

	ifstream fromFFFile;
	fromFFFile.open("NewCoord.txt", ios::in);
	ofstream fromNewFFFile;
	fromNewFFFile.open("SortCoord.txt", ios::app);

	int cent2[44][2];
	int dotes[44][8];

	for (int z = 0; z < 44; z++) {
		fromFFFile >> dotes[z][0];	fromFFFile >> dotes[z][1];
		fromFFFile >> dotes[z][2];	fromFFFile >> dotes[z][3];
		fromFFFile >> dotes[z][4];	fromFFFile >> dotes[z][5];
		fromFFFile >> dotes[z][6];	fromFFFile >> dotes[z][7];

		cent2[z][0] = (dotes[z][0] + dotes[z][2] + dotes[z][4] + dotes[z][6]) / 4;
		cent2[z][1] = (dotes[z][1] + dotes[z][3] + dotes[z][5] + dotes[z][7]) / 4;

		//cout << "Center Coordinate x = " << cent2[z][0] << ", y = " << cent2[z][1] << "." << endl;
	}

	for (int g = 0; g < 44; g++) {
		for (int y = 0; y < 44; y++) {
			if ((cent[g][1] == cent2[y][1]) && (cent[g][0] == cent2[y][0])) {
				fromNewFFFile << dotes[y][0]; fromNewFFFile << " "; fromNewFFFile << dotes[y][1]; fromNewFFFile << " ";
				fromNewFFFile << dotes[y][2]; fromNewFFFile << " "; fromNewFFFile << dotes[y][3]; fromNewFFFile << " ";
				fromNewFFFile << dotes[y][4]; fromNewFFFile << " "; fromNewFFFile << dotes[y][5]; fromNewFFFile << " ";
				fromNewFFFile << dotes[y][6]; fromNewFFFile << " "; fromNewFFFile << dotes[y][7]; fromNewFFFile << " ";
				fromNewFFFile << endl;
				y = 44;
			}
		}
	}

	fromFFFile.close();
	fromNewFFFile.close();

	system("pause");
	return 0;
}

//надеюсь я не забуду переписать, чтобы все было опрятнее и быстрее....