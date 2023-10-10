#include "../incs/miniRT.h"

void print_infos(t_info *info)
{
	printf("element A\n");
	printf("light ratio : %lf\n", info->A.light_ratio);
	printf("RGB : %lld,%lld,%lld\n", info->A.color.R, info->A.color.G, info->A.color.B);

	printf("\nelemant SR\n");
	printf("light ratio : %lf\n", info->SR.light_ratio);
	printf("RGB : %lld,%lld,%lld\n", info->SR.color.R, info->SR.color.G, info->SR.color.B);

	printf("\nelemant C\n");
	printf("view coor : %lf,%lf,%lf\n", info->C.view_coor.x, info->C.view_coor.y, info->C.view_coor.z);
	printf("vector coor : %lf,%lf,%lf\n", info->C.vector_coor.x, info->C.vector_coor.y, info->C.vector_coor.z);
	printf("FOV : %d\n", info->C.FOV);

	printf("\nelement L\n");
	printf("light coor : %lf,%lf,%lf\n", info->L.light_coor.x, info->L.light_coor.y, info->L.light_coor.z);
	printf("light ratio : %lf\n", info->L.light_ratio);
	printf("RGB : %lld,%lld,%lld\n", info->L.color.R, info->L.color.G, info->L.color.B);

	printf("\n\nobject sp\n");
	printf("coor : %lf,%lf,%lf\n", info->sp.coor.x, info->sp.coor.y, info->sp.coor.z);
	printf("diameter : %lf\n", info->sp.diameter);
	printf("RGB : %lld,%lld,%lld\n", info->sp.color.R, info->sp.color.G, info->sp.color.B);

	printf("\nobject pl\n");
	printf("coor : %lf,%lf,%lf\n", info->pl.coor.x, info->pl.coor.y, info->pl.coor.z);
	printf("vector coor : %lf,%lf,%lf\n", info->pl.vector_coor.x, info->pl.vector_coor.y, info->pl.vector_coor.z);
	printf("RGB : %lld,%lld,%lld\n", info->pl.color.R, info->pl.color.G, info->pl.color.B);

	printf("\nobject cy\n");
	printf("coor : %lf,%lf,%lf\n", info->cy.coor.x, info->cy.coor.y, info->cy.coor.z);
	printf("vector coor : %lf,%lf,%lf\n", info->cy.vector_coor.x, info->cy.vector_coor.y, info->cy.vector_coor.z);
	printf("diameter : %lf\n", info->cy.diameter);
	printf("height : %lf\n", info->cy.height);
	printf("RGB : %lld,%lld,%lld\n", info->cy.color.R, info->cy.color.G, info->cy.color.B);

	printf("\nobject co\n");
	printf("coor : %lf,%lf,%lf\n", info->co.coor.x, info->co.coor.y, info->co.coor.z);
	printf("vector coor : %lf,%lf,%lf\n", info->co.vector_coor.x, info->co.vector_coor.y, info->co.vector_coor.z);
	printf("diameter : %lf\n", info->co.diameter);
	printf("height : %lf\n", info->co.height);
	printf("RGB : %lld,%lld,%lld\n", info->co.color.R, info->co.color.G, info->co.color.B);
}