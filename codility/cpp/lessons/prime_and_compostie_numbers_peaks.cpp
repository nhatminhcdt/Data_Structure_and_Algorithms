/***
 * 
 * @brief [Task description](https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/)
 * 
 * A non-empty array A consisting of N integers is given.
 * A peak is an array element which is larger than its neighbors. More precisely, it is an index P such that 0 < P < N ? 1,  A[P ? 1] < A[P] and A[P] > A[P + 1].
 * 
 * @example The following array A:
 *     A[0] = 1
 *     A[1] = 2
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
 * has exactly three peaks: 3, 5, 10.
 * We want to divide this array into blocks containing the same number of elements. 
 * More precisely, we want to choose a number K that will yield the following blocks:
 *  A[0], A[1], ..., A[K ? 1],
 *  A[K], A[K + 1], ..., A[2K ? 1],
 *  ...
 *  A[N ? K], A[N ? K + 1], ..., A[N ? 1].
 * What's more, every block should contain at least one peak. Notice that extreme elements of the blocks (for example A[K ? 1] or A[K]) can also be peaks, but only if they have both neighbors (including one in an adjacent blocks).
 * The goal is to find the maximum number of blocks into which the array A can be divided.
 * Array A can be divided into blocks as follows:
 *  one block (1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2). This block contains three peaks.
 *  two blocks (1, 2, 3, 4, 3, 4) and (1, 2, 3, 4, 6, 2). Every block has a peak.
 *  three blocks (1, 2, 3, 4), (3, 4, 1, 2), (3, 4, 6, 2). Every block has a peak.
 * Notice in particular that the first block (1, 2, 3, 4) has a peak at A[3], because A[2] < A[3] > A[4], even though A[4] is in the adjacent block.
 * However, array A cannot be divided into four blocks, (1, 2, 3), (4, 3, 4), (1, 2, 3) and (4, 6, 2), because the (1, 2, 3) blocks do not contain a peak.
 * Notice in particular that the (4, 3, 4) block contains two peaks: A[3] and A[5].
 * The maximum number of blocks that array A can be divided into is three.
 * 
 * Write a function:
 *  class Solution { public int solution(int[] A); }
 * that, given a non-empty array A consisting of N integers, returns the maximum number of blocks into which A can be divided.
 * If A cannot be divided into some number of blocks, the function should return 0.
 * 
 * @example Given:
 *     A[0] = 1
 *     A[1] = 2
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
 *  - N is an integer within the range [1..100,000];
 *  - each element of array A is an integer within the range [0..1,000,000,000].
 * 
*/

#include <numeric>

enum {
  kNo_peak = 0,
  kPeak = 1
};

int solution(vector<int> &A) {
  /**
   * @note Time complexity: O(N * log(log(N)))
   * 
   */
  int kVec_size = A.size();
  if (kVec_size < 3) return 0;

  // Find all peaks
  std::vector<int> peaks(kVec_size, kNo_peak);
  for (int i = 1; i < kVec_size - 1; ++i) {
    if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
      peaks[i] = kPeak;
    }
  }

  int peak_count = std::accumulate(peaks.begin(), peaks.end(), 0);
  if (peak_count < 2) return peak_count;

  for (int k = peak_count; k >= 2; --k) {
    if (kVec_size % k != 0) continue;

    int block_size = kVec_size / k;
    int peak_in_block = 0;
    int i = 0;
    for (; i < kVec_size; i++) {
      peak_in_block += peaks[i];
      if ((i + 1) % block_size == 0 && peak_in_block < 1) break;  // If there is no peak in the current block, we can't divide the array into k blocks
      else if ((i + 1) % block_size == 0) peak_in_block = 0;      // Reset peak_in_block to the beginning of the next block
    }
    if (i >= kVec_size) return k;
  }

  return 1;
}