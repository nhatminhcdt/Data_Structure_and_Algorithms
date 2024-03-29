/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/6-sorting/distinct/)
 * 
 * Write a function
 *  int solution(vector<int> &A);
 * that, given an array A consisting of N integers, returns the number of distinct values in array A.
 * For example, given array A consisting of six elements such that:
 *  A[0] = 2    A[1] = 1    A[2] = 1
 *  A[3] = 2    A[4] = 3    A[5] = 1
 * the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [0..100,000];
 *  - each element of array A is an integer within the range [?1,000,000..1,000,000].
 * 
*/

#include <unordered_set>

int solution(vector<int> &A) {
  /**
   * @note time complexity: O(N*log(N)) or O(N)
   * 
   */
  
  if (A.empty()) return 0;

  unordered_set<int> distinct_values;

  for (int i = 0; i < A.size(); ++i) {
    distinct_values.insert(A[i]);
  }

  return distinct_values.size();
}