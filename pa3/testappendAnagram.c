/*
 * Filename: testappendAnagram.c
 * Author: Vanessa Chou
 * Userid: cs30xhu
 * Description: Unit test program to test the function appendAnagram.
 * Date: 5/12/2015
 * Sources of Help: Piazza, PA1 instructions.
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include "pa3.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */
#include <string.h>
#include <stdio.h>

struct anagramHeader * header;
struct anagram * anagram1;
struct anagram * anagram2;
char words1[]="helloworld";
char words2[]="byeworld";
int i;

void
testappendAnagram()
{
    printf( "Testing appendAnagram()\n" );
    
    header=malloc(sizeof(struct anagramHeader));
    header->anagrams=NULL;
    header->numElements=0;
    anagram1=malloc(sizeof(struct anagram)); 
    for(i=0; i<strlen(words1); i++){
        anagram1->word[i]= words1[i];
    }

    appendAnagram(header, anagram1);
    
    TEST(header->anagrams[0].word[0]=='h');
    TEST(header->anagrams[0].word[1]=='e');
    TEST(header->anagrams[0].word[2]=='l');
    TEST(header->anagrams[0].word[3]=='l');
    TEST(header->anagrams[0].word[4]=='o');
    TEST(header->anagrams[0].word[5]=='w');
    TEST(header->anagrams[0].word[6]=='o');
    TEST(header->anagrams[0].word[7]=='r');
    TEST(header->anagrams[0].word[8]=='l');
    TEST(header->anagrams[0].word[9]=='d');
    TEST(header->numElements==1);


    anagram2=malloc(sizeof(struct anagram)); 
    for(i=0; i<strlen(words2) ; i++){
        anagram2->word[i]= words2[i];
    }
    appendAnagram(header, anagram2);

    TEST(header->anagrams[0].word[0]=='h');
    TEST(header->anagrams[0].word[1]=='e');
    TEST(header->anagrams[0].word[2]=='l');
    TEST(header->anagrams[0].word[3]=='l');
    TEST(header->anagrams[0].word[4]=='o');
    TEST(header->anagrams[0].word[5]=='w');
    TEST(header->anagrams[0].word[6]=='o');
    TEST(header->anagrams[0].word[7]=='r');
    TEST(header->anagrams[0].word[8]=='l');
    TEST(header->anagrams[0].word[9]=='d');

    TEST(header->anagrams[1].word[0]=='b');
    TEST(header->anagrams[1].word[1]=='y');
    TEST(header->anagrams[1].word[2]=='e');
    TEST(header->anagrams[1].word[3]=='w');
    TEST(header->anagrams[1].word[4]=='o');
    TEST(header->anagrams[1].word[5]=='r');
    TEST(header->anagrams[1].word[6]=='l');
    TEST(header->anagrams[1].word[7]=='d');
    TEST(header->numElements==2);
    printf( "Finished running tests on appendAnagram()\n" );
}

int
main()
{
    testappendAnagram();

    return 0;
}

