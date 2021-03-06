#include<iostream>
#include"function.hpp"

const char* weekday[7]={"Sunday","Monday","Tuesday","Wednesday",
					"Thursday","Friday","Saturday"};
const int month_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

//闰年的判断，润年二月29天
bool isleap(int year){
	if(year%400==0)
		return true;
	else if(year%4==0&&year%100!=0)
		return true;
	else
		return false;
}

Date add_day(struct Date date){
    Date newdate;
    newdate.year=date.year;
    newdate.mon=date.mon;
    //增加一天
    if(isleap(date.year)){//是闰年
        if(date.mon==4||date.mon==6||date.mon==9||date.mon==11){//天数为30天的月份时
            if(date.day==30){
                newdate.mon=date.mon+1;
                newdate.day=1;
            }
            else newdate.day=date.day+1;
        }
        else if(date.mon==2){//2月单独处理
            if(date.day==29){
                newdate.mon=3;
                newdate.day=1;
            }
            else newdate.day=date.day+1;
        }
        else if(date.mon==12){//12月单独处理
            if(date.day==31)
                newdate.year=date.year+1;
                newdate.mon=1;
                newdate.day=1;
        }
        else{//31天的月
             if(date.day==31){
                newdate.mon=date.mon+1;
                newdate.day=1;
            }
            else newdate.day=date.day+1;
        }
    }
    else{//平年
        if(date.mon==4||date.mon==6||date.mon==9||date.mon==11){//天数为30天的月份时
            if(date.day==30){
                newdate.mon=date.mon+1;
                newdate.day=1;
            }
            else newdate.day=date.day+1;
        }
        else if(date.mon==2){//2月单独处理
            if(date.day==28){
                newdate.mon=3;
                newdate.day=1;
            }
            else newdate.day=date.day+1;
        }
        else if(date.mon==12){//12月单独处理
            if(date.day==31)
                newdate.year=date.year+1;
                newdate.mon=1;
                newdate.day=1;
        }
        else{//31天的月
             if(date.day==31){
                newdate.mon=date.mon+1;
                newdate.day=1;
            }
            else newdate.day=date.day+1;
        }
    }
    return newdate;
}
Date add_mon(struct Date date){
    Date newdate;
    newdate.year=date.year;
    newdate.mon=date.mon+1;
    newdate.day=date.day;
    if(date.mon==1){
        if(isleap(date.year)){
            if(date.day==29||date.day==30||date.day==31){
                newdate.mon=2;
                newdate.day=29;
            }
        }
        else{
            if(date.day==29||date.day==30||date.day==31){
                newdate.mon=2;
                newdate.day=28;
            }
        }
    }
    else if(date.mon==3||date.mon==5||date.mon==8||date.mon==10){
        if(date.day==31){
            newdate.mon=date.mon+1;
            newdate.day=30;
        }
    }
    else if(date.mon==12){
        newdate.year=date.year+1;
        newdate.mon=1;
        newdate.day=date.day;
    }
    else{
        newdate.mon=date.mon+1;
        newdate.day=date.day;
    }
    return newdate;

}

Date add_year(struct Date date){
    Date newdate;
    newdate.mon=date.mon;
    newdate.year=date.year+1;
    newdate.day=date.day;
    if(isleap(date.year)){
        if(date.mon==2&&date.day==29){
            if(isleap(newdate.year))
                newdate.day=29;
            else newdate.day=28;
        }
    }
    else{
        if(date.mon==2&&date.day==28){
            if(isleap(newdate.year))
                newdate.day=29;
            else newdate.day=28;
        }
    }
    return newdate;
}

int _day_of_week(struct Date date)
{
	int sum_days=0;
	int day_of_w=0;
	int i_year;
	int i_mon;
	if(date.year<2019)
	{
		//第一年单独判断
		if(isleap(date.year)&&date.mon<=2&&date.year<2018)
			sum_days-=366;
		else
			sum_days-=365;
		for(i_year=date.year+1;i_year<2018;i_year++)
		{
			if(isleap(i_year))
			{
				sum_days-=366;
			}
			else
			{
				sum_days-=365;
			}
		}
		//此时i_year=2018
		for(i_mon=date.mon;i_mon<12;i_mon++)
		{
			sum_days-=month_day[i_mon-1];
		}
		//此时i_mon=12
		sum_days-=(32-date.day);
		//cout<<sum_days;
		day_of_w=(sum_days%7+9)%7;
	}
	else
	{
		for(i_year=2019;i_year<date.year;i_year++)
		{
			if(isleap(i_year))
			{
				sum_days+=366;
			}
			else
			{
				sum_days+=365;
			}
		}
		//此时i_year=date.year
		for(i_mon=1;i_mon<date.mon;i_mon++)
		{
			if(i_mon==2&&isleap(date.year))
				sum_days+=month_day[i_mon-1]+1;
			else
				sum_days+=month_day[i_mon-1];
		}
		//此时i_mon=date.mon
		sum_days+=(date.day-1);
		//cout<<sum_days;
		day_of_w=(sum_days%7+2)%7;
	}

	return day_of_w;
}

Date next_monday(struct Date date){
    int now_day_w=_day_of_week(date);
    int b_days=8-now_day_w;//到下一个周一还有几天
    Date newdate;
    newdate.day=date.day+b_days;
    newdate.mon=date.mon;
    newdate.year=date.year;
    if(newdate.day>month_day[date.mon-1]){//日溢出
        newdate.day=newdate.day%month_day[date.mon-1];
        newdate.mon++;
        if(newdate.mon>12){//月溢出
            newdate.mon=newdate.mon%12;
            newdate.year++;
        }
    }
    return newdate;
}
