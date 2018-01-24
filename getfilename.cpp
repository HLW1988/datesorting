#include<iostream>
#include<string>
#include<io.h>
#include<vector>
#include "getfilename.h"
using namespace std;

// struct _finddata_t 
//{ 
//     unsigned attrib; 
  //   time_t time_create; 
 //    time_t time_access; 
 //    time_t time_write; 
 //    _fsize_t size; 
 //    char name[_MAX_FNAME]; 
 //    };

// 读取某给定路径下所有文件夹与文件名称，并带完整路径。
void getAllFiles(string path, vector<string>& files)
{
    //文件句柄  
    long   hFile = 0;
    //文件信息  
    struct _finddata_t fileinfo;  //很少用的文件信息读取结构
    string p;  //string类很有意思的一个赋值函数:assign()，有很多重载版本
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib &  _A_SUBDIR))  //判断是否为文件夹
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                {
                files.push_back(p.assign(path).append("/").append(fileinfo.name));//保存文件夹名字
                    getAllFiles(p.assign(path).append("/").append(fileinfo.name), files);//递归当前文件夹
                }
            }
            else    //文件处理
            {
                files.push_back(p.assign(path).append("/").append(fileinfo.name));//文件名
            }
        } while (_findnext(hFile, &fileinfo) == 0);  //寻找下一个，成功返回0，否则-1
        _findclose(hFile);
    }
}
//测试
//只读取某给定路径下的当前文件夹名(以下类似，只给出函数，调用案例同上)

void getJustCurrentDir(string path, vector<string>& files) 
{
    //文件句柄
      long hFile = 0;
      //文件信息 
      struct _finddata_t fileinfo;
      string p;
      if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) != -1) {
          do {  
              if ((fileinfo.attrib & _A_SUBDIR)) {  
                 if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
                     files.push_back(fileinfo.name);
                     //files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                 }
             }
         } while (_findnext(hFile, &fileinfo) == 0);
         _findclose(hFile);
     }
 }


//只读取某给定路径下的当前文件名
void getJustCurrentFile(string path, vector<string>& files) 
{
   //文件句柄
      long hFile = 0;
      //文件信息
      struct _finddata_t fileinfo;
      string p;
      if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
          do {
             if ((fileinfo.attrib & _A_SUBDIR)) {
                 ;
             } else {
                 files.push_back(fileinfo.name);
                 //files.push_back(p.assign(path).append("\\").append(fileinfo.name));
             }
         } while (_findnext(hFile, &fileinfo) == 0);
         _findclose(hFile);
     }
 }

//只读取某给定路径下的所有文件名(即包含当前目录及子目录的文件)
 void getFilesAll(string path, vector<string>& files) 
 {
      //文件句柄
      long hFile = 0;
      //文件信息
      struct _finddata_t fileinfo;
      string p;  
      if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
          do {
              if ((fileinfo.attrib & _A_SUBDIR)) {
                 if (strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0) {
                     //files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                     getFilesAll(p.assign(path).append("\\").append(fileinfo.name), files);
                 }
             } else {  
                 files.push_back(p.assign(path).append("\\").append(fileinfo.name));
             }
         } while (_findnext(hFile, &fileinfo) == 0);
         _findclose(hFile);
     }
 }



//获取特定格式的文件名  (当前文件夹下，不包括子文件夹)
// 该函数有两个参数，第一个为路径字符串(string类型，最好为绝对路径)；  
// 第二个参数为文件夹与文件名称存储变量(vector类型,引用传递)。 
void GetAllFormatFiles( string path, vector<string>& files,string format)    
{    
    //文件句柄    
    long   hFile   =   0;    
    //文件信息    
    struct _finddata_t fileinfo;    
    string p;    
    if((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(),&fileinfo)) !=  -1)    
    {    
        do    
        {      
            if((fileinfo.attrib &  _A_SUBDIR))    
            {    
                if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)    
                {  
                    //files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
                    GetAllFormatFiles( p.assign(path).append("\\").append(fileinfo.name), files,format);   
                }  
            }    
            else    
            {    
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );    
            }    
        }while(_findnext(hFile, &fileinfo)  == 0);    
  
        _findclose(hFile);   
    }   
}   
  
// 该函数有两个参数，第一个为路径字符串(string类型，最好为绝对路径)；  
// 第二个参数为文件夹与文件名称存储变量(vector类型,引用传递)。  

/*int main()  
{  
    string filePath = "testimages\\water";    
    vector<string> files;    
    char * distAll = "AllFiles.txt";  
  
    //读取所有的文件，包括子文件的文件  
    //GetAllFiles(filePath, files);  
  
    //读取所有格式为jpg的文件  
    string format = ".jpg";  
    GetAllFormatFiles(filePath, files,format);  
    ofstream ofn(distAll);  
    int size = files.size();   
    ofn<<size<<endl;  
    for (int i = 0;i<size;i++)    
    {    
        ofn<<files[i]<<endl;   
        cout<< files[i] << endl;  
    }  
    ofn.close();  
    return 0;  
}   */
