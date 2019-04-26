#include<stdio.h>
#include <iostream>
#include "ctime"
#include <conio.h>
#include "windows.h"
using namespace std;
int Array_qx[4][4] = { 0 };
bool IsFull = false;
bool IsHave0 = true;
void IsHave0Judgment();
int ProduceNum2or4();
void Up_();
void Down_();
void InitialArray();
void Right_();
void Left_();
void show();
void Up_Sum();
void Down_Sum();
void Left_Sum();
void Right_Sum();
void AddNewNum();
void Judgement();
void flash();

int main() {
	int ControlDirection;
	InitialArray();
	while (true)
	{
		ControlDirection = _getch();
		if (ControlDirection == 75) {
			if (IsFull == true && IsHave0 == false)
			{
				cout << "You Lose!" << endl;
				break;
			}
			Left_();
			Left_Sum();
			if (IsHave0 == true)
				AddNewNum();
			Judgement();
			IsHave0Judgment();
			flash();
		}
		if (ControlDirection == 72) {
			if (IsFull == true && IsHave0 == false)
			{
				cout << "You Lose!" << endl;
				break;
			}
			Up_();
			Up_Sum();
			if (IsHave0 == true)
				AddNewNum();
			Judgement();
			IsHave0Judgment();
			flash();
		}
		if (ControlDirection == 77) {

			if (IsFull == true && IsHave0 == false)
			{
				cout << "You Lose!" << endl;
				break;
			}
			Right_();
			Right_Sum();
			if (IsHave0 == true)
				AddNewNum();
			Judgement();
			IsHave0Judgment();
			flash();
		}
		if (ControlDirection == 80) {

			if (IsFull == true && IsHave0 == false)
			{
				cout << "You Lose!" << endl;
				break;
			}
			Down_();
			Down_Sum();
			if (IsHave0 == true)
				AddNewNum();
			Judgement();
			IsHave0Judgment();
			flash();

		}
		if (ControlDirection == 27)
		{
			cout << "Exit£¡" << endl;
			break;
		}
	}

	Sleep(500);
	return 0;
}
int ProduceNum2or4() {
	int i = 2, j = 4;
	int k = (int)rand() % 3;
	if (k == 0) {
		return j;
	}
	else {
		return i;
	}
}

void InitialArray() {
	srand((int)time(0));
	int i = (int)rand() % 4;
	int j = (int)rand() % 4;
	Array_qx[i][j] = ProduceNum2or4();
	i = (int)rand() % 4;
	j = (int)rand() % 4;
	Array_qx[i][j] = ProduceNum2or4();
	show();
}

void show() {

	cout << endl << "*************New 2048************" << endl << endl << "             By q.x      " << endl << endl <<
		endl << endl;
	cout << "¡ü ¡ý ¡û ¡ú Esc(ÍË³ö)" << endl;
	for (int i = 0; i < 4; ++i)
	{
		cout << "---------------------------------" << endl;
		for (int j = 0; j < 4; ++j)
		{
			if (Array_qx[i][j] == 0)
			{
				cout << "|   \t";
			}
			else
			{
				cout << "|   " << Array_qx[i][j] << "\t";
			}
		}
		cout << "|" << endl;
	}
	cout << "---------------------------------" << endl;
}

void Up_() {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Array_qx[i][j] == 0)
			{
				Array_qx[i][j] = Array_qx[i + 1][j];
				Array_qx[i + 1][j] = 0;
			}
		}
	}
}

void Down_() {

	for (int i = 3; i > 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Array_qx[i][j] == 0)
			{
				Array_qx[i][j] = Array_qx[i - 1][j];
				Array_qx[i - 1][j] = 0;
			}
		}
	}
}

void Right_() {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (Array_qx[i][j] == 0)
			{
				Array_qx[i][j] = Array_qx[i][j - 1];
				Array_qx[i][j - 1] = 0;
			}
		}
	}

}

void Left_() {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Array_qx[i][j] == 0)
			{
				Array_qx[i][j] = Array_qx[i][j + 1];
				Array_qx[i][j + 1] = 0;
			}
		}
	}
}

void Up_Sum() {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Array_qx[i][j] == Array_qx[i + 1][j] && Array_qx[i][j] != 0)
			{
				Array_qx[i][j] = Array_qx[i + 1][j] * 2;
				Array_qx[i + 1][j] = 0;
				
			}
		}
	}
	int k = 0;
	while (k++<3)
	{
		Up_();
	}
}

void Down_Sum() {

	for (int i = 3; i > 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Array_qx[i][j] == Array_qx[i - 1][j] && Array_qx[i][j] != 0)
			{
				Array_qx[i][j] = Array_qx[i - 1][j] * 2;
				Array_qx[i - 1][j] = 0;
			}
		}
	}
	int k = 0;
	while (k++ < 3)
	{
		Down_();
	}

}

void Left_Sum() {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Array_qx[i][j] == Array_qx[i][j + 1] && Array_qx[i][j] != 0)
			{
				Array_qx[i][j] = Array_qx[i][j + 1] * 2;
				Array_qx[i][j + 1] = 0;

			}
		}
	}
	int k = 0;
	while (k++ < 3)
	{
		Left_();
	}

}

void Right_Sum() {

	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (Array_qx[i][j] == Array_qx[i][j - 1] && Array_qx[i][j] != 0)
			{
				Array_qx[i][j] = Array_qx[i][j - 1] * 2;
				Array_qx[i][j - 1] = 0;

			}
		}
	}
	int k = 0;
	while (k++ < 3)
	{
		Right_();
	}
}

void AddNewNum() {
	int i, j;
	i = (int)rand() % 4;
	j = (int)rand() % 4;
	while (Array_qx[i][j] != 0)
	{
		i = (int)rand() % 4;
		j = (int)rand() % 4;
	}
	Array_qx[i][j] = ProduceNum2or4();
}

void Judgement() {
	IsFull = true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Array_qx[i][j] == 0 || Array_qx[i][j] == Array_qx[i + 1][j] || Array_qx[i][j] == Array_qx[i][j + 1])
			{
				IsFull = false;
			}
		}
	}
}

void IsHave0Judgment() {
	IsHave0 = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Array_qx[i][j] == 0)
			{
				IsHave0 = true;
			}
		}
	}
}

void flash() {
	system("cls");
	show();
}