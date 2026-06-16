# LCC_Mimic_Panel_Node

To assist the general railway modeller, I wanted to be able to provide a series of ESP32 based modules, using off the shelf readily available add on modules form various online vendors. This would allow people who have tried and succeeded with a similar approach for DCC-EX around the world. Then they could take advantage of a can bus based LCB. These will use the OpenLCB Single Thread Library. Which is available from the Arduino library manager. At the moment the end user will need away of connecting their can bus network to a pc running JMRI. there are currently 3 ways to do this. The cost of each node needed to be kept as inexpensive as reasonable as possible. While some may feel DuPont connectors are not an elegant solution for an exhibition layouts. Maybe in the future one of MERGs members who likes to create PCB designs may come up with a PCB to mount the various external devices.

MERG's Cansb4
Sprog LCC offers their USB LCC
RR-Circuits LCC Buffer-USB

### Goals for this node

 - For this node is to take advantage of 16 input pins to control routes on my layout.
 - Allow for multiple turnouts to be set with a single push button press.
 - Staggered events using a end user global delay.
 - Can bus based using the SN65VHD230 can transceiver using pins D15 for RX and D2 for TX.
 - To use a commercial available modules for breaking out the GPIO from the ESP32 Devkit 1
 - Keeping the code easy for non Arduino Eco-system uses Two lines of code will need amending only.
 - Keeping the CDI in JMRI as easy for the end user to be able to configure it once uploaded to the ESP32.
 - The node can use a pyhsical mimic panel or just use a glass panel in JMRI.

### Pin definitions
The pins that will be used are as follows, as they appear on the shield I use.

Righthand side facing the 2.1 power jack barrel.
 - D15 RX to the transceiver module.
 - D2 TX to the transceiver module.
 - D4, D16, D17, D5, D18, D19, D21, D22, D23


Lefthand Side.

 - D13, D14, D27, D26, D25, D33, D32, D35.
   
