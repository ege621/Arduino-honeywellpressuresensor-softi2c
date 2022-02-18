# Arduino-honeywellpressuresensor-softi2c
This code demonstrates software i2c communication with 3 sensors which have the same slave address 

The sensors in question are pressure sensors from Honeywell with the slave address of 0x24. 

The sensors are connected to the software i2c buses declared in the code. 

You can practically declare any combination of the digital I/O pins as SDA SCL with this approach.

This method comes in handy if you you are using multiple sensors with the same address.

Some i2c devices usually include toggle pins that you can pull high or low to change its address.
