/*===============================================================================
* Find the way to properly catch the start-byte in parsing serial communication
*
* Designing a protocol for transfer of measurements betweens two embedded systems. 
* The communication between the microcontrollers use UART
*  The dataframes look like this:

[start byte] [message id] [payload len] [payload data] [checksum]
*/
#include <iostream>
#include <type_traits>
#include <cstdint>
#include <limits>
#include <typeinfo>


int main() {
   
   
	return 0;
}