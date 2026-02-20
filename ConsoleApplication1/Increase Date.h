#pragma once

#pragma once

#include <iostream>

using namespace std;

namespace Increase {
    struct stDate {

        short Year;
        short Month;
        short Day;

    };
    short ReadYear() {

        short Number = 0;

        cout << "Enter a Year : ";

        cin >> Number;

        return Number;

    }

    short ReadMonth() {

        short Number = 0;

        cout << "Enter a Month : ";

        cin >> Number;

        return Number;
    }

    short ReadDays() {

        short Number = 0;

        cout << "\nEnter a Day : ";

        cin >> Number;

        return Number;
    }

    bool IsLeapYear(short Year) {


        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    short NumberOfDaysInMonth(short Year, short Month) {


        if (Month < 1 || Month>12)
        {
            return 0;
        }


        short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
    }

    bool IsLastDayInMonth(stDate Date) {
        return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
    }

    bool IsLastMonthInYear(short Month) {

        return (Month == 12);
    }

    stDate IncreaseDateByOneDay(stDate Date) {

        if (IsLastDayInMonth(Date)) {

            if (IsLastMonthInYear(Date.Month))
            {
                Date.Month = 1;
                Date.Day = 1;
                Date.Year++;
            }

            else {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else {
            Date.Day++;
        }
        return Date;
    }

    stDate ReadFullData() {

        stDate Date;

        Date.Day = ReadDays();
        Date.Month = ReadMonth();
        Date.Year = ReadYear();

        return Date;
    }

    stDate IncreaseDateByXDays(stDate Date, short Days) {

        for (short i = 1; i <= Days; i++) {

            Date = IncreaseDateByOneDay(Date);

        }

        return Date;
    }

    stDate IncreaseDateByOneWeek(stDate Date) {

        for (short i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }

        return Date;
    }

    stDate IncreaseDateByXWeeks(stDate Date, short Weeks) {

        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }

        return Date;
    }

    stDate IncreaseDateByOneMonth(stDate Date) {

        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
            Date.Month++;

        short CurrentNumberOfMonths = NumberOfDaysInMonth(Date.Year, Date.Month);

        if (Date.Day > CurrentNumberOfMonths)
        {
            Date.Day = CurrentNumberOfMonths;
        }

        return Date;
    }

    stDate IncreaseDateByXMonths(stDate Date, short Months) {

        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);

        }

        return Date;
    }

    stDate IncreaseDateByOneYear(stDate Date) {

        Date.Year++;

        return Date;

    }

    stDate IncreaseDateByXYears(stDate Date, short Years) {

        for (short i = 1; i <= Years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }

        return Date;
    }

    stDate IncreaseDateByXYearsFaster(stDate Date, short Years) {


        Date.Year += Years;


        return Date;
    }

    stDate IncreaseDateByOneDecade(stDate Date) {



        Date.Year += 10;


        return Date;
    }

    stDate IncreaseDateByXDecade(stDate Date, short Decades) {

        for (short i = 1; i <= Decades * 10; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }


        return Date;
    }

    stDate IncreaseDateByXDecadeFaster(stDate Date, short Decades) {


        Date.Year += Decades * 10;



        return Date;
    }

    stDate IncreaseDateByOneCentury(stDate Date) {


        Date.Year += 100;



        return Date;
    }

    stDate IncreaseDateByOneMillennium(stDate Date) {


        Date.Year += 1000;



        return Date;
    }
}