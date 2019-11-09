#include "Date.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ext;

namespace ext
{

	TimeDelta countJDN(Date date)
	{
		int a = (14 - static_cast<int>(date.month)) / 12;
		int y = date.year + 4800 - a;
		int m = static_cast<int>(date.month) + (12 * a) - 3;

		int JDN = date.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045;

		return TimeDelta{ JDN };

	}

	TimeDelta countDistance(Date from, Date to)
	{
		int a = (14 - static_cast<int>(from.month)) / 12;
		int y = from.year + 4800 - a;
		int m = static_cast<int>(from.month) + (12 * a) - 3;

		int JDN1 = from.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045;

		a = (14 - static_cast<int>(to.month)) / 12;
		y = to.year + 4800 - a;
		m = static_cast<int>(to.month) + (12 * a) - 3;

		int JDN2 = to.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045;

		int distance = JDN2 - JDN1;

		return TimeDelta{ distance };
	}

	string monthToString(Month month)
	{
		switch (month)
		{
		case Month::December:
			return "December";
		case Month::January:
			return "January";
		case Month::February:
			return "February";
		case Month::March:
			return "March";
		case Month::April:
			return "April";
		case Month::May:
			return "May";
		case Month::June:
			return "June";
		case Month::July:
			return "July";
		case Month::August:
			return "August";
		case Month::September:
			return "December";
		case Month::October:
			return "November";
		case Month::November:
			return "November";
		default:
			throw exception("Invalid month");
		}
	}

	void print(Date data, DateFormat format)
	{
		cout << data.year << " ";
		print(data.month, format);
		cout << data.day;
	}

	void print(TimeDelta delta)
	{
		cout << delta.delta;
	}

	void print(Month month, DateFormat format)
	{
		if (format == DateFormat::MonthAsInt)
		{
			cout << static_cast<int>(month) << " ";
		}
		else if (format == DateFormat::MonthAsString)
		{
			cout << monthToString(month) << " ";
		}
		else
		{
			throw exception("invalid format of month");
		}
	}

	Season getSeason(Date date)
	{
		switch (date.month)
		{
		case Month::December:
		case Month::January:
		case Month::February:
			return Season::Winter;
		case Month::March:
		case Month::April:
		case Month::May:
			return Season::Spring;
		case Month::June:
		case Month::July:
		case Month::August:
			return Season::Summer;
		case Month::September:
		case Month::October:
		case Month::November:
			return Season::Autumn;
		default:
			throw exception("Invalid Date");
		}
	}

	Season getSeason(Month month) 
	{
		switch (month)
		{
		case Month::December:
		case Month::January:
		case Month::February:
			return Season::Winter;
		case Month::March:
		case Month::April:
		case Month::May:
			return Season::Spring;
		case Month::June:
		case Month::July:
		case Month::August:
			return Season::Summer;
		case Month::September:
		case Month::October:
		case Month::November:
			return Season::Autumn;
		default:
			throw exception("Invalid month");
		}
	}

	bool operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day
			&& lhs.month == rhs.month
			&& lhs.year == rhs.year;
	}

	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}

	bool operator < (const Date lhs, const Date rhs)
	{
		return (lhs.year < rhs.year) || (lhs.year == rhs.year && lhs.month < rhs.month) || (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day);
	}

	bool operator >= (const Date lhs, const Date rhs)
	{
		return !(lhs < rhs);
	}

	bool operator > (const Date lhs, const Date rhs)
	{
		return !(lhs < rhs) && (lhs != rhs);
	}

	bool operator <= (const Date lhs, const Date rhs)
	{
		return !(lhs > rhs);
	}

	Date converter(TimeDelta delta) 
	{
		Date result;
		int a = delta.delta + 32044;
		int b = ((4 * a) + 3) / 146097;
		int c = a - ((146097 * b) / 4);
		int d = ((4 * c) + 3) / 1461;
		int e = c - ((1461 * d) / 4);
		int m = ((5 * e) + 2) / 153;
		result.day = e - ((153 * m + 2) / 5) + 1;
		result.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		result.year = (100 * b) + d - 4800 + (m / 10);
		return result;
	}
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta sum;
		sum.delta = lhs.delta + rhs.delta;
		return sum;
	}
	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta sum = countJND(date);
		return JDNToDate(sum + delta);
	}
	Date operator + (const TimeDelta delta, const Date date) {
		TimeDelta sum = countJND(date);
		return JDNToDate(sum + delta);
	}
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta sum;
		sum.delta = lhs.delta - rhs.delta;
		return sum;
	}
	Date operator - (const Date date, const TimeDelta delta) {
		TimeDelta one = countJND(date);
		return JDNToDate(sum - delta);
	}
	Date operator - (const TimeDelta delta, const Date date) {
		TimeDelta one = countJND(date);
		return JDNToDate(sum - delta);
	}
	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		TimeDelta one;
		one.delta = (delta.delta * multiplier);
		return sum;
	}
	TimeDelta operator / (const TimeDelta delta, int multiplier) {
		TimeDelta one;
		one.delta = (delta.delta / multiplier);
		return sum;
	}
	TimeDelta operator ++ (TimeDelta& delta)
	{
		++delta.delta;
		return delta;
	}
	TimeDelta operator ++ (TimeDelta& delta, int)
	{

		++delta.delta;
		return delta;
	}
	TimeDelta operator -- (TimeDelta& delta)
	{
		--delta.delta;
		return delta;
	}
	TimeDelta operator -- (TimeDelta& delta, int)
	{

		--delta.delta;
		return delta;
	}
	Date operator ++ (Date& delta)
	{
		delta.day++;
		delta.year++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date operator ++ (Date& delta, int)
	{
		delta.day++;
		delta.year++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date operator -- (Date& delta)
	{
		delta.day--;
		delta.year--;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date operator -- (Date& delta, int)
	{
		delta.day--;
		delta.year--;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}

	void swap(Date& lhs, Date& rhs)
	{
		int temp = 0;
		Month temp_m;

		temp = lhs.year;
		lhs.year = rhs.year;
		rhs.year = temp;
		temp = lhs.day;
		lhs.day = rhs.day;
		rhs.day = lhs.day;
		temp_m = lhs.month;
		lhs.month = rhs.month;
		rhs.month = temp_m;
	}

	void swap(TimeDelta& lhs, TimeDelta& rhs)
	{
		TimeDelta temp = lhs;
		lhs = rhs;
		rhs = temp;
	}

	Date& max(Date& lhs, Date& rhs)
	{
		if (lhs > rhs)
		{
			return lhs;
		}
		else
		{
			return rhs;
		}
	}

	Date& min(Date& lhs, Date& rhs)
	{
		if (lhs < rhs)
		{
			return lhs;
		}
		else
		{
			return rhs;
		}
	}

	Date& getMinDate(Date dates[], int size)
	{
		Date& min = dates[0];
		for (int i = 0; i <= size; i++)
		{
			if (dates[i] < min)
			{
				min = dates[i];
			}
		}
		return min;
	}

	Date& getMaxDate(Date dates[], int size)
	{
		Date& max = dates[0];
		for (int i = 0; i <= size; i++)
		{
			if (dates[i] > max)
			{
				max = dates[i];
			}
		}
		return max;
	}

}
