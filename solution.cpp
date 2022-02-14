#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <sstream>
using namespace sol280;
using namespace std;

/*takeaways
  - you can sort the nums or not before
    the wiggle sort
*/

vector<int> Solution::wiggleSort(vector<int> &nums)
{
  if (nums.size() <= 1)
    return nums;

  /*
    - numbers on a even position will guarantee
      to be smaller than the number comes
      immediately before it after each swap
    - look at positon 2 with an initial value of 100
      - 5,2,100,30...
      - 5,100,2,30... swap position 1 and 2
      - 5,100,2,30...
        - now we are at position 3 to look back
        - nothing change. If any thing needs to
          change, it will be swapping position 2
          with a even smaller number. This means
          position 1 always is bigger than
          position 2 after swaps
  */
  for (auto i = 1; i < nums.size(); i++)
  {
    if (i % 2 == 1 && nums[i - 1] > nums[i] ||
        i % 2 == 0 && nums[i - 1] < nums[i])
      swap(nums[i - 1], nums[i]);
  }
  return nums;
}

vector<int> Solution::wiggleSort2(vector<int> &nums)
{
  if (nums.size() <= 1)
    return nums;
  /*
    - need to sort it first in ascending order
      to guarantee that if we need to swap
      nums[i] and nums[i+1], nums[i-1] is smaller
      than both,i is an odd number.
      before the swap - ...,2(i-1),4(i),5(i+1),...
      after the swap  - ...,2(i-1),5(i),4(i+1),...
  */
  sort(nums.begin(), nums.end());

  /*
    - nums[0] and num[1] already in proper order
      after sorting so we can ignore nums[0]
 */
  for (int i = 1; i < nums.size() - 2; i += 2)
    swap(nums[i], nums[i + 1]);

  return nums;
}