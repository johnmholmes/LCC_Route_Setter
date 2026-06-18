**Disclaimer and Limitation of Liability**

This sketch (software) has been developed specifically for the **ESP32 DevKit 1** and the **SN65VHD230** CAN transceiver module. It has only been tested on the author’s personal model railway layout.

**The sketch is provided “AS IS” and “AS AVAILABLE”**, without any warranties or guarantees of any kind. The author explicitly disclaims all warranties, whether express, implied, or statutory, including but not limited to any warranties of merchantability, fitness for a particular purpose, accuracy, reliability, or non-infringement.

The author accepts **no responsibility or liability** for:
- Any malfunction, failure, or unexpected behaviour of the sketch
- Damage to hardware, loss of data, or disruption to your layout
- Incompatibility caused by updates to third-party libraries, Arduino core, JMRI, or other software
- Any direct, indirect, incidental, consequential, or punitive damages arising from the use or inability to use this sketch

This code is offered strictly for **educational and hobbyist purposes** to help railway modellers learn how to use the OpenLCB Single Thread Library. It is not intended for commercial use, safety-critical applications, or any situation where failure could cause damage or injury.

By downloading, using, or modifying this sketch, you acknowledge that you assume **all risk** and full responsibility for any outcomes resulting from its use.

The author reserves the right to modify or remove this sketch at any time without notice.

An adaptation of the original _v1 sketch for use as a Route setting node.

 - Allows for 40 routes to be controlled by single push buttons.
 - Allows for 8 tigger events to be sent out onto the Can bus.
 - Allows for a global delay to configured between 0- 2000 millisecond in 100 ms ingraments
 - Can be used with commercial nodes, a eithernet cable will need to be spliced into to gain access to the Can H & Can L

