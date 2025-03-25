# HeatingBoard
PCB for MOD11 project, 
[Schematic](HeatingBoard.pdf)


Annotations of review on commit 1aa25621acdf8ef7814e08bc60a55e5036fec723 (Jelle, 24-3-2025)

Schematic:
- Are R7 & R6 assumed to be determined for a certain I2C speed? Is this something we should keep in mind for the communication between the control Pico and this board?
- Its probably good to work together with the control subgroup on what data is exactly put out by the chips (wattage?)
- The four channels will all have the same I2C address according to the schematic with A1 and A0. But it's possible to have 4 addresses if you think about it when soldering so its fine i guess
- I yeeted the calculation for the maximum PWM frequency into ChatGPT and it says you need to account for both ON and OFF transitions?, so it says it should be about half of that 10MHz as max aka ca. 5.5MHz
- The backup regulator U5 is not in the PDF schematic yet

PCB:
- Can't find U5 in the BOM, so I assume you are sure to DNP it?
- There's 2 5pin terminals in the BOM, but only one on the PCB, intentional?
- Do you want to order more Capacitor 0603, 100nF just in case you need to implement those DNP input filters?
- Nice QR code :P
- The physical pins of the T2N7002AK seem to be wrong. The S connected to GND is actually the D according to the datasheet, the G is actually the S and the D is actually physically the G
- pinout DMP is also wrong. The VOUT D is in the datasheet the G, the S is actually the D and the G is actually the S
- Cant find any productnumber or specs of the fuse holder so cant check if it fits

TLDR:
- Footprint pinouts of the MOSFETS are incorrect