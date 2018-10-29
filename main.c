#include <stdio.h>
/**
 * Enum
 */
enum {
    Encryption,
    Decryption
};

/**
 * Union
 */
typedef union {
    int number : 16;
    char v[2];
} Fields;

/**
 *
 * @param value - the element that will be changed
 * @param type - the operation type - Encryption/Decryption
 * @return new value obtained after Encryption/Decryption
 */
Fields swap_order(Fields value, int type) {
    switch (type) {
        case Encryption: {
            char aux = value.v[0];
            value.v[0] = value.v[1];
            value.v[1] = aux;
            return value;
        }
        case Decryption: {
            char aux = value.v[1];
            value.v[1] = value.v[0];
            value.v[0] = aux;
            return value;
        }
        default:
            return value;
    }
}

int main() {
    Fields var, returned_var;
    int aux_number;
    printf("Insert number");
    scanf("%d", &aux_number);
    var.number = aux_number;
    returned_var = swap_order(var, Decryption);
    printf("Encrypted number is:%d", returned_var.number);

}