#include"DTO\DTO.h"
#include"Utils\Parser.h"
#include<iostream>

int main()
{
	DTO::SaveStringToFile(Parser::ParseCppHtmlToHtml("View/EmptyHTMLPage.htm"));	
	system("Pause");
}