//�ļ�ժҪ��
//17130130312 �ܳ���
//2019.5.29
#include<iostream>
#include<cstdio>
#include<ctime>
#include"function.hpp"
using namespace std;

Date::Date(int y,int m,int d)
{
    int max;//�ж������Ƿ�Ϸ�
    if(m<1||m>12)
        cout << "�������";
    switch(m)
    {
    case 2:
        max=28+isleapyear(y);
        break;
    case 4: case 6: case 9: case 11:
        max=30;
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        max=31;
        break;
    default:
        cout << "�������";
    }
    days = date_to_days(y,m,d);
	print_date();
}
Date::Date(int m,int d)
{
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    int y;
    y=timeinfo->tm_year+1900;
    days=date_to_days(y,m,d);
    print_date();
}
Date::Date(int d)
{
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    int m=timeinfo->tm_mon+1;
    int y=timeinfo->tm_year+1900;
    days=date_to_days(y,m,d);
    print_date();
}
Date::Date()
{
    int d,m,y;
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    d=timeinfo->tm_mday;
    m=timeinfo->tm_mon+1;
    y=timeinfo->tm_year+1900;
    days=date_to_days(y,m,d);
    print_date();
}

void Date::print_date()
{
    int y,m,d;
    days_to_date(days,&y,&m,&d);
    cout << "the date is :"<<y<<"."<<m<<"."<<d<<endl;
}

void Date::add_day(int n)
{//�ڵ�ǰ���������n��ĺ���
    days +=n;
    cout << "add: " << n << " day"<<endl;
    print_date();
}

void Date::add_month(int n)
{//�ڵ�ǰ���������n�µĺ���
    int y,m,d;
    days_to_date(days,&y,&m,&d);
    //�Ƚ���ǰ����ת��������
    for( int i=0;i<n;i++ )
    {
        switch(m)
        {
        case 3: case 5: case 8: case 10:
            if(d==31)
            {
                days+=30;
                d=30;
            }
            else days+=30;
            break;
        case 1:
            if( d>29 && isleapyear(y)==1 ){ days+=29;d=29; }
            else if( d>28 && isleapyear(y)==0 ){ days+=28;d=28; }
            else days+=31;
            break;
        default:
            days+=31;
            break;
        }
        m++;
    }
    cout << "add: " << n << " month"<<endl;
    print_date();
    //����n�º����
}

void Date::add_year(int n)
{//���n��
    int y,m,d;
    days_to_date(days,&y,&m,&d);
    //�Ƚ���ǰ����ת��������
    for( int i=0;i<n;i++ )
    {
        if( isleapyear(y)) days+=366;
        else days+=365;
        y++;
    }
    cout << "add: " << n << " year"<<endl;
    print_date();
    //����n������
}

int isleapyear(int year)
{
	if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
		return 1;
	}
	return 0;
}

void days_to_date(int new_days,int *y,int *m,int *d)
{
     int not_amon=0;//�жϵ��������Ƿ���һ���µı��
    for((*y)=1970;new_days/365>0;(*y)++ )
    {
        if( isleapyear(*y)==0 )
        {
            if(new_days>=366)  new_days-=366;
            else break;//��ʱnew_days=365������һ����
        }
        else new_days-=365;
    }
    for( (*m)=1;new_days/28>0;(*m)++ )
    {
        switch(*m)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(new_days>=31) new_days-=31;
            else not_amon =1;
            break;
        case 4: case 6: case 9: case 11:
            if(new_days>=30) new_days-=30;
            else not_amon =1;//
            break;
        case 2:
            if( isleapyear(*y)==0 )
            {
                if(new_days>=29)  new_days-=29;
                else
                {
                    not_amon = 1;
                    break;
                }
            }
            else new_days-=28;
            break;
        }
        if(not_amon) break;
    }
    *d = new_days+1;
}
int date_to_days(int y,int m,int d)
{
    int new_days=0;
    for( int i=1970;i<y;i++ )
    {//������������
        if( isleapyear(i)==1 ) new_days+=366;
        else new_days+=365;
    }
    for( int j=1;j<m;j++ )
    {//������������
        switch(j)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            new_days+=31;
            break;
        case 4: case 6: case 9: case 11:
            new_days+=30;
            break;
        case 2:
            if( isleapyear(y)==1) new_days+=29;
            else new_days+=28;
            break;
        }
    }
    new_days+=(d-1);//��������
    return new_days;
}

