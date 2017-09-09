#include "Parser.h"
#include<list>
#include"../DTO/DTO.h"
#include<regex>


string Parser::ParseCppHtmlToHtml(string fileName)
{

	string  htmlString = "";
	string cppHtmlString = DTO::GetFileContent(fileName);
	regex regularExp("<%");
	string::size_type pos1, pos2;
	string cppCode;

	while (regex_search(cppHtmlString.begin(), cppHtmlString.end(), regularExp))
	{
		cppCode = "";
		pos1 = cppHtmlString.find("<%");
		pos2 = cppHtmlString.find("%>");


		if (pos2 < pos1 || !IsValid("") || pos2 == -1)
		{
			throw "invalid syntax ";
		}

		htmlString.append(cppHtmlString.substr(0, pos1));
		cppCode = cppHtmlString.substr(pos1, pos2 - pos1 + 2);//
		htmlString.append(CompileCppCode(cppCode));
		int tempPos1 = pos1;

		pos1 = cppHtmlString.find("<%", pos2 + 1);
		if (pos1 == -1)
		{ 
			htmlString.append(cppHtmlString.substr(pos2 + 2, cppHtmlString.length()-2));
		}
		else
		{
			htmlString.append(cppHtmlString.substr(pos2 + 1, pos1 - pos2));
		}
		cppHtmlString.erase(tempPos1, pos2 - tempPos1 + 2);//
	}



	if (empty(htmlString))
	{
		htmlString = cppHtmlString;
	}
	else
	{

	}
	return htmlString;
}

bool Parser::IsValid(string cppCodeAtHtmlPage)
{
	// check if cpp code is valid 
	bool isValid;
	isValid = true;

	return isValid;
}

string Parser::CompileCppCode(string cppCode)
{
	string result = "";
	cppCode.erase(0, 2);
	cppCode.erase(cppCode.length() - 2, 2);
	if (HelperFunctions::isLoopFor(cppCode))
	{
		result = HelperFunctions::executeLoopFor(cppCode);
	}
	else if (HelperFunctions::isLoopForeach(cppCode))
	{
		result = HelperFunctions::executeLoopForeach(cppCode);
	}
	else
	{
		result = cppCode;
	}
	return result;
}

