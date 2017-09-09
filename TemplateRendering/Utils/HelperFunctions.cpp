#include "HelperFunctions.h"

bool HelperFunctions::isLoopFor(string code)
{
	bool isExist;
	isExist = false;
	regex loopForExpr("\\s*for\\s*\\(\\s*int \\s*[a-z]{1,}\\s*=\\s*\\d{1,}\\s*;\\s*[a-z]{1,}\\s*<\\s*\\d{1,}\\s*;\\s*[a-z]{1,}\\+\\+\\s*\\)\\s*\\{\\s*(.|\\n)*?\\s*\\}\\s*");
	if (regex_search(code.begin(), code.end(), loopForExpr))
	{
		isExist = true;
	}
	return isExist;
}

bool HelperFunctions::isLoopForeach(string code)
{
	bool isExist;
	isExist = false;
	regex LoopForeachExpr("\\s*foreach\\s*\\(\\s*var \\s*[a-z]{1,} \\s*in \\s*[a-z]{1,}\\s*\\)\\s*\\{\\s*(.|\\n)*?\\s*\\}\\s*");
	if (regex_search(code.begin(), code.end(), LoopForeachExpr))
	{
		isExist = true;
	}
	return isExist;
}

string findValue(int previousPos, string code)
{
	string result;
	code.erase(0, previousPos + 1);
	int index = 0;
	while (code[index] == ' ')
	{
		code.erase(0, 1);
	}
	index = 0;
	while (code[index] != ';' && code[index] != ' ')
	{
		result += code[index];
		index++;
	}
	return result;
}



string HelperFunctions::executeLoopFor(string code)
{
	string result = "";

	string htmlContent;
	string::size_type pos1, pos2;
	pos1 = code.find("{");
	pos2 = code.find("}");
	htmlContent = code.substr(pos1 + 1, pos2 - pos1 - 1);

	int firstValue, secondValue;
	firstValue = atoi(findValue(code.find("="), code).c_str());
	secondValue = atoi(findValue(code.find("<"), code).c_str());
	for (firstValue; firstValue < secondValue; firstValue++)
	{
		result.append(htmlContent);
	}
	return result;
}




string HelperFunctions::executeLoopForeach(string code)
{
	return string();
}



