#include <stdio.h>


void imprimirMenu() {
    printf("\n\tMcDonalds\n\n");
    printf("1. Hamburguer\t\t$15\t\t5. Root Beer\t\t$10\n");
    printf("2. CheeseBurguer\t$19\t\t6. Orangeade\t\t$10\n");
    printf("3. French Fries\t\t$10\t\t7. Coca Cola\t\t$10\n");
    printf("4. Milk\t\t\t$10\t\t8. Coffe\t\t$10\n");
}

void mostrarOpcionYTotal() {
    int opcion, total = 0;
    do {
        imprimirMenu();
        scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("Ha elegido Hamburguer por el costo de $15\n");
            total += 15;
            printf("El total hasta el momento es: $%d\n", total);
        break;
        case 2:
            printf("Ha elegido CheeseBurguer por el costo de $19\n");
            total += 19;
            printf("El total hasta el momento es: $%d\n", total);
        break;
        case 3:
            printf("Ha elegido French Fries por el costo de $10\n");
            total += 10;
            printf("El total hasta el momento es: $%d\n", total);
        break;
        case 4:
            printf("Ha elegido Milk por el costo de $10\n");
            total += 10;
            printf("El total hasta el momento es: $%d\n", total);
        break;
        case 5:
            printf("Ha elegido Root Beer por el costo de $10\n");
            total += 10;
            printf("El total hasta el momento es: $%d\n", total);
        break;
        case 6:
            printf("Ha elegido Orangeade por el costo de $10\n");
            total += 10;
            printf("El total hasta el momento es: $%d\n", total);
        break;
        case 7:
            printf("Ha elegido Coca Cola por el costo de $10\n");
            total += 10;
            printf("El total hasta el momento es: $%d\n", total);
        break;
        case 8:
            printf("Ha elegido Coffe por el costo de $10\n");
            total += 10;
            printf("El total hasta el momento es: $%d\n", total);
        break;
        default:
            printf("\nOpción no valida\n");
        break;
    }
    printf("\nPresione 1 Para Seguir Comprando\n");
    printf("Presione 0 Para Terminar la Compra\n");
    scanf("%d", &opcion);
    } while(opcion != 0);

    printf("\nEl Total es $%d\n", total);
    
}

int main() {
    mostrarOpcionYTotal();
    return 0;
}