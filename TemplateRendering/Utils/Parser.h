using namespace std;
#include<string>
#include"../Utils/HelperFunctions.h"


class Parser
{
public:
	static string ParseCppHtmlToHtml(string fileName);
	static bool IsValid(string cppCodeAtHtmlPage);
	static string CompileCppCode(string cppCode);
};