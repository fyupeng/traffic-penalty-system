 #include<stdio.h>
#include<stdlib.h>
#include<windows.h> 
typedef struct traffic_Fine //�����µ������������������� 
{
	char plate_Number[20];     //���ƺ� 
	char drive_License[20];    //��ʻ֤��
	char police_Code[20];      //��������
	char punish_Position[20];  //Υ�µص�
	char punish_Time[20];      //Υ��ʱ�� 
	char fine_Money[20];       //������ 
	char stata[20];            //�ɷ�״̬ 
    struct traffic_Fine *next; //�ṹ��ָ��ָ����һ���ṹ�� 
    struct traffic_Fine *ahead; //�ṹ��ָ��ָ����һ���ṹ�� 
} Node,*Link;
int i,j,k;
int find_data(); //�������ݣ��������½����ݣ��������� 
void select_Line(int flag); //������ѡ���� 
void welcom_Frame_pr1(); //��ӭ���� 
void welcom_Frame_pr2(); //��ӭ���� 
void line_Frame(); //����������
Link create_list(); //�������� 
void display_Node(Link head); //�����������  
void correct_node(Link p); //�޸�����
void clear_List(Link head);//�ͷ�������� 
void gotoxy(int x,int y); //�Զ����꺯��
void color(const unsigned short color_Const);//const unsigned short �޷��Ŷ��ͳ�������
void create_Menu(); //�����˵�ѡ�� 
void write_To_File_pre(Link head);//�½�ʱ�Ĵ洢 
Link read_From_File(); //�������ݣ�Ҳ����Ϊ���� 
int number_Trans(char code1[]);//�����ַ�ת��Ϊ����
int power(int n,int x,int &ra); //����"x"��"n"�η�
void query_Node(Link head); //���ҷ�������
void query_Frame();//������ҽ����� 
void IQDW_Line_Frame();//���������ҡ�ɾ����������� 
void write_To_File(Link head); //�������������뵽�ı��� 
Link insert_Node(Link head); //������������ 
int delete_Node_pr1(Link head,char x[]);//xΪ�ַ���
void delete_Node_pr2(Link head,char x[]);
void page();//���ݷ���ģ�� 
void query_Print_Frame();
void query_Print_Data(int y,Link p); 
int main()
{
	int flag; //����һ����������������find_data()�����н���ѡ���ٷ�����ֵ��select_Line��flag��ִ�в�ͬ����� 
	flag=find_data();
	select_Line(flag);  //���е����˸��ֺ������䵱������ 
	gotoxy(0,36);
	return 0;
}

int find_data() //�������ݣ����������½����ݣ���������
{
	int flag=0;
	FILE *fp=NULL;
	fp=fopen("fine_data.txt","r");
	if(fp==NULL){
		gotoxy(15,10);
		printf("�����ݣ�����ӷ���������ݣ�����Ϊ����ת...");
		Sleep(2000);
		flag=1;//��д����������£�ѡ����ѡ��1 
	}
	else{
		gotoxy(20,10);
		printf("�ϴ������ݱ��棬����Ϊ���ȡ��...");
		Sleep(2000); 
		flag=2; // д����������£�ѡ����ѡ��2 
	}
	if(flag==0){
		gotoxy(25,10);
		printf("ϵͳ����");
		fclose(fp);  //�����ȥҲҪ���ı�ָ��ر�
		exit(1);
	}
	fclose(fp);  //��ȷ��ʽҪ���ı�ָ��ر� 
return flag;  //����flagֵ 
} 

void select_Line(int flag)  //������ѡ���� 
{
	Link head=NULL;
	if(flag==1){ //��д����������£�ѡ����ѡ��1
		welcom_Frame_pr1();
	    line_Frame();	
		head=create_list();//��ȡ����
		display_Node(head);		
		write_To_File_pre(head); //�½�ʱ�Ĵ洢 
		clear_List(head);//���ڴ棨1������2���ͷ�  
		system("cls");
		gotoxy(45,16);
		printf("���ݴ洢��ϣ�������ϵͳ");
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
	    head=read_From_File();//��ȡ����
	    gotoxy(10,12);
//	    display_Node(head);
		clear_List(head);
		create_Menu();
		clear_List(head);//���ڴ棨1������2���ͷ� 
		 
	}
}

void line_Frame() //����������
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
	printf("ִ����");
	gotoxy(70,1);
	printf("ѡ����");
	

}

void welcom_Frame_pr1() //��ӭ���� 
{		
		for(i=0;i<1;i++){  //ͨ��i����ѭ�����������ƿ������涯�������ȴ�ʱ�� 
		welcom_Frame_pr2();
		Sleep(150);color(8);gotoxy(40,20);printf("��");
		Sleep(150);color(8);gotoxy(42,20);printf("ӭ");
		Sleep(150);color(8);gotoxy(44,20);printf("��"); 
		Sleep(150);color(8);gotoxy(46,20);printf("��"); 
		Sleep(150);color(8);gotoxy(48,20);printf("��"); 
		Sleep(150);color(8);gotoxy(50,20);printf("ͨ");
		Sleep(150);color(8);gotoxy(52,20);printf("��");
		Sleep(150);color(8);gotoxy(54,20);printf("��");
		Sleep(150);color(8);gotoxy(56,20);printf("ϵ");
		Sleep(150);color(8);gotoxy(57,20);printf("ͳ");welcom_Frame_pr2(); 
	}
	system("cls"); 
}

void welcom_Frame_pr2() //��ӭ����
{
		system("mode con cols=100 lines=40"); //����CMD���ڳ�ʼ��С 
		color(16);
		gotoxy(40,20);
		printf("��");
		gotoxy(42,20);
		printf("ӭ");
		gotoxy(44,20);
		printf("��"); 
		gotoxy(46,20);
		printf("��"); 
		gotoxy(48,20);
		printf("��"); 
		gotoxy(50,20);
		printf("ͨ"); 
		gotoxy(52,20);
		printf("��"); 
		gotoxy(54,20);
		printf("��"); 
		gotoxy(56,20);
		printf("ϵ"); 
		gotoxy(58,20);
		printf("ͳ");
}



void display_Node(Link head)
{
	if(head==NULL){
		return;
	}
	typedef struct temp_Plate{ //������ֵ���ƺŸ�temp_Plate[i] 
		char plate[20];
	} inNode;
	Link p;
	int count=0;
	int temp_Money[50]={0};//������ֵ�������temp_Money[i]----������ 
	inNode temp_Plate[50];//��ų�Աplate_Number��ֵ-----�ַ����� 
	int temp1;        //�����ֵ�õ��м����
	char temp2[20];        //�����ֵ�õ��м����
	p=head->next;         //ָ���ʼ�� 
	while(p!=NULL){
		count++;
		p=p->next;
	}
	p=head->next;//ָ���ʼ�� 
	for(i=0;i<count;i++){
		temp_Money[i]=number_Trans(p->fine_Money);
		p=p->next; 
	}
	p=head->next;//ָ���ʼ�� 
	for(i=0;i<count;i++){
		strcpy(temp_Plate[i].plate,p->plate_Number);
		p=p->next;
	}
	
	for(int j=0;j<count-1;j++){           //�����Ӵ�С���� 
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
	fp=fopen("display_Data.txt","w");//���ļ��Լ���������ļ����� 
	fclose(fp);
	fp=fopen("display_Data.txt","a");//�������������д���ļ� 
	for(i=0;i<count;i++){		
		fprintf(fp,"\t%s",temp_Plate[i].plate);
		fprintf(fp,"\t%d",temp_Money[i]);
		fputc('\n',fp);
	}
	fclose(fp);
	page();//���ݷ���ģ�� 
}

Link create_list()
{
	int select_CL=1;
	int select_PS=1;
	Link head,p;
	head=(Link)malloc(sizeof(Node)); //������ڴ棨2��-----���ͷ�
	head->next=NULL;
	p=head;
	while(select_CL==1){
		Link node;
		node=(Link)malloc(sizeof(Node)); //������ڴ�(1)-----���ͷ� 				
		gotoxy(5,3);
		printf("�����복�ƺţ�M5**4��");
		gotoxy(5,4);
		scanf("%s",&(node->plate_Number));
		gotoxy(5,5);
		printf("�������ʻ֤�ţ�13*****7��");
		gotoxy(5,6);
		scanf("%s",&(node->drive_License));
		gotoxy(5,7);
		printf("�����뽻�����ţ�K****0��");
		gotoxy(5,8);
		scanf("%s",&(node->police_Code));
		gotoxy(5,9);
		printf("������Υ�µص㣨տ����");
		gotoxy(5,10);
		scanf("%s",&(node->punish_Position));
		gotoxy(5,11);
		printf("������Υ��ʱ�䣨12��00��");
		gotoxy(5,12);
		scanf("%s",&(node->punish_Time));
		gotoxy(5,13);
		printf("�����뷣���120��");
		gotoxy(5,14);
		scanf("%s",&(node->fine_Money));
		gotoxy(5,15);
		printf("������ɷ�״̬����/δ�ɷѣ�");
		gotoxy(5,16);
		scanf("%s",&(node->stata));
		
		gotoxy(5,17);
		printf("ȷ�������밴1�����޸İ�2(��������Ĭ��ȷ��)");
		gotoxy(5,18);
		scanf("%d",&select_PS);
		if(select_PS==2){
			correct_node(node);
		}
		if(select_PS!=2){
			gotoxy(5,19);
			printf("���������밴1�������밴0(���������ּ�Ĭ�Ͻ���)");
			gotoxy(5,20); 
			scanf("%d",&select_CL);
		}
		if(select_PS==2){
			gotoxy(5,24);
			printf("���������밴1�������밴0(���������ּ���Ĭ�Ͻ���)");
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


void correct_node(Link p) //�޸����� 
{
	char temp1[20]={0},temp2[20]={0}; 
	gotoxy(	5,19);
	printf("�뽫�ղŴ��������������������ȷ��:");
	gotoxy(5,20);
	scanf("%s",temp1);
	gotoxy(5,21);
	printf("�������µ����ݣ�");
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
	printf("�޸ĳɹ���");
	Sleep(1000); 	
}

void clear_List(Link head) //�ͷ�������� 
{
	Link p;
	while(head!=NULL) //����ָ��û�����ݣ�����if��� 
	{
		p=head;
		head=p->next;
		free(p); //�ͷ��ڴ� 
	}
}
void gotoxy(int x,int y) //�Զ����꺯�� 
{
	COORD pos; //�����ʾλ�� 
	pos.X=x;  //�������� 
	pos.Y=y;  //�ر������� 
	HANDLE hOut; //������---�Կ���̨����Ĳ��� 
	hOut=GetStdHandle(STD_OUTPUT_HANDLE); //���ر�׼�����롢����������豸�ľ����Ҳ���ǻ�����롢���/�������Ļ�������ľ����STD_OUT_HANDLE---ֵ 
	SetConsoleCursorPosition(hOut,pos);  //���ÿ���̨����λ�� 
	
}
void color(const unsigned short color_Const) //const unsigned short �޷��Ŷ̳�������
/*�õ���16���Ƶ���ɫ��*/ 
{
	if(color_Const>=1&&color_Const<=15){ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_Const);
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);//7Ϊ����ɫ 
	}
	
}

void create_Menu() //�����˵�ѡ�� 
{
int flag=0;	
	int chose=1;
	Link txt_head=NULL; //����ʡ�ԣ���clear_List()���������õ����������û�������ڴ��ȥ�ͷţ����ܻ���������д��ָ��գ���֤��ִ��free()����
	char temp[20];
	do{
		system("cls");line_Frame();		
		gotoxy(55,4); 
		printf("1.����");
		gotoxy(65,4);
		printf("2.����");
		gotoxy(75,4);
		printf("3.ˢ��/��ҳ"); 
		gotoxy(55,6);
		printf("4.ɾ��");
		gotoxy(65,6);
		printf("5.�洢");
		gotoxy(75,6);
		printf("6.�˳���");
		gotoxy(55,8);
		printf("��ѡ��");
		gotoxy(65,8);
		if(chose<1||chose>9){
			system("cls");
			gotoxy(48,20);
			printf("ϵͳ����,������������֣�");
			Sleep(2000);
			gotoxy(0,36); 
			exit(1);
		} 
		scanf("%d",&chose);		
		gotoxy(65,8);
		/*ÿ��case����һ���Ķ����ԣ��Լ���ȡ�ļ���������ʹ��*/	
		switch(chose){
			case 1: clear_List(txt_head);txt_head=read_From_File();txt_head=insert_Node(txt_head);break;               //����������ĳ��ȣ������Դ���                                        
			case 2: clear_List(txt_head);txt_head=read_From_File();query_Node(txt_head);break;                         //ֻ�������ݣ���������Ӱ��                                              
			case 3: clear_List(txt_head);txt_head=read_From_File();display_Node(txt_head);gotoxy(65,8);printf("5���Զ���ת...");Sleep(5000);break;                                              //��������ϵ��������¶�ȡ����ɸ��µ�Ч�� 
			case 4: clear_List(txt_head);txt_head=read_From_File();
					system("cls");line_Frame();display_Node(txt_head);gotoxy(55,5);printf("�����복�ƺ�:");
					gotoxy(68,5);scanf("%s",temp); 
					flag=delete_Node_pr1(txt_head,temp);
					if(flag==1){
					delete_Node_pr2(txt_head,temp);
					}
					break;                                                    //�ⲿ����Ҫ��ȡ���� 
			case 5:	Sleep(2000);write_To_File(txt_head);break;                                                               //���������ⲿ�ļ��� 
			case 6: system("cls");gotoxy(45,16);printf("��ӭ�´�ʹ�ã��ټ���");clear_List(txt_head);gotoxy(0,36);exit(0);     
		  default : system("cls");Sleep(2000);gotoxy(48,20);printf("��������Ч����");break;                                                            //Ϊ��ֹ�˳�ʱ�����ԣ��޷���                 
	}                                                                                                                         // ȡ��clear_List()����,��Ҫ               
	}while(chose!=6);                                                                  //�������һ���ͷ��ڴ�ĺ���
	
}

void write_To_File_pre(Link head) //�������������뵽�ı��� 
{
	FILE *fp=NULL;
	Link p=head->next;
	fp=fopen("fine_data.txt","w"); //��ֻд��ʽ���ļ������Ҳ������ļ��Զ����ɸ��ļ� 
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
	printf("���ݴ洢�ɹ�");
	Sleep(2000);	
	fclose(fp);	//�ǵ�ʹ���ı�ָ�������һ��Ҫ�ر��� 
}

Link read_From_File() //�������ݣ�Ҳ����Ϊ����  
{
	FILE *fp=NULL;
	Link head,node,p;
	char temp[20];
	head=(Link)malloc(sizeof(Node));//������ڴ� ��3�� 
	head->next=NULL; //��ʡ�ԣ�д��ȥ���� 
	
	
	p=head;
	fp=fopen("fine_Data.txt","r");
	if(fp==NULL){
	gotoxy(45,16);
	printf("���ݶ�ȡʧ�ܣ�(��ȷ���ı�fine_Data�����������ݴ��棡)");	
    exit(1);
	}	
	
	while(fscanf(fp,"%s",temp)!=EOF){
		node=(Link)malloc(sizeof(Node)); //ÿ��ѭ��������ڴ� ��3�� 
		node->next=NULL; //��֤�ܶ�ȡ�����������һ��ָ��գ�����ϵͳ���� ----ѭ��һ����һ�� 
		strcpy(node->plate_Number,temp);
		fscanf(fp,"%s",&(node->drive_License));
		fscanf(fp,"%s",&(node->police_Code));
		fscanf(fp,"%s",&(node->punish_Position));
		fscanf(fp,"%s",&(node->punish_Time));
		fscanf(fp,"%s",&(node->fine_Money));
		fscanf(fp,"%s",&(node->stata));
		p->next=node;            //��������������˳��һ�� 
		p=p->next;	 	
	}
	fclose(fp);//�ǵ�ʹ���ı�ָ�������һ��Ҫ�ر��� 
	return head;
}

int number_Trans(char code1[]) //�����ַ�ת��Ϊ����,�����Ϊ�ַ������Ҳ���Ϊ����
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
	flag=count;//��ȡcount��ֵ 
	for(i=0;i<count;i++){
		code2[i]=code1[i]-'0';
	}
	//printf("����һ��%dλ�������ַ�",count);
	for(i=0;i<flag;i++){
		count=count-1;
		power(count,10,a);
		number=number+code2[i]*a;
	}
	
return number;
}

int power(int n,int x,int &ra) //����"x"��"n"�η�
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

void query_Node(Link head) //�������� 
{
	Link p=head->next;
	char Plate[20],Licence[20],Code[20],Position[20],Time[20],Money[20],State[20]; 
	int chose=1;
	int y;//��Ϊ7�ֲ������ݵ���ʾ������ 
	int flag;//��Ϊ�ж����ݱ��� 
	do{
			system("cls");line_Frame();query_Frame(); //������ҽ����� 
			flag=0;
			gotoxy(55,12);
			printf("��ѡ��");
			gotoxy(63,12);
			if(chose<1||chose>10){
				system("cls");				
				gotoxy(48,20);
				printf("ϵͳ����,������������֣�");
				Sleep(2000);
				gotoxy(0,36);
				clear_List(head); 
				exit(1); 
			}
			scanf("%d",&chose);			
			switch(chose){ 
				case 1: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("�����복�ƺţ�");gotoxy(69,5);scanf("%s",Plate);
						y=5;
						/*�����whileѭ����һ�����ƺ�����Υ��Ĺ��ܣ������������ݳ��г���*/
						system("cls");IQDW_Line_Frame();//���������ҡ�ɾ����������� 
 						query_Print_Frame();
						p=head->next;
						while(p!=NULL){						
							if(strcmp(p->plate_Number,Plate)==0){   //----------------------------------ѡ����ڣ�1�� 
								flag=1;								
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}
						
						if(flag==0){                                //-----------------------------------ѡ����ڣ�2�� 
							system("cls");
							gotoxy(35,16);
							printf("�����ڸó��ƺŻ������������");
							Sleep(2000);
							break;							 
						}
						gotoxy(55,36);
						printf("ϵͳ������10����Զ���ת...");
						Sleep(10000);
						
						break; 
									
				case 2: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("�������ʻ֤�ţ�");;gotoxy(72,5);scanf("%s",Licence);
						y=5;
						/*�����whileѭ����һ����ʻ֤�Ŷ��Υ��Ĺ��ܣ������������ݳ��г���*/
						system("cls");IQDW_Line_Frame();//���������ҡ�ɾ����������� 
 						query_Print_Frame();						
						p=head->next;
						while(p!=NULL){						
							if(strcmp(p->drive_License,Licence)==0){   //----------------------------------ѡ����ڣ�1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}
						
						if(flag==0){                                //-----------------------------------ѡ����ڣ�2)
							system("cls");
							gotoxy(35,16);
							printf("�����ڸü�ʻ֤�Ż������������");
							Sleep(2000);
							break;							 
						}
						gotoxy(55,36);
						printf("ϵͳ������10����Զ���ת...");
						Sleep(10000);
						break; 					
																				
				case 3: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("�����뽻�����ţ�");;gotoxy(72,5);scanf("%s",Code);
						y=5;
						/*�����whileѭ����һ���������Ŷ��Υ��Ĺ��ܣ������������ݳ��г���*/
						system("cls");IQDW_Line_Frame();//���������ҡ�ɾ����������� 
 						query_Print_Frame();
						p=head->next;
						while(p!=NULL){
							if(strcmp(p->police_Code,Code)==0){   //----------------------------------ѡ����ڣ�1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------ѡ����ڣ�2)
							system("cls");	
							gotoxy(35,16);
							printf("�����ڸý������Ż������������");
							Sleep(2000);
							break;
						}
						gotoxy(55,36);
						printf("ϵͳ������10����Զ���ת...");
						Sleep(10000);
						break; 						
																									
				case 4: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("������Υ�µص㣺");;gotoxy(72,5);scanf("%s",Position);
						y=5;
						/*�����whileѭ����һ��Υ�µص���Υ��Ĺ��ܣ������������ݳ��г���*/
						system("cls");IQDW_Line_Frame();//���������ҡ�ɾ����������� 
 						query_Print_Frame();
						p=head->next;				
						while(p!=NULL){
							if(strcmp(p->punish_Position,Position)==0){   //----------------------------------ѡ����ڣ�1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------ѡ����ڣ�2)
							system("cls");
							gotoxy(35,16);
							printf("�����ڸ�Υ�µص�������������");
							Sleep(2000);
							break;
						}
						gotoxy(55,36);
						printf("ϵͳ������10����Զ���ת...");
						Sleep(10000);
						break; 					
																									
				case 5: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("������Υ��ʱ��");;gotoxy(72,5);scanf("%s",Time);
						y=5;
						/*�����whileѭ����һ��Υ��ʱ����Υ��Ĺ��ܣ������������ݳ��г���*/
						system("cls");IQDW_Line_Frame();//���������ҡ�ɾ����������� 
 						query_Print_Frame();	
						p=head->next;					
						while(p!=NULL){
							if(strcmp(p->punish_Time,Time)==0){   //----------------------------------ѡ����ڣ�1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------ѡ����ڣ�2)
							system("cls");	
							gotoxy(35,16);
							printf("�����ڸ�Υ��ʱ��������������");
							Sleep(2000);
							break;							
						}
						gotoxy(55,36);
						printf("ϵͳ������10����Զ���ת...");
						Sleep(10000);
						break;					
																													
				case 6: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("�����뷣����");;gotoxy(72,5);scanf("%s",Money);
						y=5;
						/*�����whileѭ����һ����������Υ��Ĺ��ܣ������������ݳ��г���*/
						system("cls");IQDW_Line_Frame();//���������ҡ�ɾ����������� 
 						query_Print_Frame();		
						p=head->next;				
						while(p!=NULL){
							if(strcmp(p->fine_Money,Money)==0){   //----------------------------------ѡ����ڣ�1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------ѡ����ڣ�2)
							system("cls");
							gotoxy(35,16);
							printf("�����ڸ÷�����������������");
							Sleep(2000);
							break;							
						}
						gotoxy(55,36);
						printf("ϵͳ������10����Զ���ת...");
						Sleep(10000);
						break; 					
																				
				case 7: system("cls");line_Frame();display_Node(head);
						gotoxy(55,5);printf("������ɷ�״̬");;gotoxy(72,5);scanf("%s",State);
						y=5;
						/*�����whileѭ����һ���ɷ�״̬���Υ��Ĺ��ܣ������������ݳ��г���*/
						system("cls");IQDW_Line_Frame();//���������ҡ�ɾ����������� 
 						query_Print_Frame();	
						p=head->next;					
						while(p!=NULL){
							if(strcmp(p->stata,State)==0){   //----------------------------------ѡ����ڣ�1)
								flag=1;
								query_Print_Data(y,p);
								y++;															
							}
							p=p->next;
						}

						if(flag==0){                                //-----------------------------------ѡ����ڣ�2)
							system("cls");
							gotoxy(35,16);
							printf("�����ڸ÷���״̬�������������");
							Sleep(2000);
							break;							
						}
						gotoxy(55,36);
						printf("ϵͳ������10����Զ���ת...");
						Sleep(10000);
						break; 					
															
				case 8: system("cls");gotoxy(45,16);printf("�����˻����˵�");Sleep(1000);break;
					
					
					
			  default :gotoxy(0,3);printf("������������������....");Sleep(1000);break;
			} 
	}while(chose!=8);		
}

void query_Frame() //������ҽ����� 
{
	gotoxy(55,4);
	printf("��ѡ�����ַ�ʽ����:");
	gotoxy(55,6);
	printf("1.���ƺ�");
	gotoxy(68,6);
	printf("2.��ʻ֤��");
	gotoxy(81,6);
	printf("3.��������");
	gotoxy(55,8);
	printf("4.Υ�µص�"); 
	gotoxy(68,8);
	printf("5.Υ��ʱ��"); 
	gotoxy(81,8);
	printf("6.������");
	gotoxy(55,10);
	printf("7.�ɷ�״̬");
	gotoxy(68,10);
	printf("8.�˻����˵�");
}

void IQDW_Line_Frame()//���������ҡ�ɾ����������� 
{
	for(i=0;i<100;i++){
		gotoxy(i,2);
		printf("-");
		gotoxy(i,35);
		printf("-");
	}
	gotoxy(16,1);printf("*����*"); 
	gotoxy(32,1);printf("*����*"); 
	gotoxy(48,1);printf("*ɾ��*"); 
	gotoxy(64,1);printf("*����*"); 
}

void write_To_File(Link head) //����������д���ı�  
{	
	if(head==NULL){
		system("cls");
		gotoxy(42,16);
		printf("�����ݿɴ洢");
		Sleep(1500);
		return;
	}
	FILE *fp=NULL;
	Link p=head->next;
	fp=fopen("fine_data.txt","r"); //����ֻ����ʽ�ж��ļ��Ƿ��ƻ�
	if(fp==NULL){
	system("cls");
	gotoxy(45,16);
	printf("�ļ�fine_data.txt�Ҳ��������ܱ�ɾ��");
	clear_List(head);
	gotoxy(0,36);
	exit(1);
	 }
	fclose(fp);//�ر��ļ�
	fp=fopen("fine_data.txt","w");//����ֻд��ʽ�򿪣������ƻ����ؽ��ļ��������ڸ��ļ� 
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
	printf("���ݴ洢�ɹ�");
	Sleep(2000);	
	fclose(fp);	//�ǵ�ʹ���ı�ָ�������һ��Ҫ�ر��� 
}

Link insert_Node(Link head) //������������ 
{
	Link node;
	int chose=1;
	int y=5;	
	do{
		system("cls");IQDW_Line_Frame();
		gotoxy(0,3);printf("���ƺ���");					
		gotoxy(14,3);printf("��ʻ֤��");					
		gotoxy(33,3);printf("��������");						
		gotoxy(47,3);printf("����ص�");						
		gotoxy(61,3);printf("����ʱ��");						
		gotoxy(75,3);printf("������");						
		gotoxy(84,3);printf("����״̬");
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
		node->next=head->next; //�������Ľṹ������������λ���ٽ�ͷ�������ָ��ýṹ��
		head->next=node;
		gotoxy(45,16);
		printf("1.���� 2.����");
		gotoxy(40,21);
		printf("��������Ĭ�Ͻ���");
		gotoxy(45,22);
		printf("��ѡ��"); 
		gotoxy(53,22);
		scanf("%d",&chose);
	}while(chose==2);
	system("cls");
	gotoxy(35,16);
	color(4);printf("�������ݺ�����˱��棬������������Ĭ����Ч");color(7); 
	Sleep(1500);
	return head;	
}

int delete_Node_pr1(Link head,char x[])//xΪ�ַ��� 
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
	IQDW_Line_Frame();//���������ҡ�ɾ����������� 
	gotoxy(0,3);printf("���ƺ���");					
	gotoxy(14,3);printf("��ʻ֤��");					
	gotoxy(28,3);printf("��������");						
	gotoxy(42,3);printf("����ص�");						
	gotoxy(56,3);printf("����ʱ��");						
	gotoxy(70,3);printf("������");						
	gotoxy(84,3);printf("����״̬");	
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
	printf("�����ڣ�");	
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
	printf("��ѡ��ɾ���");
	gotoxy(70,36);
	scanf("%d",&select);
	while(p!=NULL)
	{
		if(strcmp(p->plate_Number,x)==0){
		
			count++;
			if(select==count){
			system("cls");
			gotoxy(48,16);
			printf("%d:%s ��ɾ��",count,p->plate_Number);
			q->next=p->next;
			free(p);															
			Sleep(2000);
			system("cls");
			gotoxy(35,16);
			color(4);printf("�������ݺ�����˱��棬����ɾ������Ĭ����Ч");color(7); 
			Sleep(1500);
			return ;
			}
		}
		q=p;
		p=p->next; 
	}
	system("cls");
	gotoxy(45,16);
	printf("ɾ��ʧ�ܣ�");
	Sleep(1000);
	return ; 
}

void page()//���ݷ���ģ�� 
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
	printf("�ļ���ʧ�ܣ�");
	return; 
	}
	fclose(fp);
	gotoxy(48,36);printf("�� ҳ(Ŀǰ��๲5ҳ)");
	gotoxy(50,36);scanf("%d",&chose);
	switch(chose){	
	case 1: gotoxy(48,36);printf("��1ҳ");count=0;
			fp=fopen("display_Data.txt","r");
		    	x=0,y=5;
		    	if(1){
		    		for(i=0;i<15&&fscanf(fp,"%s",page1[i].data_Plate)!=EOF;i++){		 	        
		 	        fscanf(fp,"%s",page1[i].data_Money);
			        gotoxy(x,y);
					printf("���ƺţ�%s",page1[i].data_Plate);
		 	        printf("\t�����%s",page1[i].data_Money);
					y+=2; 											
		            }
					fclose(fp);   	            
	       		    break;		            
				}
		    		gotoxy(0,5);
	      			printf("������");						
					fclose(fp);   	            
			        break;
	case 2:gotoxy(48,36);printf("��2ҳ");count=0;
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
					printf("���ƺţ�%s",page2[i].data_Plate);
		 	        printf("\t�����%s",page2[i].data_Money);
				    y+=2;	 											
		            }
		            fclose(fp);
		            break;
				}
		        gotoxy(0,5);
		        printf("������");
		        fclose(fp);
				break; 
	 		 		
	            
	 
    case 3:gotoxy(48,36);printf("��3ҳ");count=0;
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
					printf("���ƺţ�%s",page3[i].data_Plate);
	 	  		    printf("\t�����%s",page3[i].data_Money);
					y+=2;   	 											
		            }
		            fclose(fp);
		            break;
				}
	            gotoxy(0,5);
	            printf("������");
	            fclose(fp);
				break;
	case 4:gotoxy(48,36);printf("��4ҳ");count=0;
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
				    printf("���ƺţ�%s",page4[i].data_Plate);
	 	        	printf("\t�����%s",page4[i].data_Money);
					y+=2; 	 											
		            }
		            fclose(fp);
		            break;
				}
	            gotoxy(0,5);
	            printf("������");
	            fclose(fp);
				break;
	case 5:gotoxy(48,36);printf("��5ҳ");count=0;
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
			     	printf("���ƺţ�%s",page5[i].data_Plate);
	 	      	    printf("\t�����%s",page5[i].data_Money);
					y+=2;   	 											
		            }
		            fclose(fp);
		            break;
				}
	            gotoxy(0,5);
	            printf("������");
	            fclose(fp);
				break;
	default :printf("��������");break;			
	}
}

void query_Print_Frame()
{
	gotoxy(0,3);printf("���ƺ���");					
	gotoxy(14,3);printf("��ʻ֤��");					
	gotoxy(28,3);printf("��������");						
	gotoxy(42,3);printf("����ص�");						
	gotoxy(56,3);printf("����ʱ��");						
	gotoxy(70,3);printf("������");						
	gotoxy(84,3);printf("����״̬");
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
 
