#include <stdlib.h>
#include <stdio.h>

int divise(int denominateur, int numerateur)
{
	return ((numerateur % denominateur) == 0);
}

int nbFacteurs(int a)
{
	int facteurs = 0;
	for (int i = 1; i <= a; i ++)
	{
		if (divise(i, a))
		{
			facteurs++;
		}
	}
	return facteurs;
}

int estPremier(int a)
{
	return (nbFacteurs(a) == 2);
}

int main()
{
	for (int i = 0; i < 10000; i++)
	{
		int premier = estPremier(i);
		if (premier)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}