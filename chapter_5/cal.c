#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);
char *month_name(int);

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()
{
  int month, day;

  printf("day of year for Nov 7: %d\n", day_of_year(2017, 11, 7));

  month_day(2017, 111, &month, &day);
  printf("day 111 is month %s, day %d\n", month_name(month), day);
  return 0;
}

/* get day of year */
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  for (i = 1; i < month; i++)
    day += daytab[leap][i];

  return day;
}

/* set month, day from day of year */
void month_day(int year, int yesterday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  for (i = 1; yesterday > daytab[leap][i]; i++)
    yesterday -= daytab[leap][i];
  *pmonth = i;
  *pday = yesterday;
}

char *month_name(int n)
{
  char *ill = "Illegal";

  static char *name[] = {
    "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
    "Aug", "Sep", "Oct", "Nov", "Dec"
  };

  return (n < 1 || n > 12) ? ill : name[n];
}
