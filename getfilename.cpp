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

// ��ȡĳ����·���������ļ������ļ����ƣ���������·����
void getAllFiles(string path, vector<string>& files)
{
    //�ļ����  
    long   hFile = 0;
    //�ļ���Ϣ  
    struct _finddata_t fileinfo;  //�����õ��ļ���Ϣ��ȡ�ṹ
    string p;  //string�������˼��һ����ֵ����:assign()���кܶ����ذ汾
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib &  _A_SUBDIR))  //�ж��Ƿ�Ϊ�ļ���
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                {
                files.push_back(p.assign(path).append("/").append(fileinfo.name));//�����ļ�������
                    getAllFiles(p.assign(path).append("/").append(fileinfo.name), files);//�ݹ鵱ǰ�ļ���
                }
            }
            else    //�ļ�����
            {
                files.push_back(p.assign(path).append("/").append(fileinfo.name));//�ļ���
            }
        } while (_findnext(hFile, &fileinfo) == 0);  //Ѱ����һ�����ɹ�����0������-1
        _findclose(hFile);
    }
}
//����
//ֻ��ȡĳ����·���µĵ�ǰ�ļ�����(�������ƣ�ֻ�������������ð���ͬ��)

void getJustCurrentDir(string path, vector<string>& files) 
{
    //�ļ����
      long hFile = 0;
      //�ļ���Ϣ 
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


//ֻ��ȡĳ����·���µĵ�ǰ�ļ���
void getJustCurrentFile(string path, vector<string>& files) 
{
   //�ļ����
      long hFile = 0;
      //�ļ���Ϣ
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

//ֻ��ȡĳ����·���µ������ļ���(��������ǰĿ¼����Ŀ¼���ļ�)
 void getFilesAll(string path, vector<string>& files) 
 {
      //�ļ����
      long hFile = 0;
      //�ļ���Ϣ
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



//��ȡ�ض���ʽ���ļ���  (��ǰ�ļ����£����������ļ���)
// �ú�����������������һ��Ϊ·���ַ���(string���ͣ����Ϊ����·��)��  
// �ڶ�������Ϊ�ļ������ļ����ƴ洢����(vector����,���ô���)�� 
void GetAllFormatFiles( string path, vector<string>& files,string format)    
{    
    //�ļ����    
    long   hFile   =   0;    
    //�ļ���Ϣ    
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
  
// �ú�����������������һ��Ϊ·���ַ���(string���ͣ����Ϊ����·��)��  
// �ڶ�������Ϊ�ļ������ļ����ƴ洢����(vector����,���ô���)��  

/*int main()  
{  
    string filePath = "testimages\\water";    
    vector<string> files;    
    char * distAll = "AllFiles.txt";  
  
    //��ȡ���е��ļ����������ļ����ļ�  
    //GetAllFiles(filePath, files);  
  
    //��ȡ���и�ʽΪjpg���ļ�  
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
