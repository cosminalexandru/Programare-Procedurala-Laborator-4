

#include <stdio.h>
#include <string.h>
typedef struct {
    char address[100];
    int surface, rooms_number;
    char property_type[30];
    union extra {
        char balcony[2];
        char apartment_type[2];
        char house_type[20];
    } extra_info;
} Building;

int main() {
    Building proprieties[100];
    int number_of_properties;
    printf("Insert number of properties: ");
    scanf("%d", &number_of_properties);
    for (int i = 0; i < number_of_properties; i++) {
        printf("------------------Property %d --------------------- \n", i);
        printf("Insert address");
        scanf("%s", proprieties[i].address);
        printf("Insert surface: ");
        scanf("%d", &proprieties[i].surface);
        printf("Insert property type:");
        scanf("%s", proprieties[i].property_type);
        while (strcmp(proprieties[i].property_type, "casa") != 0 &&
               strcmp(proprieties[i].property_type, "apartament") != 0 &&
               strcmp(proprieties[i].property_type, "garsoniera") != 0) {
            printf("Te rog sa incerci din nou!%s\nTip locuinta (apartament/casa/garsoniera) : ",
                   proprieties[i].property_type);
            scanf("%s", proprieties[i].property_type);
        }
        if (strcmp(proprieties[i].property_type, "garsoniera") == 0) {
            printf("Are balcon?(1/0)");
            scanf("%s", proprieties[i].extra_info.balcony);
            while (strcmp(proprieties[i].extra_info.balcony, "1") != 0
                   && strcmp(proprieties[i].extra_info.balcony, "0") != 0) {
                printf("Te rog sa incerci din nou!\nBalcon(1/0): ");
                scanf("%s", proprieties[i].extra_info.balcony);
            }
        } else if (strcmp(proprieties[i].property_type, "apartament") == 0) {
            printf("Decomandat/Nedecomandat?(D/N)");
            scanf("%c", proprieties[i].extra_info.apartment_type);
            while (strcmp(proprieties[i].extra_info.apartment_type, "D") != 0 &&
                   strcmp(proprieties[i].extra_info.apartment_type, "N") != 0) {
                printf("Te rog sa incerci din nou!\nDecomandat(D/N): ");
                scanf("%s", proprieties[i].extra_info.apartment_type);
            }
        } else if (strcmp(proprieties[i].property_type, "casa") == 0) {
            printf("Introduceti tipul casei: ");
            scanf("%s", proprieties[i].extra_info.house_type);
            while (strcmp(proprieties[i].extra_info.house_type, "nr_etaje") != 0 &&
                   strcmp(proprieties[i].extra_info.house_type, "parter+mansarda") != 0 &&
                   strcmp(proprieties[i].extra_info.house_type, "pe_sol") != 0) {
                printf("Te rog sa incerci din nou!\nTip(pe_sol, parter+mansarda, nr_etaje): ");
                scanf("%s", proprieties[i].extra_info.house_type);
            }
        }
    }

    int max_surface = 0;

    for (int i = 0; i < number_of_properties; i++) {
        if (strcmp(proprieties[i].extra_info.balcony, "1") == 0 &&
            max_surface < proprieties[i].surface) { max_surface = i; }
    }

    printf("Locuinta cu suprafata maxima este %s de la adresa %s, cu suprafata de %u m^2.\n",
           proprieties[max_surface].property_type, proprieties[max_surface].address, proprieties[max_surface].surface);
}