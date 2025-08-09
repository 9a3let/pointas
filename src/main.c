#include <stdio.h>
#include <stdlib.h>

#include "vec3.h"
#include "calcs.h"
#include "types.h"

#define HEAT_MAP_RADIUS 5
#define HEAT_MAP_RESOLUTION 0.1

int 
charges_enter(Charge **chargesArray)
{
    int i, nCharges;
    float qh, ph1, ph2, ph3;

    do {
        printf("\nEnter the amount of charges.\n> ");
        scanf("%d", &nCharges);
    } 
    while (nCharges < 1);

    *chargesArray = (Charge*) calloc(nCharges, sizeof(Charge));
    if(chargesArray == NULL) {
        perror("Memory error");
        return -1;
    }

    printf("\nEnter the value of a Charge and its corresponding point in [Q(As) X Y Z] format.\n");
    for(i=0; i<nCharges; i++) {
        printf("> ");
        scanf("%f %f %f %f", &qh, &ph1, &ph2, &ph3);
        (*chargesArray)[i].value = qh;

        (*chargesArray)[i].point.x = ph1;
        (*chargesArray)[i].point.y = ph2;
        (*chargesArray)[i].point.z = ph3;
    }

    return nCharges;
}

int 
main(void)
{
    int i, n;
    float fi, fj;
    int amountOfCharges;
    Charge *charges = NULL;
    Vec3f netForce = VEC3F_NULL;

    printf("\n\t\t Point-As BY LET\n\n");

    amountOfCharges = charges_enter(&charges);
    if(amountOfCharges == -1)
        return 1;

    printf("\n======================\n");
    for(i=0; i<amountOfCharges; i++)
        printf("%d. Q=%e As (%.2fi %.2fj %.2fk)\n", i+1, charges[i].value, charges[i].point.x, charges[i].point.y, charges[i].point.z);

    printf("\nOn which Charge to calculate net force?\n> ");
    do {
        scanf("%d", &n);
    } while (n < 1 || n > amountOfCharges);

    for(i=0; i<amountOfCharges; i++)
        if(i != n-1)
            netForce = vec3f_add(netForce, charge_coulomb_force(charges[i], charges[n-1], 1)); 

    printf("\n~F = (%ei %ej %ek) N\n", netForce.x, netForce.y, netForce.z);
    printf("F = %e N\n\n", vec3f_lenght(netForce));
    
    FILE *fp=fopen("out.tsv", "w");
    for(fi=HEAT_MAP_RADIUS; fi>-HEAT_MAP_RADIUS; fi-=HEAT_MAP_RESOLUTION)
        for(fj=-HEAT_MAP_RADIUS; fj<HEAT_MAP_RADIUS; fj+=HEAT_MAP_RESOLUTION)
            fprintf(fp, "%.2f\t%.2f\t%e\n", fj, fi, vec3f_lenght(net_efield(charges, amountOfCharges, (Point3f){fj,fi,0}, 1)));
    
    free(charges);
    charges = NULL;

    return 0;
}
