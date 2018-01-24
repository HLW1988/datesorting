#include<iostream>
#include<string>
#include<io.h>
#include<vector>
using namespace std;

#ifndef getfilename
#define getfilename

#endif // SWAPBYTE

void getAllFiles(string path, vector<string>& files);
void getJustCurrentDir(string path, vector<string>& files); 
void getJustCurrentFile(string path, vector<string>& files); 
void getFilesAll(string path, vector<string>& files); 
void GetAllFormatFiles( string path, vector<string>& files,string format);    
