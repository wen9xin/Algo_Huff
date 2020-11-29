#ifndef __HUFFMAN_CODE__
#define __HUFFMAN_CODE__

struct code_char {
    int lg;
    int code[256]; /* ne contient que des 0 ou des 1 */
};

void InitTableHuff(Arbre huff,int cd[],int lg);


#endif
