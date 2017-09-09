#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include <streambuf>

class DTO
{
public:
	static string GetFileContent(string filename);
	static void SaveStringToFile(string fileContent);
};

