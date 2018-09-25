#ifndef AES_H
#define AES_H 1

#define NUM_COL 4 // Nb
#define NUM_WORDS_128 4 // Nk for 128bit
#define NUM_WORDS_256 8 // Nk for 256bit
#define NUM_ROUNDS_128 10 // Nr for 128bit
#define NUM_ROUNDS_256 14 // Nr for 256bit

#define BLOCK_SIZE 16

typedef enum {
    KEYSIZE_128,
    KEYSIZE_256
} E_KEYSIZE;
typedef enum  {
    MODE_ENCRYPT,
    MODE_DECRYPT
} E_MODE;

typedef struct {
    E_KEYSIZE keysize;
    E_MODE mode;
    int is_verbose;

    char* keyfile;
    char* inputfile;
    char* outputfile;
} Options;

typedef struct {
    unsigned char byte[4][NUM_COL];
} State;

typedef struct {
    unsigned char byte[4][1];
} Word;

typedef Word* Key;
typedef Word* KeySchedule;

Options handleArgs(int, char**);

State** readStates(const char*, size_t*);
long int findSize(const char*);
void printStates(State**);


size_t writeStates(const char*, State**, size_t);

void freeStates(State**);

void subBytes(State*);
void shiftRows(State*);
void mixColumns(State*);
void addRoundKey(State* state, Word* partialSchedule);

KeySchedule generateKeySchedule(const char* keyfile, E_KEYSIZE keysize);
KeySchedule keyExpansion(Key rawKey, E_KEYSIZE keysize);
void copyWord(Word* to, const Word* from);
Word xorWord(Word* left, Word* right);
Word* rotWord(Word* word);
Word* subWord(Word* word);
Word rcon(int i);
Key readKey(const char* filename, E_KEYSIZE keysize);
//void rotWord(State*);
//void subWord(State*);

void invSubBytes(State*);
void invShiftRows(State*);
void invMixColumns(State*);

State** encrypt(E_KEYSIZE, State**, size_t*, KeySchedule);
State** decrypt(E_KEYSIZE, State**, size_t*, KeySchedule);

#endif
