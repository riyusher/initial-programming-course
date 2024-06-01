#include <stdio.h>

int peticionMenu() {
    int peticion;
    
    printf("\n\tMcDonalds\n\n");
    printf("1. Hamburguer\t\t$15\t\t5. Root Beer\t\t$10\n");
    printf("2. CheeseBurguer\t$19\t\t6. Orangeade\t\t$10\n");
    printf("3. French Fries\t\t$10\t\t7. Coca Cola\t\t$10\n");
    printf("4. Milk\t\t\t$10\t\t8. Coffe\t\t$10\n");

    scanf("%d", &peticion);
    
    return peticion;
}

void imprimirResultadoMenu(int opcion) {
    switch(opcion) {
        case 1:
            printf("Ha elegido Hamburguer por el costo de $15");
        break;
        case 2:
            printf("Ha elegido CheeseBurguer por el costo de $19");
        break;
        case 3:
            printf("Ha elegido French Fries por el costo de $10");
        break;
        case 4:
            printf("Ha elegido Milk por el costo de $10");
        break;
        case 5:
            printf("Ha elegido Root Beer por el costo de $10");
        break;
        case 6:
            printf("Ha elegido Orangeade por el costo de $10");
        break;
        case 7:
            printf("Ha elegido Coca Cola por el costo de $10");
        break;
        case 8:
            printf("Ha elegido Coffe por el costo de $10");
        break;
        default:
            printf("\nOpción no valida\n");
        break;
    }
}

int main() {
    int opcion;
    
    opcion = peticionMenu();
    imprimirResultadoMenu(opcion);
    
    return 0;
}