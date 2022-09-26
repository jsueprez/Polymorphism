#include <iostream>

using std::cout;

/* functions has external linkage by default,
 * so I can use this function defined in other files
 * just placing a forward declaration */
void test_forms();

int main()
{
  test_forms();
  return 0;
}
