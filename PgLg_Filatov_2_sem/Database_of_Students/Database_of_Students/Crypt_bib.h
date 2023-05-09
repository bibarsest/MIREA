#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <time.h>
#include <windows.h>
#include <string>

void Crypt()
{
	srand(time(NULL));
	string pass;
	for (int i = 0; i < 128; ++i) {
		switch (rand() % 3) {
		case 0:
			pass += rand() % 10 + '0';
			break;
		case 1:
			pass += rand() % 26 + 'A';
			break;
		case 2:
			pass += rand() % 26 + 'a';
		}
	}
	string command = "OpenSSL\\bin\\openssl.exe enc -aes-256-cbc -salt -in DB.txt -out DB.txt.enc -pass pass:";
	command += pass;
	command += " -iter 1000";
	system(command.c_str());
	if (remove("DB.txt") != 0) 
	{
		cout << "[ОШИБКА 0021091] - Не удалось удалить файл с базой." << endl;
	}
	ofstream filein;
	filein.open("key.bin", ios::binary);
	filein << pass;
	filein.close();
	command = "OpenSSL\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.bin -out key.bin.enc";
	system(command.c_str());
	if (remove("key.bin") != 0) 
	{
		cout << "[ОШИБКА 0021092] - Не удалось удалить файл с ключом." << endl;
	}
}
void Decrypt()
{
	string command = "OpenSSL\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.bin.enc -out key.bin";
	system(command.c_str());
	if (remove("key.bin.enc") != 0) 
	{
		cout << "[ОШИБКА 0021093] - Не удалось удалить файл с зашифрованным ключом." << endl;
	}
	string pass;
	ifstream fileout;
	fileout.open("key.bin", ios::binary);
	fileout >> pass;
	fileout.close();
	if (remove("key.bin") != 0) 
	{
		cout << "[ОШИБКА 0021094] - Не удалось удалить файл с ключом." << endl;
	}
	command = "OpenSSL\\bin\\openssl.exe enc -aes-256-cbc -d -in DB.txt.enc -out DB.txt -pass pass:";
	command += pass;
	command += " -iter 1000";
	system(command.c_str());
	if (remove("DB.txt.enc") != 0) 
	{
		cout << "[ОШИБКА 0021095] - Не удалось удалить файл с зашифрованной базой." << endl;
	}
}
