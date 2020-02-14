//2019-1-1  ÐÇÆÚ¶þ i=2
#include<iostream>
#include"function.hpp"

using namespace std;


int main(){
    const char* weekday[7]={"Sunday","Monday","Tuesday","Wednesday",
					"Thursday","Friday","Saturday"};
    const int month_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	struct Date d;
	cin>>d.year>>d.mon>>d.day;
	Date newdate1=add_day(d);
	cout<<"add_day:"<<newdate1.year<<" "<<newdate1.mon<<" "<<newdate1.day<<endl;
	Date newdate2=add_mon(d);
	cout<<"add_mon:"<<newdate2.year<<" "<<newdate2.mon<<" "<<newdate2.day<<endl;
	Date newdate3=add_year(d);
	cout<<"add_year:"<<newdate3.year<<" "<<newdate3.mon<<" "<<newdate3.day<<endl;
	int dayofweek=_day_of_week(d);
	cout<<"xingqiji:"<<weekday[dayofweek]<<endl;
	Date next_mon=next_monday(d);
	cout<<"next_monday:"<<next_mon.year<<" "<<next_mon.mon<<" "<<next_mon.day<<endl;
	return 0;
}
