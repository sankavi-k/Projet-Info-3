#include <stdio.h>
#include "year_data.h"

int main() {

    StatAnnee tab[NB_ANNEES];

    initialiserYearData(tab);

    menuYearData(tab);

    return 0;
}