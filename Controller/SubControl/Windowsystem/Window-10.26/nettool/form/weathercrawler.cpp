#include "weathercrawler.h"

WeatherCrawler::WeatherCrawler(QObject *parent) : QObject(parent)
{
    Python_Init();
    Timer=new QTimer(this);
    Message=new CrawlMessage();
    connect(Timer,&QTimer::timeout,this,&WeatherCrawler::Crawl);
    qDebug()<<"WeatherCrawl---init";

}

void WeatherCrawler::Python_Init()
{
    Py_Initialize();//如果初始化失败，返回

    PyEval_InitThreads();//添加GIL

    if(!Py_IsInitialized())
    {
        qDebug() << "Send---IsInitialized: error";
    }
    PyRun_SimpleString("import sys");//导入.py文件---导入搜索的库
   // PyRun_SimpleString("sys.path.append('/home/pi/Desktop/9.28/nettool/form/')");//添加python模块路径
    PyRun_SimpleString("sys.path.append('/home/pi/Desktop/Windowsystem/Window-10.26/nettool/form/')");//添加python模块路径
    PyEval_ReleaseThread(PyThreadState_Get());

}

void WeatherCrawler::Analysis(QStringList data,int Key)
{

    if(Key==0){
        Message->OutSideAir.insert(data[0],data[1]);
        Message->OutSideAir.insert(data[0],data[1]);
        Message->OutSideAir.insert(data[2],data[3]);
        Message->OutSideAir.insert(data[4],data[5]);
        Message->OutSideAir.insert(data[6],data[7]);
        Message->OutSideAir.insert(data[8],data[9]);
        Message->OutSideAir.insert(data[8],data[9]);
        Message->OutSideAir.insert(data[10],data[11]);
        Message->OutSideAir.insert(data[12],data[13]);
    }
    else if(Key==1)
    {
        Message->WeatherNow.insert("Weather",data[4]);
        Message->WeatherNow.insert(data[0],data[1]);
        Message->WeatherNow.insert(data[2],data[3]);
    }
    else if(Key>=2&&Key<=5)
    {
        Message->Activity.insert(data[0],data[1]);
    }
    else{

        Message->HoulyTemp.insert(HoulyTimes,data[2]);
        Message->HoulyWeather.insert(HoulyTimes,data[1]);
        Message->HoulyHum.insert(HoulyTimes,data[3]);
        HoulyTimes=HoulyTimes+1;
        if(Key==17){
            qDebug()<<"toooooo------tooooooooooooooooo";
            emit SendMessage(Message);
            HoulyTimes=0;
        }
    }
}


void WeatherCrawler::Crawl()
{
    CrollerTimes=CrollerTimes+1;
    qDebug()<<"执行次数:"<<CrollerTimes;
    qDebug()<<"抓取天气信息中.......";
    qDebug()<<"天气线程ID"<<QThread::currentThread();
    class PyThreadStateLock PyThreadLock;
    //创建模块指针

    PyObject* pModule = PyImport_ImportModule("Crawler");
    if (!pModule)
        qDebug()<<"获取模块指针失败";

    PyObject* Crawler= PyObject_GetAttrString(pModule,"GetMessage");//调用的函数
    //    PyObject *pArgs = PyTuple_New(1);

    PyObject* PyList  = PyList_New(3);//定义一个与数组等长的PyList对象数组

    PyObject* ArgList = PyTuple_New(1);//定义一个Tuple对象，Tuple对象的长度与Python函数参数个数一直，上面Python参数个数为1，所以这里给的长度为1

    PyTuple_SetItem(ArgList, 0, PyList);//将PyList对象放入PyTuple对象中

    qDebug()<<"ArgList:"<<ArgList;
    PyObject* pReturn=nullptr;
//    try {
//        pReturn=PyEval_CallObject(Crawler,ArgList);//调用函数,并传入参数pArgs
//    } catch (...) {
//        PyErr_Print();
//    }

    qDebug()<<"innnn-赋值前"<<pReturn;
    pReturn=PyEval_CallObject(Crawler,ArgList);
    qDebug()<<"innn---赋值后"<<pReturn;
    QStringList list1;

    int SizeOfList = PyList_Size(pReturn);//List对象的大小，这里SizeOfList =
    for(int i = 0; i < SizeOfList; i++){
        PyObject *Item = PyList_GetItem(pReturn, i);//获取List对象中的每一个元素
        char *result;
        PyArg_Parse(Item, "s", &result);//i表示转换成int型变量
        list1= QString::fromStdString(result).split(',');
        Analysis(list1,i);
        list1.clear();
       // Py_DECREF(Item); //释放空间
    }
//    Py_DECREF(ArgList); //释放空间
//    Py_DECREF(PyList); //释放空间
//  //  Py_DECREF(pReturn); //释放空间
//    Py_DECREF(Crawler); //释放空间
//    Py_DECREF(pModule); //释放空间


}

void WeatherCrawler::TimeCatch()
{
    // Crawl();
    //    qDebug()<<"TimeCatch线程ID"<<QThread::currentThread();
     Timer->start(650000);
}
