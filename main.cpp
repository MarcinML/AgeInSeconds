#include <iostream>
#include <ctime>
#include <cstdio>
#include <string>
#include <limits>

typedef std::numeric_limits< long double > dbl;

class Date
{
public:
    int year,month,day;
    Date():year(0),month(0),day(0){};
};

void correct(Date &date);
void enterDate(Date &date);
int checkHowManyLeapYears(const Date &date,const int &actual);
int actualYear();
double actualNumberOfsecondsSinceNewYear();

const long double numberOfSecondsInNormalYear = 365 * 24 * 3600;
const long double numberOfssecondsinOneDay = 24 * 3600;


int main()
{

    std::cout<<"Welcome, \n"
               "I will compute number of seconds of your life \nsince you were born to actual time"<<std::endl;
    Date date;
    enterDate(date);
    correct(date);

    int actualY=actualYear();
    int numberOfLeapYears = checkHowManyLeapYears(date,actualY);

    int HowManyFullYears = actualY - date.year;
    double HowManySecondsInThisYear = actualNumberOfsecondsSinceNewYear();

    int tab[12]{31,28,31,30,31,30,31,31,30,31,30,31};

    long double howLongYouLive= (HowManyFullYears * numberOfSecondsInNormalYear) + (numberOfLeapYears * numberOfssecondsinOneDay)
            + HowManySecondsInThisYear;

    for(int i = date.month; i<12; ++i)
    {
        howLongYouLive+=tab[i]*numberOfssecondsinOneDay;
    }
    howLongYouLive -= date.day * numberOfssecondsinOneDay;
    std::cout.precision(dbl::max_digits10);

    std::cout<<"You live "<< howLongYouLive<<" seconds"<<std::endl;


    std::cout<<numberOfSecondsInNormalYear<<"seconds in normal year"<<std::endl;
    std::cout<<numberOfssecondsinOneDay<<"seconds in one day"<<std::endl;
    std::cout<<actualY<<"actual year"<<std::endl;
    std::cout<<numberOfLeapYears<<"number leap years"<<std::endl;
    std::cout<<HowManyFullYears<<"how many full year"<<std::endl;
    std::cout<<HowManySecondsInThisYear<<"howmany second in this year"<<std::endl;

    return 0;
}

void correct(Date &date)
{
    char answer;
    do
    {
    std::cout<<"is this correct date? (y/n)\n";
               std::cin>>answer;
    switch(answer)
    {
    case 'y':
        std::cout<<"Ok, lets go!"<<std::endl;
        break;
    case 'n':
        std::cout<<"Ok, lets do some amendments"<<std::endl;
        enterDate(date);
        break;
    default:
        break;
    }
   }while(answer!='y');
}

void enterDate(Date &date)
{
    std::cout<<"\n\nPlease enter your:\nYear of birth :"<<std::endl;
    std::cin>>date.year;
    std::cout<<"\nMonth of birth :"<<std::endl;
    std::cin>>date.month;
    std::cout<<"\nDay of birth :"<<std::endl;
    std::cin>>date.day;
    std::cout<<"You were born at "<<date.day<<"."<<date.month<<"."<<date.year<<std::endl;
}

int checkHowManyLeapYears(const Date &date, const int &actual)
{
    int result=0;
    int counter = actual;

    while(counter!=date.year)
    {
        if(counter%4 == 0) result++;
        counter--;
    }
    if((date.year % 4 == 0) && (date.month>2) && (date.year != actual)) result--;

    return result;
}
int actualYear()
{
    time_t czas;
    time( & czas );

    std::string actualyear=asctime( localtime( & czas ) );
    std::string str2 = actualyear.substr (20,4);
    int actual = std::stoi( str2 );
    return actual;
}

double actualNumberOfsecondsSinceNewYear()
{

    time_t now;
    struct tm newyear;
    double seconds;

    time(&now);  /* get current time; same as: now = time(NULL)  */

    newyear = *localtime(&now);

    newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
    newyear.tm_mon = 0;  newyear.tm_mday = 1;

    seconds = difftime(now,mktime(&newyear));

    return seconds;
}




























