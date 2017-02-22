#include <printf.h>
#include <bitset>
#include <iostream>
#include <stdlib.h>
#include "tiff.h"

#define card_size 8
#define num_cards 52
#define deck_size (card_size * num_cards) /* 52 cards x 8 bits */

typedef uint8 DECK[num_cards];
typedef uint8 SEED[num_cards];

/*
#parties 2

#input 1 SEED
#output 1 DECK
#input 2 SEED
#output 2 DECK
*/


void initSeed(SEED s1, SEED s2, SEED seed) {
    for (uint8_t i = 0; i < num_cards; ++i) {
/*
        seed[i] = s1[i] ^ s2[i];
*/
        seed[i] = rand();
    }
}

void initDeck(DECK deck) {
    for (uint8_t j = 0; j < num_cards; ++j) {
        deck[j] = j + 1;
    }
}

void shuffleDeck(DECK deck, SEED seed) {
    initDeck(deck);

    uint8 card = 0;
    uint8 s = 0;
    for (uint8_t i = 0; i < num_cards; ++i) {
        s = seed[i] % num_cards;
        card = deck[i];

        if (s == 1) {
            deck[i] = deck[1];
            deck[1] = card;
        } else if ( s== 2) {
            deck[i] = deck[2];
            deck[2] = card;
        } else if ( s== 3) {
            deck[i] = deck[3];
            deck[3] = card;
        } else if ( s== 4) {
            deck[i] = deck[4];
            deck[4] = card;
        } else if ( s== 5) {
            deck[i] = deck[5];
            deck[5] = card;
        } else if ( s== 6) {
            deck[i] = deck[6];
            deck[6] = card;
        } else if ( s== 7) {
            deck[i] = deck[7];
            deck[7] = card;
        } else if ( s== 8) {
            deck[i] = deck[8];
            deck[8] = card;
        } else if ( s== 9) {
            deck[i] = deck[9];
            deck[9] = card;
        } else if ( s== 10) {
            deck[i] = deck[10];
            deck[10] = card;
        } else if ( s== 11) {
            deck[i] = deck[11];
            deck[11] = card;
        } else if ( s== 12) {
            deck[i] = deck[12];
            deck[12] = card;
        } else if ( s== 13) {
            deck[i] = deck[13];
            deck[13] = card;
        } else if ( s== 14) {
            deck[i] = deck[14];
            deck[14] = card;
        } else if ( s== 15) {
            deck[i] = deck[15];
            deck[15] = card;
        } else if ( s== 16) {
            deck[i] = deck[16];
            deck[16] = card;
        } else if ( s== 17) {
            deck[i] = deck[17];
            deck[17] = card;
        } else if ( s== 18) {
            deck[i] = deck[18];
            deck[18] = card;
        } else if ( s== 19) {
            deck[i] = deck[19];
            deck[19] = card;
        } else if ( s== 20) {
            deck[i] = deck[20];
            deck[20] = card;
        } else if ( s== 21) {
            deck[i] = deck[21];
            deck[21] = card;
        } else if ( s== 22) {
            deck[i] = deck[22];
            deck[22] = card;
        } else if ( s== 23) {
            deck[i] = deck[23];
            deck[23] = card;
        } else if ( s== 24) {
            deck[i] = deck[24];
            deck[24] = card;
        } else if ( s== 25) {
            deck[i] = deck[25];
            deck[25] = card;
        } else if ( s== 26) {
            deck[i] = deck[26];
            deck[26] = card;
        } else if ( s== 27) {
            deck[i] = deck[27];
            deck[27] = card;
        } else if ( s== 28) {
            deck[i] = deck[28];
            deck[28] = card;
        } else if ( s== 29) {
            deck[i] = deck[29];
            deck[29] = card;
        } else if ( s== 30) {
            deck[i] = deck[30];
            deck[30] = card;
        } else if ( s== 31) {
            deck[i] = deck[31];
            deck[31] = card;
        } else if ( s== 32) {
            deck[i] = deck[32];
            deck[32] = card;
        } else if ( s== 33) {
            deck[i] = deck[33];
            deck[33] = card;
        } else if ( s== 34) {
            deck[i] = deck[34];
            deck[34] = card;
        } else if ( s== 35) {
            deck[i] = deck[35];
            deck[35] = card;
        } else if ( s== 36) {
            deck[i] = deck[36];
            deck[36] = card;
        } else if ( s== 37) {
            deck[i] = deck[37];
            deck[37] = card;
        } else if ( s== 38) {
            deck[i] = deck[38];
            deck[38] = card;
        } else if ( s== 39) {
            deck[i] = deck[39];
            deck[39] = card;
        } else if ( s== 40) {
            deck[i] = deck[40];
            deck[40] = card;
        } else if ( s== 41) {
            deck[i] = deck[41];
            deck[41] = card;
        } else if ( s== 42) {
            deck[i] = deck[42];
            deck[42] = card;
        } else if ( s== 43) {
            deck[i] = deck[43];
            deck[43] = card;
        } else if ( s== 44) {
            deck[i] = deck[44];
            deck[44] = card;
        } else if ( s== 45) {
            deck[i] = deck[45];
            deck[45] = card;
        } else if ( s== 46) {
            deck[i] = deck[46];
            deck[46] = card;
        } else if ( s== 47) {
            deck[i] = deck[47];
            deck[47] = card;
        } else if ( s== 48) {
            deck[i] = deck[48];
            deck[48] = card;
        } else if ( s== 49) {
            deck[i] = deck[49];
            deck[49] = card;
        } else if ( s== 50) {
            deck[i] = deck[50];
            deck[50] = card;
        } else if ( s== 51) {
            deck[i] = deck[51];
            deck[51] = card;
        } else if ( s== 52) {
            deck[i] = deck[52];
            deck[52] = card;
        }
    }
}

void printDeck(DECK deck) {
    printf("DECK: ");
    for (int i = 0; i < num_cards; ++i) {
        printf("%u, ", deck[i]);
    }
    printf("\n");
}

/*
 * TOMORROW DO ADD, SUB, MOD IN ONE FUNCTION
 * */


/*
uint8_t add(uint8_t n, uint8_t tmp) {
    uint8_t sum = n ^ tmp;
    uint8_t carry = n & tmp;

    for (uint8_t i = 0; i < 8; ++i) {
        carry = carry << 1;
        n = sum;
        tmp = carry;
        sum = n ^ tmp;
        carry = n & tmp;
    }

    return sum;
}
*/

/*
uint8_t sub(uint8_t n, uint8_t divisor) {
    uint8_t complement = divisor ^ 255; */
/* 255 in bits is 1111 1111 *//*

    uint8_t one = 1;

    */
/* Calculating: complement + 1 *//*

    uint8_t tmp = complement ^ one;
    uint8_t carry = complement & one;

    for (uint8_t i = 0; i < 8; ++i) {
        carry = carry << 1;
        complement = tmp;
        one = carry;
        tmp = complement ^ one;
        carry = complement & one;
    }

    */
/* Calculating: complement + 1 *//*


    uint8_t sum = n ^ tmp;
    carry = n & tmp;

    for (uint8_t i = 0; i < 8; ++i) {
        carry = carry << 1;
        n = sum;
        tmp = carry;
        sum = n ^ tmp;
        carry = n & tmp;
    }

    return sum;
}
*/

uint8_t mod(uint8_t n, uint8_t divisor) {
    for (uint8_t i = 0; i < 254 ; ++i) {
        if (n >= divisor) {
            uint8_t complement = divisor ^ 255; /* 255 in bits is 1111 1111 */
            uint8_t one = 0;

            /* Calculating: complement + 1 */
            uint8_t tmp = complement ^ 1;
            uint8_t carry = complement & 1;

            for (uint8_t j = 0; j < 7; ++j) {
                carry = carry << 1;
                complement = tmp;
                one = carry;
                tmp = complement ^ one;
                carry = complement & one;
            }

            /* Calculating: n + temp */
            uint8_t sum = n ^ tmp;
            carry = n & tmp;

            for (uint8_t k = 0; k < 8; ++k) {
                carry = carry << 1;
                n = sum;
                tmp = carry;
                sum = n ^ tmp;
                carry = n & tmp;
            }
        }
    }

    return n;
}

void testMod() {
    printf("___TEST MOD___\n");
    int s = 1;
    int f = 0;

    for (int i = 0; i < 255; ++i) {
        for (int j = 1; j < 255; ++j) {
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


int main() {
    SEED input1 = {0}, input2 = {0};
    SEED seed = {0};
    initSeed(input1, input2, seed);

    DECK deck = {0}, output1 = {0}, output2 = {0};
    shuffleDeck(deck, seed);

//    printDeck(deck);

    testMod();
    return 1;
}









/*
const uint8_t NUM_CARDS = 52;

typedef uint8_t DECK[NUM_CARDS];
typedef uint8_t SEED[NUM_CARDS];

DECK deck = {0};
SEED seed = {0};

uint8_t add(uint8_t m, uint8_t n) {
    uint8_t sum = m ^ n;
    uint8_t carry = m & n;

    for (int i = 0; i < carry; i) {
        carry = carry << 1;
        m = sum;
        n = carry;
        sum = m ^ n;
        carry = m & n;
    }

    return sum;
}

uint8_t sub(uint8_t m, uint8_t n) {
    uint8_t complement = (uint8_t) (n ^ 255);
    uint8_t x = add(complement, 1);

    return add(m,x);
}

uint8_t mod(uint8_t n, uint8_t divisor) {
    for (int i = 0; n > divisor ; i) {
        n = sub(n, divisor);
    }

    if (n == divisor) {
        n = sub(n, divisor);
    }

    return n;
}

 void initSeed(SEED s) {
    for (int i = 0; i < sizeof(SEED); ++i) {
        s[i] = rand();
    }
}

void printDeck(DECK deck) {
    printf("DECK: ");
    for (int i = 0; i < num_cards; ++i) {
        printf("%u, ", deck[i]);
    }
    printf("\n");
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

*/
/* NOT NEEDED FUNCTIONS ONLY FOR TESTING *//*


void initSeed(SEED s) {
    for (int i = 0; i < sizeof(SEED); ++i) {
        s[i] = rand();
    }
}

//void sortDeck() {
//    for (int i = 0; i < sizeof(DECK); ++i) {
//        uint8_t card = i + 1;
//        deck[i] = card;
//    }
//}


//void printSeed(SEED s) {
//    printf("SEED: ");
//    for (int i = 0; i < sizeof(SEED); ++i) {
//        printf("%u, ", s[i]);
//    }
//    printf("\n");
//}

void printDeck() {
    printf("DECK: ");
    for (int i = 0; i < sizeof(DECK); ++i) {
        printf("%u, ", deck[i]);
    }
    printf("\n");
}


//void testAdd() {
//    printf("___TEST ADD___\n");
//    int s = 1;
//    int f = 0;
//
//    for (int i = 0; i < pow(2,8); ++i) {
//        for (int j = 0; j < pow(2,8); ++j) {
//            uint8_t a = add(i, j);
//            uint8_t b = i + j;
//
//            if (a != b) {
//                char c = i ^ j;
//                char d = i & j;
//
//                s = 0;
//                std::bitset<8> x(a);
//                std::bitset<8> y(b);
//                std::bitset<8> z(c);
//                std::bitset<8> w(d);
//
//                std::cout << i << " + " << j << ": FAILED! was: " << x << ", should have been: " << y << ". "
//                          << "c: " << w << ", x: " << z << std::endl;
//                f++;
//            }
//        }
//    }
//
//    if (s == 1) {
//        printf("SUCCESS!\n\n");
//    } else {
//        printf("%u FAILED ATTEMPTS\n\n", f);
//    }
//}

//void testSub() {
//    printf("___TEST SUB___\n");
//    int s = 1;
//    int f = 0;
//
//    for (int i = 0; i < pow(2,8); ++i) {
//        for (int j = 0; j < pow(2,8); ++j) {
//            uint8_t a = sub(i, j);
//            uint8_t b = i - j;
//
//            if (a != b) {
//                char c = i ^ j;
//                char d = i & j;
//
//                s = 0;
//                std::bitset<8> x(a);
//                std::bitset<8> y(b);
//                std::bitset<8> z(c);
//                std::bitset<8> w(d);
//
//                std::cout << i << " + " << j << ": FAILED! was: " << x << ", should have been: " << y << ". "
//                          << "c: " << w << ", x: " << z << std::endl;
//                f++;
//            }
//        }
//    }
//
//    if (s == 1) {
//        printf("SUCCESS!\n\n");
//    } else {
//        printf("%u FAILED ATTEMPTS\n\n", f);
//    }
//}

//void testMod() {
//    printf("___TEST MOD___\n");
//    int s = 1;
//    int f = 0;
//
//    for (int i = 0; i < pow(2,8); ++i) {
//        for (int j = 1; j < pow(2,8); ++j) {
//            uint8_t a = mod(i, j);
//            uint8_t b = i % j;
//
//
//            if (a != b) {
//                char c = i ^ j;
//                char d = i & j;
//
//                s = 0;
//                std::bitset<8> x(a);
//                std::bitset<8> y(b);
//                std::bitset<8> z(c);
//                std::bitset<8> w(d);
//
//                std::cout << i << " + " << j << ": FAILED! was: " << x << ", should have been: " << y << ". "
//                          << "c: " << w << ", x: " << z << std::endl;
//                f++;
//            }
//        }
//    }
//
//    if (s == 1) {
//        printf("SUCCESS!\n\n");
//    } else {
//        printf("%u FAILED ATTEMPTS\n\n", f);
//    }
//}

#define deck_size 416

typedef deck_size DECK

int main() {
//    testAdd();
//    testSub();
//    testMod();

//    sortDeck();
//    printDeck();

    uint8_t s1[52], s2[52];
//    initSeed(s1);
//    initSeed(s2);



//    XORSeed(s1, s2);
//    printSeed(seed);

    shuffleDeck();
//    printDeck();

    return 1;
}*/
