#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

// Buffer length for the exchanged messages
#define BUFLEN      20

// Command code for the option negociation the server
#define DO          0xfd
#define WONT        0xfc
#define WILL        0xfb
#define DONT        0xfe
#define CMD         0xff

#define SE          240 // End of subnegotiation parameters.
#define NOP         241 // No operation
#define DATA_MARK   242
#define BRK         234 // Break
#define IP          244 // Interupt process
#define AO          245 // Abort output
#define AYT         246 // Are you there ?
#define EC          247 // Erase character
#define EL          248 // Erase line
#define GA          249 // Go ahead
#define SB          250 // What follows is a subnegciation parameter
#define CWILL       251
#define CWONT       252
#define CDO         253
#define CDONT       254
#define IAC         255 // Beggiing of a command

/*
0 	Binary Transmission
1 	Echo
2 	Reconnection 
3 	Suppress Go Ahead 
4 	Approx Message Size Negotiation
5 	Status 
6 	Timing Mark 
7 	Remote Controlled Trans and Echo
8 	Output Line Width 
9 	Output Page Size
10 	Output Carriage-Return Disposition 
11 	Output Horizontal Tab Stops
12 	Output Horizontal Tab Disposition 
13 	Output Formfeed Disposition 
14 	Output Vertical Tabstops 
15 	Output Vertical Tab Disposition
16 	Output Linefeed Disposition 
17 	Extended ASCII 
18 	Logout 
19 	Byte Macro 
20 	Data Entry Terminal
21 	SUPDUP 
22 	SUPDUP Output 
23 	Send Location 
24 	Terminal Type 
25 	End of Record 
26 	TACACS User Identification 
27 	Output Marking 
28 	Terminal Location Number 
29 	Telnet 3270 Regime 
30 	X.3 PAD 
31 	Negotiate About Window Size 
32 	Terminal Speed 
33 	Remote Flow Control 
34 	Linemode 
35 	X Display Location 
36 	Environment Option 
37 	Authentication Option 
38 	Encryption Option
39 	New Environment Option 
40 	TN3270E 
41 	XAUTH 
42 	CHARSET 
43 	Telnet Remote Serial Port (RSP) 
44 	Com Port Control Option 
45 	Telnet Suppress Local Echo 
46 	Telnet Start TLS 
47 	KERMIT 	
48 	SEND-URL 
49 	FORWARD_X
138 	TELOPT PRAGMA LOGON
139 	TELOPT SSPI LOGON 
140 	TELOPT PRAGMA HEARTBEAT 
255 	Extended-Options-List
*/

#define CMD_ECHO 1
#define CMD_WINDOW_SIZE 31

#endif /* __CONSTANTS_H__ */
