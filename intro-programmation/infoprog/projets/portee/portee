int dernier;
int prochainFacteur(int a)
{
int facteurs = 0;
for(int i = dernier + 1; i <= a; i++)
{
if (a % i == 0)
{
dernier = i;
return dernier;
}
}
}
int nbFacteurs(int a)
{
int facteurs = 0;
for(int i = 1; i <= a; i++)
facteurs += (a % i == 0);
return facteurs;
}
int main()
{
dernier = 0;
int z = 55;
for (int i = 0; i < nbFacteurs(z); i++)
printf("%d", prochainFacteur(z));
}