#include "headers.h"
#include <time.h>

void get_current_date(date *current)
{
	time_t timestamp = time(NULL);
	struct tm *timeInfos = localtime(&timestamp);

	current->dd = timeInfos->tm_mday;
	current->mm = timeInfos->tm_mon + 1;
	current->yy = timeInfos->tm_year + 1900;
}

// this function is developed for this software only , means that it's designed only to support adding a maximum of 21 days to a date
void ajouter_jours(date *debut, int days, date *delai)
{
	delai->mm = debut->mm;
	delai->yy = debut->yy;
	if (debut->dd + days <= 28)
	{
		delai->yy = debut->yy;
		delai->mm = debut->mm;
		delai->dd = debut->dd + days;
		return;
	}
	int nbr_jours;
	if (debut->mm == 2)
	{
		if (debut->yy % 4 == 0)
		{
			if (debut->yy % 100 == 0)
			{
				if (debut->yy % 400 == 0)
					nbr_jours = 29;
				else
					nbr_jours = 28;
			}
			else
				nbr_jours = 29;
		}
		else
			nbr_jours = 29;
	}
	else if (debut->mm == 1 || debut->mm == 3 || debut->mm == 5 || debut->mm == 7 || debut->mm == 8 || debut->mm == 10 || debut->mm == 12)
	{
		nbr_jours = 31;
	}
	else
	{
		nbr_jours = 30;
	}
	if (debut->dd + days > nbr_jours)
	{
		delai->dd = debut->dd + days - nbr_jours;
		if (debut->mm == 12)
		{

			delai->yy = debut->yy + 1;

			delai->mm = 1;
			return;
		}
		delai->mm = debut->mm + 1;
		return;
	}
	printf("here");
	delai->dd = debut->dd + days;
	return;
}

int test_date(date *date)
{
	// menich 3aref 3lech ta3mel erreur fil creation mta3 l date
	// date* current = (date*)malloc(sizeof(date));
	// get_current_date(current);
	if (date->yy < 1 || date->yy > 2023 || date->dd < 1 || date->dd > 31 || date->mm < 1 || date->mm > 12)
	{ // add a condition for max date using current date
		return -1;
	}
	if (date->mm == 2 && date->dd == 29)
	{
		if (date->yy % 4 != 0)
		{
			return -1;
		}
		if (date->yy % 100 == 0)
		{
			if (date->yy % 400 == 0)
				return 1;
			else
				return -1;
		}
		if (date->mm == 2 && date->dd == 28)
		{
			return 1;
		}
		else if (date->mm == 1 || date->mm == 3 || date->mm == 5 || date->mm == 7 || date->mm == 8 || date->mm == 10 || date->mm == 12)
		{
			return 1;
		}
		else
		{
			if (date->dd <= 30)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
}
