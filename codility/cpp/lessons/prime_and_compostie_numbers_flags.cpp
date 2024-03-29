/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/flags/)
 * 
 * A non-empty array A consisting of N integers is given.
 * A peak is an array element which is larger than its neighbours. More precisely, it is an index P such that 0 < P < N ? 1 and A[P ? 1] < A[P] > A[P + 1].
 * 
 * @example The following array A:
 *     A[0] = 1
 *     A[1] = 5
 *     A[2] = 3
 *     A[3] = 4
 *     A[4] = 3
 *     A[5] = 4
 *     A[6] = 1
 *     A[7] = 2
 *     A[8] = 3
 *     A[9] = 4
 *     A[10] = 6
 *     A[11] = 2
 * has exactly four peaks: elements 1, 3, 5 and 10.
 * 
 * You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. You have to choose how many flags you should take with you.
 * The goal is to set the maximum number of flags on the peaks, according to certain rules.
 * Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K.
 * The distance between indices P and Q is the absolute value |P ? Q|.
 * 
 * @example Given the mountain range represented by array A, above, with N = 12, if you take:
 *  two flags, you can set them on peaks 1 and 5;
 *  three flags, you can set them on peaks 1, 5 and 10;
 *  four flags, you can set only three flags, on peaks 1, 5 and 10.
 * You can therefore set a maximum of three flags in this case.
 * 
 * Write a function:
 *  int solution(vector<int> &A);
 * that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.
 * 
 * @example The following array A:
 *     A[0] = 1
 *     A[1] = 5
 *     A[2] = 3
 *     A[3] = 4
 *     A[4] = 3
 *     A[5] = 4
 *     A[6] = 1
 *     A[7] = 2
 *     A[8] = 3
 *     A[9] = 4
 *     A[10] = 6
 *     A[11] = 2
 * the function should return 3, as explained above.
 * 
 * @note Assumptions:
 *  - N is an integer within the range [1..400,000];
 *  - each element of array A is an integer within the range [0..1,000,000,000].
 * 
*/

#include <math.h>

int solution(vector<int> &A) {
  /**
   * @note Time complexity: O(N * log(N))
   * 
   */
  const int kArr_size = A.size();
  if (kArr_size < 3) return 0;

  vector<int> peaks;
  for (int i = 1; i < kArr_size - 1; i++) {
    if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
      peaks.push_back(i);
    }
  }

  const int kPeak_size = peaks.size();  
  if ((kPeak_size == 0) || (kPeak_size == 1)) return kPeak_size;

  int num_flag = 1, peak_max = 0;
  int peak_limit = min(kPeak_size, static_cast<int>(sqrt(kArr_size)) + 1);
  for (int k = peak_limit; k >= 1; k--) {
    int last_flag = 0;
    num_flag = 1;
    for (int i = 1; i < kPeak_size; i++) {
      if ((peaks[i] - peaks[last_flag] >= k) && (num_flag < k)) {
        num_flag++;
        last_flag = i;
      }
    }
    if (num_flag < peak_max) return peak_max;
    else if (peak_max < num_flag) peak_max = num_flag;
  }

  return num_flag;
}