#include "wxsend.h"

WxSend::WxSend(QObject *parent) : QObject(parent)
{
    Python_Init();
}

void WxSend::SendData(QString Id, int data)
{
    class PyThreadStateLock PyThreadLock;

    //创建模块指针
    PyObject* pModule = PyImport_ImportModule("Send");
    if (!pModule)
        qDebug()<<"获取模块指针失败";

    //创建函数指针
    PyObject* pFunc= PyObject_GetAttrString(pModule,"Send");
    if(!pFunc)
        qDebug()<<"获取函数指针失败";

    PyObject* pPara = PyTuple_New(2);        // 2个参数

    char *Charid;//导入的信息
    QByteArray Transition = Id.toLatin1();//中间量
    Charid=Transition.data();

    PyTuple_SetItem(pPara, 0, Py_BuildValue("s",Charid));  //参数1为char*型
    PyTuple_SetItem(pPara, 1, Py_BuildValue("i",data));  //参数2为int型

    //调用Python函数，传入元组参数pPara
    PyObject *FuncBack = PyObject_CallObject(pFunc,pPara);
}

void WxSend::Python_Init()
{
    Py_Initialize();//如果初始化失败，返回

    PyEval_InitThreads();//添加GIL

    if(!Py_IsInitialized())
    {
        qDebug() << "Send---IsInitialized: error";
    }
    PyRun_SimpleString("import sys");//导入.py文件---导入搜索的库
    PyRun_SimpleString("sys.path.append('/home/pi/Desktop/Main/nettool/form/')");//添加python模块路径

    PyEval_ReleaseThread(PyThreadState_Get());
}
