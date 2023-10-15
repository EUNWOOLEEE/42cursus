#include "../incs/miniRT.h"

void print_infos(t_info *info)
{
	printf("element A\n");
	printf("light ratio : %lf\n", info->A.light_ratio);
	printf("RGB : %lf,%lf,%lf\n", info->A.rgb.x, info->A.rgb.y, info->A.rgb.z);

	printf("\nelemant SR\n");
	printf("light ratio : %lf\n", info->SR.light_ratio);
	printf("RGB : %lf,%lf,%lf\n", info->SR.rgb.x, info->SR.rgb.y, info->SR.rgb.z);

	printf("\nelemant C\n");
	printf("view coor : %lf,%lf,%lf\n", info->C.view_coor.x, info->C.view_coor.y, info->C.view_coor.z);
	printf("vector coor : %lf,%lf,%lf\n", info->C.vector_coor.x, info->C.vector_coor.y, info->C.vector_coor.z);
	printf("FOV : %d\n", info->C.FOV);

	printf("\nelement L\n");
	printf("light coor : %lf,%lf,%lf\n", info->L.light_coor.x, info->L.light_coor.y, info->L.light_coor.z);
	printf("light ratio : %lf\n", info->L.light_ratio);
	printf("RGB : %lf,%lf,%lf\n", info->L.rgb.x, info->L.rgb.y, info->L.rgb.z);

	printf("\n\nobject sp\n");
	printf("coor : %lf,%lf,%lf\n", info->sp.coor.x, info->sp.coor.y, info->sp.coor.z);
	printf("diameter : %lf\n", info->sp.diameter);
	printf("RGB : %lf,%lf,%lf\n", info->sp.rgb.x, info->sp.rgb.y, info->sp.rgb.z);

	printf("\nobject pl\n");
	printf("coor : %lf,%lf,%lf\n", info->pl.coor.x, info->pl.coor.y, info->pl.coor.z);
	printf("vector coor : %lf,%lf,%lf\n", info->pl.vector_coor.x, info->pl.vector_coor.y, info->pl.vector_coor.z);
	printf("RGB : %lf,%lf,%lf\n", info->pl.rgb.x, info->pl.rgb.y, info->pl.rgb.z);

	printf("\nobject cy\n");
	printf("coor : %lf,%lf,%lf\n", info->cy.coor.x, info->cy.coor.y, info->cy.coor.z);
	printf("vector coor : %lf,%lf,%lf\n", info->cy.vector_coor.x, info->cy.vector_coor.y, info->cy.vector_coor.z);
	printf("diameter : %lf\n", info->cy.diameter);
	printf("height : %lf\n", info->cy.height);
	printf("RGB : %lf,%lf,%lf\n", info->cy.rgb.x, info->cy.rgb.y, info->cy.rgb.z);

	printf("\nobject co\n");
	printf("coor : %lf,%lf,%lf\n", info->co.coor.x, info->co.coor.y, info->co.coor.z);
	printf("vector coor : %lf,%lf,%lf\n", info->co.vector_coor.x, info->co.vector_coor.y, info->co.vector_coor.z);
	printf("diameter : %lf\n", info->co.diameter);
	printf("height : %lf\n", info->co.height);
	printf("RGB : %lf,%lf,%lf\n", info->co.rgb.x, info->co.rgb.y, info->co.rgb.z);
}