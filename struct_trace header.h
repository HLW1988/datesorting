struct traceheader

{	int   Trace_Seq_No;                //   0    0-3 Trace Seq.Int No. Within Line ���ߵ�˳�����
	int   Trace_Seq_Reel;              //   1    4-7 Trace Seq. Within Reel �����˳���
	int   Field_Record_No;             //   2    8-11 Originalfield Record ԭʼҰ���¼�� �ں�
	int   Channel_No;                  //   3   12-15 Trace No[Chann#] Within Originalfield Record. ԭʼҰ���¼�еĵ���
	int   Shot_Point_No;               //   4   16-19 Energy Source Point Number. �������ڵ�׮��(��ͬһ��������ж���һ����¼ʱʹ��)
	int   Cmp_No;                      //   5   20-23 Cmp Ensemblenumber  CMP�ţ���CDP�ţ�������=��������Ԫ�ţ�
	int   Cmp_Seq_No;                  //   6   24-27 Sequenceno. Within Cmp. ��CMP�����еĵ���(��ÿ��CMP�����е��Ŵ�1��ʼ)
	short int Trace_Id_Code;               //   7   28-29 Trace Id Code ��ʶ���룺	l=�������ݣ�4=��ը�źţ�7����ʱ�źţ�2=������5=���ڵ���8��ˮ���źţ�3=��Ч�����յ�����6��ɨ�����9��N=ѡ��ʹ��(N=32767)
	short int Fold;                        //   8   30-31 No. Of Verticalstacked Traces->Trace.  ���ɸõ��Ĵ�ֱ���ӵ���(1��һ����2���������;��)
	short int Trace_Hstack;                //   9   32-33 No. Of Horiz. Stacked Traces... ���ɸõ���ˮƽ���ӵ���(1��һ��; 2����������;��)
	short int Test_Code;                   //  10   34-35 1-Produc2-Test �������ͣ�1=������    2=����
	int   Offset_Sh_Rec;               //  11   36-39 Distancefrom Shot To Recv(Maybe -Ve) ���ڵ㵽���յ�ľ���(��������뼤��ǰ�������෴ȡ��ֵ) �����ף�
	int   Elev_Rec;                    //  12   40-43 Elevatioof Receivergroup. ���յ�ĵ���̡߳����ں�ƽ��ĸ߳�Ϊ�������ں�ƽ��Ϊ����cm����
	int   Elev_Shot;                   //  13   44-47 Elevatioof Shot. �ڵ�ĵ���̣߳�cm��
	int   Depth_Shot;                  //  14   48-51 Source Depth Below Surface. �ھ����(������cm)
	int   Elev_FloatDatum_Rec;         //  15   52-55 Floatingdatum Elevatioof Receivergroup. ���յ��׼��̣߳�cm��
	int   Elev_FloatDatum_Shot;        //  16   56-59 Floatingdatum Elevatioof Source. �ڵ��׼��̣߳�cm����
	int   Water_Depth_Shot;            //  17   60-63 Water Depth At Source. �ڵ��ˮ�cm��
	int   Water_Depth_Rec;             //  18   64-67 Water Depth At Receivergroup. ���յ��ˮ�cm��
	short int  Elev_Depth_Scaler;           //  19   68-69 Scalar To Be Applied To All Elevatioand Depths.  ��41һ68�ֽ��е����и̺߳����Ӧ�ô����Ӹ�����ֵ����������=l����10����100����1000���� ��10000�����Ϊ�����������ӣ����Ϊ������������ӡ�(��Լ����= -100)
	short int  Coord_Scaler;                //  20   70-71 Scalar To Be Applied To All Coordinates. ��73-88�ֽ��е���������Ӧ�ô����Ӹ�����ֵ����������=1����10����[00����1000������10000�����Ϊ�����������ӣ����Ϊ������������ӡ�(��Լ����= -10)
	int   Xshot;                       //  21   72-75 Shot X Coordina72) �ڵ�����-X�����ף�����������굥λ�ǻ��ȡ���
	int   Yshot;                       //  22   76-79 Shot Y Coordina76) �ڵ�����-Y�����ף���Xֵ�����ȣ�Yֵ����
	int   Xrec;                        //  23   80-83 Receivergroup X Coordinate(80) ���յ�����-X�����ף���γ�ȣ���ֵ���������
	int   Yrec;                        //  24   84-87 Receivergroup Y Coordinate(84) ���յ�����-Y�����ף����������߶����߳��������������ֵ��Ϊ�������ϵ�������
	short int  Units;                       //  25   88-89 1-Length,2-Lat/Long,3-Meters,4-Feet ���굥λ�� 1=����(�׻���Ӣ��)��2=���ȡ���
	short int  Velocity_Weather;            //  26   90-91 Weatherivelocity ���յ��·绯���ٶȣ����ٴ��ٶȣ�M/S��
	short int  Velocity_Subweather;         //  27   92-93 Sub-Weatvelocityvelocity). ���յ��´η绯���ٶȣ����ٴ��ٶȣ�M/S��
	short int  Uphole_Shot;                 //  28   94-95 Uphole Time At Source. ��Դ���ľ���ʱ�䣨ms��
	short int  Uphole_Rec;                  //  29   96-97 Uphole Time At Receivergroup.���յ㴦�ľ���ʱ�䣨ms��
	short int  Static_Src;                  //  30   98-99 Source Static Correction. �ڵ��Ұ��һ�ξ�У��ֵ��ms��
	short int  Static_Rec;                  //  31  100-101 Receivergroup Static Correction. ���յ��Ұ��һ�ξ�У��ֵ��ms��
	short int  Static_Total;                //  32  102-103 Total Static Applied. ��Ұ��һ�ξ�У����(��δ�þ�УʱΪ�㣬��ms��
	short int  Lag_Time_A;                  //  33  104-105 Time In Ms. �ӳ�ʱ��-A����ms��ʾ��240�ֽڵĵ���ʶ�Ľ�����ʱ���ź�֮���ʱ�䡣���ʱ���źų����ڵ�ͷ����֮ǰΪ�������ʱ���źų����ڵ�ͷ����֮��Ϊ����ʱ���źž�����ʼ���壬����¼�ڸ������ϻ����ɼ�¼ϵͳָ����
	short int  Lag_Time_B;                  //  34  106-107 (Ms) Between Initiatiof ʱ���ӳ�-B����ms��ʾ��Ϊʱ���źź���֮����ӳ�ʱ�䡣�����ɸ���
	short int  Delay_Time;                  //  35  108-109 Delay Recordintime(Ms). �ӳټ�¼ʱ�䣬��ms��ʾ����Դ����ʱ��Ϳ�ʼ��¼��������֮���ʱ��(��ˮʱ�����ݼ�¼����ʱ���㿪ʼ)��
	short int  Mute_Time_Start;             //  36  110-111 Mute Time Start. ��ʼ�г�ʱ�䣨ms��
	short int  Mute_Time_End;               //  37  112-113 Mute Time End. �����г�ʱ�䣨ms��
	unsigned  short int  Nsamples;                    //  38  114-115 Number Of Samples For This Trace. �����Ĳ���������
	unsigned  short int  Samplerate;                  //  39  116-117 Sample Intervalin Us For This Trace. �����Ĳ����������us��ʾ��
	short int  Gain_Type;                   //  40  118-119 Gain Type Of Field Instrume1-Fixed/2-Binary/3-Float/4-..Optional Optional Ұ���������������ͣ�	l���̶����棻    2�����������棻	3���������棻    4��N��ѡ��ʹ��
	short int  Gain_Constant;               //  41  120-121 Instrumegain Constant. �������泣����
	short int  Gain_Initial;                //  42  122-123 Instrumeearly Or Initial Gain(Db). ������ʼ����(db)���̶����棩��
	short int  Data_Correlated;             //  43  124-125 1=No, 2=Yes. ����룺  1��û����أ�    2�����
	short int  Sweep_Freq_Start;            //  44  126-127 Sweep Frequencat Start. ��ʼɨ��Ƶ�ʡ�
	short int  Sweep_Freq_End;              //  45  128-129 Sweep Frequencat End. ����ɨ��Ƶ�ʡ�
	short int  Sweep_Length;                //  46  130-131 Sweep Length In Ms. ɨ�賤�ȣ���ms��ʾ��
	short int  Sweep_Type;                  //  47  132-133 Sweep Type: 1=Linear2=Parabo3=Exp., 4=Other. ɨ�����ͣ�1�����ԣ�2�������ߣ�3��ָ����4������
	short int  Sweep_Taperlen_Start;        //  48  134-135 Sweep Taper Length At Start In Ms. ɨ�����ʼб�³��ȣ���ms��ʾ��
	short int  Sweep_Taperlen_End;          //  49  136-137 Sweep Taper Length At End In Ms. ɨ�������б�³��ȣ���ms��ʾ��
	short int  Sweep_Tapertype;             //  50  138-139 Taper Type: 1=Linear2=Cos2, 3=Other. б�����ͣ�1�����ԣ�2��COS?��3������
	short int  Alias_Filter_Freq;           //  51  140-141 Alias Filter Frequencif Used. �˼�Ƶ��Ƶ��(���ʹ��)
	short int  Alias_Filter_Slope;          //  52  142-143 Alias Filter Slope. �˼�Ƶ�Ķ���
	short int  Notch_Filter_Freq;           //  53  144-145 Notch Filter Frequencif Used. �ݲ�Ƶ��(���ʹ��)
	short int  Notch_Filter_Slope;          //  54  146-147 Notch Filter Slope. �ݲ�����
	short int  Lowcut_Freq;                 //  55  148-149 Low Cut Frequencif Used. �ͽ�Ƶ��(���ʹ��)
	short int  Highcut_Freq;                //  56  150-151 High Cut Frequencif Used. �߽�Ƶ��(���ʹ��)
	short int  Lowcut_Slope;                //  57  152-153 Low Cut Slope. �ͽ�Ƶ�ʶ���
	short int  Highcut_Slope;               //  58  154-155 High Cut Slope. �߽�Ƶ�ʶ���
	short int  DataRecorded_Year;           //  59  156-157 Year Data Recorded. ���ݼ�¼����
	short int  DataRecorded_Day;            //  60  158-159 Day Of Year Data Recorded. ��
	short int  DataRecorded_Hour;           //  61  160-161 Hour Of Day(24 Hour Clock). Сʱ(24Сʱ��)
	short int  DataRecorded_Minute;         //  62  162-163 Minute Of Hour Data Recorded. ��
	short int  DataRecorded_Second;         //  63  164-165 Second Of Minute Data Recorded. ��
	short int  Time_Basis_Code;             //  64  166-167 Time Basis Code: 1=Local,2=Gmt, 3=Other. ʱ����룺1������ʱ�䣻2����������ʱ�䣻3������
	short int  Trace_Weighting_Factor;      //  65  168-169 Trace Weightinfactor--As 2-N Volts.... ����Ȩ����(��С��Чλ����Ϊ2**(-N)��N��0��1��2������32767) (Maxwave ʱ�� ms)
	short int  Geophone_Group_Number;       //  66  170-171 Geophonegroup Number Of Roll Switch Positionone. ���ǿ���λ��1���ļ첨�����������š�   (Maxwave ʱ�� us)
	short int  Geophone_Group_Firsttrace;   //  67  172-173 Geophonegroup Number Of First In Org. Field Rec. ��ԭʼҰ���¼�е�һ���ļ첨�����š�
	short int  Geophone_Group_Lasttrace;    //  68  174-175 Geophonegroup Number Of Last Trace In Org. Field Rec. ��ԭʼҰ���¼�����һ���ļ첨�����š�
	short   int  User1;                     //  69  176-177 ȱ�ڴ�С(���ǹ������ܵ���)����Ϊ����=1�����߼�����=2���м伤������
	short   int  User2;                     //  70  178-179 �ڲ��ߵĿ�ʼ���߽������ĸ���б��λ�ã�1���ں��棨���У��� 2����ǰ�棨���У���	��Ϊ��=0�������ꣻ=1���и̣߳�=2��������͸̡߳�
	int X_MidPoint;                    //  71  180-183 X Mid-Poinof Trace.���߻�ֱ������ÿ����������X���꣨���ף���
	int Y_MidPoint;                    //  72  184-187 Y Mid-Poinof Trace.���߻�ֱ������ÿ����������Y���꣨���ף�
	int   Cmp_Xcenter;                 //  73  188-191 X Coordinaof Cmp Bin Center������ÿ����������Ԫ�е��X���꣨���ף�
	int   Cmp_Ycenter;                 //  74  192-195 Y Coordinaof Cmp Bin Center������ÿ����������Ԫ�е��Y���꣨���ף�
	int   User3;                       //  75  196-199 �������������ε�X���꣨���ף�
	int   User4;                       //  76  200-203 �������������ε�Y���꣨���ף�
	short int  Recv_Point_No;               //  77  204-205 �����ڽ��յ�׮�š�
	short int  Recv_Distance;               //  78  206-207 վ��������ࣨ���ף�
	short int  Traces_Per_Shot;             //  79  208-209 ����/ÿ��
    short int  User5;                       //  80  210-211 �ڵ��µ��ٴ��ٶȣ�M/S��
	short int  User6;                       //  81  212-213 �ڵ��½��ٴ��ٶȣ�M/S��
	short int  User7;                       //  82  214-215 CMP��CDP�������Ԫ�е��ࣨ���ף�
	short int  User8;                       //  83  216-217 ��������Чվ������
	short int  User9;                       //  84  218-219 ������CMP��CDP�������Ԫ������
	short int  User10;                      //  85  220-221 �ڵ�ʣ�ྲУ������ms��
	short int  User11;                      //  86  222-223 ���յ�ʣ�ྲУ������ms��
	short int  User12;                      //  87  224-225 ��ʣ�ྲУ������ms��
	short int  User13;                      //  88  226-227 �ڵ��µ��ٴ���ȣ����ף�
	short int  User14;                      //  89  228-229 ���յ��µ��ٴ���ȣ����ף�
	short int  User15;                      //  90  230-231 �����иõ��к�
	short int  User16;                      //  91  232-233 �����иõ��к�
	short int  User17;                      //  92  234-235 �������������εĶκ�
	int   User18;                      //  93  236-239 �����ڵ��ܵ���                                                                                          
};