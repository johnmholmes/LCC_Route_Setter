# LCC Mimic Panel & Route Setter Nodes

Example files available

- RouteSetter_v1 this is for 40 routes with 8 turnouts each. with 16 being controlled by input pins and 24 from external ndoes / JMRI. ESP32 Devkit 1 based node
- RouteSetter_v2 this is for 40 routes with 8 turnouts each. All being controlled from external nodes / JMRI. ESP32 Devkit 1 based nodebased node
- RouteSetter_v3 This is for 40 routes with 8 channels each. All being controlled from external nodes / JMRI. M5Stack Atom Lite based node

To assist the general railway modeller, I wanted to be able to provide a series of ESP32 based modules, using off the shelf readily available add on modules form various online vendors. This would allow people who have tried and succeeded with a similar approach for DCC-EX around the world. Then they can take advantage of a can bus based LCB. These nodes use the OpenLCB Single Thread Library. Which is available from the Arduino library manager.The end user will need away of connecting their can bus network to a pc running JMRI. There are currently 3 devices that can do this, listed below with links to there websites. The cost of each node needed to be kept as inexpensive as reasonable as possible. While some may feel DuPont connectors are not an elegant solution for an exhibition layouts. Maybe in the future one of MERGs members who likes to create PCB designs may come up with a PCB to mount the various external devices.

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


### RouteSetter_v1

Esp32 devkit 1 node

40 routes in total 16 controlled by on board inputs 24 routes controlled by remote events from another LCC device, or JMRI

The GPIO pins that will be used are as follows, as they appear on the shield I use.

Righthand side facing the 2.1 power jack barrel.
 - D15 RX to the transceiver module.
 - D2 TX to the transceiver module.
 - D4, D16, D17, D5, D18, D19, D21, D22, D23.

Lefthand Side.

 - D13, ,D12 ,D14, D27, D26, D25, D33, D32.

### RouteSetter_v2

Esp32 devkit 1 node

40 routes for external LCC node route setting. This has none of the GPIO pins doing anything. It is just a logix node.

### RouteSetter_v3

M5Stack Atom Lite with the M5Stack MiniCan module

40 routes for external LCC node route setting. This has none of the GPIO pins doing anything. It is just a logix node.
   
