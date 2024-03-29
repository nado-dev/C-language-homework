//-------------------------------------------------------------------
//说明：商品管理系统的链表实现框架
//时间：2018.11.20
//其他：1. 关于goodsinfo.txt编码问题（商品内容有中文）
//        MAC下测试UNICODE无法读取，utf-8中文乱码，GBK和ASCII可以中文正常读写
//        Windows下测试ANSII编码存储的正常
//        或者，使用utf-8编码，但在控制台中发出如下命令：
//        chcp 65001
//        这条命令将切换到utf-8模式。切换回原来的模式请发出如下命令：
//        chcp 936
//     2. visualstudio报错fopen等一系列文件操作函数不安全，则在项目-》
//        属性-》预处理器-》预处理器定义处增加_CRT_SECURE_NO_WARNINGS
//任务：1. 完善带有//TO DO YOUR WORK的函数
//     2. 数据结构的实现方式采用链表实现
//     3. 文件的读写参考fileIOreferrence函数
//     4. 注意传指针*L和传指针的地址**L的区别
//-------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//--------------------------------------------------------------------
//商品的最大数量
//--------------------------------------------------------------------
#define MAX 100
//--------------------------------------------------------------------
//全局变量，存储当前商品的数量
//--------------------------------------------------------------------
int CurrentCnt = 0;
//--------------------------------------------------------------------
//商品信息结构的定义
//--------------------------------------------------------------------
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30

bool occur;

typedef struct {
    char	goods_id[MAX_ID_LEN];
    char	goods_name[MAX_NAME_LEN];
    int  	goods_price;
    char	goods_discount[MAX_DISCOUNT_LEN];
    int		goods_amount;
    int		goods_remain;
} GoodsInfo;

//--------------------------------------------------------------------
//定义商品链表的结点
//--------------------------------------------------------------------
typedef struct node
{
    GoodsInfo data;
    struct node *next;
} GoodsList;

//--------------------------------------------------------------------
//参考函数：本函数用于提供文件读写的参照
//--------------------------------------------------------------------

void fileIOreferrence(void)
{
    char tempstring[30];

    //定义文件操作的指针
    FILE *fp;
    //fopen用于打开文件，接收两个参数，一个是文件的路径，一个是文件打开的方式
    //例如xxxxxx.txt和该项目的可执行文件在同一目录下，则此处只需要所读取内容文件名
    //例如r代表以只读方式打开文件
    fp = fopen("xxxxxxx.txt", "r"); 
    //如果w代表打开只写文件，若文件存在则长度清为0，即该文件内容消失，若不存在则创建该文件
    //其余打开方式请自行查阅文档
    fp = fopen("xxxxxxx.txt", "w");

    //fscanf用于从txt文件中读取内容，下例以字符串形式读入一段字符并存放在tempstring中
    fscanf(fp, "%s", tempstring);
    //或者以格式化的方式读入字符串
    fscanf(fp, "\t%s\n", tempstring);

    //fprintf以格式化的方式向txt文件中写入内容
    fprintf(fp, "%s\t", tempstring);

    //检查文件内容是否已经读到文件结束符了
    while ( !feof(fp))
    {
        //…………
    }

    //最后需要使用fclose关闭文件指针
    fclose(fp);
}

//--------------------------------------------------------------------
//检查商品文件是否存在或者是否为空
//--------------------------------------------------------------------
bool check_nullfile(void)
{
    FILE *fp = fopen("D:/C/project", "r");
    //file not exist
    if (!fp) {
        printf("商品信息初始化文件不存在！程序将为您新建一个.\n");
        FILE *fp = fopen("C:/goodsinfo.txt", "w");
        fclose(fp);

        return false;
    }
        //file already exist
    else {
        int temp;
        //res for try to read file if file null feof() can't determine whether file is null or not
        int res = fscanf(fp, "%d", &temp);
        fclose(fp);
        if (res <= 0)
            return false;
        else
            return true;
    }
}

//--------------------------------------------------------------------
//以行读取输入的信息
//--------------------------------------------------------------------
int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;
    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}
//-------------------------------------------------------------
//打印单个商品链表节点的信息 
//-------------------------------------------------------------
void Goodsprint(GoodsList *p){
    /**
     * 1.打印单个链表商品结点的信息
     */
    //TO DO YOUR WORK

    //    输出格式参考：
    //    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    //    printf("ID:%s\t名称:%s\t价格:%s\t折扣:%s\t数量:%d\t剩余:%d\n",
    //           ……………………);
    //    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"); 
}
//--------------------------------------------------------------------
//释放商品链表
//--------------------------------------------------------------------
void DestroyGoods(GoodsList **L) {
    /**
     * 1.使用free函数依次free掉L的所有节点
     */
    //TO DO YOUR WORK
    GoodsList *TMP = NULL;  
    if((*L) == NULL)  
    {  
        printf("链表已空，无需操作\n");  
        return;  
    }  
    while((*L) -> next != NULL)             // 循环释放链表中的结点所占内存
    {  
        TMP = (*L) -> next;  
        free((*L));  
        (*L) = TMP;                         //此时指向的是原来的下一个    
    }  
  
    
    if((*L) != NULL)                        //清空结束后，清除最后一个结点  
    {  
        free((*L));  
        (*L) = NULL;  
                                            //头结点指针设为空 
    }  
    printf("操作完成\n");  
    return;
    
}

//--------------------------------------------------------------------
//删除商品文件以及商品链表中的所有信息
//--------------------------------------------------------------------
void DelAll(GoodsList **L) {
    /**
     * 1.清空存储商品内容的文件
     * 2.清空商品链表，销毁已有的节点，并新建一个空链表头
     */
    //TO DO YOUR WORK
//1
   FILE *fp;              //修改在当前PC下的路径 
   fp = fopen("D:/C/project", "w");
   fclose(fp);
//2
	DestroyGoods(L);     //清空链表 
	GoodsList *TMP ;
	if ((*L)== NULL)
	  return;
    while ((*L) != NULL)  //销毁所有存在的节点 
    {
    	TMP = (*L) -> next;
    	free((TMP));
    	(*L) = TMP;
    	return;
    }
}

//--------------------------------------------------------------------
//读取商品文件goodsinfo.txt的内容,并建立链表L
//--------------------------------------------------------------------
GoodsList* info_init() {
     /**
     * 1.判断goodsinfo.txt是否存在，不存在则新建一个goodsinfo.txt
     * 2.在未达到文件尾的情况下，从文件中读取商品信息
     * 3.然后新建链表
     * 文件信息的读写可参照fileIOreferrence函数
     */

    //TO DO YOUR WORK
   
   // printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
   check_nullfile();
   GoodsList *head = (GoodsList *)malloc(sizeof(GoodsList));
   GoodsList *p;
   GoodsList *q;
   p = q = head;
   FILE *fp = fopen("C:/goodsinof.txt", "r");
    
   if ( fp == NULL)
   {
   	  printf("打开文件失败\n");
   	  return NULL;
   }
   char	id[MAX_ID_LEN];
    char	name[MAX_NAME_LEN];
    int  	price;
    char	discount[MAX_DISCOUNT_LEN];
    int		amount;
    int		remain;
   while (fscanf(fp, "%s\t%s\t%s\t%s\t%d\t%d\n", id, name, &price, discount, &amount, &remain) != EOF)
   {
   	  
	    q = (GoodsList *)malloc(sizeof(GoodsList));
   	    strcpy(q->data.goods_id, id);
   	    strcpy(q->data.goods_name, name);
   	    q->data.goods_price = price;
   	    strcpy(q ->data .goods_discount, discount);
   	    q->data.goods_amount = amount;
   	    q->data.goods_remain = remain;
   	    p ->next = q;
   	    p = q;
   }
   p ->next = NULL;
   fclose(fp);
   return head;
   
   
   
}

//--------------------------------------------------------------------
//将当前商品链表中的内容存入商品文件goodsinfo.txt，存盘后销毁链表L
//--------------------------------------------------------------------
void info_flush(GoodsList *L) {
    /**
     * 1.将链表内容写入到goodsinfo.txt
     * 2.销毁链表
     * 3.商品数量置0
     * 文件信息的读写可参照fileIOreferrence函数
     */

    //TO DO YOUR WORK
   
    //    输出内容参考：
    //    if .... printf("提示：%d个商品信息存入Goodsinfo.txt文件\n", savecount);
    //    else printf("提示：未写入任何商品信息到Goodsinfo.txt文件\n");
    GoodsList *p = L->next;
    FILE *fp = fopen("D:/C/project", "w");
    if (fp == NULL)
    {
    	printf("打开文件失败！\n");
    	return ;
    }
    while(p)
    {
    	fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%d", p->data.goods_id, p->data.goods_name,
		p->data.goods_price, p->data.goods_discount, p->data.goods_amount, p->data.goods_remain );
		p = p->next;
    }
    
    fprintf(fp,"\n");
    fclose(fp);
    
    DestroyGoods(&L);
    
    CurrentCnt = 0;
    
    
}

//--------------------------------------------------------------------
//在屏幕上输出所有商品信息
//--------------------------------------------------------------------
void OutputAll(GoodsList *L)
{
     /**
     * 1.对链表内容进行读取，然后输出商品信息
     */
    //TO DO YOUR WORK

    //    输出格式参考：
    //    printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    //    printf("ID:%s\t名称:%s\t价格:%s\t折扣:%s\t数量:%d\t剩余:%d\n",
    //           ……………………);
    //    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");   
	
	GoodsList *p;
	printf("将进行打印\n");
	p = L;
	if( L!= NULL){
		
		do{
		  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		  printf("ID:%s\t名称:%s\t价格:%s\t折扣:%s\t数量:%d\t剩余:%d\n",
		  L->data.goods_name, L->data.goods_price,L->data.goods_discount,
		  L->data.goods_amount,L->data.goods_remain);
	      printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	      
		  p = p ->next;
			
		}while(p != NULL);
	} 
	
}

//--------------------------------------------------------------------
//添加一条商品记录
//--------------------------------------------------------------------
void info_insert(GoodsList **L) {
    /**
     * 1.接收输入的某一条商品的信息，包括ID、名称、价格、折扣、数量、剩余
     * 注：首先通过scanf()函数读入待插入的商品信息的每项数据以换行符来区分信息中的每个条目
     *    分配大小商品信息结构体的内存空间，然后将读入的数据分别拷贝到已分配得到的内存中，
     *    其中字符串的拷贝调用系统函数strcpy。
     *    另外：可以使用前面自定义的read_line函数进行行数据读取
     * 2.分别实现头插法、尾插法，中间位置插入三种，
     * 3.然后根据用户输入的插入方式进行相应的节点位置插入
     * 4.【选作】ID号在插入的时候需要进行查重，如果已经有该ID号了，提示重复
     */

    // TO DO YOUR WORK
    
}

//--------------------------------------------------------------------
//删除一条商品记录
//--------------------------------------------------------------------

GoodsList *info_dele(void) {
    /**
     * 1.输入商品的名称，如果名称存在则删除商品信息，即释放对应指针所指向的内存，
     *   并且将该指针赋值为空，然后打印出删除成功的提示
     * 2.如果输入的商品名称不存在则出现商品不存在的提示
     */

    // TO DO YOUR WORK
   
    
}

//--------------------------------------------------------------------
//查找一条商品记录
//--------------------------------------------------------------------
GoodsList *info_search(GoodsList *L) {
    /**
     * 1.输入商品的名称，如果名称存在则打印商品信息
     * 2.如果商品不存在则提示商品不存在
     */

    // TO DO YOUR WORK
   GoodsList *pointer;
   
   char name[MAX_NAME_LEN +1];
   printf("输入商品的名称以搜索："); 
   scanf("%s", name);
   
   pointer = L;
   while(pointer != NULL)
   {
   	  if(strcmp(L->data.goods_name ,name ) == 0)
   	  {
  	 	  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		  printf("ID:%s\t名称:%s\t价格:%s\t折扣:%s\t数量:%d\t剩余:%d\n",
		  L->data.goods_name, L->data.goods_price,L->data.goods_discount,
		  L->data.goods_amount,L->data.goods_remain);
	      printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	      occur = true;
		 
  	   }
  	   else {
  		  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		  printf("该商品不存在\n");
	      printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	      occur = false;
   	  }
   	 pointer = pointer->next; 
   }
   return pointer;
}

//--------------------------------------------------------------------
//修改一条商品记录
//--------------------------------------------------------------------
void info_change(GoodsList **L) {
     /**
     * 1.输入商品的名称，如果名称存在则打印商品信息
     * 2.然后用户输入新的商品信息
     * 3.如果要修改的商品存在并且信息输入结束后则出现修改成功并且重新打印出软件选择界面
     */

    // TO DO YOUR WORK
}

//--------------------------------------------------------------------
//冒泡排序实现对链表节点的排序
//--------------------------------------------------------------------
void bubble_sort(GoodsList **L) {
     /**
     * 1.采用冒泡排序对商品链表进行排序，按照价格从低到高进行排序
     * 2.然后输出排序后的商品链表
     */

    // TO DO YOUR WORK
}

//--------------------------------------------------------------------
//主函数
//--------------------------------------------------------------------
int main()
{
     /**
     * 1.初始化一个链表
     * 2.循环显示商品管理系统的操作选择列表
     * 3.用户选择后调用相应的函数进行处理，处理完成后再度显示系统选择列表
     * 4.如果选择超出列表范围，则默认退出系统不存盘。
     */

    // TO DO YOUR WORK   
    
    
    GoodsList *L;
    L = (GoodsList *)malloc(sizeof(GoodsList));
    if(L == NULL){
    	printf("申请内存空间失败\n");
    }
    L ->next = NULL;
    
    info_
    for(;;){
    	
   
    printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
    printf("超市商品管理系统\n");
    printf("*************************************************\n");
    printf("1.显示所有商品的信息：\n"); 
	printf("2.修改某个商品的信息：\n") ;
	printf("3.插入某个商品的信息：\n") ;
	printf("4.删除某个商品的信息：\n") ;
	printf("5.查找某个商品的信息：\n") ;
	printf("6.商品存盘并退出系统：\n") ;
	printf("7.对商品价格进行排序：\n") ;
	printf("8.（慎用）删除所有内容：\n") ;
	printf("其他，不存在并退出系统：\n") ;
	printf("*************************************************\n");
	
	int choose;
	printf("输入您的选择: ");
	scanf("%d", &choose);
	switch(choose)
	{
		case 1:
		OutputAll(L);	break;
		case 2:
		info_change(&L);	break;
		case 3:
		info_insert(&L);  break;
		case 4:
		info_dele();  break;
		case 5:
		info_search(L);  break;
		case 6:
		info_flush(L);  break; 
		case 7:
		bubble_sort(&L);  break;
		case 8:
		DelAll(&L);  break;
		
		default:
		return 0;	break;
	}
	 }
    return 0;
}