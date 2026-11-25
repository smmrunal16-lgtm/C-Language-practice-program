/* Structures, unions, enums and bitwise operators. */
#include <stdio.h>

typedef enum { BASIC = 1, PREMIUM = 2, VIP = 3 } Membership;
typedef struct { unsigned int active : 1; unsigned int admin : 1; } UserFlags;
typedef union { unsigned int whole; unsigned char bytes[sizeof(unsigned int)]; } NumberBytes;

int main(void) {
    struct Student { int roll; char name[32]; float marks; };
    struct Student student = {16, "Mrunal", 91.5f};
    Membership level = PREMIUM;
    UserFlags flags = {1, 0};
    NumberBytes data = {.whole = 0x12345678u};

    printf("Student: %d %s %.1f\n", student.roll, student.name, student.marks);
    printf("Membership enum: %d; active=%u admin=%u\n", level, flags.active, flags.admin);
    unsigned int a = 12u, b = 10u;
    printf("AND=%u OR=%u XOR=%u LEFT_SHIFT=%u RIGHT_SHIFT=%u\n",
           a & b, a | b, a ^ b, a << 1, a >> 1);
    printf("Union first byte (platform byte order): %u\n", (unsigned)data.bytes[0]);
    return 0;
}
