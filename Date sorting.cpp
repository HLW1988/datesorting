#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "swapbyte.h"
#include "getfilename.h"
#include "IOsgy.h"
using namespace std;

/*void main()
{
	string filename="H:/红87-2-8三井监测";
	vector<string> wellfiles,datefiles;       // 井名子文件夹，date子文件夹

	getJustCurrentDir(filename,wellfiles);  //读取子文件夹
	int sizewell=wellfiles.size();
	for(int i=0;i<sizewell;i++)
	{
		wellfiles[i]=filename+"/"+wellfiles[i];
		cout<<wellfiles[i]<<endl;
	}
	
	getJustCurrentDir(wellfiles[0],datefiles); 
	int sizedate=datefiles.size();

	string **welldate;                 //二维数据 主数据    [井个数][天数]
 	welldate=new string*[sizewell];
    for(int i=0;i<sizedate;i++)
		welldate[i]=new string[sizedate]; 
	
	for(int i=0;i<sizewell;i++)         //二维数组赋值
	{
		for(int j=0;j<sizedate;j++)
		{   
			welldate[i][j]=wellfiles[i]+"/"+datefiles[j];
			cout<<welldate[i][j]<<endl;
		}
	}


	for(int i=0;i<sizedate;i++)       //   [天数][sgy文件]
	{
		for(int j=0;j<sizewell;j++)
		{

		}
	}
}
*/

// sprinf(filename,"%d.txt",i+1);
// fout.open(filename);

void array2D(int **p,int n1,int n2);
void deletearray2D(int **p,int n1);
void array3D(int ***p,int n1,int n2,int n3);
void deletearray3D(int ***p,int n1,int n2);
string i2s(int i,int len);

void main()
{
	
	
	

//	string filename;
//	cout<<"请输入3井文件路径"<<endl;
//	cin>>filename;
	string filename1="H:/红87-2-8三井监测/红87-3-4监测/射孔",filename2="H:/红87-2-8三井监测/红87-3-8井监测/射孔",filename3="H:/红87-2-8三井监测/红87-6-12井监测/射孔";
	string outfilename="H:/红87-2-8三井监测/合并";
	string ss;
	vector<string>  sgyfiles1,sgyfiles2,sgyfiles3;
	ifstream fin1,fin2,fin3;
	reel *headreel1,*headreel2,*headreel3,*outheadreel,nheadreel1,nheadreel2,nheadreel3,noutheadreel;
	headreel1=&nheadreel1;
	headreel2=&nheadreel2;
	headreel3=&nheadreel3;
	outheadreel=&noutheadreel;
	reel headreel;
	traceheader headfile;
	
	unsigned short *sp1,*sp2,*sp3,*sr1,*sr2,*sr3; //采样点、采样率
	unsigned short  nsp1,nsp2,nsp3,nsr1,nsr2,nsr3;
	short *tn1,*tn2,*tn3,*tn,*volume[1600];//道数 ，时间
	short ntn1,ntn2,ntn3,ntn;
	sp1=&nsp1,sp2=&nsp2,sp3=&nsp3,sr1=&nsr1,sr2=&nsr2,sr3=&nsr3;
	tn1=&ntn1;
	tn2=&ntn2;
	tn3=&ntn3;
	tn=&ntn;
	long *time1,*time2,*time3,mintime,temp,ntime1,ntime2,ntime3;     //采样开始时间  ms
	time1=&ntime1,time2=&ntime2,time3=&ntime3;
	
	getAllFiles(filename1,sgyfiles1);              //读取文件名及路径
	getAllFiles(filename2,sgyfiles2);
	getAllFiles(filename3,sgyfiles3);

	int size1=sgyfiles1.size();                   //文件个数
	int size2=sgyfiles2.size();
	int size3=sgyfiles3.size();


	int i=0,j=0,k=0,o=1;                           //循环开始  
	part2:


	read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp1,sr1,tn1,time1,sgyfiles1[i]);    //预读第一个文件采样点、采样间隔、道数、采样时间
	read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp2,sr2,tn2,time2,sgyfiles2[j]);
	read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp3,sr2,tn3,time3,sgyfiles3[k]);
	traceheader *headfile1=new traceheader[ntn1],*headfile2=new traceheader[ntn2],*headfile3=new traceheader[ntn3],*outheadfile=new traceheader[ntn1+ntn2+ntn3];

	temp=min(*time1,*time2);
	mintime=min(temp,*time3);

	int   **data1,**data2,**data3,**outdata;    //开二维数组
	data1=new int* [ntn1],data2=new int*[ntn2],data3=new int*[ntn3],outdata=new int*[ntn1+ntn2+ntn3];
	array2D(data1,ntn1,nsp1),array2D(data2,ntn2,nsp2),array2D(data3,ntn3,nsp3),array2D(outdata,(ntn1+ntn2+ntn3),nsp1);
//	headfile1=new traceheader[ntn1],headfile2=new traceheader[ntn2],headfile3=new traceheader[ntn3],outheadfile=new traceheader[ntn1+ntn2+ntn3];
	
	
	
	
	
	while(i<size1||j<size2||k<size3)
		{ 
			

			cout<<sgyfiles3[k]<<endl;
			read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp1,sr1,tn1,time1,sgyfiles1[i]);    //预读第一个文件采样点、采样间隔、道数、采样时间
			read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp2,sr2,tn2,time2,sgyfiles2[j]);
			read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp3,sr3,tn3,time3,sgyfiles3[k]);

			noutheadreel=headreel;                                 //卷头
			for(int r=0;r<(ntn1+ntn2+ntn3);r++)                    //道头
			{
				outheadfile[r]=headfile;
				outheadfile[r].Channel_No=r+1;
				outheadfile[r].Trace_Seq_Reel=r+1;
				swap_int_4(&outheadfile[r].Trace_Seq_Reel);
				swap_int_4(&outheadfile[r].Channel_No);
			}


			if(ntime1==mintime||ntime2==mintime||ntime3==mintime)
			{
				if(*time1>(mintime+10000)||i>=size1)                           //第一口井
					{                                          
						for(int l=0;l<ntn1;l++)
							for(int m=0;m<nsp1;m++)
								outdata[l][m]=0;
					
					}

				else if(*time1==mintime)
					{
						input(headfile1,headreel1,data1,volume,nsp1,nsr1,ntn1,sgyfiles1[i]);
						
						for(int r=0;r<(ntn1+ntn2+ntn3);r++)
							{
								outheadfile[r].DataRecorded_Year=headfile1[0].DataRecorded_Year;
								outheadfile[r].DataRecorded_Day=headfile1[0].DataRecorded_Day;
								outheadfile[r].DataRecorded_Hour=headfile1[0].DataRecorded_Hour;
								outheadfile[r].DataRecorded_Minute=headfile1[0].DataRecorded_Minute;
								outheadfile[r].DataRecorded_Second=headfile1[0].DataRecorded_Second;
								outheadfile[r].Trace_Weighting_Factor=headfile1[0].Trace_Weighting_Factor;
							}
					
				
					for(int l=0;l<ntn1;l++)
						for(int m=0;m<nsp1;m++)
							{
								outdata[l][m]=data1[l][m];
							}
					
						i=i+1;
					}

				else if((*time1>mintime)&&(*time1<mintime+10000))
				{
					input(headfile1,headreel1,data1,volume,nsp1,nsr1,ntn1,sgyfiles1[i]);
					int l=int((*time1-mintime)/0.25);
					for(int n=0;n<ntn1;n++)
					{
						for(int m=0;m<l;m++)
							outdata[n][m]=0;
						for(int m=l;m<nsp1;m++)
							outdata[n][m]=data1[n][m-l];
					}
				}

				else
				{
					input(headfile1,headreel1,data1,volume,nsp1,nsr1,ntn1,sgyfiles1[i]);
					int l=int((mintime-*time1)/0.25);
					for(int n=0;n<ntn1;n++)
						for(int m=0;m<(nsp1-l);m++)
							outdata[n][m]=data1[n][l+m];
					i=i+1;
					int ntime=ntime1+10000;
					read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp1,sr1,tn1,time1,sgyfiles1[i]);
					if(abs(ntime-*time1)<5)
					{
						input(headfile1,headreel1,data1,volume,nsp1,nsr1,ntn1,sgyfiles1[i]);
						for(int n=0;n<ntn1;n++)
							for(int m=(nsp1-l);m<nsp1;m++)
							{
								outdata[n][m]=data1[n][m-nsp1+l];
							}
					}
					else 
					{
						for(int n=0;n<ntn1;n++)
							for(int m=(nsp1-l);m<nsp1;m++)
							{
								outdata[n][m]=0;
							}
					}
								
				}


			//第二口井

			if(*time2>(mintime+10000)||j>=size2)                           //第一口井
				{
					for(int l=ntn1;l<ntn1+ntn2;l++)
						for(int m=0;m<nsp1;m++)
							outdata[l][m]=0;
					
				}

			else if(*time2==mintime)
				{
					input(headfile2,headreel2,data2,volume,nsp2,nsr2,ntn2,sgyfiles2[j]);
					
					for(int r=0;r<(ntn1+ntn2+ntn3);r++)
						{
							outheadfile[r].DataRecorded_Year=headfile2[0].DataRecorded_Year;
							outheadfile[r].DataRecorded_Day=headfile2[0].DataRecorded_Day;
							outheadfile[r].DataRecorded_Hour=headfile2[0].DataRecorded_Hour;
							outheadfile[r].DataRecorded_Minute=headfile2[0].DataRecorded_Minute;
							outheadfile[r].DataRecorded_Second=headfile2[0].DataRecorded_Second;
							outheadfile[r].Trace_Weighting_Factor=headfile2[0].Trace_Weighting_Factor;
						}
														
					for(int l=ntn1;l<ntn1+ntn2;l++)
					{
						
						for(int m=0;m<nsp1;m++)
						{
							outdata[l][m]=data2[l-ntn1][m];
						}
					}
					j=j+1;
				}




			else if((*time2>mintime)&&(*time2<mintime+10000))
				{
					input(headfile2,headreel2,data2,volume,nsp2,nsr2,ntn2,sgyfiles2[j]);
					int l=int((*time2-mintime)/0.25);
					for(int n=ntn1;n<ntn1+ntn2;n++)
					{
						for(int m=0;m<l;m++)
							outdata[n][m]=0;
						for(int m=l;m<nsp2;m++)
							outdata[n][m]=data2[n-ntn1][m-l];
					}
				}


				else
				{
					input(headfile2,headreel2,data2,volume,nsp2,nsr2,ntn2,sgyfiles2[j]);
					int l=int((mintime-*time2)/0.25);
					for(int n=ntn1;n<ntn1+ntn2;n++)
						for(int m=0;m<(nsp2-l);m++)
							outdata[n][m]=data2[n-ntn1][l+m];
					j=j+1;
					int ntime=ntime2+10000;
					read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp2,sr2,tn2,time2,sgyfiles2[j]);
					if(abs(ntime-*time2)<5)
					{
						input(headfile2,headreel2,data2,volume,nsp2,nsr2,ntn2,sgyfiles2[j]);
						for(int n=ntn1;n<ntn1+ntn2;n++)
							for(int m=(nsp2-l);m<nsp2;m++)
							{
								outdata[n][m]=data2[n-ntn1][m-nsp2+l];
							}
					}
					else 
					{
						for(int n=ntn1;n<ntn1+ntn2;n++)
							for(int m=(nsp2-l);m<nsp2;m++)
							{
								outdata[n][m]=0;
							}
					}
								
				}

			//第三口井

			if(*time3>(mintime+10000)||k>=size3)                           
				{
					for(int l=ntn1+ntn2;l<ntn1+ntn2+ntn3;l++)
						for(int m=0;m<nsp1;m++)
							outdata[l][m]=0;
					
				}

			else if(*time3==mintime)
				{
					input(headfile3,headreel3,data3,volume,nsp3,nsr3,ntn3,sgyfiles3[k]);
					
					for(int r=0;r<(ntn1+ntn2+ntn3);r++)
						{
							outheadfile[r].DataRecorded_Year=headfile3[0].DataRecorded_Year;
							outheadfile[r].DataRecorded_Day=headfile3[0].DataRecorded_Day;
							outheadfile[r].DataRecorded_Hour=headfile3[0].DataRecorded_Hour;
							outheadfile[r].DataRecorded_Minute=headfile3[0].DataRecorded_Minute;
							outheadfile[r].DataRecorded_Second=headfile3[0].DataRecorded_Second;
							outheadfile[r].Trace_Weighting_Factor=headfile3[0].Trace_Weighting_Factor;
						}
					for(int l=ntn1+ntn2;l<ntn1+ntn2+ntn3;l++)
					{
						
						for(int m=0;m<nsp3;m++)
						{
							outdata[l][m]=data3[l-ntn1-ntn2][m];
						}
							
					}
					k=k+1;
				}

				else if((*time3>mintime)&&(*time3<mintime+10000))
				{
					input(headfile3,headreel3,data3,volume,nsp3,nsr3,ntn3,sgyfiles3[k]);
					int l=int((*time3-mintime)/0.25);
					for(int n=ntn1+ntn2;n<ntn1+ntn2+ntn3;n++)
					{
						for(int m=0;m<l;m++)
							outdata[n][m]=0;
						for(int m=l;m<nsp3;m++)
							outdata[n][m]=data3[n-ntn1-ntn2][m-l];
					}
				}

				else
				{
					input(headfile3,headreel3,data3,volume,nsp3,nsr3,ntn3,sgyfiles3[k]);
					int l=int((mintime-*time3)/0.25);
					for(int n=ntn1+ntn2;n<ntn1+ntn2+ntn3;n++)
						for(int m=0;m<(nsp3-l);m++)
							outdata[n][m]=data3[n-ntn1-ntn2][l+m];
					k=k+1;
					int ntime=ntime3+10000;
					read_ahead((char*)&headreel,(char*)&headfile,(char*)volume,sp3,sr3,tn3,time3,sgyfiles3[k]);
					if(abs(ntime-*time3)<5)
					{
						input(headfile3,headreel3,data3,volume,nsp3,nsr3,ntn3,sgyfiles3[k]);
						for(int n=ntn1+ntn2;n<ntn1+ntn2+ntn3;n++)
							for(int m=(nsp3-l);m<nsp3;m++)
							{
								outdata[n][m]=data3[n-ntn1-ntn2][m-nsp3+l];
							}
					}
					else 
					{
						for(int n=ntn1+ntn2;n<ntn1+ntn2+ntn3;n++)
							for(int m=(nsp3-l);m<nsp3;m++)
							{
								outdata[n][m]=0;
							}
					}
								
				}



			mintime=mintime+10000;
			ss=i2s(o,6);
			ss=outfilename+"/"+"File"+ss+".sgy";
			
			outheadreel ->ntrpr=ntn1+ntn2+ntn3;
			swap_short_2(&(outheadreel ->ntrpr));
			for(int r=0;r<(ntn1+ntn2+ntn3);r++)                    //道头
			{
				outheadfile[r].Field_Record_No=o;
				swap_int_4(&outheadfile[r].Field_Record_No);
				}
						
			output(outheadfile,outheadreel,outdata,volume,nsp1,nsr1,(ntn1+ntn2+ntn3),ss);   
			cout<<ss<<endl;
			o=o+1;
//		
		}
		
		else
		{

			goto part2;

		}

	}
}


void array2D(int **p,int n1,int n2)
{                                               
   int i;  
   for(i=0;i<n1;i++)
   {
     p[i] = new int[n2];
   }
   //cout<<"ss 2D"<<endl;
}//end of array2D()
/* 释放2维数组 */
void deletearray2D(int **p,int n1)
{
    int i;
	for(i=0;i<n1;i++)
      delete[] p[i];

    delete[]p;

    
}//end of deletearray2D()


/* 申请三维数组 */
void array3D(int ***p,int n1,int n2,int n3)
{                                               
   int i,j;  
   for(i=0;i<n1;i++)
   {
     p[i] = new int *[n2];
     for(j=0;j<n2;j++)
        p[i][j] = new int[n3];
   }
}//end of array3D()
/* 释放三维数组 */
void deletearray3D(int ***p,int n1,int n2)
{   
	//
    int i,j;
    for(i=0;i<n1;i++)
	{
       for(j=0;j<n2;j++)
         delete[] p[i][j];
	}
    
	for(i=0;i<n1;i++)
      delete[] p[i];
    delete[]p;

    
}//end of deletearray3D()
//数字转化为字符前面几位补零
string i2s(int i, int len )
{
    stringstream ss;
    ss << setw(len) << setfill('0') << i;
    return ss.str();
}



/*
   void main()
{
	string infilename1="file000001.sgy";
	long ll;

//	cout<<"请输入文件名："<<endl;
//	cin>>infilename;    
	traceheader  headfile;   
	ifstream fin;
	fin.open(infilename,ios::binary );                 //打开文件
	if(!fin)                                           //判断文件是否存在
	{
		cerr<<"Can't open"<<fin<<"file for input.\n";
		exit(EXIT_FAILURE);  
	}

	fin.seekg(3600,ios::beg);                         //跳过卷头

	fin.read((char*)&headfile,240);
	fin.seekg(0,ios::end);     //使指针位于流结尾处
    ll=fin.tellg();        //求文件大小
	fin.close();
	
	swap_u_short_2(&headfile.Nsamples);
	swap_u_short_2(&headfile.Samplerate);
	swap_short_2(&headfile.Time_Basis_Code);
	swap_short_2(&headfile.DataRecorded_Year);
	swap_short_2(&headfile.DataRecorded_Day);
	swap_short_2(&headfile.DataRecorded_Hour);
	swap_short_2(&headfile.DataRecorded_Minute);
	swap_short_2(&headfile.DataRecorded_Second);
	swap_short_2(&headfile.Trace_Weighting_Factor); 


	int temp=(ll-3600)/int(headfile.Nsamples*sizeof(int)+240);//确定总道数

	cout<<temp<<endl;

	cout<<headfile.Nsamples<<endl;
	cout<<headfile.Samplerate<<endl;
	cout<<headfile.Time_Basis_Code<<endl;
	cout<<headfile.DataRecorded_Year<<endl;
	cout<<headfile.DataRecorded_Day<<endl;
	cout<<headfile.DataRecorded_Hour<<endl;
	cout<<headfile.DataRecorded_Minute<<endl;
	cout<<headfile.DataRecorded_Second<<endl;
	cout<<headfile.Trace_Weighting_Factor<<endl;

}   */

/* void main()
{ 
	string filePath = "H:/红87-2-8三井监测/红87-3-4监测/3-4-射孔";    
    vector<string> files1,files2,files3,files4,files5;    
    char * distAll1 = "AllFiles.txt";  
	char * distAll2 ="JustCurrentDir.txt";
	char * distAll3 = "JustCurrentFile.txt";
	char * distAll4 = "getFilesAll.txt";
	char * distAll5 = "GetAllFormatFiles.txt";
	string format = ".sgy";  
	getAllFiles(filePath,files1);
	getJustCurrentDir(filePath,files2);
	getJustCurrentFile(filePath,files3);
	getFilesAll(filePath,files4);
	GetAllFormatFiles(filePath,files5,format);


	int size1=files1.size();
	int size2=files2.size();
	int size3=files3.size();
	int size4=files4.size();
	int size5=files5.size();

	ofstream ofn1(distAll1); 
	ofstream ofn2(distAll2); 
	ofstream ofn3(distAll3); 
	ofstream ofn4(distAll4); 
	ofstream ofn5(distAll5); 

	for (int i = 0;i<size1;i++)    
    {    
        ofn1<<files1[i]<<endl;   
        cout<< files1[i] << endl;  
    }  
     

	for (int i = 0;i<size2;i++)    
    {    
        ofn2<<files2[i]<<endl;   
        cout<< files2[i] << endl;  
    }  
    

	for (int i = 0;i<size3;i++)    
    {    
        ofn3<<files3[i]<<endl;   
        cout<< files3[i] << endl;  
    }  
	  

	for (int i = 0;i<size4;i++)    
    {    
        ofn4<<files4[i]<<endl;   
        cout<< files4[i] << endl;  
    }  
	 

	for (int i = 0;i<size5;i++)    
    {    
        ofn5<<files5[i]<<endl;   
        cout<< files5[i] << endl;  
    }  

	ofn1.close(); 
	ofn2.close(); 
    ofn3.close(); 
    ofn4.close(); 
    ofn5.close();  

}
*/


