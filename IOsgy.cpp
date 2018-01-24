// maxiwave����sgy���ݶ�д����

#include <iostream>
#include <iomanip>
#include <fstream>
#include "swapbyte.h"
#include"struct_trace header.h"
using namespace std;
// Ԥ��
void read_ahead(unsigned short *sp/*��������*/,unsigned short *sr/*������*/,short *tn/*����*/, long *readtime,string infilename/*�ļ���*/)
{
	ifstream fin; 
	short hour,Minute,second,Microsecond;
	long filelength/*�����ܳ���*/;
//	cout<<"������ļ���";
//	cin>>infilename;
	fin.open(infilename,ios::binary);
	fin.seekg(3714,ios::beg);
	fin.read((char*)&(*sp),2);     //����������
	fin.read((char*)&(*sr),2);	   //��������

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

	fin.seekg(0,ios::end);     //ʹָ��λ������β��
	filelength=fin.tellg(); //���ļ���С
	*tn=(filelength-3600)/((*sp*4)+240);
	*readtime=(hour*60*60+Minute*60+second)*1000+Microsecond;
	fin.close();
//	cout<<filelength<<endl<<*sp<<endl<<*sr<<endl<<*tn<<endl;

}



//����


void input(traceheader *headfile/*��ͷ*/,float **data/*����*/,short **volume,short sampling_point/*��������*/,short sampling_rate/*�������*/,short trace_num/*����*/,string infilename/*�ļ���*/)
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



//���

void output(traceheader *headfile/*��ͷ*/,float **data/*����*/,short **volume,short sampling_point/*��������*/,short sampling_rate/*�������*/,short trace_num/*����*/,string outfilename)
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