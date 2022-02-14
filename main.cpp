#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol280;

string toString(vector<int> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += to_string(e);
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

/*
Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]
        pick this one  [1,3,2,5,4,6]
*/
tuple<vector<int>, vector<int>> testFixture1()
{
  return make_tuple(
      vector<int>{3, 5, 2, 1, 6, 4},
      vector<int>{3, 5, 1, 6, 2, 4});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << toString(get<1>(f)) << endl;
  auto result = Solution::wiggleSort(get<0>(f));
  cout << "result: " << toString(result) << endl;
  result = Solution::wiggleSort2(get<0>(f));
  cout << "other possible result:" << toString(result) << endl;
}

main()
{
  test1();
  return 0;
}