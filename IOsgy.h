#ifndef IOsgy
#define IOsgy

#endif
#include "struct_trace header.h"
using namespace std;

void read_ahead(unsigned short *sp/*��������*/,unsigned short *sr/*������*/,short *tn/*����*/, long *readtime,string infilename/*�ļ���*/);
void input(traceheader *headfile/*��ͷ*/,float **data/*����*/,short **volume,short sampling_point/*��������*/,short sampling_rate/*�������*/,short trace_num/*����*/,string infilename/*�ļ���*/);
void output(traceheader *headfile/*��ͷ*/,float **data/*����*/,short **volume,short sampling_point/*��������*/,short sampling_rate/*�������*/,short trace_num/*����*/,string outfilename);
