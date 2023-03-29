#include "Document.h"
#include <filesystem>
#include <fstream>
#include <regex>
#include <iostream>

using namespace std;


Document::Document(string _file_path) : file(_file_path)
{
    getTemplateName();
    getTags();
}


void Document::getTemplateName()
{
    fstream file(this->file);
    string buf;
    regex label("&name&");
    getline(file, buf);
    cout << this->file << " ";
    cout << "   " << buf << "\n";
    if (regex_search(buf, label))
    {
        //buf.replace(buf.begin(), buf.end(), "&name&");
        buf = regex_replace(buf, label, "");
        cout << "   " << buf << "\n";
        this->templateName = buf;
    }
    else
    {
        this->templateName = "can not get name for this template";
    }
    file.close();
}


void Document::getTags()
{
    fstream file(this->file);
    string buf;
    bool isTag = true;
    string tagName;
    string description;
    while (file >> buf)
    {
        if (buf == "&tags&")
        {
            while (buf != "&end&")
            {
                file >> buf;
                if (isTag)
                {
                    tagName = buf;
                }
                else
                {
                    description = buf;
                    tags.push_back(Tag(tagName, description));
                }
                isTag = !isTag;
            }
            return;
        }
    }
}


void Document::getTagsValue()
{
    cout << "tagname" << tags[0].name;
    for (vector<Tag>::iterator iter = tags.begin(); iter != tags.end(); ++iter)
    {
        cout << "Enter" << iter->description << "\n";
        cin >> iter->value;
    }
}


void Document::writeInFile()
{
    fstream file(this->file);
    fstream new_file(templateName + "_31.12.2022.txt");
    if (!file.is_open())
    {
        cout << "File is not open\n\n";
    }
    else
    {
        cout << "File is open\n\n";
    }
    for (vector<Tag>::iterator iter = tags.begin(); iter != tags.end(); ++iter)
    {

        string buf;
        regex r = regex(iter->name);
        while (getline(file, buf))
        {
            new_file << regex_replace(buf, r, iter->value);
            new_file << "\n";
        }
    }
    new_file.close();
    file.close();
}




string Document::getName()
{
    return this->templateName;
}