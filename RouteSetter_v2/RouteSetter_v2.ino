/*RouteSetter_v2 40 routes example for the ESP32 Devkit 1 for remote control of the events
==============================================================
 Adaoted from the original OlcbBasicNode sketch
   A prototype of a basic 4-channel OpenLCB board

   David Harris 2019, adapted from
   Bob Jacobsen 2010, 2012
      based on examples by Alex Shepherd and David Harris
   Updated 2024.09 DPH
   Modified for Route setting by John Holmes & DPH June 2026
==============================================================
*/

#include "config.h"               // User defined otions
#include "mdebugging.h"           // debugging
#include "processor.h"            // auto-selects the processor type, EEPROM lib etc.
#include "OpenLCBHeader.h"        // System house-keeping.
#include "boardChoices.h"         // Used by intermedates who wish to change the board from ESP32 to Atom only
#include "memstruct.h"            // Please do not allter the setting in this tab unless an LCC developer

extern "C" {                      // the following are defined as external
#define N(x) xN(x)                // allow the insertion of the value (x) ..
#define xN(x) #x                  // .. into the CDI string.

// ===== CDI =====
//   Configuration Description Information in xml, **must match MemStruct below**
//   See: http://openlcb.com/wp-content/uploads/2016/02/S-9.7.4.1-ConfigurationDescriptionInformation-2016-02-06.pdf
//   CDIheader and CDIFooter contain system-parts, and includes user changable node name and description fields.
     const char configDefInfo[] PROGMEM =
       // vvvvv Enter User definitions below CDIheader line vvvvv
       //       It must match the Memstruct struct{} below
       CDIheader R"(
         <group replication=')" N(NUM_GROUPS) R"('>
           <name>Route Setter</name>
           <repname>Group </repname>
           <hints><visibility hideable='yes' hidden='yes' ></visibility></hints>
           <description>Define events associated with input pins or consumer events</description>
           <group replication=')" N(GROUP_SIZE) R"('>
             <name>Routes controlled with a single push button or consumed events. Description can be changed to suit your layout</name>
             <repname>Route </repname>
             <string size='24'><name>Description</name></string>
             <eventid><name>When this event is consumed it will trigger the following events</name></eventid>
             <group replication=')" N(NUM_TURNOUTS) R"('>
             <name>Paste your turnouts event for the position you require setting</name>
               <repname>Trigger turnout </repname>
               <eventid></eventid>
              </group>
           </group>
         </group>

         <group>
            <name>Global Delay Between Triggers</name>
            <hints><visibility hideable='yes' hidden='yes' ></visibility></hints>     
            <description>Possible choices between 0-2000ms in 100ms steps</description>
            <int size='1'><name>Choose one value and click write to save the new value</name>
              <map>
                <relation><property>0</property><value>None</value></relation> 
                <relation><property>1</property><value>100ms</value></relation> 
                <relation><property>2</property><value>200ms</value></relation> 
                <relation><property>3</property><value>300ms</value></relation>
                <relation><property>4</property><value>400ms</value></relation>
                <relation><property>5</property><value>500ms</value></relation>
                <relation><property>6</property><value>600ms</value></relation>
                <relation><property>7</property><value>700ms</value></relation>
                <relation><property>8</property><value>800ms</value></relation>
                <relation><property>9</property><value>900ms</value></relation>
                <relation><property>10</property><value>1000ms</value></relation>
                <relation><property>11</property><value>1100ms</value></relation>
                <relation><property>12</property><value>1200ms</value></relation>
                <relation><property>13</property><value>1300ms</value></relation>
                <relation><property>14</property><value>1400ms</value></relation>
                <relation><property>15</property><value>1500ms</value></relation>
                <relation><property>16</property><value>1600ms</value></relation>
                <relation><property>17</property><value>1700ms</value></relation>
                <relation><property>18</property><value>1800ms</value></relation>
                <relation><property>19</property><value>1900ms</value></relation>
                <relation><property>20</property><value>2000ms</value></relation>
              </map>
            </int>
         </group>
       )" CDIfooter;
       // ^^^^^ Enter User definitions above CDIfooter line ^^^^^
}

// ===== MemStruct =====
//   Memory structure of EEPROM, **must match CDI above**
    typedef struct {
          EVENT_SPACE_HEADER eventSpaceHeader; // MUST BE AT THE TOP OF STRUCT - DO NOT REMOVE!!!
          char nodeName[20];  // optional node-name, used by ACDI
          char nodeDesc[24];  // optional node-description, used by ACDI
      // vvvvv Enter User definitions below vvvvv
            struct {
              char desc[24];        // description of this input-pin
              EventID consumer;
              EventID to[NUM_TURNOUTS];
            } inputs[NUM_INPUTS];     
          uint8_t turnoutDelay;       

      // ^^^^^ Enter User definitions above ^^^^^
    } MemStruct;                    // EEPROM memory structure, must match the CDI above

extern "C" {
  
  /* ===== eventid Table =====
  Array of the offsets to every eventID in MemStruct/EEPROM/mem, and P/C flags
    -- each eventid needs to be identified as a consumer, a producer or both.
    -- PEID = Producer-EID, CEID = Consumer, and PC = Producer/Consumer
    -- note matching name-references to MemStruct.
  */
const EIDTab eidtab[NUM_EVENT] PROGMEM = {
    //ROUTEEID(NUM_INPUTS),
    ACTIONEID(NUM_INPUTS, NUM_TURNOUTS),
};
 
  // SNIP Short node description for use by the Simple Node Information Protocol
  // See: http://openlcb.com/wp-content/uploads/2016/02/S-9.7.4.3-SimpleNodeInformation-2016-02-06.pdf
        extern const char SNII_const_data[] PROGMEM = "\001" MANU "\000" MODEL "\000" HWVERSION "\000" OlcbCommonVersion ; // last zero in double-quote

}; // end extern "C"

// PIP Protocol Identification Protocol uses a bit-field to indicate which protocols this node supports
// See 3.3.6 and 3.3.7 in http://openlcb.com/wp-content/uploads/2016/02/S-9.7.3-MessageNetwork-2016-02-06.pdf
uint8_t protocolIdentValue[6] = {   //0xD7,0x58,0x00,0,0,0};
        pSimple | pDatagram | pMemConfig | pPCEvents | !pIdent    | pTeach     | !pStream   | !pReservation, // 1st byte
        pACDI   | pSNIP     | pCDI       | !pRemote  | !pDisplay  | !pTraction | !pFunction | !pDCC        , // 2nd byte
        0, 0, 0, 0                                                                                           // remaining 4 bytes
};

uint16_t turnoutDelay = 0;
uint8_t actionIndex[NUM_INPUTS] = {0};  // each input has an actionIndex, 0=no pending actions, >1 the number of pending actions
void processInputs() {
  static long last =0;
  if( (millis()-last) <250 ) return;
  last = millis();
  for(int i=0; i<NUM_INPUTS; i++) {
    if( pin[i]==255 ) continue;
    if( digitalRead( pin[i])==0 && actionIndex[i]==0 ) {
      dP("\nButton pushed "); dP(i); dP(" pin="); dP(pin[i]);
      actionIndex[i] = NUM_TURNOUTS;
    }
  }
}
void processTurnouts() {
  static long last = 0;
  static int i = 0;
  if( (millis()-last) < turnoutDelay ) return;
  if( actionIndex[i]>0 ) {                                        // if there is an actionIndex for this button ..
    OpenLcb.produce( (i+1)*(NUM_TURNOUTS+1) - actionIndex[i]);    // .. produce a turnout actionIndex
    dP("\n  produce "); dP((i+1)*NUM_TURNOUTS - actionIndex[i]);
    actionIndex[i]--;                                             // .. decrement the actionIndex #
    last = millis();                                              // remember for next time
  } else {                                                        // else 
    if( ++i >= NUM_INPUTS ) i = 0;                                // .. move to the next button
  }
}

void pceCallback(uint16_t index) {
  dP("\n pceCallback, index="); dP(index);
  uint8_t i = index / (NUM_TURNOUTS+1);
  actionIndex[i] = NUM_TURNOUTS;
}

/* userInitAll() -- include any initialization after Factory reset "Mfg clear" or "User clear"
 -- clear or pre-define text variables.
 USER defined only use 19 characters for the name and 23 for the discription.
*/
void userInitAll() {
    NODECONFIG.put(EEADDR(nodeName), ESTRING( "Route Setter" ) );
    NODECONFIG.put(EEADDR(nodeDesc), ESTRING( "Alpha" ) );
    NODECONFIG.write(EEADDR(turnoutDelay), 4 );
    for(int i=0; i<NUM_INPUTS; i++) {
      if( pin[i]<255) {
        String s = "Pin " + String(pin[i]);
        NODECONFIG.put(EEADDR(inputs[i].desc), s );
      } else {
        NODECONFIG.put(EEADDR(inputs[i].desc), ESTRING("No pin") );
      }
    }
}

/*
 userSoftReset() - include any initialization after a soft reset, ie after configuration changes.
 USER defined
*/
void userSoftReset() {
  dP("\n In userSoftReset()"); Serial.flush();
  REBOOT;  // defined in processor.h for each mpu
}

/* 
userHardReset() - include any initialization after a hard reset, ie on boot-up.
 USER defined
*/
void userHardReset() {
  dP("\n In userHardReset()"); Serial.flush();
  REBOOT;  // defined in processor.h for each mpu
}

/* 
===== Callback from a Configuration write =====
 Use this to detect changes in the node's configuration
 This may be useful to take immediate action on a change.
 param address - address in space of change
 param length  - length of change
 NB: if address=0 and length==0xffff, then user indicated UPDATE_COMPLETE
 USER defined

*/
void userConfigWritten(uint32_t address, uint16_t length, uint16_t func) {
    dP("\nuserConfigWritten "); dPH((uint32_t)address);
    dP(" length="); dPH((uint16_t)length);
    dP(" func="); dPH((uint8_t)func);
    for(uint8_t i=0; i<length; i++) {
      dP(" "); dP(NODECONFIG.read(address));
    }
  // recalculate turnoutDelay in case it changed.
  turnoutDelay = NODECONFIG.read( EEADDR( turnoutDelay ) ) * 100;
}

NodeID nodeid(NODE_ADDRESS);       // this node's nodeid, must be before next line
#include "OpenLCBMid.h"            // System house-keeping

// ==== Setup does initial configuration =============================
void setup() {
  EEPROM.begin(EEPROMSIZE);
  Olcb_init(nodeid, RESET_TO_FACTORY_DEFAULTS);

  dP("\neeprom:\n");
  for(int i=0; i<(sizeof(MemStruct)+8); i++) {
    if( i!=0 && (i%16==0) ) { dP("\n"); dP(i); dP(": "); }
    uint8_t x = EEPROM.read(i);
    if(x<16)dP(0); dPH(x); dP(" ");
  }
  //dP("\n Size of MemStruct = "); dP(sizeof(MemStruct)); Caused issues so not used
  dP("\n Number of events = "); dP(NUM_EVENT);
  for(int i=0; i<NUM_INPUTS; i++) {
    pinMode( pin[i], INPUT_PULLUP );
    actionIndex[i] = 0;
  }
  turnoutDelay = NODECONFIG.read( EEADDR( turnoutDelay ) ) * 100;
  dP("\nturnoutDelay = "); dP(turnoutDelay);
}

// ==== MAIN LOOP ===========================================
//  -- this performs system functions, such as CAN alias maintenence
void loop() {
  bool activity = Olcb_process();     // System processing happens here, with callbacks for app action.
  // app calls
  processInputs();
  processTurnouts();
}
