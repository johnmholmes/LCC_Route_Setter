# LCC Mimic Panel & Route Setter Nodes

## Example files available

- ESP32_16inputRouteSetter_v1 this is for 16 routes with 8 turnouts each. Controlled by input pins or can use consumed events from JMRI . ESP32 Devkit 1 based node
- ESP32_40RouteSetter_v1 this is for 40 routes with 8 turnouts each. All being controlled from external nodes or JMRI. ESP32 Devkit 1 based node.
- Atom_40RouteSetter_v1 This is for 40 routes with 8 channels each. All being controlled from external nodes or JMRI. M5Stack Atom Lite based node

---

## Disclaimer and Limitation of Liability

This sketch (software) has been developed specifically for the **ESP32 DevKit 1** and the **SN65VHD230** CAN transceiver module, or the M5Stack Atom Lite with their MiniCan module. It has only been tested on the author’s personal model railway layout.

**The sketch is provided “AS IS” and “AS AVAILABLE”**, without any warranties or guarantees of any kind. The author explicitly disclaims all warranties, whether express, implied, or statutory, including but not limited to any warranties of merchantability, fitness for a particular purpose, accuracy, reliability, or non-infringement.

The author accepts **no responsibility or liability** for:
- Any malfunction, failure, or unexpected behaviour of the sketch
- Damage to hardware, loss of data, or disruption to your layout
- Incompatibility caused by updates to third-party libraries, Arduino core, JMRI, or other software
- Any direct, indirect, incidental, consequential, or punitive damages arising from the use or inability to use this sketch

This code is offered strictly for **educational and hobbyist purposes** to help railway modellers learn how to use the OpenLCB Single Thread Library. It is not intended for commercial use, safety-critical applications, or any situation where failure could cause damage or injury.

By downloading, using, or modifying this sketch, you acknowledge that you assume **all risk** and full responsibility for any outcomes resulting from its use.

The author reserves the right to modify or remove this sketch at any time without notice.

---

## Node introduction

To help the wider railway modelling community, I set out to develop a series of ESP32-based modules that use readily available off-the-shelf add-on boards from popular online suppliers.
This approach builds on the success many modellers around the world have already had with similar Arduino solutions for DCC-EX. It allows them to easily adopt a CAN bus-based OpenLCB (Layout Command Bus) system. The nodes run the OpenLCB Single Thread Library, which is available directly through the Arduino Library Manager.
End users will need a way to connect their CAN bus network to a PC running JMRI. There are currently three devices capable of doing this (listed below with links to their websites).
I have kept the cost of each node as low as reasonably possible. While some modellers may consider DuPont connectors less elegant for exhibition layouts, they remain a practical and affordable choice for now. In the future, perhaps a MERG member with PCB design skills will create a dedicated board to neatly mount the various external modules.

  - MERG's Cansb4 https://merg.org.uk
  - Sprog LCC offers their USB LCC https://www.sprog-dcc.co.uk/lcc/usb-lcc
  - RR-Circuits LCC Buffer-USB https://www.rr-cirkits.com

### Goals for this node

 - This node takes advantage of 16 input pins to control 16 routes.
 - Allow for multiple turnouts to be set with a single push button press.
 - Staggered events using a end user global delay 0 to 2000ms in 100ms steps.
 - Can bus based using the SN65VHD230 can transceiver using pins D15 for RX and D2 for TX.
 - Uses a commercial available modules for breaking out the GPIO from the ESP32 Devkit 1
 - Keeping the code easy for non Arduino Eco-system uses.
 - Only two lines of code will need amending in the Arduino IDE to be able to upload to the ESP32.
 - Keeping the graphical user interface simple to use in JMRI to configure the node.
 - The node can use a pyhsical mimic panel or just use a glass panel in JMRI.
 - M5Sack Atom support 40 routes controlled from external nodes or JMRI


### ESP32_16inputRouteSetter_v1

Esp32 devkit 1 node

16 routes in total 16 controlled by on board inputs 

The GPIO pins that will be used are as follows, as they appear on the shield I use.

Righthand side facing the 2.1 power jack barrel.
 - D15 RX to the transceiver module.
 - D2 TX to the transceiver module.
 - D4, D16, D17, D5, D18, D19, D21, D22, D23.

Lefthand Side.

 - D13, ,D12 ,D14, D27, D26, D25, D33, D32.

### ESP32_40RouteSetter_v1

Esp32 devkit 1 node

40 routes for external LCC node route setting. This has none of the GPIO pins doing anything. It is just a logix node.

### Atom_40RouteSetter_v1

M5Stack Atom Lite with the M5Stack MiniCan module

40 routes for external LCC node route setting. This has none of the GPIO pins doing anything. It is just a logix node.
   
