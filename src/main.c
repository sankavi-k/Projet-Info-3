#include<stdio.h>
#include "year_data.h"
#include "age_data.h"
#include "crash_data.h"
#include "interface.h"
#include "csv.h"

int main(){

    StatAnnee tab[NB_ANNEES];

    initialiserAnnees(tab);

    menuYearData(tab);

    return 0;
}