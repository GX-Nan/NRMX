#include "wxreceive.h"

WxReceive::WxReceive(QObject *parent) : QObject(parent)
{
    Python_Init();

    Online();
}

void WxReceive::Online()//登入onenet
{
    class PyThreadStateLock PyThreadLock;

    //创建模块指针
    PyObject* pModule = PyImport_ImportModule("Receive");
    if (!pModule)
        qDebug()<<"获取模块指针失败";

    //创建函数指针
    PyObject* pFunc= PyObject_GetAttrString(pModule,"main");
    if(!pFunc)
        qDebug()<<"获取函数指针失败";

    PyObject_CallObject(pFunc,nullptr); //无参数调用
}

void WxReceive::Crawl()//抓取数据
{
    class PyThreadStateLock PyThreadLock;
    //创建模块指针
    PyObject* pModule = PyImport_ImportModule("Receive");
    if (!pModule)
        qDebug()<<"获取模块指针失败";

    PyObject* pFunc_2= PyObject_GetAttrString(pModule,"CallBackToQt");

    PyObject* pPara = PyTuple_New(0);        // 2个参数

    // 调用Python函数，传入元组参数pPara
    PyObject *FuncBack = PyObject_CallObject(pFunc_2,pPara);
    //FuncBack是返回值指针，转换获取返回值
    int str=0;
    PyArg_Parse(FuncBack,"i",&str);
    qDebug()<<"返回值: "<<str;
    Analysis(str);

}

void WxReceive::Python_Init()
{
    Py_Initialize();

    PyEval_InitThreads();

    //如果初始化失败，返回
    if(!Py_IsInitialized())
    {
        qDebug() << "IsInitialized: error";
    }
    //导入.py文件
    //添加python模块路径
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('/home/pi/Desktop/9.28/nettool/form/')");

    PyEval_ReleaseThread(PyThreadState_Get());
}

void WxReceive::KeepCrawl()
{
    qDebug()<<"KeepCrawl线程ID"<<QThread::currentThread();
    while(true){
        Crawl();
    }
}

void WxReceive::Analysis(int data)
{
    QString Order=QString::number(data);
    QString Main,Fun,Sub,Number="";

    Main.append(Order.at(0));
    qDebug()<<"Analysis:"<<data;
    for(int i=1;i<=2;i++){
        Fun.append(Order.at(i));
    }
    for(int i=3;i<=4;i++){
        Sub.append(Order.at(i));
    }
    for(int i=5;i<=6;i++){
        Number.append(Order.at(i));
    }
    qDebug()<<Main<<Fun<<Sub<<Number;
    switch(Main.toInt())
    {
    case 1:
        if(Fun.toInt()==1)
        {
            emit Window_Status(Sub.toInt(),Number.toInt());
        }
        else {
            emit Curtain_Status(Sub.toInt(),Number.toInt());
        }
        break;
    case 2:
        if(Fun.toInt()==2)
        {
            emit Air_Status(Number.toInt());
        }
        else{
            emit Light_Status(Fun.toInt(),Sub.toInt(),Number.toInt());
        }
        break;
    case 6:
        emit Wind_Status(Number.toInt());
    }

}
