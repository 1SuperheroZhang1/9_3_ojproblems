#include <stdio.h>
/*
 * Description
    初始化顺序表(顺序表中元素为整型),里边的元素是1,2,3，
    然后通过scanf读取一个元素（假如插入的是6），插入到第2个位置，打印输出顺序表，
    每个元素占3个空格，格式为1  6  2  3，
    然后scanf读取一个整型数，是删除的位置（假如输入为1），
    然后输出顺序表  6  2  3，
    假如输入的位置不合法，输出false字符串。
   Input
    第一次输入插入的元素值，第二次输入删除的位置
   Output
    假如插入的元素为6，那么输出为1  6  2  3
    假如删除的位置为1，那么输出为6  2  3
 * */
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;
//顺序表中插入元素
bool ListInsert(SqList &L,int i,ElemType e){
    if(i<1||i>L.length+1){//判断插入位置i是否合法
        return false;
    }
    if(L.length>=MaxSize){
        return false;
    }
    for(int j=L.length;j>=i;j--){//是把数据往后移动
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;//将要插入的数据放入对应的位置上去
    L.length++;
    return true;
}
//打印顺序表中的元素
void PrintList(SqList L){
    int i=0;
    for(i=0;i<L.length;i++){
        printf("%3d",L.data[i]);
    }
    printf("\n");
}
//要不要加引用，就是看是不是在子函数中去改变主函数中对应的变量，要改，就要加，不加，不需要改。
//顺序表的删除元素
bool ListDelete(SqList &L,int i,ElemType &e){
    if(i<1||i>L.length){//判断删除位置是否合法
        return false;
    }
    e=L.data[i-1];
    for(int j=i;j<L.length;j++){//把数据往前移动
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
int main() {
    SqList L;//定义顺序表
    bool ret_insert;//存放函数的返回值
    bool ret_delete;
    L.data[0]=1;//手动赋值
    L.data[1]=2;
    L.data[2]=3;
    L.length=3;
    int insert;
    scanf("%d",&insert);//输入要添加的元素值
    ret_insert=ListInsert(L,2,insert);//读取的元素放在固定的位置
    if(ret_insert){
        PrintList(L);
    }else{
        printf("false\n");
    }
    int del;
    ElemType e;
    scanf("%d",&del);
    ret_delete= ListDelete(L,del,e);//读取删除的位置
    if(ret_delete){
        PrintList(L);
    }else{
        printf("false\n");
    }
    return 0;
}
