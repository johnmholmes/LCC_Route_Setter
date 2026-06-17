/*
 Application definitions:
 
 - The end user can alter the number of inputs without the need to change the CDI & Memstruct
 - The NUM_INPUTS must match the array count of pins

 */

#define NUM_INPUTS 20   // number of buttons requires to match the "pin definition"
// Pin definitions, if there is no pin assigned use 255
uint8_t pin[NUM_INPUTS] = { 4,16,17,5,18,19,21,22,13,12,14,27,26,25,33,32,255,255,255,255};            // for ESP32 
//uint8_t pin[NUM_INPUTS] = { 19, 39, 21, 22, 23, 25, 26, 255,255,255 }; // for Atom

#define NUM_TURNOUTS 8  // number of turnouts in a route changing this requires to the CDI & Memstruct 
#define NUM_EVENT (NUM_INPUTS + NUM_INPUTS * NUM_TURNOUTS)

/*
 Node ID --- this must come from a range controlled by the user.
 See: http://registry.openlcb.org/uniqueidranges
 To choose a new NODEID edit this address
*/
#define NODE_ADDRESS 5,1,1,1,0x8E,0x01  // DIY range example, not for global use.

/* Set to 1 to Force Reset to Factory Defaults, else 0.
 This needs to be done at least once for each new board.
*/
#define RESET_TO_FACTORY_DEFAULTS 1

/* Send GC to Serial
 To allow direct to JMRI via USB, without CAN controller,
 note: disable debugging if this option is chosen
*/
//#include "GCSerial.h"
//#define NOCAN    
//#define DEBUG Serial 

/*
 If using Can you can use the serial monitor for debugging during development
 uncomment the #define DEBUG Serial above
*/

/*
 Board definitions Keep short text within the " " if making alterations.
*/

#define MANU "J Holmes"         // The manufacturer of node
#define MODEL "ESP32"           // The model of the board
#define HWVERSION "ESP32 Dev1"  // Hardware version
#define SWVERSION "0.1"         // Software version

/*
  ************** End of USER DEFINTIONS *****************************
*/

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

//#define ROUTE(i) PEID(inputs[i].routeA), PEID(inputs[i].routeB), PEID(inputs[i].routeC), PEID(inputs[i].routeD), PEID(inputs[i].routeE), PEID(inputs[i].routeF)
#define ROUTE(i) PEID(inputs[i].to[0]), PEID(inputs[i].to[1]),PEID(inputs[i].to[2]),PEID(inputs[i].to[3]),PEID(inputs[i].to[4]),PEID(inputs[i].to[5])

#define _ROUTEEID_0 
#define _ROUTEEID_1 ROUTE(0)
#define _ROUTEEID_2 _ROUTEEID_1, ROUTE(1)
#define _ROUTEEID_3 _ROUTEEID_2, ROUTE(2)
#define _ROUTEEID_4 _ROUTEEID_3, ROUTE(3)
#define _ROUTEEID_5 _ROUTEEID_4, ROUTE(4)
#define _ROUTEEID_6 _ROUTEEID_5, ROUTE(5)
#define _ROUTEEID_7 _ROUTEEID_6, ROUTE(6)
#define _ROUTEEID_8 _ROUTEEID_7, ROUTE(7)
#define _ROUTEEID_9 _ROUTEEID_8, ROUTE(8)
#define _ROUTEEID_10 _ROUTEEID_9, ROUTE(9)
#define _ROUTEEID_11 _ROUTEEID_10, ROUTE(10)
#define _ROUTEEID_12 _ROUTEEID_11, ROUTE(11)
#define _ROUTEEID_13 _ROUTEEID_12, ROUTE(12)
#define _ROUTEEID_14 _ROUTEEID_13, ROUTE(13)
#define _ROUTEEID_15 _ROUTEEID_14, ROUTE(14)
#define _ROUTEEID_16 _ROUTEEID_15, ROUTE(15)
#define _ROUTEEID_17 _ROUTEEID_16, ROUTE(16)
#define _ROUTEEID_18 _ROUTEEID_17, ROUTE(17)
#define _ROUTEEID_19 _ROUTEEID_18, ROUTE(18)
#define _ROUTEEID_20 _ROUTEEID_19, ROUTE(19)
#define _ROUTEEID_21 _ROUTEEID_20, ROUTE(20)

#define _ROUTEEID(n) _ROUTEEID_##n
#define ROUTEEID(n) _ROUTEEID(n)

#define TO(i,t) PEID( inputs[i].to[t] )

#define TO1(i) CEID( inputs[i].consumer), TO(i,0)
#define TO2(i) TO1(i), TO(i,1)
#define TO3(i) TO2(i), TO(i,2)
#define TO4(i) TO3(i), TO(i,3)
#define TO5(i) TO4(i), TO(i,4)
#define TO6(i) TO5(i), TO(i,5)
#define TO7(i) TO6(i), TO(i,6)
#define TO8(i) TO7(i), TO(i,7)
#define TO9(i) TO8(i), TO(i,8)
#define TO10(i) TO9(i), TO(i,9)
#define TO11(i) TO10(i), TO(i,10)
#define TO12(i) TO11(i), TO(i,11)
#define TO13(i) TO12(i), TO(i,12)
#define TO14(i) TO13(i), TO(i,13)
#define TO15(i) TO14(i), TO(i,14)
#define TO16(i) TO15(i), TO(i,15)
#define TO17(i) TO16(i), TO(i,16)
#define TO18(i) TO17(i), TO(i,17)
#define TO19(i) TO18(i), TO(i,18)
#define TO20(i) TO19(i), TO(i,19)

#define TON(n,i) TO##n(i)
#define TOEID(n,i) TON(n,i) // Usage: TOEID(num_to_elements, action_index)
#define CONSEID() 

#define ACTION1(n) TOEID(n,0)
#define ACTION2(n) ACTION1(n), TOEID(n,1)
#define ACTION3(n) ACTION2(n), TOEID(n,2)
#define ACTION4(n) ACTION3(n), TOEID(n,3)
#define ACTION5(n) ACTION4(n), TOEID(n,4)
#define ACTION6(n) ACTION5(n), TOEID(n,5)
#define ACTION7(n) ACTION6(n), TOEID(n,6)
#define ACTION8(n) ACTION7(n), TOEID(n,7)
#define ACTION9(n) ACTION8(n), TOEID(n,8)
#define ACTION10(n) ACTION9(n), TOEID(n,9)
#define ACTION11(n) ACTION10(n), TOEID(n,10)
#define ACTION12(n) ACTION11(n), TOEID(n,11)
#define ACTION13(n) ACTION12(n), TOEID(n,12)
#define ACTION14(n) ACTION13(n), TOEID(n,13)
#define ACTION15(n) ACTION14(n), TOEID(n,14)
#define ACTION16(n) ACTION15(n), TOEID(n,15)
#define ACTION17(n) ACTION16(n), TOEID(n,16)
#define ACTION18(n) ACTION17(n), TOEID(n,17)
#define ACTION19(n) ACTION18(n), TOEID(n,18)
#define ACTION20(n) ACTION19(n), TOEID(n,19)

#define ACTIONN(n,t) ACTION##n(t)
#define ACTIONEID(n,t) ACTIONN(n,t) // Usage: ACTIONEID(num_actions, num_to_elements)


/*
 Leave uncomment to disable blue/gold other as it will slowdown opening in JMRI
*/

#define OLCB_NO_BLUE_GOLD  


