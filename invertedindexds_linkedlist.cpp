#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
typedef struct wordInfor //save the word information
{
string file; //file name
int line; //which line
int index; //index in the line
wordInfor *next = NULL; //point to next node
}wordInfor;
class InvertedIndex
{
public:
void addFile(string fileName);
void query(string word);
const vector<string>
&getFileList(); ~InvertedIndex();
private:
map<string, wordInfor*> wordDict;
vector<string> fileList;
};
const vector<string> &InvertedIndex::getFileList()
{
return fileList;
}
void InvertedIndex::addFile(string fileName) //read from file, complete the wordDict
{
string wd, line;
ifstream in;
in.open("xx.txt");
if (in)
{
int recordConter = 0;
while (getline(in, line)) //get every line
{
istringstream record(line);
int indexConter = 0;
while (record >> wd) //get every word
{
if (wordDict.find(wd) == wordDict.end())
{
wordDict[wd] == NULL;
}
wordInfor *n = new wordInfor();
n->next = wordDict[wd];
wordDict[wd] = n;
n->file = fileName; n-
>line = recordConter; n-
>index = indexConter;
indexConter++;
}
recordConter++;
}
fileList.push_back(fileName);
in.close();
}
else
cout << "no such file" << endl;
}
void InvertedIndex::query(string word)
{
wordInfor *cur = 0;
if ( wordDict.find(word) == wordDict.end())
{
cout << "\"" << word << "\":" << endl;
cout << "no such word";
return;
}
else
cur = wordDict[word];
cout << "\"" << word << "\" occurred in:" << endl;
while (cur)
{
cout << "file: " << cur->file << " line: " << cur->line << " index: " << cur->index << endl;
cur = cur->next;
}
}
InvertedIndex::~InvertedIndex()
{
for (auto it = wordDict.begin(); it != wordDict.end(); ++it)
{
wordInfor *q, *p = it->second;
while (p)
{
q = p->next;
delete p;
p = q;
}
}
}
int main()
{
InvertedIndex i;
int choice;
while (1)
{
cout << "enter 0 to add file" << endl;
cout << "enter 1 to query word" <<
endl; cout << "enter 2 to quit" << endl;
const vector<string> &fileList = i.getFileList();
if (!fileList.empty())
{
cout << "added files: ";
for (auto f : fileList)
cout << f << "
"; cout << endl;
}
cin >> choice;
switch (choice)
{
case 0:
{
string file;
cout << "enter the file name you want to add" <<
endl; cin >> file;
i.addFile(file);
break;
}
case 1:
{
string word;
cout << "enter the word you want to query" << endl;
cin >> word;
i.query(word);
break;
}
case 2:
exit(0);
default:
{
cout << "please enter 0 or 1 or 2" << endl;
}
}
system("pause");
system("CLS");
}
}