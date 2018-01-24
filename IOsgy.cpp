// maxiwave仪器sgy数据读写程序

#include <iostream>
#include <iomanip>
#include <fstream>
#include "swapbyte.h"
#include"struct_trace header.h"
using namespace std;
// 预读
void read_ahead(unsigned short *sp/*采样点数*/,unsigned short *sr/*采样率*/,short *tn/*道数*/, long *readtime,string infilename/*文件名*/)
{
	ifstream fin; 
	short hour,Minute,second,Microsecond;
	long filelength/*数据总长度*/;
//	cout<<"请出入文件名";
//	cin>>infilename;
	fin.open(infilename,ios::binary);
	fin.seekg(3714,ios::beg);
	fin.read((char*)&(*sp),2);     //读采样点数
	fin.read((char*)&(*sr),2);	   //读采样率

	fin.seekg(3760,ios::beg);
	fin.read((char*)&(hour),2);
	fin.read((char*)&(Minute),2);
	fin.read((char*)&(second),2);

	fin.seekg(3768,ios::beg);
	fin.read((char*)&(Microsecond),2);

	swap_u_short_2(sp);
	swap_u_short_2(sr);
	swap_short_2(&hour);
	swap_short_2(&Minute);
	swap_short_2(&second);
	swap_short_2(&Microsecond);

	fin.seekg(0,ios::end);     //使指针位于流结尾处
	filelength=fin.tellg(); //求文件大小
	*tn=(filelength-3600)/((*sp*4)+240);
	*readtime=(hour*60*60+Minute*60+second)*1000+Microsecond;
	fin.close();
//	cout<<filelength<<endl<<*sp<<endl<<*sr<<endl<<*tn<<endl;

}



//输入


void input(traceheader *headfile/*道头*/,float **data/*数据*/,short **volume,short sampling_point/*采样点数*/,short sampling_rate/*采样间隔*/,short trace_num/*道数*/,string infilename/*文件名*/)
{
	ifstream fin;
	fin.open(infilename,ios::binary);
	int i;
	
	for(i=0;i<trace_num;i++)
	{
		
		fin.read((char *)volume,3600);
		fin.read((char *)&(headfile[i]),240);
//		for(j=0;j<sampling_point;j++)
//			fin.read((char *)&(data[i][j]),4);
		fin.read((char *)data[i],4*sampling_point);
	}
	fin.close();
}



//输出

void output(traceheader *headfile/*道头*/,float **data/*数据*/,short **volume,short sampling_point/*采样点数*/,short sampling_rate/*采样间隔*/,short trace_num/*道数*/,string outfilename)
{
	ofstream fout;
		
	fout.open(outfilename,ios::binary);
	int i;
//	cout<<sampling_point<<endl;
	for(i=0;i<trace_num;i++)
	{
		fout.write((char *)volume,3600);
		fout.write((char *)&(headfile[i]),240);
		fout.write((char *)data[i],4*sampling_point);
	}
	fout.close();
}