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

uint8 add(uint8 m, uint8 n) {
    uint8 sum = m ^ n;
    uint8 carry = m & n;

    for (int i = 0; i < carry; i) {
        carry = carry << 1;
        m = sum;
        n = carry;
        sum = m ^ n;
        carry = m & n;
    }

    return sum;
}

uint8 sub(uint8 m, uint8 n) {
    uint8 complement = (uint8) (n ^ 255);
    uint8 x = add(complement, 1);

    return add(m,x);
}

uint8 mod(uint8 n, uint8 divisor) {
    for (int i = 0; n > divisor ; i) {
        n = sub(n, divisor);
    }

    if (n == divisor) {
        n = sub(n, divisor);
    }

    return n;
}


void XORSeeds(SEED s1, SEED s2, SEED seed) {
    for (int i = 0; i < num_cards; ++i) {
        seed[i] = s1[i] ^ s2[i];
    }
}

void initDeck(DECK deck) {
    for (int j = 0; j < num_cards; ++j) {
        deck[j] = (uint8) (j + 1);
    }
}

void shuffleDeck(DECK deck, SEED seed) {
    initDeck(deck);

    uint8 card = 0;
    uint8 s = 0;
    for (int i = 0; i < num_cards; ++i) {
        s = mod(seed[i], num_cards);
        card = deck[i];
        deck[i] = deck[s];
        deck[s] = card;
    }
}

void syncOutput(DECK deck, DECK output) {
    for (int i = 0; i < num_cards; ++i) {
        output[i] = deck[i];
    }
}

int main() {
    SEED input1 = {0}, input2 = {0};
    SEED seed = {0};
    XORSeeds(input1, input2, seed);

    DECK deck = {0}, output1 = {0}, output2 = {0};
    shuffleDeck(deck, seed);

    syncOutput(deck, output1);
    syncOutput(deck, output2);

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
