#ifndef IOsgy
#define IOsgy

#endif
#include "struct_trace header.h"
using namespace std;

void read_ahead(unsigned short *sp/*采样点数*/,unsigned short *sr/*采样率*/,short *tn/*道数*/, long *readtime,string infilename/*文件名*/);
void input(traceheader *headfile/*道头*/,float **data/*数据*/,short **volume,short sampling_point/*采样点数*/,short sampling_rate/*采样间隔*/,short trace_num/*道数*/,string infilename/*文件名*/);
void output(traceheader *headfile/*道头*/,float **data/*数据*/,short **volume,short sampling_point/*采样点数*/,short sampling_rate/*采样间隔*/,short trace_num/*道数*/,string outfilename);
