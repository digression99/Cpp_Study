#include <bitset>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  bitset<8> bit;
  bit.set(); // set all bit to 1
  bit.reset(); // set all bit to 0
  
  int bitsize = (int)bit.size(); // bit size -> 8
  bool bAny = bit.any(); // if there's any bit set to 1, true
  bool bNone = bit.none(); // if there's no bit set to 1, true
  
  bit.set(0, true); // set first bit to 1
  bit.flip(4); // flip fifth bit
  
  bit.flip(); // flip every bits
  
  bool bFlag = bit.test(3); // true if fourth bit is true, else false
  
  int setcount = (int)bit.count(); // count every bit that set to 1
  
  bit = 0xF0; // assign the bit pattern
  
  string s = bit.to_string(); // bit pattern to string
  int nBitVal = bit.to_ulong(); // bit pattern to #
  return 0;
}
