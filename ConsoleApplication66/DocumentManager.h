#pragma once
#include <string>
#include <vector>
#include "Document.h"

using namespace std;


class DocumentManager
{
private:
	string folder;
	vector<Document> documents;
public:
	DocumentManager(string folder_path);

	int checkFiles();


	void showFilesToUser();

	void getFile();
};

