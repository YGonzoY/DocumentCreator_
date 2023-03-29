#pragma once
#include <string>
#include <vector>
#include "Tag.h"

using namespace std;



class Document
{
private:
	string file;
	string text;
	string templateName;
	vector<Tag> tags;
public:
	Document(string _file_path);

	void getTemplateName();
	void getTags();


	void getTagsValue();

	void writeInFile();


	string getName();
};


