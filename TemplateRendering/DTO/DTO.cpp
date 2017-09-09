#include "DTO.h"

string DTO::GetFileContent(string filename)
{
	ifstream ifs(filename);
	if (!ifs.is_open())
	{
		cout << "can not open file " << filename << "\n";
	}
	string result((istreambuf_iterator<char>(ifs)),istreambuf_iterator<char>());
	return result;	
}

void DTO::SaveStringToFile(string fileContent)
{
	ofstream ofs("RenderedView/Index.html", ios_base::out | ios_base::trunc);
	if (!ofs.is_open())
	{
		cout << "can not open file";
	}
	ofs << fileContent;
	ofs.close();
}
