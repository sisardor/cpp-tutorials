#include<stdio.h>
#include<stdbool.h>

/* check to if first array contains same valuein second array */
bool isContained(unsigned int arr1[], unsigned int arr2[], unsigned int len) {
  for (size_t i = 0; i < len; i++) {
    bool contains = false;
    for (size_t j = 0; j < len; j++) {
      if (arr1[i] == arr2[j]) {
        contains = true;
        break;
      }
    }
    if (!contains)
      return false;
  }
  return true;
}


int scrambled(unsigned int arr1[], unsigned int arr2[], unsigned int len) {
  if (len == 0) return 1;
  if (! isContained(arr1, arr2, len)) {
    return 0;
  } else if (! isContained(arr2, arr1, len)) {
    return 0;
  }
  return 1;
}

void test() {
  unsigned int test1_arr1[3] = {10,15,20}, test1_arr2[3] = {10,15,20};
  unsigned int test2_arr1[1] = {99}, test2_arr2[1] = {99};
  unsigned int test3_arr1[5] = {1,2,3,4,5}, test3_arr2[5] = {5,3,4,2,1};
  unsigned int test4_arr1[0] = {}, test4_arr2[0] = {};
  unsigned int test5_arr1[5] = {2,1,3,4,5}, test5_arr2[5] = {1,2,4,3,5};
  unsigned int test6_arr1[2] = {1,1}, test6_arr2[2] = {1,2};
  unsigned int test7_arr1[3] = {10,15,20}, test7_arr2[3] = {10,15,21};
  unsigned int test8_arr1[5] = {1,2,3,4,5}, test8_arr2[5] = {5,3,4,2,2};
  printf("Test 1: %d\n", scrambled( test1_arr1, test1_arr2, 3 ) );
  printf("Test 2: %d\n", scrambled( test2_arr1, test2_arr2, 1 ) );
  printf("Test 3: %d\n", scrambled( test3_arr1, test3_arr2, 5 ) );
  printf("Test 4: %d\n", scrambled( test4_arr1, test4_arr2, 0 ) );
  printf("Test 5: %d\n", scrambled( test5_arr1, test5_arr2, 5 ) );
  printf("Test 6: %d\n", scrambled( test6_arr1, test6_arr2, 2 ) );
  printf("Test 7: %d\n", scrambled( test7_arr1, test7_arr2, 3 ) );
  printf("Test 8: %d\n", scrambled( test8_arr1, test8_arr2, 5) );
}

int main(int argc, char const *argv[]) {
  unsigned int arr1[5] = {1,2,3,4,5};
  unsigned int arr2[5] = {5,3,4,2,1};

  if( scrambled( arr1, arr2, 5 ) == 1 )
  {
     printf( "arr2 is a scrambled version of arr1\n" );
  } else {
     printf( "arr2 has different contents to arr1\n" );
  }

  test();

  return 0;
}
