struct traceheader

{	int   Trace_Seq_No;                //   0    0-3 Trace Seq.Int No. Within Line 测线道顺序号码
	int   Trace_Seq_Reel;              //   1    4-7 Trace Seq. Within Reel 本卷道顺序号
	int   Field_Record_No;             //   2    8-11 Originalfield Record 原始野外记录号 炮号
	int   Channel_No;                  //   3   12-15 Trace No[Chann#] Within Originalfield Record. 原始野外记录中的道号
	int   Shot_Point_No;               //   4   16-19 Energy Source Point Number. 测线内炮点桩号(在同一个地面点有多于一个记录时使用)
	int   Cmp_No;                      //   5   20-23 Cmp Ensemblenumber  CMP号（或CDP号）（弯线=共反射面元号）
	int   Cmp_Seq_No;                  //   6   24-27 Sequenceno. Within Cmp. 在CMP道集中的道号(在每个CMP道集中道号从1开始)
	short int Trace_Id_Code;               //   7   28-29 Trace Id Code 道识别码：	l=地震数据；4=爆炸信号；7＝计时信号；2=死道；5=井口道；8＝水断信号；3=无效道（空道）；6＝扫描道；9…N=选择使用(N=32767)
	short int Fold;                        //   8   30-31 No. Of Verticalstacked Traces->Trace.  构成该道的垂直叠加道数(1是一道；2是两道相加;…)
	short int Trace_Hstack;                //   9   32-33 No. Of Horiz. Stacked Traces... 构成该道的水平叠加道数(1是一道; 2是两道叠加;…)
	short int Test_Code;                   //  10   34-35 1-Produc2-Test 数据类型：1=生产；    2=试验
	int   Offset_Sh_Rec;               //  11   36-39 Distancefrom Shot To Recv(Maybe -Ve) 从炮点到接收点的距离(如果排列与激发前进方向相反取负值) （分米）
	int   Elev_Rec;                    //  12   40-43 Elevatioof Receivergroup. 接收点的地面高程。高于海平面的高程为正，低于海平面为负（cm）。
	int   Elev_Shot;                   //  13   44-47 Elevatioof Shot. 炮点的地面高程（cm）
	int   Depth_Shot;                  //  14   48-51 Source Depth Below Surface. 炮井深度(正数，cm)
	int   Elev_FloatDatum_Rec;         //  15   52-55 Floatingdatum Elevatioof Receivergroup. 接收点基准面高程（cm）
	int   Elev_FloatDatum_Shot;        //  16   56-59 Floatingdatum Elevatioof Source. 炮点基准面高程（cm）。
	int   Water_Depth_Shot;            //  17   60-63 Water Depth At Source. 炮点的水深（cm）
	int   Water_Depth_Rec;             //  18   64-67 Water Depth At Receivergroup. 接收点的水深（cm）
	short int  Elev_Depth_Scaler;           //  19   68-69 Scalar To Be Applied To All Elevatioand Depths.  对41一68字节中的所有高程和深度应用此因子给出真值。比例因子=l，土10，土100，土1000或者 土10000。如果为正，乘以因子；如果为负，则除以因子。(此约定中= -100)
	short int  Coord_Scaler;                //  20   70-71 Scalar To Be Applied To All Coordinates. 对73-88字节中的所有坐标应用此因子给出真值。比例因子=1，土10，土[00，土1000或者土10000。如果为正，乘以因子；如果为负，则除以因子。(此约定中= -10)
	int   Xshot;                       //  21   72-75 Shot X Coordina72) 炮点坐标-X（分米）。（如果坐标单位是弧度·秒
	int   Yshot;                       //  22   76-79 Shot Y Coordina76) 炮点坐标-Y（分米）。X值代表径度，Y值代表
	int   Xrec;                        //  23   80-83 Receivergroup X Coordinate(80) 接收点坐标-X（分米）。纬度；正值代表格林威
	int   Yrec;                        //  24   84-87 Receivergroup Y Coordinate(84) 接收点坐标-Y（分米）。治子午线东或者赤道北的秒数。负值则为西或者南的秒数）
	short int  Units;                       //  25   88-89 1-Length,2-Lat/Long,3-Meters,4-Feet 坐标单位； 1=长度(米或者英尺)；2=弧度·秒
	short int  Velocity_Weather;            //  26   90-91 Weatherivelocity 接收点下风化层速度（低速带速度，M/S）
	short int  Velocity_Subweather;         //  27   92-93 Sub-Weatvelocityvelocity). 接收点下次风化层速度（降速带速度，M/S）
	short int  Uphole_Shot;                 //  28   94-95 Uphole Time At Source. 震源处的井口时间（ms）
	short int  Uphole_Rec;                  //  29   96-97 Uphole Time At Receivergroup.接收点处的井口时间（ms）
	short int  Static_Src;                  //  30   98-99 Source Static Correction. 炮点的野外一次静校正值（ms）
	short int  Static_Rec;                  //  31  100-101 Receivergroup Static Correction. 接收点的野外一次静校正值（ms）
	short int  Static_Total;                //  32  102-103 Total Static Applied. 总野外一次静校正量(若未用静校时为零，（ms）
	short int  Lag_Time_A;                  //  33  104-105 Time In Ms. 延迟时间-A，以ms表示。240字节的道标识的结束和时间信号之间的时间。如果时间信号出现在道头结束之前为正。如果时间信号出现在道头结束之后为负。时间信号就是起始脉冲，它记录在辅助道上或者由记录系统指定。
	short int  Lag_Time_B;                  //  34  106-107 (Ms) Between Initiatiof 时间延迟-B，以ms表示。为时间信号和起爆之间的延迟时间。可正可负。
	short int  Delay_Time;                  //  35  108-109 Delay Recordintime(Ms). 延迟记录时间，以ms表示。震源的起爆时间和开始记录数据样点之间的时间(深水时，数据记录不从时间零开始)。
	short int  Mute_Time_Start;             //  36  110-111 Mute Time Start. 起始切除时间（ms）
	short int  Mute_Time_End;               //  37  112-113 Mute Time End. 结束切除时间（ms）
	unsigned  short int  Nsamples;                    //  38  114-115 Number Of Samples For This Trace. 本道的采样点数。
	unsigned  short int  Samplerate;                  //  39  116-117 Sample Intervalin Us For This Trace. 本道的采样间隔，以us表示。
	short int  Gain_Type;                   //  40  118-119 Gain Type Of Field Instrume1-Fixed/2-Binary/3-Float/4-..Optional Optional 野外仪器的增益类型：	l＝固定增益；    2＝二进制增益；	3＝浮点增益；    4…N＝选择使用
	short int  Gain_Constant;               //  41  120-121 Instrumegain Constant. 仪器增益常数。
	short int  Gain_Initial;                //  42  122-123 Instrumeearly Or Initial Gain(Db). 仪器起始增益(db)（固定增益）。
	short int  Data_Correlated;             //  43  124-125 1=No, 2=Yes. 相关码：  1＝没有相关；    2＝相关
	short int  Sweep_Freq_Start;            //  44  126-127 Sweep Frequencat Start. 起始扫描频率。
	short int  Sweep_Freq_End;              //  45  128-129 Sweep Frequencat End. 结束扫描频率。
	short int  Sweep_Length;                //  46  130-131 Sweep Length In Ms. 扫描长度，以ms表示。
	short int  Sweep_Type;                  //  47  132-133 Sweep Type: 1=Linear2=Parabo3=Exp., 4=Other. 扫描类型：1＝线性；2＝抛物线；3＝指数；4＝其他
	short int  Sweep_Taperlen_Start;        //  48  134-135 Sweep Taper Length At Start In Ms. 扫描道起始斜坡长度，以ms表示。
	short int  Sweep_Taperlen_End;          //  49  136-137 Sweep Taper Length At End In Ms. 扫描道终了斜坡长度，以ms表示。
	short int  Sweep_Tapertype;             //  50  138-139 Taper Type: 1=Linear2=Cos2, 3=Other. 斜坡类型：1＝线性；2＝COS?；3＝其他
	short int  Alias_Filter_Freq;           //  51  140-141 Alias Filter Frequencif Used. 滤假频的频率(如果使用)
	short int  Alias_Filter_Slope;          //  52  142-143 Alias Filter Slope. 滤假频的陡度
	short int  Notch_Filter_Freq;           //  53  144-145 Notch Filter Frequencif Used. 陷波频率(如果使用)
	short int  Notch_Filter_Slope;          //  54  146-147 Notch Filter Slope. 陷波陡度
	short int  Lowcut_Freq;                 //  55  148-149 Low Cut Frequencif Used. 低截频率(如果使用)
	short int  Highcut_Freq;                //  56  150-151 High Cut Frequencif Used. 高截频率(如果使用)
	short int  Lowcut_Slope;                //  57  152-153 Low Cut Slope. 低截频率陡度
	short int  Highcut_Slope;               //  58  154-155 High Cut Slope. 高截频率陡度
	short int  DataRecorded_Year;           //  59  156-157 Year Data Recorded. 数据记录的年
	short int  DataRecorded_Day;            //  60  158-159 Day Of Year Data Recorded. 日
	short int  DataRecorded_Hour;           //  61  160-161 Hour Of Day(24 Hour Clock). 小时(24小时制)
	short int  DataRecorded_Minute;         //  62  162-163 Minute Of Hour Data Recorded. 分
	short int  DataRecorded_Second;         //  63  164-165 Second Of Minute Data Recorded. 秒
	short int  Time_Basis_Code;             //  64  166-167 Time Basis Code: 1=Local,2=Gmt, 3=Other. 时间代码：1＝当地时间；2＝格林威治时间；3＝其他
	short int  Trace_Weighting_Factor;      //  65  168-169 Trace Weightinfactor--As 2-N Volts.... 道加权因子(最小有效位定义为2**(-N)，N＝0，1，2，…，32767) (Maxwave 时间 ms)
	short int  Geophone_Group_Number;       //  66  170-171 Geophonegroup Number Of Roll Switch Positionone. 覆盖开关位置1处的检波器串（道）号。   (Maxwave 时间 us)
	short int  Geophone_Group_Firsttrace;   //  67  172-173 Geophonegroup Number Of First In Org. Field Rec. 在原始野外记录中第一道的检波器串号。
	short int  Geophone_Group_Lasttrace;    //  68  174-175 Geophonegroup Number Of Last Trace In Org. Field Rec. 在原始野外记录中最后一道的检波器串号。
	short   int  User1;                     //  69  176-177 缺口大小(覆盖滚动的总道数)；改为：（=1，单边激发；=2，中间激发。）
	short   int  User2;                     //  70  178-179 在测线的开始或者结束处的覆盖斜坡位置：1＝在后面（下行）； 2＝在前面（上行）；	改为：=0，无坐标；=1，有高程；=2，有坐标和高程。
	int X_MidPoint;                    //  71  180-183 X Mid-Poinof Trace.弯线或直测线中每个共反射点的X坐标（分米）。
	int Y_MidPoint;                    //  72  184-187 Y Mid-Poinof Trace.弯线或直测线中每个共反射点的Y坐标（分米）
	int   Cmp_Xcenter;                 //  73  188-191 X Coordinaof Cmp Bin Center弯线中每个共反射面元中点的X坐标（分米）
	int   Cmp_Ycenter;                 //  74  192-195 Y Coordinaof Cmp Bin Center弯线中每个共反射面元中点的Y坐标（分米）
	int   User3;                       //  75  196-199 弯线中输出剖面段的X坐标（分米）
	int   User4;                       //  76  200-203 弯线中输出剖面段的Y坐标（分米）
	short int  Recv_Point_No;               //  77  204-205 测线内接收点桩号。
	short int  Recv_Distance;               //  78  206-207 站点间距或道间距（分米）
	short int  Traces_Per_Shot;             //  79  208-209 道数/每炮
    short int  User5;                       //  80  210-211 炮点下低速带速度（M/S）
	short int  User6;                       //  81  212-213 炮点下降速带速度（M/S）
	short int  User7;                       //  82  214-215 CMP（CDP）点或共面元中点间距（分米）
	short int  User8;                       //  83  216-217 测线内有效站点总数
	short int  User9;                       //  84  218-219 剖面内CMP（CDP）点或共面元点总数
	short int  User10;                      //  85  220-221 炮点剩余静校正量（ms）
	short int  User11;                      //  86  222-223 接收点剩余静校正量（ms）
	short int  User12;                      //  87  224-225 总剩余静校正量（ms）
	short int  User13;                      //  88  226-227 炮点下低速带厚度（分米）
	short int  User14;                      //  89  228-229 接收点下低速带厚度（分米）
	short int  User15;                      //  90  230-231 弯线中该道列号
	short int  User16;                      //  91  232-233 弯线中该道行号
	short int  User17;                      //  92  234-235 弯线中输出剖面段的段号
	int   User18;                      //  93  236-239 测线内的总道数                                                                                          
};