// *****************************************************************************
// Nom : structures-2-points-3d.c
// Auteur : 
// Date : 21 septembre 2018
//
// Exercice sur les structures
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>


typedef struct  Point3d Point3d;
struct Point3d{
	double x;
	double y;
	double z;
	
};


Point3d symetrieXY ( Point3d coord ){
	
	Point3d retour;

	retour.x = coord.x;
	retour.y = coord.y;
	retour.z = coord.z  * (-1)  ;

	return retour;

}


Point3d translation ( Point3d coord1, Point3d coord2  ){
	
	Point3d retour;

	retour.x = coord1.x + coord2.x;
	retour.y = coord1.y + coord2.y;
	retour.z = coord1.z + coord2.z;

	return retour;

}



int main(int argc, char const *argv[])
{
	
	Point3d p = { 0,0,2};
	Point3d p2 = { 1,1,1};

	Point3d sym = symetrieXY(p);
	Point3d trans = translation(p,p2);

	printf("La syméetrie par rapport au plan XY de (%lf, %lf, %lf\n)", p.x, p.y, p.z );
	printf(" est (%lf, %lf, %lf\n", sym.x, sym.y, sym.z  );

	printf("\n\n\n\n");

	printf("La translation point (%lf, %lf, %lf\n) et ( %lf, %lf, %lf\n ) est ( %lf, %lf, %lf\n )", p.x, p.y, p.z, p2.x, p2.y, p2.z , trans.x, trans.y, trans.z  );


}