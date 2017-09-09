using namespace std;
#include<string>
#include<regex>

class HelperFunctions
{
public:
	static bool isLoopFor(string code);
	static bool isLoopForeach(string code);
	static string executeLoopFor(string code);
	static string executeLoopForeach(string code);
};

