unsigned short b[4][2] = {{77, 50},  // 0x1000 y 0x1002
                          {5, 2},   //  0x1004 y 0x1006
                          {28, 39}, // 0x1008 y 0x100A
                          {99, 3}}; // 0x100C y 0x100D
• b = 0x1000
• b+2 = 0x1008
• *(b+2)= b[2][0] = 0x1008 con unsigned char
• *(b+2)+1 = 0x100A
• *(*(b+2)+1) = 0x100A con usnigned char
• b[3][1] = 3
• *b++ = se incrementa segun a donde este apuntando b
