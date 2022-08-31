#include "analysis_air.h"
#include "app.h"

Analysis_Air::Analysis_Air(QObject *parent) : QObject(parent)
{
    qDebug()<<"innnn--Analysis";
   // connect(this,&Analysis_Air::testSignals,System,&AirSystem::testMessage);
}

Analysis_Air::~Analysis_Air()
{

}

void Analysis_Air::Receive_Data(QMultiMap<int, QString> Data)
{
    QStringList DataStringList=Data.values(2);//选择键值
    /*
    --2 窗帘
*/
    QString HandleData;
    int Number =DataStringList.count();
    for(int i=0;i<Number;i++)
    {
        HandleData=DataStringList.at(i);
        Handle_Data(HandleData);
    }
}

void Analysis_Air::Handle_Data(QString Data)
{
    //ZB10101011
    QString Sub;
    QString Value;
    QString Function;
    //-----截取------------
    for(int i=3;i<=4;i++)
    {
        Function.append(Data.at(i));
    }
    for(int a=5;a<=6;a++)
    {
        Sub.append(Data.at(a));
    }
    for(int b=7;b<=8;b++)
    {
        Value.append(Data.at(b));
    }
    //------------------
    if(Function.toInt()==2)
    {
        if(Sub.toInt()==1)
        {
            Air_Decode(Value.toInt());
        }
    }
    //int Test=binary_search(Array,0,6,Value.toInt());
    //qDebug()<<"Test:"<<Test;
}

void Analysis_Air::Data_Update(Data Lastest)
{
   // data=Lastest;
    //qDebug()<<"更新成功";
}




int Analysis_Air::binary_search(int *arr,int p,int q,int ele)
{
    int mid = 0;
    //如果[p,q] 不存在，返回 -1
    if (p > q) {
        return -1;
    }
    // 找到中间元素所在的位置
    mid = p + (q - p) / 2;
    //递归的出口
    if (ele == arr[mid]) {
        return mid;
    }
    //比较 ele 和 arr[mid] 的值，缩小 ele 可能存在的区域
    if (ele < arr[mid]) {
        //新的搜索区域为 [p,mid-1]
        return binary_search(arr, p, mid - 1, ele);
    }
    else {
        //新的搜索区域为 [mid+1,q]
        return binary_search(arr, mid + 1, q, ele);
    }
}
/*
 * Fan 0--自动 1--低档 2---中档 3---高档
 * Mode 0---自动 1--制冷 2--制热 3---除湿 4---送风
 */
void  Analysis_Air::Air_Decode(int Value)
{
    if(Value<16){
        switch (Value) {
        case 0:
            data.Station=0;
            break;
        case 1:
            data.Station=1;
            break;
        case 2://"Low"
            data.Fan=1;
            break;
        case 3://"Mid"
            data.Fan=2;
            break;
        case 4://"High"
            data.Fan=3;
            break;
        case 5:
            data.Swing_L_R=1;
            break;
        case 6:
            data.Swing_L_R=0;
            break;
        case 7:
            data.Swing_U_D=1;
            break;
        case 8:
            data.Swing_U_D=0;
            break;
        case 9://"Cool"
            data.Mode=1;
            break;
        case 10://"Dry"
            data.Mode=3;
            break;
        case 11://"Heat"
            data.Mode=2;
            break;
        case 12://"Auto"
            data.Mode=0;
            break;
        case 13://"Auto"
            data.Fan=0;
            break;
        case 14:
            data.Mode=4;
        case 15:
            break;
        }
    }
    else {
        data.Temp=Value;
    }
    emit Air_UiValue(data);
}

