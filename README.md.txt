
	This is a network based TCP/IP socket program with Client-server architecture that enables controlling the manufacturing process remotely. A set of functions have been designed on the server and a corresponding APIs are called on the client.

A detailed explanation can be found below video link

http://www.youtube.com/watch?v=VuuxDWTtelA


Code Details
1) Server- Visual C#, Requires windows xp (or above) OS and visual studio 2005 (or above)

2) Client- Visual C++, Requires windows xp (or above) OS and visual studio 2005 (or above), google chrome browser.

Instructions
1) Make serial port connections to machine to a server. Connect the IP camera to the server and configure the same. Also make sure the lab view is running on the server.

2) Run the server code which is connected to a machine on a serial port using a RS232 cable.

3) Start the server

4) Run the client code on the client machine.

5) Follow the below mentioned API command syntax

Command API syntax
1) open <port name> <Baud Rate>

2) set <direction> <type of movement> <slow velocity> <home offset> <homing mode> <slow velocity>

3) move <direction> <type of movement> <position> <max velocity> <max acceleration> <max deceleration>

Example commands
1) open COM1 9600 ?.

2) set f a 4000 1000 0 21 ?.

3) move f a 0 7000 20000 20000 ?.

Note: ASCII manual for the API can be found along with the code values for each variables in the command.




