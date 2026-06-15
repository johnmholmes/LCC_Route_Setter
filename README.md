# LCC_Mimic_Panel_Node
ESP32 based OpenLCB mimic panel based on the OpenLCB_Single_Thread library.

### Goals for this node

 - For this node is to take advantage of 16 input pins to control routes on my layout.
 - Allow for multiple turnouts to be set with a sigal push button press.
 - Staggered events using a end user global delay.
 - Can bus based using the SN65VHD230 can transceiver using pins D15 for RX and D2 for TX.
 - To use a commercial available modules for breaking out the GPIO from the ESP32 Devkit 1
 - Keeping the code easy for non Arduino Eco-system uses Two lines of code will need amending only.
 - Keeping the CDI in JMRI as easy for the end user to be able to configure it once uploaded to the ESP32.

### Pin definitions
The pins that will be used are as follows, as they appear on the shield I use.

Righthand side facing the 2.1 power jack barrel.
 - D15 RX to the transceiver module.
 - D2 TX to the transceiver module.
 - D4, D4, D16, D17, D5, D18,D 19, D23
 - D21 & D22 left fee incase I decide later to add an i2c expander.

Lefthand Side.

 - D13, D12, D14, D27, D26, D25, D33, D32, D35.
   
