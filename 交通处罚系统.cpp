 #include<stdio.h>
#include<stdlib.h>
#include<windows.h> 
typedef struct traffic_Fine //声明新的类型来代替已有类型 
{
	char plate_Number[20];     //车牌号 
	char drive_License[20];    //驾驶证号
	char police_Code[20];      //交警代号
	char punish_Position[20];  //违章地点
	char punish_Time[20];      //违章时间 
	char fine_Money[20];       //罚款金额 
	char stata[20];            //缴费状态 
    struct traffic_Fine *next; //结构体指针指向下一个结构体 
    struct traffic_Fine *ahead; //结构体指针指向上一个结构体 
} Node,*Link;
int i,j,k;
int find_data(); //查找数据，若无数新建数据，有则跳过 
void select_Line(int flag); //主干线选择器 
void welcom_Frame_pr1(); //欢迎界面 
void welcom_Frame_pr2(); //欢迎界面 
void line_Frame(); //制作界面框架
Link create_list(); //建立链表 
void display_Node(Link head); //输出链表数据  
void correct_node(Link p); //修改数据
void clear_List(Link head);//释放清除链表 
void gotoxy(int x,int y); //自定义光标函数
void color(const unsigned short color_Const);//const unsigned short 无符号短型常量类型
void create_Menu(); //制作菜单选项 
void write_To_File_pre(Link head);//新建时的存储 
Link read_From_File(); //储存数据，也可视为保存 
int number_Trans(char code1[]);//数字字符转化为数字
int power(int n,int x,int &ra); //构建"x"的"n"次方
void query_Node(Link head); //查找罚款数据
void query_Frame();//构造查找界面框架 
void IQDW_Line_Frame();//新增、查找、删除、储存界面 
void write_To_File(Link head); //将链表数据输入到文本中 
Link insert_Node(Link head); //新增罚款数据 
int delete_Node_pr1(Link head,char x[]);//x为字符串
void delete_Node_pr2(Link head,char x[]);
void page();//数据翻找模块 
void query_Print_Frame();
void query_Print_Data(int y,Link p); 
int main()
{
	int flag; //定义一个变量，用来进入find_data()函数中进行选择，再返回数值给select_Line（flag）执行不同的语句 
	flag=find_data();
	select_Line(flag);  //当中调用了各种函数，充当于容器 
	gotoxy(0,36);
	return 0;
}

int find_data() //查找数据，若无数据新建数据，有则跳过
{
	int flag=0;
	FILE *fp=NULL;
	fp=fopen("fine_data.txt","r");
	if(fp==NULL){
		gotoxy(15,10);
		printf("无数据，请添加罚款相关数据，正在为你跳转...");
		Sleep(2000);
		flag=1;//无写入数据情况下，选择器选择1 
	}
	else{
		gotoxy(20,10);
		printf("上次有数据保存，正在为你读取中...");
		Sleep(2000); 
		flag=2; // 写入数据情况下，选择器选择2 
	}
	if(flag==0){
		gotoxy(25,10);
		printf("系统错误！");
		fclose(fp);  //错误出去也要把文本指针关闭
		exit(1);
	}
	fclose(fp);  //正确方式要把文本指针关闭 
return flag;  //返回flag值 
} 

void select_Line(int flag)  //主干线选择器 
{
	Link head=NULL;
	if(flag==1){ //无写入数据情况下，选择器选择1
		welcom_Frame_pr1();
	    line_Frame();	
		head=create_list();//获取链表
		display_Node(head);		
		write_To_File_pre(head); //新建时的存储 
		clear_List(head);//堆内存（1）、（2）释放  
		system("cls");
		gotoxy(45,16);
		printf("数据存储完毕，请重启系统");
		Sleep(500);
		gotoxy(70,16);printf(".");
		Sleep(500);
		gotoxy(71,16);printf(".");
		Sleep(500);
		gotoxy(72,16);printf(".");				 
	}
	if(flag==2){
		welcom_Frame_pr1();
		gotoxy(10,10);
	    line_Frame();
	   	gotoxy(10,11);
	    head=read_From_File();//获取链表
	    gotoxy(10,12);
//	    display_Node(head);
		clear_List(head);
		create_Menu();
		clear_List(head);//堆内存（1）、（2）释放 
		 
	}
}

void line_Frame() //制作界面框架
{


	for(i=0;i<100;i++){
		gotoxy(i,2);
		printf("-");
		gotoxy(i,35);
		printf("-");
	}
	for(i=0;i<35;i++){
		gotoxy(50,i);
		printf("|");		
	}
	gotoxy(20,1);
	printf("执行区");
	gotoxy(70,1);
	printf("选项区");
	

}

void welcom_Frame_pr1() //欢迎界面 
{		
		for(i=0;i<1;i++){  //通过i控制循环次数，控制开启界面动画连续等待时长 
		welcom_Frame_pr2();
		Sleep(150);color(8);gotoxy(40,20);printf("欢");
		Sleep(150);color(8);gotoxy(42,20);printf("迎");
		Sleep(150);color(8);gotoxy(44,20);printf("进"); 
		Sleep(150);color(8);gotoxy(46,20);printf("入"); 
		Sleep(150);color(8);gotoxy(48,20);printf("交"); 
		Sleep(150);color(8);gotoxy(50,20);printf("通");
		Sleep(150);color(8);gotoxy(52,20);printf("处");
		Sleep(150);color(8);gotoxy(54,20);printf("罚");
		Sleep(150);color(8);gotoxy(56,20);printf("系");
		Sleep(150);color(8);gotoxy(57,20);printf("统");welcom_Frame_pr2(); 
	}
	system("cls"); 
}

void welcom_Frame_pr2() //欢迎界面
{
		system("mode con cols=100 lines=40"); //设置CMD窗口初始大小 
		color(16);
		gotoxy(40,20);
		printf("欢");
		gotoxy(42,20);
		printf("迎");
		gotoxy(44,20);
		printf("进"); 
		gotoxy(46,20);
		printf("入"); 
		gotoxy(48,20);
		printf("交"); 
		gotoxy(50,20);
		printf("通"); 
		gotoxy(52,20);
		printf("处"); 
		gotoxy(54,20);
		printf("罚"); 
		gotoxy(56,20);
		printf("系"); 
		gotoxy(58,20);
		printf("统");
}



void display_Node(Link head)
{
	if(head==NULL){
		return;
	}
	typedef struct temp_Plate{ //用来赋值车牌号给temp_Plate[i] 
		char plate[20];
	} inNode;
	Link p;
	int count=0;
	int temp_Money[50]={0};//用来赋值罚款金额给temp_Money[i]----整数型 
	inNode temp_Plate[50];//存放成员plate_Number的值-----字符串型 
	int temp1;        //求最大值用的中间变量
	char temp2[20];        //求最大值用的中间变量
	p=head->next;         //指针初始化 
	while(p!=NULL){
		count++;
		p=p->next;
	}
	p=head->next;//指针初始化 
	for(i=0;i<count;i++){
		temp_Money[i]=number_Trans(p->fine_Money);
		p=p->next; 
	}
	p=head->next;//指针初始化 
	for(i=0;i<count;i++){
		strcpy(temp_Plate[i].plate,p->plate_Number);
		p=p->next;
	}
	
	for(int j=0;j<count-1;j++){           //将金额从大到小排序 
		for(int k=j+1;k<count;k++){
			if(temp_Money[j]<temp_Money[k]){
				temp1=temp_Money[j];
				temp_Money[j]=temp_Money[k];
				temp_Money[k]=temp1;
				strcpy(temp2,temp_Plate[j].plate);
				strcpy(temp_Plate[j].plate,temp_Plate[k].plate);
				strcpy(temp_Plate[k].plate,temp2);
			}
		} 			
	}
	FILE *fp=NULL;
	fp=fopen("display_Data.txt","w");//打开文件以及后续清空文件内容 
	fclose(fp);
	fp=fopen("display_Data.txt","a");//将排序完的数据写入文件 
	for(i=0;i<count;i++){		
		fprintf(fp,"\t%s",temp_Plate[i].plate);
		fprintf(fp,"\t%d",temp_Money[i]);
		fputc('\n',fp);
	}
	fclose(fp);
	page();//数据翻找模块 
}

Link create_list()
{
	int select_CL=1;
	int select_PS=1;
	Link head,p;
	head=(Link)malloc(sizeof(Node)); //申请堆内存（2）-----待释放
	head->next=NULL;
	p=head;
	while(select_CL==1){
		Link node;
		node=(Link)malloc(sizeof(Node)); //申请堆内存(1)-----待释放 				
		gotoxy(5,3);
		printf("请输入车牌号（M5**4）");
		gotoxy(5,4);
		scanf("%s",&(node->plate_Number));
		gotoxy(5,5);
		printf("请输入驾驶证号（13*****7）");
		gotoxy(5,6);
		scanf("%s",&(node->drive_License));
		gotoxy(5,7);
		printf("请输入交警代号（K****0）");
		gotoxy(5,8);
		scanf("%s",&(node->police_Code));
		gotoxy(5,9);
		printf("请输入违章地点（湛江）");
		gotoxy(5,10);
		scanf("%s",&(node->punish_Position));
		gotoxy(5,11);
		printf("请输入违章时间（12：00）");
		gotoxy(5,12);
		scanf("%s",&(node->punish_Time));
		gotoxy(5,13);
		printf("请输入罚款金额（120）");
		gotoxy(5,14);
		scanf("%s",&(node->fine_Money));
		gotoxy(5,15);
		printf("请输入缴费状态（已/未缴费）");
		gotoxy(5,16);
		scanf("%s",&(node->stata));
		
		gotoxy(5,17);
		printf("确认无误请按1，需修改按2(按其他键默认确认)");
		gotoxy(5,18);
		scanf("%d",&select_PS);
		if(select_PS==2){
			correct_node(node);
		}
		if(select_PS!=2){
			gotoxy(5,19);
			printf("继续输入请按1，结束请按0(按其他数字键默认结束)");
			gotoxy(5,20); 
			scanf("%d",&select_CL);
		}
		if(select_PS==2){
			gotoxy(5,24);
			printf("继续输入请按1，结束请按0(按其他数字键键默认结束)");
			gotoxy(5,25); 
			scanf("%d",&select_CL);
		}
		
		
		node->next=NULL;
		p->next=node;
		p=p->next;
		system("cls");
		line_Frame();
	}
	system("cls");
	line_Frame();
	
return head;
}


void correct_node(Link p) //修改数据 
{
	char temp1[20]={0},temp2[20]={0}; 
	gotoxy(	5,19);
	printf("请将刚才错误输入的数据重新输入确认:");
	gotoxy(5,20);
	scanf("%s",temp1);
	gotoxy(5,21);
	printf("请输入新的数据：");
	gotoxy(5,22);
	scanf("%s",temp2);
	if(strcmp(p->drive_License,temp1)==0){
		strcpy(p->drive_License,temp2);
	}
	
	if(strcmp(p->fine_Money,temp1)==0){
		strcpy(p->fine_Money,temp2);	
	}
	
	if(strcmp(p->plate_Number,temp1)==0){
		strcpy(p->plate_Number,temp2);		
	}
	
	if(strcmp(p->police_Code,temp1)==0){
		strcpy(p->police_Code,temp2);
	}
	
	if(strcmp(p->punish_Position,temp1)==0){
		strcpy(p->punish_Position,temp2);	
	}
	
	if(strcmp(p->punish_Time,temp1)==0){
		strcpy(p->punish_Time,temp2);	
	}
	
	if(strcmp(p->stata,temp1)==0){
		strcpy(p->stata,temp2);
	}
	
	gotoxy(5,23);
	printf("修改成功！");
	Sleep(1000); 	
}

void clear_List(Link head) //释放清除链表 
{
	Link p;
	while(head!=NULL) //若该指针没有数据，跳出if语句 
	{
		p=head;
		head=p->next;
		free(p); //释放内存 
	}
}
void gotoxy(int x,int y) //自定义光标函数 
{
	COORD pos; //光标显示位置 
	pos.X=x;  //光标横坐标 
	pos.Y=y;  //关闭纵坐标 
	HANDLE hOut; //定义句柄---对控制台程序的操作 
	hOut=GetStdHandle(STD_OUTPUT_HANDLE); //返回标准的输入、输出或错误的设备的句柄，也就是获得输入、输出/错误的屏幕缓冲区的句柄。STD_OUT_HANDLE---值 
	SetConsoleCursorPosition(hOut,pos);  //设置控制台光标的位置 
	
}
void color(const unsigned short color_Const) //const unsigned short 无符号短常量类型
/*用到了16进制的颜色符*/ 
{
	if(color_Const>=1&&color_Const<=15){ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_Const);
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//7为亮白色 
	}
	
}

void create_Menu() //制作菜单选项 
{
int flag=0;	
	int chose=1;
	Link txt_head=NULL; //不可省略，在clear_List()函数中有用到，如果本来没有申请内存而去释放，可能会出错，这里就写成指向空，保证不执行free()函数
	char temp[20];
	do{
		system("cls");line_Frame();		
		gotoxy(55,4); 
		printf("1.新增");
		gotoxy(65,4);
		printf("2.查找");
		gotoxy(75,4);
		printf("3.刷新/翻页"); 
		gotoxy(55,6);
		printf("4.删除");
		gotoxy(65,6);
		printf("5.存储");
		gotoxy(75,6);
		printf("6.退出！");
		gotoxy(55,8);
		printf("请选择：");
		gotoxy(65,8);
		if(chose<1||chose>9){
			system("cls");
			gotoxy(48,20);
			printf("系统错误,请勿输入非数字！");
			Sleep(2000);
			gotoxy(0,36); 
			exit(1);
		} 
		scanf("%d",&chose);		
		gotoxy(65,8);
		/*每个case都有一定的独立性：自己读取文件建立链表使用*/	
		switch(chose){
			case 1: clear_List(txt_head);txt_head=read_From_File();txt_head=insert_Node(txt_head);break;               //增加了链表的长度，链表仍存在                                        
			case 2: clear_List(txt_head);txt_head=read_From_File();query_Node(txt_head);break;                         //只查找内容，对链表无影响                                              
			case 3: clear_List(txt_head);txt_head=read_From_File();display_Node(txt_head);gotoxy(65,8);printf("5秒自动跳转...");Sleep(5000);break;                                              //将储存完毕的链表重新读取，达成更新的效果 
			case 4: clear_List(txt_head);txt_head=read_From_File();
					system("cls");line_Frame();display_Node(txt_head);gotoxy(55,5);printf("请输入车牌号:");
					gotoxy(68,5);scanf("%s",temp); 
					flag=delete_Node_pr1(txt_head,temp);
					if(flag==1){
					delete_Node_pr2(txt_head,temp);
					}
					break;                                                    //这部分需要读取链表 
			case 5:	Sleep(2000);write_To_File(txt_head);break;                                                               //储存链表到外部文件中 
			case 6: system("cls");gotoxy(45,16);printf("欢迎下次使用，再见！");clear_List(txt_head);gotoxy(0,36);exit(0);     
		  default : system("cls");Sleep(2000);gotoxy(48,20);printf("请输入有效数字");break;                                                            //为防止退出时而电脑，无法读                 
	}                                                                                                                         // 取到clear_List()函数,需要               
	}while(chose!=6);                                                                  //在这里加一个释放内存的函数
	
}

void write_To_File_pre(Link head) //将链表数据输入到文本中 
{
	FILE *fp=NULL;
	Link p=head->next;
	fp=fopen("fine_data.txt","w"); //以只写方式打开文件，若找不到该文件自动生成该文件 
	while(p!=NULL){
			fprintf(fp,"%s\t\t",p->plate_Number);
			fprintf(fp,"%s\t\t",p->drive_License);
			fprintf(fp,"%s\t\t",p->police_Code);
			fprintf(fp,"%s\t",p->punish_Position);
			fprintf(fp,"%s\t",p->punish_Time);
			fprintf(fp,"%s\t",p->fine_Money);
			fprintf(fp,"%s\t",p->stata);
			fputc('\n',fp);
			p=p->next;
	}

	gotoxy(0,35);
	printf("数据存储成功");
	Sleep(2000);	
	fclose(fp);	//记得使用文本指针结束后一定要关闭它 
}

Link read_From_File() //储存数据，也可视为保存  
{
	FILE *fp=NULL;
	Link head,node,p;
	char temp[20];
	head=(Link)malloc(sizeof(Node));//申请堆内存 （3） 
	head->next=NULL; //可省略，写上去更好 
	
	
	p=head;
	fp=fopen("fine_Data.txt","r");
	if(fp==NULL){
	gotoxy(45,16);
	printf("数据读取失败！(请确保文本fine_Data存在且有数据储存！)");	
    exit(1);
	}	
	
	while(fscanf(fp,"%s",temp)!=EOF){
		node=(Link)malloc(sizeof(Node)); //每次循环申请堆内存 （3） 
		node->next=NULL; //保证能读取到的情况下下一个指向空，避免系统错误 ----循环一次做一次 
		strcpy(node->plate_Number,temp);
		fscanf(fp,"%s",&(node->drive_License));
		fscanf(fp,"%s",&(node->police_Code));
		fscanf(fp,"%s",&(node->punish_Position));
		fscanf(fp,"%s",&(node->punish_Time));
		fscanf(fp,"%s",&(node->fine_Money));
		fscanf(fp,"%s",&(node->stata));
		p->next=node;            //链表输出跟输入的顺序一样 
		p=p->next;	 	
	}
	fclose(fp);//记得使用文本指针结束后一定要关闭它 
	return head;
}

int number_Trans(char code1[]) //数字字符转化为数字,左参数为字符串，右参数为数组
{
 	int code2[100]={0};
	int number=0;
	int count=0;
	int flag,a;
	int i;
	for(i=0;;i++){
		if(code1[i]!='\0'){
			count++;
		}
		else{
			break;
		}
	}
	flag=count;//提取count的值 
	for(i=0;i<count;i++){
		code2[i]=code1[i]-'0';
	}
	//printf("这是一个%d位的数字字符",count);
	for(i=0;i<flag;i++){
		count=count-1;
		power(count,10,a);
		number=number+code2[i]*a;
	}
	
return number;
}

int power(int n,int x,int &ra) //构建"x"的"n"次方
{
	int i=0;
	int t=1;
	if(n==0){
		ra=1;
	}
	else{
		for(i=0;i<n;i++){
		t=t*x;
		}
		ra=t;
	}	
}

void query_Node(Link head) //查找数据 
{
	Link p=head->next;
	char Plate[20],Licence[20],Code[20],Position[20],Time[20],Money[20],State[20]; 
	int chose=1;
	int y;//作为7种查找内容的显示纵坐标 
	int flag;//作为判断依据变量 
	do{
			system("cls");line_Frame();query_Frame(); //构造查找界面框架 
			flag=0;
			gotoxy(55,12);
			printf("请选择：");
			gotoxy(63,12);
			if(chose<1||chose>10){
				system("cls");				
				gotoxy(48,20);
				printf("系统错误,请勿输入非数字！");
				Sleep(2000);
				gotoxy(0,36);
				clear_List(head); 
				exit(1); 
			}
			scanf("%d",&chose);			
			switch(chose){ 
				case 1: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("请输入车牌号：");gotoxy(69,5);scanf("%s",Plate);
						y=5;
						/*这里的while循环有一个车牌号码多次违规的功能，并将所有数据陈列出来*/
						system("cls");IQDW_Line_Frame();//新增、查找、删除、储存界面 
 						query_Print_Frame();
						p=head->next;
						while(p!=NULL){						
							if(strcmp(p->plate_Number,Plate)==0){   //----------------------------------选择入口（1） 
								flag=1;								
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}
						
						if(flag==0){                                //-----------------------------------选择入口（2） 
							system("cls");
							gotoxy(35,16);
							printf("不存在该车牌号或你的输入有误！");
							Sleep(2000);
							break;							 
						}
						gotoxy(55,36);
						printf("系统操作：10秒后自动跳转...");
						Sleep(10000);
						
						break; 
									
				case 2: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("请输入驾驶证号：");;gotoxy(72,5);scanf("%s",Licence);
						y=5;
						/*这里的while循环有一个驾驶证号多次违规的功能，并将所有数据陈列出来*/
						system("cls");IQDW_Line_Frame();//新增、查找、删除、储存界面 
 						query_Print_Frame();						
						p=head->next;
						while(p!=NULL){						
							if(strcmp(p->drive_License,Licence)==0){   //----------------------------------选择入口（1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}
						
						if(flag==0){                                //-----------------------------------选择入口（2)
							system("cls");
							gotoxy(35,16);
							printf("不存在该驾驶证号或你的输入有误！");
							Sleep(2000);
							break;							 
						}
						gotoxy(55,36);
						printf("系统操作：10秒后自动跳转...");
						Sleep(10000);
						break; 					
																				
				case 3: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("请输入交警代号：");;gotoxy(72,5);scanf("%s",Code);
						y=5;
						/*这里的while循环有一个交警代号多次违规的功能，并将所有数据陈列出来*/
						system("cls");IQDW_Line_Frame();//新增、查找、删除、储存界面 
 						query_Print_Frame();
						p=head->next;
						while(p!=NULL){
							if(strcmp(p->police_Code,Code)==0){   //----------------------------------选择入口（1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------选择入口（2)
							system("cls");	
							gotoxy(35,16);
							printf("不存在该交警代号或你的输入有误！");
							Sleep(2000);
							break;
						}
						gotoxy(55,36);
						printf("系统操作：10秒后自动跳转...");
						Sleep(10000);
						break; 						
																									
				case 4: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("请输入违章地点：");;gotoxy(72,5);scanf("%s",Position);
						y=5;
						/*这里的while循环有一个违章地点多次违规的功能，并将所有数据陈列出来*/
						system("cls");IQDW_Line_Frame();//新增、查找、删除、储存界面 
 						query_Print_Frame();
						p=head->next;				
						while(p!=NULL){
							if(strcmp(p->punish_Position,Position)==0){   //----------------------------------选择入口（1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------选择入口（2)
							system("cls");
							gotoxy(35,16);
							printf("不存在该违章地点或你的输入有误！");
							Sleep(2000);
							break;
						}
						gotoxy(55,36);
						printf("系统操作：10秒后自动跳转...");
						Sleep(10000);
						break; 					
																									
				case 5: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("请输入违章时间");;gotoxy(72,5);scanf("%s",Time);
						y=5;
						/*这里的while循环有一个违章时间多次违规的功能，并将所有数据陈列出来*/
						system("cls");IQDW_Line_Frame();//新增、查找、删除、储存界面 
 						query_Print_Frame();	
						p=head->next;					
						while(p!=NULL){
							if(strcmp(p->punish_Time,Time)==0){   //----------------------------------选择入口（1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------选择入口（2)
							system("cls");	
							gotoxy(35,16);
							printf("不存在该违章时间或你的输入有误！");
							Sleep(2000);
							break;							
						}
						gotoxy(55,36);
						printf("系统操作：10秒后自动跳转...");
						Sleep(10000);
						break;					
																													
				case 6: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("请输入罚款金额");;gotoxy(72,5);scanf("%s",Money);
						y=5;
						/*这里的while循环有一个罚款金额多次违规的功能，并将所有数据陈列出来*/
						system("cls");IQDW_Line_Frame();//新增、查找、删除、储存界面 
 						query_Print_Frame();		
						p=head->next;				
						while(p!=NULL){
							if(strcmp(p->fine_Money,Money)==0){   //----------------------------------选择入口（1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------选择入口（2)
							system("cls");
							gotoxy(35,16);
							printf("不存在该罚款金额或你的输入有误！");
							Sleep(2000);
							break;							
						}
						gotoxy(55,36);
						printf("系统操作：10秒后自动跳转...");
						Sleep(10000);
						break; 					
																				
				case 7: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("请输入缴费状态");;gotoxy(72,5);scanf("%s",State);
						y=5;
						/*这里的while循环有一个缴费状态多次违规的功能，并将所有数据陈列出来*/
						system("cls");IQDW_Line_Frame();//新增、查找、删除、储存界面 
 						query_Print_Frame();	
						p=head->next;					
						while(p!=NULL){
							if(strcmp(p->stata,State)==0){   //----------------------------------选择入口（1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------选择入口（2)
							system("cls");
							gotoxy(35,16);
							printf("不存在该罚款状态或你的输入有误！");
							Sleep(2000);
							break;							
						}
						gotoxy(55,36);
						printf("系统操作：10秒后自动跳转...");
						Sleep(10000);
						break; 					
															
				case 8: system("cls");gotoxy(45,16);printf("即将退回主菜单");Sleep(1000);break;
					
					
					
			  default :gotoxy(0,3);printf("输入有误！请重新输入....");Sleep(1000);break;
			} 
	}while(chose!=8);		
}

void query_Frame() //构造查找界面框架 
{
	gotoxy(55,4);
	printf("请选择哪种方式查找:");
	gotoxy(55,6);
	printf("1.车牌号");
	gotoxy(68,6);
	printf("2.驾驶证号");
	gotoxy(81,6);
	printf("3.交警代号");
	gotoxy(55,8);
	printf("4.违章地点"); 
	gotoxy(68,8);
	printf("5.违章时间"); 
	gotoxy(81,8);
	printf("6.罚款金额");
	gotoxy(55,10);
	printf("7.缴费状态");
	gotoxy(68,10);
	printf("8.退回主菜单");
}

void IQDW_Line_Frame()//新增、查找、删除、储存界面 
{
	for(i=0;i<100;i++){
		gotoxy(i,2);
		printf("-");
		gotoxy(i,35);
		printf("-");
	}
	gotoxy(16,1);printf("*新增*"); 
	gotoxy(32,1);printf("*查找*"); 
	gotoxy(48,1);printf("*删除*"); 
	gotoxy(64,1);printf("*储存*"); 
}

void write_To_File(Link head) //将链表数据写入文本  
{	
	if(head==NULL){
		system("cls");
		gotoxy(42,16);
		printf("无数据可存储");
		Sleep(1500);
		return;
	}
	FILE *fp=NULL;
	Link p=head->next;
	fp=fopen("fine_data.txt","r"); //先以只读方式判断文件是否破坏
	if(fp==NULL){
	system("cls");
	gotoxy(45,16);
	printf("文件fine_data.txt找不到，可能被删除");
	clear_List(head);
	gotoxy(0,36);
	exit(1);
	 }
	fclose(fp);//关闭文件
	fp=fopen("fine_data.txt","w");//再已只写方式打开，若被破坏则重建文件，若存在该文件 
	while(p!=NULL){
		
	    fprintf(fp,"\t\t%s",p->plate_Number);
		fprintf(fp,"\t\t%s",p->drive_License);
		fprintf(fp,"\t\t%s",p->police_Code); 
	    fprintf(fp,"\t\t%s",p->punish_Position);
        fprintf(fp,"\t\t%s",p->punish_Time);
	    fprintf(fp,"\t\t%s",p->fine_Money);
	    fprintf(fp,"\t\t%s",p->stata);
	    fputc('\n',fp);
	    p=p->next;
	}	  	 
	gotoxy(0,36);
	printf("数据存储成功");
	Sleep(2000);	
	fclose(fp);	//记得使用文本指针结束后一定要关闭它 
}

Link insert_Node(Link head) //新增罚款数据 
{
	Link node;
	int chose=1;
	int y=5;	
	do{
		system("cls");IQDW_Line_Frame();
		gotoxy(0,3);printf("车牌号码");					
		gotoxy(14,3);printf("驾驶证号");					
		gotoxy(33,3);printf("交警代号");						
		gotoxy(47,3);printf("罚款地点");						
		gotoxy(61,3);printf("罚款时间");						
		gotoxy(75,3);printf("罚款金额");						
		gotoxy(84,3);printf("罚款状态");
		node=(Link)malloc(sizeof(Node));
		node->next=NULL;		
		gotoxy(0,y);scanf("%s",node->plate_Number);																								
		gotoxy(14,y);scanf("%s",node->drive_License);																
		gotoxy(33,y);scanf("%s",node->police_Code);																
		gotoxy(47,y);scanf("%s",node->punish_Position);																
		gotoxy(61,y);scanf("%s",node->punish_Time);														
		gotoxy(75,y);scanf("%s",node->fine_Money);															
		gotoxy(84,y);scanf("%s",node->stata);
		y++;
		node->next=head->next; //将新增的结构体置于链表首位，再将头结点重新指向该结构体
		head->next=node;
		gotoxy(45,16);
		printf("1.结束 2.继续");
		gotoxy(40,21);
		printf("按其他键默认结束");
		gotoxy(45,22);
		printf("请选择："); 
		gotoxy(53,22);
		scanf("%d",&chose);
	}while(chose==2);
	system("cls");
	gotoxy(35,16);
	color(4);printf("新增数据后请回退保存，否则新增数据默认无效");color(7); 
	Sleep(1500);
	return head;	
}

int delete_Node_pr1(Link head,char x[])//x为字符串 
{
    int count=0,flag=0;
    Link p,q;
    int y=5;
	if(head==NULL||head->next==NULL)
	{
		return 0;
	}
	p=head->next;
	q=head;
	system("cls");
	IQDW_Line_Frame();//新增、查找、删除、储存界面 
	gotoxy(0,3);printf("车牌号码");					
	gotoxy(14,3);printf("驾驶证号");					
	gotoxy(28,3);printf("交警代号");						
	gotoxy(42,3);printf("罚款地点");						
	gotoxy(56,3);printf("罚款时间");						
	gotoxy(70,3);printf("罚款金额");						
	gotoxy(84,3);printf("罚款状态");	
	while(p!=NULL)
	{			
		if(strcmp(p->plate_Number,x)==0)
		{
			flag=1;
			count++;
			gotoxy(97,y);printf("%d",count);
			gotoxy(0,y);printf("%s",p->plate_Number);																								
			gotoxy(14,y);printf("%s",p->drive_License);																
			gotoxy(28,y);printf("%s",p->police_Code);																
			gotoxy(42,y);printf("%s",p->punish_Position);																
			gotoxy(56,y);printf("%s",p->punish_Time);																
			gotoxy(70,y);printf("%s",p->fine_Money);																
			gotoxy(84,y);printf("%s",p->stata);
			y++;
		}				
    	q=p;
	    p=p->next;			
	}
	if(flag==1)
	{
		return flag;
	}
	system("cls");
	gotoxy(45,16);
	printf("不存在！");	
	Sleep(1000);
}
void delete_Node_pr2(Link head,char x[])
{
	int count=0,select;
	Link p,q;
	if(head==NULL||head->next==NULL)
	{
		return ;
	}
	p=head->next;
	q=head;
	gotoxy(56,36);
	printf("请选择删除项：");
	gotoxy(70,36);
	scanf("%d",&select);
	while(p!=NULL)
	{
		if(strcmp(p->plate_Number,x)==0){
		
			count++;
			if(select==count){
			system("cls");
			gotoxy(48,16);
			printf("%d:%s 已删除",count,p->plate_Number);
			q->next=p->next;
			free(p);															
			Sleep(2000);
			system("cls");
			gotoxy(35,16);
			color(4);printf("新增数据后请回退保存，否则删除数据默认无效");color(7); 
			Sleep(1500);
			return ;
			}
		}
		q=p;
		p=p->next; 
	}
	system("cls");
	gotoxy(45,16);
	printf("删除失败！");
	Sleep(1000);
	return ; 
}

void page()//数据翻找模块 
{
	typedef struct page
	{
	 char data_Plate[20];
	 char data_Money[20];
	} PAGE; 
	PAGE page1[15],page2[15],page3[15],page4[15],page5[15];
	int count=0,chose=1,x=0,y=5;
	char ch;
	FILE *fp;
	fp=fopen("display_Data.txt","r");
	if(fp==NULL){
	printf("文件打开失败！");
	return; 
	}
	fclose(fp);
	gotoxy(48,36);printf("第 页(目前最多共5页)");
	gotoxy(50,36);scanf("%d",&chose);
	switch(chose){	
	case 1: gotoxy(48,36);printf("第1页");count=0;
			fp=fopen("display_Data.txt","r");
		    	x=0,y=5;
		    	if(1){
		    		for(i=0;i<15&&fscanf(fp,"%s",page1[i].data_Plate)!=EOF;i++){		 	        
		 	        fscanf(fp,"%s",page1[i].data_Money);
			        gotoxy(x,y);
					printf("车牌号：%s",page1[i].data_Plate);
		 	        printf("\t罚款金额：%s",page1[i].data_Money);
					y+=2; 											
		            }
					fclose(fp);   	            
	       		    break;		            
				}
		    		gotoxy(0,5);
	      			printf("无数据");						
					fclose(fp);   	            
			        break;
	case 2:gotoxy(48,36);printf("第2页");count=0;
		   fp=fopen("display_Data.txt","r");
		   ch=fgetc(fp);
	       while(fgetc(fp)!=EOF){
			    ch=fgetc(fp);	  		        	
		        if(fgetc(fp)=='\n'||ch=='\n'){	        	
			    	count++;
			    }
			    if(count==15){
			    	break;
				}
			    }
			    if(count==15){
			    	x=0,y=5;
			    	for(i=0;i<15&&!feof(fp);i++){
		            fscanf(fp,"%s",page2[i].data_Plate);
		         	fscanf(fp,"%s",page2[i].data_Money);
		         	gotoxy(x,y);
					printf("车牌号：%s",page2[i].data_Plate);
		 	        printf("\t罚款金额：%s",page2[i].data_Money);
				    y+=2;	 											
		            }
		            fclose(fp);
		            break;
				}
		        gotoxy(0,5);
		        printf("无数据");
		        fclose(fp);
				break; 
	 		 		
	            
	 
    case 3:gotoxy(48,36);printf("第3页");count=0;
		   fp=fopen("display_Data.txt","r");
		   ch=fgetc(fp);
	       while(fgetc(fp)!=EOF){
			    ch=fgetc(fp);	  		        	
		        if(fgetc(fp)=='\n'||ch=='\n'){	        	
			    	count++;
			    }
			    if(count==30){
			    	break;
				}
			    }
	    	    if(count==30){
	    	    	x=0,y=5;
	    	    	for(i=0;i<15&&!feof(fp);i++){
		            fscanf(fp,"%s",page3[i].data_Plate);
	             	fscanf(fp,"%s",page3[i].data_Money);
	             	gotoxy(x,y);
					printf("车牌号：%s",page3[i].data_Plate);
	 	  		    printf("\t罚款金额：%s",page3[i].data_Money);
					y+=2;   	 											
		            }
		            fclose(fp);
		            break;
				}
	            gotoxy(0,5);
	            printf("无数据");
	            fclose(fp);
				break;
	case 4:gotoxy(48,36);printf("第4页");count=0;
		   fp=fopen("display_Data.txt","r");
		   ch=fgetc(fp);
	       while(fgetc(fp)!=EOF){
			    ch=fgetc(fp);	  		        	
		        if(fgetc(fp)=='\n'||ch=='\n'){	        	
			    	count++;
			    }
			    if(count==45){
			    	break;
				}
			    }
	    	    if(count==45){
	    	    	x=0,y=5;
	    	    	for(i=0;i<15&&!feof(fp);i++){
		            fscanf(fp,"%s",page2[i].data_Plate);
	             	fscanf(fp,"%s",page2[i].data_Money);
	             	gotoxy(x,y);
				    printf("车牌号：%s",page4[i].data_Plate);
	 	        	printf("\t罚款金额：%s",page4[i].data_Money);
					y+=2; 	 											
		            }
		            fclose(fp);
		            break;
				}
	            gotoxy(0,5);
	            printf("无数据");
	            fclose(fp);
				break;
	case 5:gotoxy(48,36);printf("第5页");count=0;
		   fp=fopen("display_Data.txt","r");
		   ch=fgetc(fp);
	       while(fgetc(fp)!=EOF){
			    ch=fgetc(fp);	  		        	
		        if(fgetc(fp)=='\n'||ch=='\n'){	        	
			    	count++;
			    }
			    if(count==60){
			    	break;
				}
			    }
	    	    if(count==60){
	    	    	x=0,y=5;
	    	    	for(i=0;i<15&&!feof(fp);i++){
		            fscanf(fp,"%s",page2[i].data_Plate);
	             	fscanf(fp,"%s",page2[i].data_Money);
	             	gotoxy(x,y);
			     	printf("车牌号：%s",page5[i].data_Plate);
	 	      	    printf("\t罚款金额：%s",page5[i].data_Money);
					y+=2;   	 											
		            }
		            fclose(fp);
		            break;
				}
	            gotoxy(0,5);
	            printf("无数据");
	            fclose(fp);
				break;
	default :printf("输入有误！");break;			
	}
}

void query_Print_Frame()
{
	gotoxy(0,3);printf("车牌号码");					
	gotoxy(14,3);printf("驾驶证号");					
	gotoxy(28,3);printf("交警代号");						
	gotoxy(42,3);printf("罚款地点");						
	gotoxy(56,3);printf("罚款时间");						
	gotoxy(70,3);printf("罚款金额");						
	gotoxy(84,3);printf("罚款状态");
}
void query_Print_Data(int y,Link p)
{
			gotoxy(0,y);printf("%s",p->plate_Number);																								
			gotoxy(14,y);printf("%s",p->drive_License);																
			gotoxy(28,y);printf("%s",p->police_Code);																
			gotoxy(42,y);printf("%s",p->punish_Position);																
			gotoxy(56,y);printf("%s",p->punish_Time);																
			gotoxy(70,y);printf("%s",p->fine_Money);																
			gotoxy(84,y);printf("%s",p->stata);
}
 
