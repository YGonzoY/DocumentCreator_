#include "DocumentManager.h"
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
namespace fs = filesystem;


DocumentManager::DocumentManager(string folder_path) : folder(folder_path)
{
    checkFiles();
    showFilesToUser();
    getFile();
}


int DocumentManager::checkFiles()
{
    int counter = 0;
    for (auto& p : fs::recursive_directory_iterator(this->folder))
    {
        if (p.path().extension().string() == ".txt")                      
        {                                                                
            documents.push_back(Document(p.path().string()));           
        }
        counter++;
    }
    return counter;
}


void DocumentManager::showFilesToUser()
{
    for (vector<Document>::iterator iter = documents.begin(); iter != documents.end(); ++iter)
    {
        cout << iter->getName() << "\n";
    }
}


void DocumentManager::getFile()
{
    int choice;
    cin >> choice;
    cout << choice << " ";
    cout << documents[choice].getName() << "\n";
    documents[choice].getTagsValue();
    string confim;
    cout << "sure? enter y/n" << "\n";
    cin >> confim;
    if (confim == "y")
    {
        documents[choice].writeInFile();
    }
    else
    {
        getFile();
    }
}