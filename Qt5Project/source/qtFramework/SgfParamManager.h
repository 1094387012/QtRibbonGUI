/************************************************************************
* ��Ȩ���� (C) ����    Email:  liang1057@163.com.cn
* 
* �ļ����ƣ� SgfParamManager.h
* ����ժҪ�� ƽ̨�ں�-����������ͷ�ļ�
* ����˵���� ��
* ��ǰ�汾�� 0.1
* ��    �ߣ� leon
* ������ڣ� 2016-11-22
* 
* �޸ļ�¼1��
*    �޸����ڣ� 
*    �� �� �ţ�
*    �� �� �ˣ� 
*    �޸����ݣ�
* �޸ļ�¼2����
************************************************************************/
#ifndef SWFPARAMMANAGER_H
#define SWFPARAMMANAGER_H

#include <map>
#include <string>
using namespace std;

class SgfParamManager
{
public:
    /** brief ����ģʽ.  */
    static SgfParamManager* GetInstance();

    /** @brief  ��Ӳ�������.
    *
    *  @details   ��Ӳ�������.
    *  @param   tKey  ��������.
    *  @param   paramValue  ����ֵָ��.
    *  @return  void.
    */
    void addParam(const string &tKey, void *paramValue);


    /** @brief  ��ȡ����ֵָ�뺯��.
    *
    *  @details   ��ȡ����ֵָ�뺯��.
    *  @param   tKey  ��������.
    *  @return  void * ����ֵָ��.
    */
    void* getParamValue(const string &tKey);
};


#endif // SWFPARAMMANAGER_H
