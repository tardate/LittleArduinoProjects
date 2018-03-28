this project is basically to build a chute that would count tins as they roll by and detect tins without paper labels.
the label detection works by runnibg a piece of wire on the floor of the chute and connecting it to the A0 pin. the 
A0 pin detects tins without labels by reading the voltage on the wire. if the metal surface of the tin (i.e tins 
without labels) comes in contact with the wire, there would be a change in the voltage. a change in voltage means the 
red led would blink once.. one blink for ever labeless tin that passes.