//#include "stdlib.h"
#include "iostream"
//#include "math.h"
//#include "bitset"

const uint8_t NUM_CARDS = 52;

typedef uint8_t DECK[NUM_CARDS];
typedef uint8_t SEED[NUM_CARDS];

DECK deck = {0};
SEED seed = {0};

uint8_t add(uint8_t m, uint8_t n) {
    uint8_t sum = m ^ n; // m XOR n
    uint8_t carry = m & n; // m AND n

    while (carry != 0) {
        carry = carry << 1; // left shift the carry
        m = sum; // initialize m as sum
        n = carry; // initialize n as carry
        sum = m ^ n; // sum is calculated
        carry = m & n; /* carry is calculated, the loop condition is
                          evaluated and the process is repeated until
                          carry is equal to 0.
                        */
    }

    return sum;
}

uint8_t sub(uint8_t m, uint8_t n) {
    uint8_t complement = (uint8_t) (n ^ 255);
    uint8_t x = add(complement, 1);

    return add(m,x);
}

uint8_t mod(uint8_t n, uint8_t divisor) {
//    return (CARD) (n % divisor); /* expect compiler will not accept this */

    while (n > divisor) {
        n = sub(n, divisor);
    }

    if (n == divisor) {
        n = sub(n, divisor);
    }

    return n;
}


void XORSeed(SEED s1, SEED s2) {
    for (int i = 0; i < sizeof(SEED); ++i) {
        seed[i] = s1[i] ^ s2[i];
    }
}

void shuffleDeck() {
    uint8_t s = 0;
    uint8_t card = 0;

    for (int i = 0; i < sizeof(SEED); ++i) {
        s = mod(seed[i],NUM_CARDS);
        card = deck[i];
        deck[i] = deck[s];
        deck[s] = card;
    }
}

/* NOT NEEDED FUNCTIONS ONLY FOR TESTING */

/*
void initSeed(SEED s) {
    for (int i = 0; i < sizeof(SEED); ++i) {
        s[i] = rand();
    }
}

void sortDeck() {
    for (int i = 0; i < sizeof(DECK); ++i) {
        uint8_t card = i + 1;
        deck[i] = card;
    }
}


void printSeed(SEED s) {
    printf("SEED: ");
    for (int i = 0; i < sizeof(SEED); ++i) {
        printf("%u, ", s[i]);
    }
    printf("\n");
}

void printDeck() {
    printf("DECK: ");
    for (int i = 0; i < sizeof(DECK); ++i) {
        printf("%u, ", deck[i]);
    }
    printf("\n");
}


void testAdd() {
    printf("___TEST ADD___\n");
    int s = 1;
    int f = 0;

    for (int i = 0; i < pow(2,8); ++i) {
        for (int j = 0; j < pow(2,8); ++j) {
            uint8_t a = add(i, j);
            uint8_t b = i + j;

            if (a != b) {
                char c = i ^ j;
                char d = i & j;

                s = 0;
                std::bitset<8> x(a);
                std::bitset<8> y(b);
                std::bitset<8> z(c);
                std::bitset<8> w(d);

                std::cout << i << " + " << j << ": FAILED! was: " << x << ", should have been: " << y << ". "
                          << "c: " << w << ", x: " << z << std::endl;
                f++;
            }
        }
    }

    if (s == 1) {
        printf("SUCCESS!\n\n");
    } else {
        printf("%u FAILED ATTEMPTS\n\n", f);
    }
}

void testSub() {
    printf("___TEST SUB___\n");
    int s = 1;
    int f = 0;

    for (int i = 0; i < pow(2,8); ++i) {
        for (int j = 0; j < pow(2,8); ++j) {
            uint8_t a = sub(i, j);
            uint8_t b = i - j;

            if (a != b) {
                char c = i ^ j;
                char d = i & j;

                s = 0;
                std::bitset<8> x(a);
                std::bitset<8> y(b);
                std::bitset<8> z(c);
                std::bitset<8> w(d);

                std::cout << i << " + " << j << ": FAILED! was: " << x << ", should have been: " << y << ". "
                          << "c: " << w << ", x: " << z << std::endl;
                f++;
            }
        }
    }

    if (s == 1) {
        printf("SUCCESS!\n\n");
    } else {
        printf("%u FAILED ATTEMPTS\n\n", f);
    }
}

void testMod() {
    printf("___TEST MOD___\n");
    int s = 1;
    int f = 0;

    for (int i = 0; i < pow(2,8); ++i) {
        for (int j = 1; j < pow(2,8); ++j) {
            uint8_t a = mod(i, j);
            uint8_t b = i % j;


            if (a != b) {
                char c = i ^ j;
                char d = i & j;

                s = 0;
                std::bitset<8> x(a);
                std::bitset<8> y(b);
                std::bitset<8> z(c);
                std::bitset<8> w(d);

                std::cout << i << " + " << j << ": FAILED! was: " << x << ", should have been: " << y << ". "
                          << "c: " << w << ", x: " << z << std::endl;
                f++;
            }
        }
    }

    if (s == 1) {
        printf("SUCCESS!\n\n");
    } else {
        printf("%u FAILED ATTEMPTS\n\n", f);
    }
}
*/


void main() {
//    testAdd();
//    testSub();
//    testMod();

//    sortDeck();
//    printDeck();

    SEED s1, s2;
//    initSeed(s1);
//    initSeed(s2);

    XORSeed(s1, s2);
//    printSeed(seed);

    shuffleDeck();
//    printDeck();
}