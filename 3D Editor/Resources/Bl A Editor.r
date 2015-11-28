#include <Carbon/Carbon.r>

data 'blED' (0, "Owner resource") {
	$"0202 01"                                            /* ... */
};

resource 'CURS' (89) {
	$"0000 0000 0000 1FE0 1FC0 1F80 1FC0 1FE0"
	$"1FF0 1BF8 11FC 00FE 007C 0038 0010",
	$"0000 0000 3FF0 3FF0 3FE0 3FC0 3FE0 3FF0"
	$"3FF8 3FFC 3BFE 31FF 00FE 007C 0038 0010",
	{3, 12}
};

resource 'CURS' (90) {
	$"0000 0000 0000 0040 00E0 01F0 03F8 07FC"
	$"01F0 01F0 01F0 01F0 01F0 01F0 01F0",
	$"0000 0000 0040 00E0 01F0 03F8 07FC 0FFE"
	$"0FFE 03F8 03F8 03F8 03F8 03F8 03F8 03F8",
	{3, 9}
};

resource 'CURS' (91) {
	$"0000 0000 0000 07F8 03F8 01F8 03F8 07F8"
	$"0FF8 1FD8 3F88 7F00 3E00 1C00 08",
	$"0000 0000 0FFC 0FFC 07FC 03FC 07FC 0FFC"
	$"1FFC 3FFC 7FDC FF8C 7F00 3E00 1C00 08",
	{3, 12}
};

resource 'CURS' (99) {
	$"0000 0000 0000 0200 0600 0FFC 1FFC 3FFC"
	$"1FFC 0FFC 0600 02",
	$"0000 0000 0300 0700 0FFE 1FFE 3FFE 7FFE"
	$"3FFE 1FFE 0FFE 0700 03",
	{7, 13}
};

resource 'CURS' (101) {
	$"0000 0000 0000 0040 0060 3FF0 3FF8 3FFC"
	$"3FF8 3FF0 0060 0040",
	$"0000 0000 00C0 00E0 7FF0 7FF8 7FFC 7FFE"
	$"7FFC 7FF8 7FF0 00E0 00C0",
	{7, 13}
};

resource 'CURS' (109) {
	$"0000 0010 0038 007C 00FE 11FC 1BF8 1FF0"
	$"1FE0 1FC0 1F80 1FC0 1FE0",
	$"0010 0038 007C 00FE 31FF 3BFE 3FFC 3FF8"
	$"3FF0 3FE0 3FC0 3FE0 3FF0 3FF0",
	{3, 12}
};

resource 'CURS' (110) {
	$"0000 01F0 01F0 01F0 01F0 01F0 01F0 01F0"
	$"07FC 03F8 01F0 00E0 0040",
	$"03F8 03F8 03F8 03F8 03F8 03F8 03F8 0FFE"
	$"0FFE 07FC 03F8 01F0 00E0 0040",
	{3, 9}
};

resource 'CURS' (111) {
	$"0000 0800 1C00 3E00 7F00 3F88 1FD8 0FF8"
	$"07F8 03F8 01F8 03F8 07F8",
	$"0800 1C00 3E00 7F00 FF8C 7FDC 3FFC 1FFC"
	$"0FFC 07FC 03FC 07FC 0FFC 0FFC",
	{3, 12}
};

resource 'CURS' (120) {
	$"0000 4000 6000 3000 1C00 0E00 0700 0380"
	$"01C4 00E4 007C 0038 003C 00EE 0006",
	$"C000 E000 F000 7C00 3E00 1F00 0F80 07C4"
	$"03EE 01FE 00FE 007C 00FE 01FF 00EF 0006",
	{1, 1}
};

resource 'CURS' (121) {
	$"0000 0000 0000 0000 9000 500C 2012 CC21"
	$"125A 1984 0CE8 0610 0320 01C0 0080",
	$"",
	{7, 3}
};

resource 'CURS' (122) {
	$"0006 000A 07F4 0AA8 1550 2030 2068 4068"
	$"4048 4010 8020 00C0 0700 0400 08",
	$"0006 000E 07FC 0FF8 1FF0 3FF0 3FF8 7FF8"
	$"7FF8 7FF0 FFE0 7FC0 3F00 1C00 08",
	{0, 14}
};

resource 'CURS' (124) {
	$"0000 0000 01C0 0080 03E0 0C98 0888 5085"
	$"7FFF 5085 0888 0C98 03E0 0080 01C0",
	$"0000 0000 01C0 0080 03E0 0FF8 0FF8 5FFD"
	$"7FFF 5FFD 0FF8 0FF8 03E0 0080 01C0",
	{8, 8}
};

resource 'CURS' (126) {
	$"0000 1FF0 3018 4004 4004 4004 4004 3018"
	$"1BF0 0A00 0C00 0800 1000 20",
	$"0000 1FF0 3FF8 7FFC 7FFC 7FFC 7FFC 3FF8"
	$"1FF0 0E00 0C00 0800 1000 20",
	{6, 7}
};

resource 'CURS' (127) {
	$"0400 0800 3500 1A00 0C00 0600 0300 0180"
	$"00C0 0060 0030 001C 0012 0012 000C",
	$"0E00 3D00 7F80 3F00 1E00 0F00 0780 03C0"
	$"01E0 00F0 007C 003E 003F 003F 001E 000C",
	{3, 2}
};

resource 'CURS' (129) {
	$"0000 0000 0780 0FC0 1860 1860 0060 00C0"
	$"0180 0300 0300 0300 0000 0300 03",
	$"0000 0FC0 1FE0 3FF0 3FF0 3CF0 3DF0 03F0"
	$"07E0 07C0 0780 0780 0780 0780 0780 0780",
	{7, 6}
};

resource 'CURS' (130) {
	$"0000 4000 6000 3000 1C00 0E00 0700 0380"
	$"01C4 00E4 007C 0038 003C 00EE 0006",
	$"C000 E000 F000 7C00 3E00 1F00 0F80 07C4"
	$"03EE 01FE 00FE 007C 00FE 01FF 00EF 0006",
	{1, 1}
};

resource 'CURS' (131) {
	$"0000 0000 0000 0070 00F8 03F8 01F8 03F0"
	$"04E0 0AA0 1100 2A00 4400 4800 70",
	$"0000 0000 0000 0070 00F8 03F8 01F8 03F0"
	$"07E0 0FA0 1F00 3E00 7C00 7800 70",
	{14, 1}
};

resource 'CURS' (132) {
	$"003C 0048 00B0 0160 02C0 0F80 1B00 1100"
	$"3300 3600 3C00 3800 3800 1C",
	$"003C 0078 00F0 01E0 03C0 0F80 1F00 1F00"
	$"3F00 3E00 3C00 3800 3800 1C",
	{13, 5}
};

resource 'CURS' (133) {
	$"0100 0010 2080 0400 0022 8200 1048 0101"
	$"0440 9008 0222 0800 4120 0004 0800 0080",
	$"",
	{8, 8}
};

resource 'CURS' (134) {
	$"FFFF 8001 8001 8001 8001 8001 8001 8001"
	$"8001 8001 8001 8001 8001 8001 8001 FFFF",
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF"
	$"FFFF FFFF FFFF FFFF FFFF FFFF FFFF FFFF",
	{8, 8}
};

resource 'CURS' (135) {
	$"FFFF 8000 8000 8000 8000 8000 8000 8000"
	$"8080 8000 8000 8000 8000 8000 8000 80",
	$"FFFF FFFF C000 C000 C000 C000 C000 C000"
	$"C000 C000 C000 C000 C000 C000 C000 C0",
	{8, 8}
};

resource 'CURS' (136) {
	$"0001 0001 0001 0001 0001 0001 0001 0001"
	$"0081 0001 0001 0001 0001 0001 0001 FFFF",
	$"0003 0003 0003 0003 0003 0003 0003 0003"
	$"0003 0003 0003 0003 0003 0003 FFFF FFFF",
	{8, 8}
};

resource 'CURS' (137) {
	$"0006 000A 07F4 0AA8 1550 2030 2068 4068"
	$"4048 4010 8020 00C0 0700 0400 08",
	$"0006 000E 07FC 0FF8 1FF0 3FF0 3FF8 7FF8"
	$"7FF8 7FF0 FFE0 7FC0 3F00 1C00 08",
	{0, 14}
};

resource 'CURS' (138) {
	$"0000 0000 0000 0080 0140 0630 0808 3006"
	$"4081",
	$"0000 0000 0000 0080 01C0 0770 0E38 380E"
	$"7007 4001",
	{8, 8}
};

resource 'CURS' (139) {
	$"0000 0000 0000 0000 0000 0000 0000 0000"
	$"4081 3006 0808 0630 0140 0080",
	$"0000 0000 0000 0000 0000 0000 0000 4001"
	$"7007 380E 0E38 0770 01C0 0080",
	{8, 8}
};

resource 'CURS' (140) {
	$"0000 0020 0050 0090 01D0 02B0 0C90 1808"
	$"3004 7802 7404 7208 3110 10A0 0040",
	$"0020 0070 00F8 01D8 03F8 0FF8 1FF8 3FFC"
	$"7FFE FFFF FFFE FFFC 7BF8 39F0 10E0 0040",
	{13, 3}
};

resource 'MBAR' (128) {
	{	/* array MenuArray: 15 elements */
		/* [1] */
		500,
		/* [2] */
		550,
		/* [3] */
		570,
		/* [4] */
		600,
		/* [5] */
		650,
		/* [6] */
		651,
		/* [7] */
		700,
		/* [8] */
		701,
		/* [9] */
		702,
		/* [10] */
		703,
		/* [11] */
		704,
		/* [12] */
		750,
		/* [13] */
		751,
		/* [14] */
		752,
		/* [15] */
		753
	}
};

data 'Mcmd' (130) {
	$"0004 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000"                                               /* .. */
};

data 'Mcmd' (550) {
	$"0006 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000"                           /* .......... */
};

data 'Mcmd' (600) {
	$"0013 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000"                 /* .............. */
};

data 'Mcmd' (650) {
	$"0011 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000"                                     /* ...... */
};

data 'Mcmd' (651) {
	$"000A 0000 0000 0000 0000 0000 0000 0000"            /* .Â.............. */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000"                           /* .......... */
};

resource 'mctb' (500, "\0x14 menu") {
	{	/* array MCTBArray: 1 elements */
		/* [1] */
		500, 0,
		{	/* array: 4 elements */
			/* [1] */
			0, 0, 0,
			/* [2] */
			65535, 65535, 65535,
			/* [3] */
			0, 0, 0,
			/* [4] */
			65535, 65535, 65535
		}
	}
};

resource 'mctb' (550, "File menu") {
	{	/* array MCTBArray: 1 elements */
		/* [1] */
		550, 0,
		{	/* array: 4 elements */
			/* [1] */
			0, 0, 0,
			/* [2] */
			65535, 65535, 65535,
			/* [3] */
			0, 0, 0,
			/* [4] */
			65535, 65535, 65535
		}
	}
};

resource 'mctb' (600, "Scenario menu") {
	{	/* array MCTBArray: 1 elements */
		/* [1] */
		600, 0,
		{	/* array: 4 elements */
			/* [1] */
			0, 0, 0,
			/* [2] */
			65535, 65535, 65535,
			/* [3] */
			0, 0, 0,
			/* [4] */
			65535, 65535, 65535
		}
	}
};

resource 'mctb' (650, "Town menu") {
	{	/* array MCTBArray: 1 elements */
		/* [1] */
		650, 0,
		{	/* array: 4 elements */
			/* [1] */
			0, 0, 0,
			/* [2] */
			65535, 65535, 65535,
			/* [3] */
			0, 0, 0,
			/* [4] */
			65535, 65535, 65535
		}
	}
};

resource 'mctb' (651, "Help menu") {
	{	/* array MCTBArray: 1 elements */
		/* [1] */
		651, 0,
		{	/* array: 4 elements */
			/* [1] */
			0, 0, 0,
			/* [2] */
			65535, 65535, 65535,
			/* [3] */
			0, 0, 0,
			/* [4] */
			65535, 65535, 65535
		}
	}
};

resource 'MENU' (101, "Set Application Path") {
	101,
	101,
	allEnabled,
	enabled,
	"Set Application Path",
	{	/* array: 4 elements */
		/* [1] */
		"Text Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"Alint", noIcon, noKey, noMark, plain,
		/* [3] */
		"Dialogue Editor", noIcon, noKey, noMark, plain,
		/* [4] */
		"Graphic Adjuster", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (102) {
	102,
	103,
	allEnabled,
	enabled,
	"Open Scenario Script",
	{	/* array: 2 elements */
		/* [1] */
		"In Text Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"In Alint", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (103) {
	103,
	103,
	allEnabled,
	enabled,
	"Open Scenario Data Script",
	{	/* array: 2 elements */
		/* [1] */
		"In Text Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"In Alint", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (104) {
	104,
	104,
	allEnabled,
	enabled,
	"Open Town Script",
	{	/* array: 2 elements */
		/* [1] */
		"In Text Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"In Alint", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (105) {
	105,
	105,
	allEnabled,
	enabled,
	"Open Town Dialogue Script",
	{	/* array: 3 elements */
		/* [1] */
		"In Dialog Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"In Text Editor", noIcon, noKey, noMark, plain,
		/* [3] */
		"In Alint", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (106) {
	106,
	106,
	allEnabled,
	enabled,
	"Open Outdoor Script",
	{	/* array: 2 elements */
		/* [1] */
		"In Text Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"In Alint", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (107) {
	107,
	107,
	allEnabled,
	enabled,
	"Open Creature Script",
	{	/* array: 2 elements */
		/* [1] */
		"In Text Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"In Alint", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (108) {
	108,
	108,
	allEnabled,
	enabled,
	"Open Terrain Script",
	{	/* array: 2 elements */
		/* [1] */
		"In Text Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"In Alint", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (500) {
	500,
	textMenuProc,
	allEnabled,
	enabled,
	apple,
	{	/* array: 5 elements */
		/* [1] */
		"About Blades of Avernum Editor", noIcon, noKey, noMark, plain,
		/* [2] */
		"License Information", noIcon, noKey, noMark, plain,
		/* [3] */
		"Check for Updates...", noIcon, noKey, noMark, plain,
		/* [4] */
		"Select Script Editor...", noIcon, noKey, noMark, plain,
		/* [5] */
		"-", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (550) {
	550,
	textMenuProc,
	0x7FFFFFEF,
	enabled,
	"File",
	{	/* array: 6 elements */
		/* [1] */
		"Open...", noIcon, "O", noMark, plain,
		/* [2] */
		"Save", noIcon, "S", noMark, plain,
		/* [3] */
		"New Scenario...", noIcon, noKey, noMark, plain,
		/* [4] */
		"Import Blades of Exile Scenario...", noIcon, noKey, noMark, plain,
		/* [5] */
		"-", noIcon, noKey, noMark, plain,
		/* [6] */
		"Quit", noIcon, "Q", noMark, plain
	}
};

resource 'MENU' (570) {
	570,
	textMenuProc,
	0x7FFFFF7B,
	enabled,
	"Edit",
	{	/* array: 22 elements */
		/* [1] */
		"Undo", noIcon, "Z", noMark, plain,
		/* [2] */
		"Redo", noIcon, "Y", noMark, plain,
		/* [3] */
		"-", noIcon, noKey, noMark, plain,
		/* [4] */
		"Cut", noIcon, "X", noMark, plain,
		/* [5] */
		"Copy", noIcon, "C", noMark, plain,
		/* [6] */
		"Paste", noIcon, "V", noMark, plain,
		/* [7] */
		"Clear", noIcon, noKey, noMark, plain,
		/* [8] */
		"-", noIcon, noKey, noMark, plain,
		/* [9] */
		"Draw Floors", noIcon, "1", noMark, plain,
		/* [10] */
		"Draw Terrains", noIcon, "2", noMark, plain,
		/* [11] */
		"Draw Heights", noIcon, "3", noMark, plain,
		/* [12] */
		"Place Creatures", noIcon, "4", noMark, plain,
		/* [13] */
		"Place Items", noIcon, "5", noMark, plain,
		/* [14] */
		"-", noIcon, noKey, noMark, plain,
		/* [15] */
		"Increase Tile Size", noIcon, "+", noMark, plain,
		/* [16] */
		"Decrease Tile Size", noIcon, "-", noMark, plain,
		/* [17] */
		"-", noIcon, noKey, noMark, plain,
		/* [18] */
		"Play Sounds", noIcon, noKey, check, plain,
		/* [19] */
		"Kelandons Strict 2D Icon Adjusts", noIcon, noKey, check, plain,
		/* [20] */
		"Always Show Height Labels", noIcon, noKey, check, plain,
		/* [21] */
		"Allow Arrow Key Navigation", noIcon, noKey, check, plain,
		/* [22] */
		"Check for Updates at Startup", noIcon, noKey, check, plain
	}
};

resource 'MENU' (600) {
	600,
	textMenuProc,
	0x7FFFFFF7,
	enabled,
	"Scenario",
	{	/* array: 22 elements */
		/* [1] */
		"Edit Town", noIcon, "T", noMark, plain,
		/* [2] */
		"Edit Outdoor Section", noIcon, "R", noMark, plain,
		/* [3] */
		"Create New Town", noIcon, noKey, noMark, plain,
		/* [4] */
		"-", noIcon, noKey, noMark, plain,
		/* [5] */
		"Basic Scenario Details", noIcon, noKey, noMark, plain,
		/* [6] */
		"Set Label Icon", noIcon, noKey, noMark, plain,
		/* [7] */
		"Set Intro Text 1", noIcon, noKey, noMark, plain,
		/* [8] */
		"Set Intro Text 2", noIcon, noKey, noMark, plain,
		/* [9] */
		"Set Intro Text 3", noIcon, noKey, noMark, plain,
		/* [10] */
		"Edit Scenario Script", noIcon, "E", noMark, plain,
		/* [11] */
		"Edit Scenario Data Script", noIcon, "E", noMark, plain,
		/* [12] */
		"-", noIcon, noKey, noMark, plain,
		/* [13] */
		"Advanced:", noIcon, noKey, noMark, plain,
		/* [14] */
		"  Reload Scenario Data", noIcon, noKey, noMark, plain,
		/* [15] */
		"  Clean Up Walls", noIcon, noKey, noMark, plain,
		/* [16] */
		"  Import Town", noIcon, noKey, noMark, plain,
		/* [17] */
		"  Import Outdoor Section", noIcon, noKey, noMark, plain,
		/* [18] */
		"  Set Variable Town Entry\n", noIcon, noKey, noMark, plain,
		/* [19] */
		"  Edit Item Placement Shortcuts", noIcon, noKey, noMark, plain,
		/* [20] */
		"  Delete Town\0x00\0x00\0x00\0x00\0x00", noIcon, noKey, noMark, plain,
		/* [21] */
		"  Write Scenario Data to Text File", noIcon, noKey, noMark, plain,
		/* [22] */
		"  Change Outdoor Size", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (650) {
	650,
	textMenuProc,
	0x7FFFFDFF,
	enabled,
	"Town",
	{	/* array: 21 elements */
		/* [1] */
		"Load Different Town", noIcon, "L", noMark, plain,
		/* [2] */
		"Town Details", noIcon, "D", noMark, plain,
		/* [3] */
		"Town Wandering Monsters", noIcon, noKey, noMark, plain,
		/* [4] */
		"Set Town Boundaries", noIcon, noKey, noMark, plain,
		/* [5] */
		"Frill Up Terrain", noIcon, noKey, noMark, plain,
		/* [6] */
		"Remove Terrain Frills", noIcon, noKey, noMark, plain,
		/* [7] */
		"Edit Area Descriptions", noIcon, noKey, noMark, plain,
		/* [8] */
		"Edit Town Script", noIcon, "E", noMark, plain,
		/* [9] */
		"Edit Town Dialogue Script", noIcon, "E", noMark, plain,
		/* [10] */
		"-", noIcon, noKey, noMark, plain,
		/* [11] */
		"Set Starting Location", noIcon, noKey, noMark, plain,
		/* [12] */
		"-", noIcon, noKey, noMark, plain,
		/* [13] */
		"Add Random Items", noIcon, noKey, noMark, plain,
		/* [14] */
		"Set All Items Contained", noIcon, noKey, noMark, plain,
		/* [15] */
		"Set All Items Not Property", noIcon, noKey, noMark, plain,
		/* [16] */
		"Clear All Items", noIcon, noKey, noMark, plain,
		/* [17] */
		"-", noIcon, noKey, noMark, plain,
		/* [18] */
		"Advanced:", noIcon, noKey, noMark, plain,
		/* [19] */
		"  Clear All Monsters", noIcon, noKey, noMark, plain,
		/* [20] */
		"  Clear All Special Encounters", noIcon, noKey, noMark, plain,
		/* [21] */
		"  Change Town Size", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (651) {
	651,
	textMenuProc,
	allEnabled,
	enabled,
	"Outdoors",
	{	/* array: 11 elements */
		/* [1] */
		"Load Different Outdoor Section", noIcon, "L", noMark, plain,
		/* [2] */
		"Outdoor Details", noIcon, "D", noMark, plain,
		/* [3] */
		"Outdoor Wandering Monsters", noIcon, noKey, noMark, plain,
		/* [4] */
		"Outdoor Special Encounters", noIcon, noKey, noMark, plain,
		/* [5] */
		"Outdoor Preset Encounters", noIcon, noKey, noMark, plain,
		/* [6] */
		"Frill Up Terrain", noIcon, noKey, noMark, plain,
		/* [7] */
		"Remove Terrain Frills", noIcon, noKey, noMark, plain,
		/* [8] */
		"Edit Area Descriptions", noIcon, noKey, noMark, plain,
		/* [9] */
		"Edit Outdoor Script", noIcon, "E", noMark, plain,
		/* [10] */
		"-", noIcon, noKey, noMark, plain,
		/* [11] */
		"Set Starting Location", noIcon, noKey, noMark, plain
	}
};

resource 'MENU' (652, "Script") {
	652,
	textMenuProc,
	allEnabled,
	enabled,
	"Script",
	{	/* array: 9 elements */
		/* [1] */
		"Set Application Path", noIcon, hierarchicalMenu, "e", plain,
		/* [2] */
		"Open Scenario Script", noIcon, hierarchicalMenu, "f", plain,
		/* [3] */
		"Open Scenario Data Script", noIcon, hierarchicalMenu, "g", plain,
		/* [4] */
		"Open CMG File in Graphic Adjuster", noIcon, noKey, noMark, plain,
		/* [5] */
		"Open Town Script", noIcon, hierarchicalMenu, "h", plain,
		/* [6] */
		"Open Town Dialogue Script", noIcon, hierarchicalMenu, "i", plain,
		/* [7] */
		"Open Outdoor Section Script", noIcon, hierarchicalMenu, "j", plain,
		/* [8] */
		"Open Creature Script", noIcon, hierarchicalMenu, "k", plain,
		/* [9] */
		"Open Terrain Script", noIcon, hierarchicalMenu, "l", plain
	}
};

resource 'MENU' (700) {
	700,
	textMenuProc,
	allEnabled,
	enabled,
	"I1",
	{	/* array: 0 elements */
	}
};

resource 'MENU' (701) {
	701,
	textMenuProc,
	allEnabled,
	enabled,
	"I2",
	{	/* array: 0 elements */
	}
};

resource 'MENU' (702) {
	702,
	textMenuProc,
	allEnabled,
	enabled,
	"I3",
	{	/* array: 0 elements */
	}
};

resource 'MENU' (703) {
	703,
	textMenuProc,
	allEnabled,
	enabled,
	"I4",
	{	/* array: 0 elements */
	}
};

resource 'MENU' (704) {
	704,
	textMenuProc,
	allEnabled,
	enabled,
	"I5",
	{	/* array: 0 elements */
	}
};

resource 'MENU' (750) {
	750,
	textMenuProc,
	allEnabled,
	enabled,
	"C1",
	{	/* array: 0 elements */
	}
};

resource 'MENU' (751) {
	751,
	textMenuProc,
	allEnabled,
	enabled,
	"C2",
	{	/* array: 0 elements */
	}
};

resource 'MENU' (752) {
	752,
	textMenuProc,
	allEnabled,
	enabled,
	"C3",
	{	/* array: 0 elements */
	}
};

resource 'MENU' (753) {
	753,
	textMenuProc,
	allEnabled,
	enabled,
	"C4",
	{	/* array: 0 elements */
	}
};

data 'PRFN' (128, "Exile II Prefs") {
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000 0000 0000 0000 0000"            /* ................ */
	$"0000 0000 0000 0000"                                /* ........ */
};

resource 'STR#' (4, "Char appear time types") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"always here (unless town dead)",
		/* [2] */
		"here at time t unless town dead",
		/* [3] */
		"disappear at time t",
		/* [4] */
		"here if event not done by time t",
		/* [5] */
		"gone if event not done by time t",
		/* [6] */
		"here if event happened",
		/* [7] */
		"gone if event happened",
		/* [8] */
		"here on day 0-2 of every 9 days",
		/* [9] */
		"here on day 3-5 of every 9 days",
		/* [10] */
		"here on day 6-8 of every 9 days",
		/* [11] */
		"here if and only if town dead",
		/* [12] */
		"",
		/* [13] */
		"",
		/* [14] */
		"",
		/* [15] */
		"",
		/* [16] */
		"",
		/* [17] */
		"",
		/* [18] */
		"",
		/* [19] */
		"",
		/* [20] */
		"",
		/* [21] */
		"",
		/* [22] */
		"",
		/* [23] */
		"",
		/* [24] */
		"",
		/* [25] */
		"",
		/* [26] */
		"",
		/* [27] */
		"",
		/* [28] */
		"",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"",
		/* [51] */
		"",
		/* [52] */
		"",
		/* [53] */
		"",
		/* [54] */
		"",
		/* [55] */
		"",
		/* [56] */
		"",
		/* [57] */
		"",
		/* [58] */
		"",
		/* [59] */
		"",
		/* [60] */
		"",
		/* [61] */
		"",
		/* [62] */
		"",
		/* [63] */
		"",
		/* [64] */
		"",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"",
		/* [81] */
		"",
		/* [82] */
		"",
		/* [83] */
		"",
		/* [84] */
		"",
		/* [85] */
		"",
		/* [86] */
		"",
		/* [87] */
		"",
		/* [88] */
		"",
		/* [89] */
		"",
		/* [90] */
		"",
		/* [91] */
		"",
		/* [92] */
		"",
		/* [93] */
		"",
		/* [94] */
		"",
		/* [95] */
		"",
		/* [96] */
		"",
		/* [97] */
		"",
		/* [98] */
		"",
		/* [99] */
		"",
		/* [100] */
		"",
		/* [101] */
		"",
		/* [102] */
		"",
		/* [103] */
		"",
		/* [104] */
		"",
		/* [105] */
		"",
		/* [106] */
		"",
		/* [107] */
		"",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"",
		/* [132] */
		"",
		/* [133] */
		"",
		/* [134] */
		"",
		/* [135] */
		"",
		/* [136] */
		"",
		/* [137] */
		"",
		/* [138] */
		"",
		/* [139] */
		"",
		/* [140] */
		"",
		/* [141] */
		"",
		/* [142] */
		"",
		/* [143] */
		"",
		/* [144] */
		"",
		/* [145] */
		"",
		/* [146] */
		"",
		/* [147] */
		"",
		/* [148] */
		"",
		/* [149] */
		"",
		/* [150] */
		"",
		/* [151] */
		"",
		/* [152] */
		"",
		/* [153] */
		"",
		/* [154] */
		"",
		/* [155] */
		"",
		/* [156] */
		"",
		/* [157] */
		"",
		/* [158] */
		"",
		/* [159] */
		"",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"",
		/* [172] */
		"",
		/* [173] */
		"",
		/* [174] */
		"",
		/* [175] */
		"",
		/* [176] */
		"",
		/* [177] */
		"",
		/* [178] */
		"",
		/* [179] */
		"",
		/* [180] */
		"",
		/* [181] */
		"",
		/* [182] */
		"",
		/* [183] */
		"",
		/* [184] */
		"",
		/* [185] */
		"",
		/* [186] */
		"",
		/* [187] */
		"",
		/* [188] */
		"",
		/* [189] */
		"",
		/* [190] */
		"",
		/* [191] */
		"",
		/* [192] */
		"",
		/* [193] */
		"",
		/* [194] */
		"",
		/* [195] */
		"",
		/* [196] */
		"",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"",
		/* [202] */
		"",
		/* [203] */
		"",
		/* [204] */
		"",
		/* [205] */
		"",
		/* [206] */
		"",
		/* [207] */
		"",
		/* [208] */
		"",
		/* [209] */
		"",
		/* [210] */
		"",
		/* [211] */
		"",
		/* [212] */
		"",
		/* [213] */
		"",
		/* [214] */
		"",
		/* [215] */
		"",
		/* [216] */
		"",
		/* [217] */
		"",
		/* [218] */
		"",
		/* [219] */
		"",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"",
		/* [227] */
		"",
		/* [228] */
		"",
		/* [229] */
		"",
		/* [230] */
		"",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (9, "Skills") {
	{	/* array StringArray: 77 elements */
		/* [1] */
		"Strength",
		/* [2] */
		"",
		/* [3] */
		"Dexterity",
		/* [4] */
		"",
		/* [5] */
		"Intelligence",
		/* [6] */
		"",
		/* [7] */
		"Endurance",
		/* [8] */
		"",
		/* [9] */
		"Melee Weapons",
		/* [10] */
		"",
		/* [11] */
		"Spears",
		/* [12] */
		"",
		/* [13] */
		"Javelins",
		/* [14] */
		"",
		/* [15] */
		"Slings",
		/* [16] */
		"",
		/* [17] */
		"Armor Use",
		/* [18] */
		"",
		/* [19] */
		"Berzerker",
		/* [20] */
		"",
		/* [21] */
		"Hardiness",
		/* [22] */
		"",
		/* [23] */
		"Defense",
		/* [24] */
		"",
		/* [25] */
		"Roman Training",
		/* [26] */
		"",
		/* [27] */
		"Riflery",
		/* [28] */
		"",
		/* [29] */
		"Druidism",
		/* [30] */
		"",
		/* [31] */
		"Health Circle",
		/* [32] */
		"",
		/* [33] */
		"War Circle",
		/* [34] */
		"",
		/* [35] */
		"Beast Circle",
		/* [36] */
		"",
		/* [37] */
		"Craft Circle",
		/* [38] */
		"",
		/* [39] */
		"Spirit Circle",
		/* [40] */
		"",
		/* [41] */
		"First Aid",
		/* [42] */
		"",
		/* [43] */
		"Herbcraft",
		/* [44] */
		"",
		/* [45] */
		"Tool Use",
		/* [46] */
		"",
		/* [47] */
		"Faerie Lore",
		/* [48] */
		"",
		/* [49] */
		"Woodscraft",
		/* [50] */
		"",
		/* [51] */
		"Barter",
		/* [52] */
		"",
		/* [53] */
		"Luck",
		/* [54] */
		"",
		/* [55] */
		"Health",
		/* [56] */
		"",
		/* [57] */
		"Spell Energy",
		/* [58] */
		"",
		/* [59] */
		"Poison Resistance",
		/* [60] */
		"",
		/* [61] */
		"Magic Resistance",
		/* [62] */
		"",
		/* [63] */
		"Willpower",
		/* [64] */
		"",
		/* [65] */
		"Rune Reading",
		/* [66] */
		"",
		/* [67] */
		"Item Lore",
		/* [68] */
		"",
		/* [69] */
		"Alchemy",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		""
	}
};

resource 'STR#' (10, "Help strings") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Welcome to Exile III: Ruined World. Thes"
		"e windows will pop up occasionally to ex"
		"plain what is going on. If they annoy yo"
		"u, they can be turned off in the Prefere"
		"nces screen (access from Options menu).",
		/* [2] */
		"In general, you can get help by clicking"
		" on the '?' buttons or typing '?'. For n"
		"ow, you should get equipment, explore th"
		"is fort, and get your orders. Press the "
		"hand buttons (or type 'g') to pick up th"
		"e nearby items.",
		/* [3] */
		"",
		/* [4] */
		"",
		/* [5] */
		"Everyone responds to 'Look', 'Name', and"
		" 'Job' (use the buttons at the bottom). "
		"To ask about something people mention, c"
		"lick on the word (click on 'Demon' to as"
		"k about demons). Certain people respond "
		"to 'Buy' and 'Sell', which puts you in s"
		"hopping mode. ",
		/* [6] */
		"Shortcuts: To get previous response, pre"
		"ss the Back button (or hit space). You c"
		"an press any of the bottom buttons by ty"
		"ping the first letter in the word. Hit R"
		"ecord to write notes in journal, and hit"
		" Bye (or type Escape) to stop talking.",
		/* [7] */
		"To cast a spell, first click on the numb"
		"er of the person to cast (to the upper l"
		"eft). Then click on the button by the sp"
		"ell to cast (hit Space to see other spel"
		"ls). Finally, if it's a spell cast on a "
		"party member, click on the correct Targe"
		"t button.",
		/* [8] */
		"Shortcut: Typing the letter after a spel"
		"l picks the spell, and typing '1'-'6' pi"
		"cks a caster. Option clicking a spell bu"
		"tton brings up a spell description. Fina"
		"lly, you can often cast spells faster us"
		"ing the Mage Spells and Priest spells me"
		"nus.",
		/* [9] */
		"This menu always contains all the spells"
		" an active PC can cast. Click on the nam"
		"e of a PC to make him/her active. Then s"
		"elect a spell from this menu to cast. Th"
		"en, if you need to pick someone to cast "
		"the spell on, a window will come up for "
		"you to do so.",
		/* [10] */
		"This is where you improve a character's "
		"skills when creating or training him/her"
		". Press the '+' button to buy a skill, a"
		"nd the '-' button to undo the choice. Th"
		"e Cancel button undoes your work, and Ke"
		"ep keeps your choices.",
		/* [11] */
		"Option-click the buttons by a skill to g"
		"et a description of the skill and advice"
		" on how much to buy. When training a cha"
		"racter, you need both gold and skill poi"
		"nts (which you get by killing things and"
		" getting experience).",
		/* [12] */
		"This menu contains the monsters you have"
		" magically obtained information about. T"
		"o make a monster appear here, cast Scry "
		"Monster on it.",
		/* [13] */
		"",
		/* [14] */
		"",
		/* [15] */
		"",
		/* [16] */
		"",
		/* [17] */
		"",
		/* [18] */
		"",
		/* [19] */
		"",
		/* [20] */
		"Sometimes, outdoors or in stores, you wi"
		"ll find ingredients to make alchemical p"
		"otions, using recipes you buy from sages"
		" in town. To make a potion, select an ac"
		"tive PC by clicking on his/her name or t"
		"yping '1'-'6'. Then access this window.",
		/* [21] */
		"To make a potion, click the appropriate "
		"button. The character needs a high enoug"
		"h alchemy skill and the right ingredient"
		". For a full description of all potions,"
		" select Alchemy & Poison from the Librar"
		"y menu.",
		/* [22] */
		"Here is where you edit your party before"
		" beginning the game. You start with 6 pr"
		"e-fabricated characters. To replace them"
		" with characters of your own, hit the de"
		"lete button and then click on the 'Hit h"
		"ere to Create' button. ",
		/* [23] */
		"Press a PCs name to rename it, the Race "
		"button to edit his/her race and advantag"
		"es/disadvantages, the Graphic button to "
		"pick a new graphic, and the Train button"
		" to adjust the character's starting skil"
		"ls. When ready to start the game, Press "
		"Done.",
		/* [24] */
		"You don't have enough gold on you to buy"
		" this skill. The cost to buy a level of "
		"a skill is the number after the slash in"
		" parentheses. Skills you can buy have th"
		"e numbers given in red.",
		/* [25] */
		"You don't have enough skill points on yo"
		"u to buy this skill. The number of skill"
		" pts. to buy a level of a skill is the n"
		"umber before the slash in parentheses. T"
		"o get skill points, kill enough monsters"
		" to gain a level.",
		/* [26] */
		"Here, you can spend your hard earned cas"
		"h on miscellaneous goodies. To select a "
		"character to do the buying, click on the"
		" character's name (or type '1' - '6'). C"
		"lick on the name of an item or type 'a'-"
		"'h' to buy something.",
		/* [27] */
		"To get info on an item (if available) cl"
		"ick on the little 'I' button to the righ"
		"t of the item's name. Finally, when thro"
		"ugh shopping, hit Escape or click on the"
		" done button.",
		/* [28] */
		"One of your characters has just become d"
		"umbfounded. This takes your ability to c"
		"ast spells. You lose higher level spells"
		" first, then lower level spells. To remo"
		"ve this, cast Restore Mind or visit a he"
		"aler. Dumbfounding is permanent until cu"
		"red.",
		/* [29] */
		"One of your characters has just become d"
		"iseased. This slowly, gradually causes a"
		" wide variety of damaging effects. Heale"
		"rs and certain priest spells can cure di"
		"sease, or it slowly fades over time.",
		/* [30] */
		"One of your characters has just magicall"
		"y made to fall asleep. He/she will event"
		"ually wake up, or an Awaken or Hyperacti"
		"vity spell can hasten the process.",
		/* [31] */
		"One of your characters has just been cov"
		"ered with webs. This will slow the chara"
		"cter down in combat and make his/her fig"
		"hting much less effective. To clean off "
		"the webs, pause repeatedly (click on the"
		" PC or type '5' on the keypad).",
		/* [32] */
		"One of your characters has just been par"
		"alyzed. He/she will not be able to move "
		"for quite some time. This can be cured b"
		"y the spell Cure Paralysis or by going t"
		"o a healer. This is a pretty nasty effec"
		"t.",
		/* [33] */
		"One of your characters has just been poi"
		"soned. This character will take damage e"
		"very few moves until the poison wears of"
		"f. Several priest spells cure poison.",
		/* [34] */
		"One of your characters has just been ble"
		"ssed. This PC will be better in combat, "
		"and he/she will be protected from the at"
		"tacks of others. The effects of blessing"
		" are cumulative: blessing a PC twice is "
		"well over twice as affecting as blessing"
		" it once.",
		/* [35] */
		"One of your characters has just been slo"
		"wed/hasted. A slowed PC loses one out of"
		" every two turns in combat. A hasted PC "
		"gets twice the action points in combat. "
		"Both effects wear off fairly quickly.",
		/* [36] */
		"From here, you can select which nearby i"
		"tems to pick up. Click an item (or type "
		"'a'-'h') to pick it up. To have someone "
		"else pick stuff up, click the appropriat"
		"e button at the bottom (or type '1'-'6')"
		".",
		/* [37] */
		"If no hostile monsters are near, you can"
		" pick up everything nearby. Otherwise, y"
		"ou can only grab adjacent items. Dresser"
		"s, desks, and other things can have item"
		"s inside them. Stand next to them and lo"
		"ok at them to search inside.",
		/* [38] */
		"Each character can only carry so many st"
		"ones worth of stuff, and you are trying "
		"to pick up too much. Increasing a charac"
		"ter's strength increases the weight you "
		"can carry.",
		/* [39] */
		"Some spells are cast on another characte"
		"r in your party. You tried to select a s"
		"pell without also selecting someone to c"
		"ast it on. Try again, but this time, aft"
		"er picking the spell, use the buttons to"
		" the right of the character's names to p"
		"ick a target.",
		/* [40] */
		"Wearing armor with a total encumbrance o"
		"f more that 1 spoils any mage spell you "
		"try to cast in combat. High defense skil"
		"l sometimes prevents this from happening"
		", but it will only go so far. If any sin"
		"gle item has encumb. higher than 2, spel"
		"ls always fail.",
		/* [41] */
		"One of your characters just learned a ne"
		"w magical spell. Before you can cast it,"
		" however, you need to get enough spell p"
		"oints and a Mage (or Priest) Spells skil"
		"l as high as the level of the spell.",
		/* [42] */
		"This person has looked over your items a"
		"nd maybe offered to buy some of them. Cl"
		"ick on the 'Sell' button to sell it, for"
		" the amount to the right of the button. "
		"Some people only try to buy certain sort"
		"s of items.",
		/* [43] */
		"Merchants will only buy items that have "
		"been identified. If you want to sell som"
		"ething, you may need to find a sage to i"
		"dentify it (such as Habecker in Fort Eme"
		"rgence).",
		/* [44] */
		"This character will, for a fee, identify"
		" some of your items whose nature is, as "
		"yet, unknown to you. Click on the 'ID' b"
		"utton by the item to get it identified.",
		/* [45] */
		"This merchant has offered to magically i"
		"mprove one of your weapons. Click on the"
		" 'Ench' button by the weapon to pay for "
		"this service. You can only augment ident"
		"ified weapons that aren't magic already.",
		/* [46] */
		"",
		/* [47] */
		"You have just discovered a secret passag"
		"e! All sorts of walls (incl. cave walls)"
		" can have secret passages in them. To fi"
		"nd them, walk into the wall. Sometimes, "
		"you can also move through things that ar"
		"en't walls...",
		/* [48] */
		"You have just entered combat mode! To st"
		"art using a weapon, click on that weapon"
		"'s name. Your characters will now move o"
		"ne at a time ... to attack a bad guy, wa"
		"lk into it. For more information on comb"
		"at mechanics, type '?'.",
		/* [49] */
		"When fighting early in the game, when yo"
		"u're still weak, rely heavily on magical"
		" spells (make sure to have a character w"
		"ith Mage Spells skill of 3). Your melee "
		"people won't be strong for a while. Hit "
		"the 'End' button to leave combat.",
		/* [50] */
		"You've just brought up the list of your "
		"Special Items. Each has an 'Info' button"
		". Some (such as maps) have a 'Use' butto"
		"n to activate them. Others (such as keys"
		") are used automatically when you can us"
		"e them (such as when you find the correc"
		"t door).",
		/* [51] */
		"You can now get a regular job. Click the"
		" 'Take' button to accept it. Doing the j"
		"ob gets you a reward. Warning - if you d"
		"on't do the job in time, this person won"
		"'t give you any new jobs for a while. Yo"
		"u can have a maximum of 4 jobs.",
		/* [52] */
		"This is the inventory page where you can"
		" see what jobs you currently have. You g"
		"et jobs from people in the major surface"
		" cities; they're a good way to earn some"
		" easy money.",
		/* [53] */
		"You have just made this town angry at yo"
		"u, by stealing something or damaging a f"
		"riendly person with a weapon or a damagi"
		"ng spell (like Shockwave). If you leave "
		"and visit other towns for a while, they'"
		"ll stop being mad at you.",
		/* [54] */
		"You have just reached a special encounte"
		"r. Many special encounters are marked by"
		" white spots. Others are invisible, and "
		"activated by stepping on them or by sear"
		"ching the right spot. Special stuff can "
		"be hidden in all terrain types.",
		/* [55] */
		"At the Preferences window, you can selec"
		"t options to speed up the game, change h"
		"ow the game window is positioned, turn t"
		"he sound on and off, and make the game e"
		"asier or harder.",
		/* [56] */
		"You are now creating a new character. Fi"
		"rst you can choose its race and advantag"
		"es/disadvantages (choose carefully - the"
		"se cannot be changed later). Then you ca"
		"n assign it skills, a graphic, and a nam"
		"e.",
		/* [57] */
		"You've just written what this person jus"
		"t said down in your talking journal. To "
		"review it later, select See Talking Note"
		"s from the Options menu.",
		/* [58] */
		"You've just written what this special en"
		"counter says down in your adventure jour"
		"nal. To review it later, select See Enco"
		"unter Notes from the Options menu.",
		/* [59] */
		"One of your characters has just been cur"
		"sed. That character will function worse "
		"in combat, be hit more easily, and take "
		"more damage from blows for a while. Curs"
		"es wear off fairly quickly.",
		/* [60] */
		"You have mounted a horse.  A horse doubl"
		"es your speed when moving outdoors: you'"
		"ll spend much less time moving from town"
		" to town and will have an easier time ev"
		"ading monsters. To dismount, pause (by c"
		"licking on your party or hitting '5' on "
		"the keypad).",
		/* [61] */
		"You have just boarded a boat. Steer the "
		"boat onto land to get out. Certain boats"
		" can pass over lava. When using a boat o"
		"utdoors, you can enter towns on the shor"
		"e by steering the boat into them.",
		/* [62] */
		"This command bring up a map of the area "
		"you're in. Generally, maps of dungeons a"
		"nd the outdoors will be remembered. Howe"
		"ver, if a town undergoes some sort of ma"
		"jor change, you'll lose your map for tha"
		"t town.",
		/* [63] */
		"Your health is a measure of how much pun"
		"ishment you can take before dying - the "
		"more the better. Whenever you get hit, y"
		"ou lose some health. Taking damage when "
		"your health is down to 0 will kill you.",
		/* [64] */
		"Your spell points are what you expend to"
		" cast spells. Each spell drains away som"
		"e of your spell points. Time and rest re"
		"store them. When creating a character, y"
		"ou get 3 bonus spell points for every le"
		"vel of Mage and Priest Spells skill you "
		"buy.",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"",
		/* [81] */
		"",
		/* [82] */
		"",
		/* [83] */
		"",
		/* [84] */
		"",
		/* [85] */
		"",
		/* [86] */
		"",
		/* [87] */
		"",
		/* [88] */
		"",
		/* [89] */
		"",
		/* [90] */
		"",
		/* [91] */
		"",
		/* [92] */
		"",
		/* [93] */
		"",
		/* [94] */
		"",
		/* [95] */
		"",
		/* [96] */
		"",
		/* [97] */
		"",
		/* [98] */
		"",
		/* [99] */
		"",
		/* [100] */
		"",
		/* [101] */
		"",
		/* [102] */
		"",
		/* [103] */
		"",
		/* [104] */
		"",
		/* [105] */
		"",
		/* [106] */
		"",
		/* [107] */
		"",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"",
		/* [132] */
		"",
		/* [133] */
		"",
		/* [134] */
		"",
		/* [135] */
		"",
		/* [136] */
		"",
		/* [137] */
		"",
		/* [138] */
		"",
		/* [139] */
		"",
		/* [140] */
		"",
		/* [141] */
		"",
		/* [142] */
		"",
		/* [143] */
		"",
		/* [144] */
		"",
		/* [145] */
		"",
		/* [146] */
		"",
		/* [147] */
		"",
		/* [148] */
		"",
		/* [149] */
		"",
		/* [150] */
		"",
		/* [151] */
		"",
		/* [152] */
		"",
		/* [153] */
		"",
		/* [154] */
		"",
		/* [155] */
		"",
		/* [156] */
		"",
		/* [157] */
		"",
		/* [158] */
		"",
		/* [159] */
		"",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"",
		/* [172] */
		"",
		/* [173] */
		"",
		/* [174] */
		"",
		/* [175] */
		"",
		/* [176] */
		"",
		/* [177] */
		"",
		/* [178] */
		"",
		/* [179] */
		"",
		/* [180] */
		"",
		/* [181] */
		"",
		/* [182] */
		"",
		/* [183] */
		"",
		/* [184] */
		"",
		/* [185] */
		"",
		/* [186] */
		"",
		/* [187] */
		"",
		/* [188] */
		"",
		/* [189] */
		"",
		/* [190] */
		"",
		/* [191] */
		"",
		/* [192] */
		"",
		/* [193] */
		"",
		/* [194] */
		"",
		/* [195] */
		"",
		/* [196] */
		"",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"",
		/* [202] */
		"",
		/* [203] */
		"",
		/* [204] */
		"",
		/* [205] */
		"",
		/* [206] */
		"",
		/* [207] */
		"",
		/* [208] */
		"",
		/* [209] */
		"",
		/* [210] */
		"",
		/* [211] */
		"",
		/* [212] */
		"",
		/* [213] */
		"",
		/* [214] */
		"",
		/* [215] */
		"",
		/* [216] */
		"",
		/* [217] */
		"",
		/* [218] */
		"",
		/* [219] */
		"",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"",
		/* [227] */
		"",
		/* [228] */
		"",
		/* [229] */
		"",
		/* [230] */
		"",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (11, "Spell cast strs") {
	{	/* array StringArray: 38 elements */
		/* [1] */
		"Can cast everywhere.",
		/* [2] */
		"Combat only.",
		/* [3] */
		"Town only.",
		/* [4] */
		"Town and outdoor only.",
		/* [5] */
		"Town & combat only.",
		/* [6] */
		"Outdoor only.",
		/* [7] */
		"                                        "
		"                                        "
		"                                        "
		"                              ",
		/* [8] */
		"Mage Spells",
		/* [9] */
		"Priest Spells",
		/* [10] */
		"Exile III was created on a PowerMac 6100"
		" using CodeWarrior, development system o"
		"f the Gods. It is written in C. Plain, o"
		"rdinary C.",
		/* [11] */
		"Many thanks to Comedy Central, for provi"
		"ding many hours of bliss during those la"
		"te night programming binges. The Daily S"
		"how added meaning to my lame life.",
		/* [12] */
		"This fine program was brought to you by "
		"coffee. \"Coffee - it's what's for dinner"
		".\"",
		/* [13] */
		"No Vahnatai were harmed during the makin"
		"g of Exile III: Ruined World.",
		/* [14] */
		"Exile III: Ruined World is a work of fic"
		"tion. Any similarity between its charact"
		"ers and persons living or dead is coinci"
		"dental. Unless, of course, it isn't.",
		/* [15] */
		"Thirty Helens Agree: Honesty is the best"
		" policy.",
		/* [16] */
		"This will be the last Exile game for a l"
		"ong, long time. Please don't be mad.",
		/* [17] */
		"Over 200 double tall iced lattes were co"
		"nsumed during the making of Exile III: R"
		"uined World. Chemical dependence can be "
		"your friend too!",
		/* [18] */
		"Many thanks to all the fine role-playing"
		" games that preceded the Exile series, f"
		"or providing many wonderful ideas to ste"
		"al.",
		/* [19] */
		"Some groups listened to while coding Exi"
		"le III: Silly Wizard, Patti Rothberg, Th"
		"e Chieftains, Pearl Jam, Nirvana, Indigo"
		" Girls, Nine Inch Nails, Tori Amos, Ever"
		"clear, REM, Smashing Pumpkins, Enya, Gre"
		"en Day, Sheryl Crow, Jethro Tull, and Ja"
		"nis.",
		/* [20] */
		"Some other things listened to while codi"
		"ng Exile III: Lots of They Might Be Gian"
		"ts, the Rent Cast Album, Oasis, Uncle Bo"
		"nsai and the Electric Bonsai Band, Joan "
		"Osborne, more Joan Osborne, and even mor"
		"e Joan Osborne.",
		/* [21] */
		"A friendly warning. If you leave a messa"
		"ge on Spiderweb Software, Inc's answerin"
		"g machine, don't leave a phone number or"
		" E-mail address, and mumble your name, p"
		"lease don't be surprised if I don't get "
		"back to you.",
		/* [22] */
		"Tips for aspiring programmers: Buy Macin"
		"tosh Programming Techniques, by Dan Park"
		"s Sydow, and Tricks of the Mac Game Prog"
		"ramming Gurus, by several people. You ca"
		"n't go wrong.",
		/* [23] */
		"",
		/* [24] */
		"",
		/* [25] */
		"",
		/* [26] */
		"",
		/* [27] */
		"",
		/* [28] */
		"",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		""
	}
};

resource 'STR#' (12, "Skills tips") {
	{	/* array StringArray: 86 elements */
		/* [1] */
		"When below 4, the health the character g"
		"ains at each level will be sharply reduc"
		"ed. Also, more strength enables you to c"
		"arry more stuff.",
		/* [2] */
		"Before a character does ANY fighting or "
		"fires any missiles, this skill should be"
		" at least 3.",
		/* [3] */
		"If the character is going to cast spells"
		", make this skill at least 4. If not, ig"
		"nore it.",
		/* [4] */
		"Edged weapons are the most common.",
		/* [5] */
		"Bashing weapons are common and cheap.",
		/* [6] */
		"Pole weapons are, in general, the most e"
		"xpensive, the most rare, and the most po"
		"werful.",
		/* [7] */
		"Thrown missiles are common and many are "
		"magical. Also, this skill is cheap. Howe"
		"ver, thrown weapons cannot be poisoned.",
		/* [8] */
		"Bows are expensive, and so is this skill"
		". However, poisoned arrows are extremely"
		" powerful.",
		/* [9] */
		"Buy a few levels for anyone in heavy arm"
		"or.",
		/* [10] */
		"Try to start with at least one character"
		" with level three in this.",
		/* [11] */
		"Try to start with at least one character"
		" with level three in this.",
		/* [12] */
		"Spread this around the party. Don't buy "
		"more than 25 points total (over the whol"
		"e game).",
		/* [13] */
		"Have only one character buy this, but ge"
		"t a lot. Alchemy is very useful.",
		/* [14] */
		"Expensive, but very useful. Knowing what"
		" items are when trapped deep in a dungeo"
		"n can save your life.",
		/* [15] */
		"Traps are deadly in Exile. Have only one"
		" character buy this, but get a lot.",
		/* [16] */
		"Not necessary, but very useful. Unlock D"
		"oor spells are expensive, and bashing is"
		" slow, damaging, and very unreliable.",
		/* [17] */
		"Wait on this. It's very effective when y"
		"our level is high.",
		/* [18] */
		"You really only need 3-4 levels of this."
		" More helps, but not too much.",
		/* [19] */
		"Although it costs no gold, hold off on b"
		"uying this until your level is high. Luc"
		"k can help A LOT, but at low levels othe"
		"r things help more.",
		/* [20] */
		"",
		/* [21] */
		"",
		/* [22] */
		"",
		/* [23] */
		"",
		/* [24] */
		"",
		/* [25] */
		"",
		/* [26] */
		"",
		/* [27] */
		"",
		/* [28] */
		"",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"Drinking many, many cups of espresso  of"
		"ten greatly heightens one's Exile III: R"
		"uined World experience.",
		/* [51] */
		"Be sure to look for Exile: Escape From t"
		"he Pit and Exile II: Crystal Souls, the "
		"hot predecessors to Exile III: Ruined Wo"
		"rld.",
		/* [52] */
		"Low on gold? Go to Krizsan, Shayder, or "
		"any other large surface city, and look f"
		"or the jobs dispatcher. It's a great way"
		" to earn extra money!",
		/* [53] */
		"Low on gold? Read the Exile III document"
		"ation. The Hints on Getting Started sect"
		"ion has a plethora of hints for finding "
		"loot.",
		/* [54] */
		"Having trouble reaching somewhere? Walk "
		"into the walls/barriers/trees/whatever i"
		"s in your way. Some things have secret d"
		"oors or entrances.",
		/* [55] */
		"Casting repeated blesses multiplies the "
		"effect. Two bless spells on somebody are"
		" more than twice as powerful as one.",
		/* [56] */
		"In small towns, most people have nothing"
		" to say. However, the innkeepers, anyone"
		" in shops, and anyone not a guard or a t"
		"ownsperson will generally have something"
		" useful to tell you.",
		/* [57] */
		"It's all fun and games until someone los"
		"es an eye.",
		/* [58] */
		"Moving too slowly never makes it impossi"
		"ble to finish the game. The things you n"
		"eed will always be there. However, movin"
		"g too slow can make finishing the game h"
		"arder. Take time to look around, but not"
		" too much.",
		/* [59] */
		"Get some horses as soon as possible. Tra"
		"veling outdoors is slow and you'll use u"
		"p a lot of food without them.",
		/* [60] */
		"Items need to be identified before you c"
		"an sell them. Fellows, in the city of Kr"
		"izsan, will identify items cheaply. Also"
		", there are people in plenty of other to"
		"wns who will perform this service.",
		/* [61] */
		"Move Mountains and Dispel Barrier are ve"
		"ry useful spells. Haste will save your p"
		"arty from many a nasty fight.",
		/* [62] */
		"Can't cast a mage spell you've learned? "
		"Make sure your Mage Spells skill is up t"
		"o at least the level of the spell. Then "
		"make sure you're not dumbfounded (Restor"
		"e Mind cures this). Then make sure you h"
		"ave enough spell points.",
		/* [63] */
		"The Exile III Editor can help you out in"
		" a lot of nasty situations, even when it"
		"'s unregistered. Take a look!",
		/* [64] */
		"Someone important not there? The friendl"
		"y people in the town suddenly mad at you"
		" and you're not sure why? You may have c"
		"lipped them with Mass Charm or Shockwave"
		". Visit a few other towns and return, an"
		"d you'll have been forgiven.",
		/* [65] */
		"Low on gold? Many towns have odd jobs av"
		"ailable. For example, someone in Krizsan"
		" has a certain interest in unicorns.",
		/* [66] */
		"Visit Anaximander, in Fort Emergence, wh"
		"enever you think you've done something i"
		"nteresting. He has much useful informati"
		"on.",
		/* [67] */
		"Visit the Tower of Magi whenever you com"
		"plete a major quest. Anaximander will te"
		"ll you where to go. You can get lovely r"
		"ewards!",
		/* [68] */
		"Have a tip, bug report, question, or com"
		"ment? Send it to SpidWeb@aol.com.",
		/* [69] */
		"Make sure everyone has a strength of at "
		"least 3. Make sure mages have plenty of "
		"intelligence. Make sure everyone who doe"
		"s a lot of melee combat has a high dexte"
		"rity.",
		/* [70] */
		"Some dungeon trips are long, and require"
		" lots of healing and endurance. It is at"
		" these times that Alchemy can be very us"
		"eful.",
		/* [71] */
		"Met the Anama? You can win the game whet"
		"her or not you join them. Joining them m"
		"akes it a bit harder, though.",
		/* [72] */
		"Do not taunt Happy Fun Ball.",
		/* [73] */
		"To cast spells quickly, click on his/her"
		" name on the upper right, and select the"
		" spell from the Mage Spells or Priest Sp"
		"ells menu.",
		/* [74] */
		"To make a character active (and see its "
		"inventory) quickly, type '1'-'6'.",
		/* [75] */
		"Sometimes you'll find a place where you "
		"know there's a dungeon, but you can't se"
		"e or enter it. That's because someone so"
		"mewhere else needs to tell you where it "
		"is. Go talk to people in towns.",
		/* [76] */
		"You don't need to destroy all the plague"
		"s of monsters on the surface to win the "
		"game. If you get totally stuck, move on.",
		/* [77] */
		"In each of the five major cities on the "
		"surface, there's someone who can tell yo"
		"u about a major artifact you can find. I"
		"f you want to find it, be thorough in yo"
		"ur questioning.",
		/* [78] */
		"Game too slow? Look in the Preferences m"
		"enu. There are several options to speed "
		"things up.",
		/* [79] */
		"Have to go through a dungeon, but you ke"
		"ep getting killed? Stock up on potions. "
		"Buy scrolls. Learn alchemy. Go in, kill "
		"a bunch of monsters, and leave to rest ("
		"if you can).",
		/* [80] */
		"One nice shortcut: typing capital 'M' ha"
		"s whoever cast your last mage spell cast"
		" it again. 'P' works the same way for pr"
		"iest spells.",
		/* [81] */
		"Beware when using the Long Rest feature "
		"in dungeons. Monsters are taking advanta"
		"ge of those pauses to get reinforcements"
		".",
		/* [82] */
		"When launching Exile III, you can hold t"
		"he space bar down to do a limited launch"
		". This eliminates the opening fades and "
		"music, and sometimes makes the game go f"
		"aster. ",
		/* [83] */
		"",
		/* [84] */
		"",
		/* [85] */
		"",
		/* [86] */
		""
	}
};

resource 'STR#' (13, "Alch and poison info") {
	{	/* array StringArray: 24 elements */
		/* [1] */
		"Alchemy and Poison",
		/* [2] */
		"22",
		/* [3] */
		"Alchemy can be incredibly useful. Potion"
		"s can give you the added boost you may n"
		"eed to get through a long grueling dunge"
		"on, and you cannot raise the dead withou"
		"t the right concoction.",
		/* [4] */
		"You need three things to make a potion:\n"
		"1. High alchemy skill. When a character "
		"tries to make a potion, his/her alchemy "
		"skill must be above a certain level. The"
		" higher above that level, the better the"
		" chance for success.",
		/* [5] */
		"2. The right ingredient. Ingredients are"
		" usually found at special encounters out"
		"doors, and regenerate themselves after a"
		" time. Generally, the person who teaches"
		" a recipe tells you what plant it needs.",
		/* [6] */
		"3. The recipe. These are usually bought "
		"in towns. You only need to buy each reci"
		"pe once for the entire party.",
		/* [7] */
		"When you have all these things, go into "
		"a town and click on the blue bottle butt"
		"on. Pick the PC with the highest alchemy"
		" skill to make the potion. Hope.",
		/* [8] */
		"Here is a list of the alchemical concoct"
		"ions, with min. skill to make:\nWeak Pois"
		"on\n  Min. Skill - 1\nNeed toadstools or s"
		"pider glands. The lowest level poison.",
		/* [9] */
		"Weak Curing\n  Min. Skill - 1\nNeed comfre"
		"y root. Cures poison somewhat.",
		/* [10] */
		"Weak Healing\n  Min. Skill - 2\nNeed comfr"
		"ey root. Provides mild healing.",
		/* [11] */
		"Medium Poison\n  Min. Skill - 4\nNeed toad"
		"stools or spider glands. A stronger pois"
		"on.",
		/* [12] */
		"Medium Curing Potion\n  Min. Skill - 5\nNe"
		"ed glowing nettle. A decent antidote for"
		" poison.",
		/* [13] */
		"Medium Healing Potion\n  Min. Skill - 5\nN"
		"eed glowing nettle. Quality healing.",
		/* [14] */
		"Strong Poison\n  Min. Skill - 5\nNeed cryp"
		"t shrooms or asp fangs. Powerful stuff.",
		/* [15] */
		"Graymold Salve\n  Min. Skill - ???\n???",
		/* [16] */
		"Resurrection Balm\n  Min. Skill - 8\nNeed "
		"ember flowers. Necessary to cast Raise D"
		"ead or Resurrection.",
		/* [17] */
		"Weak Energy Potion\n  Min. Skill - 10\nNee"
		"d crypt shrooms. Restores some of your s"
		"pell points.",
		/* [18] */
		"Strong Healing Potion\n  Min. Skill - 10\n"
		"Need ember flowers. Provides excellent h"
		"ealing.",
		/* [19] */
		"Killer Poison\n  Min. Skill - 12\nNeed asp"
		"tongue mold. The strongest poison.",
		/* [20] */
		"One of the most useful things you can ma"
		"ke with alchemy is poison, a powerful we"
		"apon in the magic-poor world of Exile.",
		/* [21] */
		"Many monsters are immune to magic and fi"
		"re. However, not many are poison-resista"
		"nt. This makes poison an excellent mage-"
		"killer.",
		/* [22] */
		"To poison a weapon, use it during combat"
		". Your hand-to-hand weapon (the first on"
		"e, if two are equipped) or arrows will b"
		"ecome poisoned. Each time you attack, th"
		"e level of poison decreases.",
		/* [23] */
		"Don't poison a weapon too long before co"
		"mbat. Its effectiveness decreases with t"
		"ime. Also, switching weapons makes the p"
		"oison disappear.",
		/* [24] */
		"Poisoning an already poisoned weapon doe"
		"sn't do much good. The weapon gets the m"
		"aximum poison level of the poison being "
		"added or the poison already there, no mo"
		"re."
	}
};

resource 'STR#' (20, "monster abil strs") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"No special ability",
		/* [2] */
		"Poison",
		/* [3] */
		"Curse/Weaken Ray",
		/* [4] */
		"Stoning Ray",
		/* [5] */
		"Slow Hit",
		/* [6] */
		"Throw Web",
		/* [7] */
		"Disease Hit",
		/* [8] */
		"Charm Ray",
		/* [9] */
		"Sleep Hit",
		/* [10] */
		"Sleep Ray",
		/* [11] */
		"Paral Hit",
		/* [12] */
		"Paral Ray",
		/* [13] */
		"Acid Hit",
		/* [14] */
		"Anti-Spell Ray",
		/* [15] */
		"Confuse Ray",
		/* [16] */
		"Terrify Ray",
		/* [17] */
		"Throw Rock",
		/* [18] */
		"Breathe Fire",
		/* [19] */
		"Breathe Cold",
		/* [20] */
		"Breathe Acid",
		/* [21] */
		"Fire Touch",
		/* [22] */
		"Cold Touch",
		/* [23] */
		"Drain Touch",
		/* [24] */
		"Cold, Drain Touch",
		/* [25] */
		"Invisible",
		/* [26] */
		"Guard",
		/* [27] */
		"Radiate Fire",
		/* [28] */
		"Radiate Cold",
		/* [29] */
		"Radiate Null Fields",
		/* [30] */
		"Divide",
		/* [31] */
		"Fire Ray",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"No ability",
		/* [51] */
		"Radiate fire fields",
		/* [52] */
		"Radiate ice fields",
		/* [53] */
		"Radiate shock fields",
		/* [54] */
		"Radiate antimagic fields",
		/* [55] */
		"Radiate sleep fields",
		/* [56] */
		"Radiate stink clouds",
		/* [57] */
		"Unused",
		/* [58] */
		"Unused",
		/* [59] */
		"Unused",
		/* [60] */
		"Summon (%5 chance)",
		/* [61] */
		"Summon (%20 chance)",
		/* [62] */
		"Summon (%50 chance)",
		/* [63] */
		"Unused",
		/* [64] */
		"Unused",
		/* [65] */
		"Death triggers scen. special",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"Unused",
		/* [81] */
		"Percentage chance (1-100%)",
		/* [82] */
		"Percentage chance (1-100%)",
		/* [83] */
		"Percentage chance (1-100%)",
		/* [84] */
		"Percentage chance (1-100%)",
		/* [85] */
		"Percentage chance (1-100%)",
		/* [86] */
		"Percentage chance (1-100%)",
		/* [87] */
		"Unused",
		/* [88] */
		"Unused",
		/* [89] */
		"Unused",
		/* [90] */
		"Number of creature to summon",
		/* [91] */
		"Number of creature to summon",
		/* [92] */
		"Number of creature to summon",
		/* [93] */
		"Unused",
		/* [94] */
		"Unused",
		/* [95] */
		"Number of special to call",
		/* [96] */
		"",
		/* [97] */
		"",
		/* [98] */
		"",
		/* [99] */
		"",
		/* [100] */
		"",
		/* [101] */
		"",
		/* [102] */
		"",
		/* [103] */
		"",
		/* [104] */
		"",
		/* [105] */
		"",
		/* [106] */
		"",
		/* [107] */
		"",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"Hits/Swings",
		/* [131] */
		"Claws",
		/* [132] */
		"Bites",
		/* [133] */
		"Slimes",
		/* [134] */
		"Hits/Punches",
		/* [135] */
		"Stings",
		/* [136] */
		"Clubs",
		/* [137] */
		"Burns",
		/* [138] */
		"Harms",
		/* [139] */
		"Stabs",
		/* [140] */
		"",
		/* [141] */
		"",
		/* [142] */
		"",
		/* [143] */
		"",
		/* [144] */
		"",
		/* [145] */
		"",
		/* [146] */
		"",
		/* [147] */
		"",
		/* [148] */
		"",
		/* [149] */
		"",
		/* [150] */
		"Human",
		/* [151] */
		"Humanoid",
		/* [152] */
		"Nephil",
		/* [153] */
		"Slith",
		/* [154] */
		"Giant",
		/* [155] */
		"Reptile",
		/* [156] */
		"Beast",
		/* [157] */
		"Demon",
		/* [158] */
		"Undead",
		/* [159] */
		"Bug",
		/* [160] */
		"Slime",
		/* [161] */
		"Stone",
		/* [162] */
		"Special",
		/* [163] */
		"Vahnatai",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"",
		/* [172] */
		"",
		/* [173] */
		"",
		/* [174] */
		"",
		/* [175] */
		"",
		/* [176] */
		"",
		/* [177] */
		"",
		/* [178] */
		"",
		/* [179] */
		"",
		/* [180] */
		"",
		/* [181] */
		"",
		/* [182] */
		"",
		/* [183] */
		"",
		/* [184] */
		"",
		/* [185] */
		"",
		/* [186] */
		"",
		/* [187] */
		"",
		/* [188] */
		"",
		/* [189] */
		"",
		/* [190] */
		"",
		/* [191] */
		"",
		/* [192] */
		"",
		/* [193] */
		"",
		/* [194] */
		"",
		/* [195] */
		"",
		/* [196] */
		"",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"",
		/* [202] */
		"",
		/* [203] */
		"",
		/* [204] */
		"",
		/* [205] */
		"",
		/* [206] */
		"",
		/* [207] */
		"",
		/* [208] */
		"",
		/* [209] */
		"",
		/* [210] */
		"",
		/* [211] */
		"",
		/* [212] */
		"",
		/* [213] */
		"",
		/* [214] */
		"",
		/* [215] */
		"",
		/* [216] */
		"",
		/* [217] */
		"",
		/* [218] */
		"",
		/* [219] */
		"",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"",
		/* [227] */
		"",
		/* [228] */
		"",
		/* [229] */
		"",
		/* [230] */
		"",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (21, "terrain spec strs") {
	{	/* array StringArray: 301 elements */
		/* [1] */
		"None",
		/* [2] */
		"Change when step on",
		/* [3] */
		"Does fire damage",
		/* [4] */
		"Does cold damage",
		/* [5] */
		"Does magical damage",
		/* [6] */
		"Poison land",
		/* [7] */
		"Diseased land",
		/* [8] */
		"Crumbling terrain",
		/* [9] */
		"Lockable terrain",
		/* [10] */
		"Unlockable terrain",
		/* [11] */
		"Unlockable/bashable",
		/* [12] */
		"Is a sign",
		/* [13] */
		"Call local special",
		/* [14] */
		"Call scenario special",
		/* [15] */
		"Is a container",
		/* [16] */
		"Waterfall",
		/* [17] */
		"Conveyor (north)",
		/* [18] */
		"Conveyor (east)",
		/* [19] */
		"Conveyor (south)",
		/* [20] */
		"Conveyor (west)",
		/* [21] */
		"Blocked to monsters",
		/* [22] */
		"Town entrance",
		/* [23] */
		"Can be used",
		/* [24] */
		"Call special when used",
		/* [25] */
		"",
		/* [26] */
		"",
		/* [27] */
		"",
		/* [28] */
		"",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"Unused",
		/* [41] */
		"What to change to?",
		/* [42] */
		"Amount of damage done",
		/* [43] */
		"Amount of damage done",
		/* [44] */
		"Amount of damage done",
		/* [45] */
		"Strength (1-8)",
		/* [46] */
		"Strength (1-8)",
		/* [47] */
		"Terrain to change to",
		/* [48] */
		"Terrain to change to when locked",
		/* [49] */
		"Terrain to change to when unlocked",
		/* [50] */
		"Terrain to change to when unlocked",
		/* [51] */
		"Unused",
		/* [52] */
		"Number of special to call",
		/* [53] */
		"Number of special to call",
		/* [54] */
		"Unused",
		/* [55] */
		"Unused",
		/* [56] */
		"Unused",
		/* [57] */
		"Unused",
		/* [58] */
		"Unused",
		/* [59] */
		"Unused",
		/* [60] */
		"Unused",
		/* [61] */
		"Terrain type if hidden",
		/* [62] */
		"Terrain to change to when used",
		/* [63] */
		"Number of scenario spec. to call",
		/* [64] */
		"",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"Unused",
		/* [81] */
		"Number of sound (200 - no sound)",
		/* [82] */
		"Damage multiplier",
		/* [83] */
		"Damage multiplier",
		/* [84] */
		"Damage multiplier",
		/* [85] */
		"Percentage chance (1-100)",
		/* [86] */
		"Percentage chance (1-100)",
		/* [87] */
		"Unused",
		/* [88] */
		"Unused",
		/* [89] */
		"Difficulty (0-10)",
		/* [90] */
		"Difficulty (0-10)",
		/* [91] */
		"Unused",
		/* [92] */
		"Unused",
		/* [93] */
		"Unused",
		/* [94] */
		"Unused",
		/* [95] */
		"Unused",
		/* [96] */
		"Unused",
		/* [97] */
		"Unused",
		/* [98] */
		"Unused",
		/* [99] */
		"Unused",
		/* [100] */
		"Unused",
		/* [101] */
		"Unused",
		/* [102] */
		"Number of sound (200 - no sound)",
		/* [103] */
		"Unused",
		/* [104] */
		"",
		/* [105] */
		"",
		/* [106] */
		"",
		/* [107] */
		"",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"",
		/* [132] */
		"",
		/* [133] */
		"",
		/* [134] */
		"",
		/* [135] */
		"",
		/* [136] */
		"",
		/* [137] */
		"",
		/* [138] */
		"",
		/* [139] */
		"",
		/* [140] */
		"",
		/* [141] */
		"",
		/* [142] */
		"",
		/* [143] */
		"",
		/* [144] */
		"",
		/* [145] */
		"",
		/* [146] */
		"",
		/* [147] */
		"",
		/* [148] */
		"",
		/* [149] */
		"",
		/* [150] */
		"",
		/* [151] */
		"",
		/* [152] */
		"",
		/* [153] */
		"",
		/* [154] */
		"",
		/* [155] */
		"",
		/* [156] */
		"",
		/* [157] */
		"",
		/* [158] */
		"",
		/* [159] */
		"",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"",
		/* [172] */
		"",
		/* [173] */
		"",
		/* [174] */
		"",
		/* [175] */
		"",
		/* [176] */
		"",
		/* [177] */
		"",
		/* [178] */
		"",
		/* [179] */
		"",
		/* [180] */
		"",
		/* [181] */
		"",
		/* [182] */
		"",
		/* [183] */
		"",
		/* [184] */
		"",
		/* [185] */
		"",
		/* [186] */
		"",
		/* [187] */
		"",
		/* [188] */
		"",
		/* [189] */
		"",
		/* [190] */
		"",
		/* [191] */
		"",
		/* [192] */
		"",
		/* [193] */
		"",
		/* [194] */
		"",
		/* [195] */
		"",
		/* [196] */
		"",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"",
		/* [202] */
		"",
		/* [203] */
		"",
		/* [204] */
		"",
		/* [205] */
		"",
		/* [206] */
		"",
		/* [207] */
		"",
		/* [208] */
		"",
		/* [209] */
		"",
		/* [210] */
		"",
		/* [211] */
		"",
		/* [212] */
		"",
		/* [213] */
		"",
		/* [214] */
		"",
		/* [215] */
		"",
		/* [216] */
		"",
		/* [217] */
		"",
		/* [218] */
		"",
		/* [219] */
		"",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"",
		/* [227] */
		"",
		/* [228] */
		"",
		/* [229] */
		"",
		/* [230] */
		"",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		"",
		/* [301] */
		""
	}
};

resource 'STR#' (22, "Names of special node types") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"No Special",
		/* [2] */
		"Set Flag",
		/* [3] */
		"Increment Flag",
		/* [4] */
		"Display Message",
		/* [5] */
		"Secret Passage",
		/* [6] */
		"Display Small Message",
		/* [7] */
		"Flip Flag",
		/* [8] */
		"Out Block",
		/* [9] */
		"Town Block",
		/* [10] */
		"Combat Block",
		/* [11] */
		"Looking Block",
		/* [12] */
		"Can't Enter",
		/* [13] */
		"",
		/* [14] */
		"Start General Timer",
		/* [15] */
		"Play a Sound",
		/* [16] */
		"",
		/* [17] */
		"",
		/* [18] */
		"",
		/* [19] */
		"Major Event Has Occured",
		/* [20] */
		"Forced Give",
		/* [21] */
		"Buy Items of Type",
		/* [22] */
		"Call Global Special",
		/* [23] */
		"",
		/* [24] */
		"Copy Flag",
		/* [25] */
		"Sever Seal Block",
		/* [26] */
		"Have a Rest",
		/* [27] */
		"Wandering will fight",
		/* [28] */
		"Call Hardcode",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"",
		/* [51] */
		"Give Item",
		/* [52] */
		"Give Special Item",
		/* [53] */
		"One-Time Do Nothing",
		/* [54] */
		"One-Time and Set",
		/* [55] */
		"One-Time Text Message",
		/* [56] */
		"Display Dialog (Dialog pic)",
		/* [57] */
		"Display Dialog (Terrain pic)",
		/* [58] */
		"Display Dialog (Monster pic)",
		/* [59] */
		"Give Item (Dialog pic)",
		/* [60] */
		"Give Item (Terrain pic)",
		/* [61] */
		"Give Item (Monster pic)",
		/* [62] */
		"One-Time Place Outdoor Enc.",
		/* [63] */
		"One-Time Place Town Enc.",
		/* [64] */
		"Trap",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"",
		/* [81] */
		"Select a PC",
		/* [82] */
		"Do Damage",
		/* [83] */
		"Affect Health",
		/* [84] */
		"Affect Spell Points",
		/* [85] */
		"Affect Experience",
		/* [86] */
		"Affect Skill Points",
		/* [87] */
		"Kill/Raise Dead",
		/* [88] */
		"Affect Poison",
		/* [89] */
		"Affect Slow/Haste",
		/* [90] */
		"Affect Invulnerability",
		/* [91] */
		"Affect Magic Resistance",
		/* [92] */
		"Affect Webs",
		/* [93] */
		"Affect Disease",
		/* [94] */
		"Affect Sanctuary",
		/* [95] */
		"",
		/* [96] */
		"Affect Dumbfounding",
		/* [97] */
		"Affect Sleep",
		/* [98] */
		"Affect Paralysis",
		/* [99] */
		"Affect Statistic",
		/* [100] */
		"Give Spell",
		/* [101] */
		"",
		/* [102] */
		"Affect Gold",
		/* [103] */
		"Affect Food",
		/* [104] */
		"Affect Alchemy",
		/* [105] */
		"",
		/* [106] */
		"",
		/* [107] */
		"Affect Featherfall",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"Stuff Done Flag?",
		/* [132] */
		"Town Number?",
		/* [133] */
		"Random Number?",
		/* [134] */
		"Have Special Item?",
		/* [135] */
		"Stuff Done Compare?",
		/* [136] */
		"Terrain this type? (town)",
		/* [137] */
		"Terrain this type? (out)",
		/* [138] */
		"Has gold?",
		/* [139] */
		"Has food?",
		/* [140] */
		"Item Class on Space?",
		/* [141] */
		"Have Item With Class?",
		/* [142] */
		"Equipped Item With Class?",
		/* [143] */
		"Has Gold? (+ take)",
		/* [144] */
		"Has Food? (+ take)",
		/* [145] */
		"Item Class on Space? (+ take)",
		/* [146] */
		"Have Item W. Class? (+ take)",
		/* [147] */
		"Equip Item W. Class? (+ take)",
		/* [148] */
		"Pers. Here? (can be dead)",
		/* [149] */
		"Any Barrels?",
		/* [150] */
		"Any Crates?",
		/* [151] */
		"Phase Reached?",
		/* [152] */
		"Has Advantage?",
		/* [153] */
		"Roman?",
		/* [154] */
		"Has Enough of Stat?",
		/* [155] */
		"Text Response?",
		/* [156] */
		"Stuff Done Equal?",
		/* [157] */
		"Floor This Type (town)",
		/* [158] */
		"Floor This Type (out)",
		/* [159] */
		"Personality in Pty, alive?",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"Town Hostile",
		/* [172] */
		"Change Terrain",
		/* [173] */
		"Swap Terrain",
		/* [174] */
		"Transform Terrain",
		/* [175] */
		"Move Party",
		/* [176] */
		"Hit Space",
		/* [177] */
		"Explosion on Space",
		/* [178] */
		"Lock Space",
		/* [179] */
		"Unlock Space",
		/* [180] */
		"Do sfx Burst",
		/* [181] */
		"Make Wandering Monster",
		/* [182] */
		"Place a Monster",
		/* [183] */
		"Destroy Monster",
		/* [184] */
		"Destroy All Monsters",
		/* [185] */
		"Generic Lever",
		/* [186] */
		"Generic Portal",
		/* [187] */
		"Generic Button",
		/* [188] */
		"Generic Stairway",
		/* [189] */
		"Lever",
		/* [190] */
		"Portal",
		/* [191] */
		"Stairway",
		/* [192] */
		"Relocate Outdoors",
		/* [193] */
		"Place Item",
		/* [194] */
		"Split Party",
		/* [195] */
		"Reunite Party",
		/* [196] */
		"Start General Timer",
		/* [197] */
		"Start Town Dialogue",
		/* [198] */
		"Change Floor",
		/* [199] */
		"Swap Floor",
		/* [200] */
		"Set Height",
		/* [201] */
		"Change Rectangle Floor",
		/* [202] */
		"Swap Rectangle Floor",
		/* [203] */
		"Change Rectangle Height",
		/* [204] */
		"",
		/* [205] */
		"",
		/* [206] */
		"",
		/* [207] */
		"",
		/* [208] */
		"Place Fire Barrier",
		/* [209] */
		"Place Force Barrier",
		/* [210] */
		"Cleanse Rectangle",
		/* [211] */
		"Place SFX",
		/* [212] */
		"Place Barrels, Etc.",
		/* [213] */
		"Move Items",
		/* [214] */
		"Destroy Items",
		/* [215] */
		"Change Rectange Terrain",
		/* [216] */
		"Swap Rectangle Terrain",
		/* [217] */
		"Transform Rectangle Terrain",
		/* [218] */
		"Lock Rectangle",
		/* [219] */
		"Unlock Rectangle",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"Make Outdoor Wandering",
		/* [227] */
		"Change Out Terrain",
		/* [228] */
		"Place Outdoor Encounter",
		/* [229] */
		"Outdoor Move Party",
		/* [230] */
		"Outdoor Store",
		/* [231] */
		"Place Outdoor Encounter",
		/* [232] */
		"Outdoor Dialogue",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (23, "Item ability names") {
	{	/* array StringArray: 179 elements */
		/* [1] */
		"",
		/* [2] */
		"Flaming Weapon",
		/* [3] */
		"Ice Weapon",
		/* [4] */
		"Undead Slayer",
		/* [5] */
		"Human Slayer",
		/* [6] */
		"Slith Slayer",
		/* [7] */
		"Acidic Weapon",
		/* [8] */
		"Giant Slayer",
		/* [9] */
		"Poisoned Weapon",
		/* [10] */
		"Demon Slayer",
		/* [11] */
		"Slow Target",
		/* [12] */
		"",
		/* [13] */
		"",
		/* [14] */
		"",
		/* [15] */
		"",
		/* [16] */
		"",
		/* [17] */
		"",
		/* [18] */
		"",
		/* [19] */
		"",
		/* [20] */
		"",
		/* [21] */
		"",
		/* [22] */
		"",
		/* [23] */
		"",
		/* [24] */
		"",
		/* [25] */
		"",
		/* [26] */
		"",
		/* [27] */
		"",
		/* [28] */
		"",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"Protection",
		/* [32] */
		"Full Protection",
		/* [33] */
		"Fire Protection",
		/* [34] */
		"Cold Protection",
		/* [35] */
		"Poison Protection",
		/* [36] */
		"Magic Protection",
		/* [37] */
		"Acid Protection",
		/* [38] */
		"Skill",
		/* [39] */
		"Strength",
		/* [40] */
		"Dexterity",
		/* [41] */
		"Intelligence",
		/* [42] */
		"Endurance",
		/* [43] */
		"Luck",
		/* [44] */
		"Spell Points",
		/* [45] */
		"Accuracy",
		/* [46] */
		"Thieving",
		/* [47] */
		"Giant Strength",
		/* [48] */
		"Better mage",
		/* [49] */
		"Better priest",
		/* [50] */
		"Prot. From Petrify",
		/* [51] */
		"Regenerate",
		/* [52] */
		"Free Action",
		/* [53] */
		"Speed",
		/* [54] */
		"Protection from Undead",
		/* [55] */
		"Cause disease",
		/* [56] */
		"",
		/* [57] */
		"",
		/* [58] */
		"Grief",
		/* [59] */
		"Hardcode",
		/* [60] */
		"Bartering",
		/* [61] */
		"Greater Knowledge",
		/* [62] */
		"",
		/* [63] */
		"",
		/* [64] */
		"",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"Cure User",
		/* [72] */
		"Shield User",
		/* [73] */
		"Poison User",
		/* [74] */
		"Speed User",
		/* [75] */
		"Add Invulnerability",
		/* [76] */
		"Add Magic Res.",
		/* [77] */
		"",
		/* [78] */
		"Cure Disease",
		/* [79] */
		"Sanct. & MartyrÕs Shield",
		/* [80] */
		"Cure Mind Stuff For All",
		/* [81] */
		"Cure Acid",
		/* [82] */
		"Bliss",
		/* [83] */
		"Restoring",
		/* [84] */
		"Beast",
		/* [85] */
		"Add Experience",
		/* [86] */
		"Add Skill Pts.",
		/* [87] */
		"Healing",
		/* [88] */
		"Add Spell Points",
		/* [89] */
		"Doom",
		/* [90] */
		"Light",
		/* [91] */
		"Featherfall",
		/* [92] */
		"Add Drunk",
		/* [93] */
		"Hardcode (take charge)",
		/* [94] */
		"Hardcode (no charge)",
		/* [95] */
		"Add Shielding",
		/* [96] */
		"Add Berzerk",
		/* [97] */
		"Divine Touch",
		/* [98] */
		"Resistance",
		/* [99] */
		"Add Flying",
		/* [100] */
		"Add Hovering Feet",
		/* [101] */
		"Acid User",
		/* [102] */
		"",
		/* [103] */
		"",
		/* [104] */
		"",
		/* [105] */
		"",
		/* [106] */
		"",
		/* [107] */
		"",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"Bolt of Fire",
		/* [112] */
		"Call Beast",
		/* [113] */
		"Bind Foe",
		/* [114] */
		"Slow",
		/* [115] */
		"Ice Lances",
		/* [116] */
		"Create Illusions",
		/* [117] */
		"Far Sight",
		/* [118] */
		"Lightning Spray",
		/* [119] */
		"Dispel Barrier",
		/* [120] */
		"Summon Aid",
		/* [121] */
		"Fireblast",
		/* [122] */
		"Repel Spirit",
		/* [123] */
		"Summon Shade",
		/* [124] */
		"Control Foes",
		/* [125] */
		"Spray Acid",
		/* [126] */
		"",
		/* [127] */
		"Paralysis",
		/* [128] */
		"Web Spell",
		/* [129] */
		"Strengthen Target",
		/* [130] */
		"",
		/* [131] */
		"",
		/* [132] */
		"Piercing Sight",
		/* [133] */
		"Bitter Loss",
		/* [134] */
		"Ravage Life",
		/* [135] */
		"",
		/* [136] */
		"Hardcode (charge, combat)",
		/* [137] */
		"",
		/* [138] */
		"",
		/* [139] */
		"Withering",
		/* [140] */
		"",
		/* [141] */
		"",
		/* [142] */
		"",
		/* [143] */
		"",
		/* [144] */
		"",
		/* [145] */
		"",
		/* [146] */
		"",
		/* [147] */
		"",
		/* [148] */
		"",
		/* [149] */
		"",
		/* [150] */
		"",
		/* [151] */
		"Toadstools",
		/* [152] */
		"Healing",
		/* [153] */
		"Spiritual",
		/* [154] */
		"Energetic",
		/* [155] */
		"Balm of Life",
		/* [156] */
		"Lockpicks",
		/* [157] */
		"First Aid",
		/* [158] */
		"Graymold",
		/* [159] */
		"Mandrake",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"Lightning",
		/* [172] */
		"Slay Undead",
		/* [173] */
		"Slay Demon",
		/* [174] */
		"Acid",
		/* [175] */
		"",
		/* [176] */
		"",
		/* [177] */
		"",
		/* [178] */
		"",
		/* [179] */
		""
	}
};

resource 'STR#' (25, "Alch & Poison") {
	{	/* array StringArray: 29 elements */
		/* [1] */
		"Alchemy and Poison",
		/* [2] */
		"27",
		/* [3] */
		"Alchemy can be incredibly useful. Potion"
		"s can give you the added boost you may n"
		"eed to get through a long grueling dunge"
		"on, and you cannot raise the dead withou"
		"t the right concoction.",
		/* [4] */
		"You need three things to make a potion:\n"
		"1. High alchemy skill. When a character "
		"tries to make a potion, his/her alchemy "
		"skill must be above a certain level. The"
		" higher above that level, the better the"
		" chance for success.",
		/* [5] */
		"2. The right ingredient. Ingredients are"
		" usually found at special encounters out"
		"doors, and regenerate themselves after a"
		" time. Generally, the person who teaches"
		" a recipe tells you what plant it needs.",
		/* [6] */
		"3. The recipe. These are usually bought "
		"in towns. You only need to buy each reci"
		"pe once for the entire party.",
		/* [7] */
		"When you have all these things, go into "
		"a town and click on the blue bottle butt"
		"on. Pick the PC with the highest alchemy"
		" skill to make the potion. Hope.",
		/* [8] */
		"Here is a list of the alchemical concoct"
		"ions, with min. skill to make: |Weak Cur"
		"ing |  Min. Skill - 1 |Need holly. Cures"
		" poison somewhat.",
		/* [9] */
		"Weak Healing |  Min. Skill - 1 |Need com"
		"frey root. Provides mild healing.\n",
		/* [10] */
		"Weak Poison |  Min. Skill - 1 |Need holl"
		"y or spider glands. The lowest level poi"
		"son.",
		/* [11] */
		"Weak Speed |  Min. Skill - 3 |Need comfr"
		"ey root and wormgrass. Hastes drinker.",
		/* [12] */
		"Medium Poison |  Min. Skill - 3 |Need wo"
		"rmgrass or spider glands. A stronger poi"
		"son.",
		/* [13] */
		"Medium Healing Potion |  Min. Skill - 4 "
		"|Need glowing nettle. Quality healing.",
		/* [14] */
		"Strong Curing Potion |  Min. Skill - 5 |"
		"Need glowing nettle. A decent antidote f"
		"or poison.",
		/* [15] */
		"Medium Speed |  Min. Skill - 5 |Need glo"
		"wing nettle and wormgrass. Hastes drinke"
		"r a lot.",
		/* [16] */
		"Graymold Salve |  Min. Skill - 7 |Need g"
		"raymold. Cures disease of all sorts.",
		/* [17] */
		"Weak Energy Potion |  Min. Skill - 9 |Ne"
		"ed wormgrass and glowing nettle. Restore"
		"s some of your spell points.",
		/* [18] */
		"Potion of Clarity |  Min. Skill - 9 |Nee"
		"d graymold and holly. Cures dumbfounding"
		".",
		/* [19] */
		"Strong Poison |  Min. Skill - 10 |Need h"
		"olly and wormgrass. Powerful stuff.",
		/* [20] */
		"Strong Healing Potion |  Min. Skill - 12"
		" |Need graymold and comfrey root. Provid"
		"es excellent healing.",
		/* [21] */
		"Killer Poison |  Min. Skill - 12 |Need m"
		"andrake root. The strongest poison.",
		/* [22] */
		"Resurrection Balm |  Min. Skill - 9 |Nee"
		"d ember flowers. Necessary to cast Raise"
		" Dead or Resurrection.",
		/* [23] */
		"Medium Power Potion |  Min. Skill - 14 |"
		"Need mandrake root and wormgrass. Restor"
		"es a fair amount of spell points.",
		/* [24] */
		"Knowledge Brew |  Min. Skill - 19 |Legen"
		"d says it is possible to make this incre"
		"dibly potent concoction. However, the se"
		"cret has been long lost.",
		/* [25] */
		"One of the most useful things you can ma"
		"ke with alchemy is poison, a powerful we"
		"apon in the magic-poor world of Exile.",
		/* [26] */
		"Many monsters are immune to magic and fi"
		"re. However, not many are poison-resista"
		"nt. This makes poison an excellent mage-"
		"killer.",
		/* [27] */
		"To poison a weapon, use it during combat"
		". Your hand-to-hand weapon (the first on"
		"e, if two are equipped) or arrows will b"
		"ecome poisoned. Each time you attack, th"
		"e level of poison decreases.",
		/* [28] */
		"Don't poison a weapon too long before co"
		"mbat. It's effectiveness decreases with "
		"time. Also, switching weapons makes the "
		"poison disappear.",
		/* [29] */
		"Poisoning an already poisoned weapon doe"
		"sn't do much good. The weapon gets the m"
		"aximum poison level of the poison being "
		"added or the poison already there, no mo"
		"re."
	}
};

resource 'STR#' (30, "Special node extra 1a") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Unused",
		/* [2] */
		"Value to change to",
		/* [3] */
		"Increase/Decrease by",
		/* [4] */
		"Unused",
		/* [5] */
		"Unused",
		/* [6] */
		"Unused",
		/* [7] */
		"Unused",
		/* [8] */
		"0 - can enter, 1 - no enter",
		/* [9] */
		"0 - can enter, 1 - no enter",
		/* [10] */
		"0 - can enter, 1 - no enter",
		/* [11] */
		"Unused",
		/* [12] */
		"0 - can enter, 1 - no enter",
		/* [13] */
		"Number of moves to set forward",
		/* [14] */
		"Number of moves to set the timer",
		/* [15] */
		"Which sound",
		/* [16] */
		"Horse to set (0 .. 29)",
		/* [17] */
		"Boat to set (0 .. 29)",
		/* [18] */
		"Town to show/hide",
		/* [19] */
		"Number of Special Event (0 .. 9)",
		/* [20] */
		"Item To Give",
		/* [21] */
		"Item Class to Take Away",
		/* [22] */
		"Usused",
		/* [23] */
		"Value to change the 10 flags to",
		/* [24] */
		"Flag to change to Part A",
		/* [25] */
		"Unused",
		/* [26] */
		"Number of moves that pass",
		/* [27] */
		"0 - no attack, 1 - attack",
		/* [28] */
		"Number of hardcode to call",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"",
		/* [51] */
		"Item to give",
		/* [52] */
		"Num. of spec. item to give (0 .. 49)",
		/* [53] */
		"Unused",
		/* [54] */
		"Unused",
		/* [55] */
		"Unused",
		/* [56] */
		"Label of 2nd button (-1 - no button)",
		/* [57] */
		"Label of 2nd button (-1 - no button)",
		/* [58] */
		"Label of 2nd button (-1 - no button)",
		/* [59] */
		"Item to give",
		/* [60] */
		"Item to give",
		/* [61] */
		"Item to give",
		/* [62] */
		"Special outdoor enc. to place (0 .. 3)",
		/* [63] */
		"Spec. enc. code to activate (0 .. 10)",
		/* [64] */
		"Type of trap (see docs. for list)",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"",
		/* [81] */
		"0 - only living, 1 - any PC",
		/* [82] */
		"Number of dice",
		/* [83] */
		"Amount",
		/* [84] */
		"Amount",
		/* [85] */
		"Amount (0 .. 100)",
		/* [86] */
		"Amount (0 .. 10)",
		/* [87] */
		"0 - dead, 1 - dust,  2- stoned",
		/* [88] */
		"Amount (0 .. 8)",
		/* [89] */
		"Amount (0 .. 8)",
		/* [90] */
		"Amount (0 .. 8)",
		/* [91] */
		"Amount (0 .. 8)",
		/* [92] */
		"Amount (0 .. 8)",
		/* [93] */
		"Amount (0 .. 8)",
		/* [94] */
		"Amount (0 .. 8)",
		/* [95] */
		"Amount (0 .. 8)",
		/* [96] */
		"Amount (0 .. 7)",
		/* [97] */
		"Amount (0 .. 8)",
		/* [98] */
		"Amount (0 .. 5000)",
		/* [99] */
		"Amount (0 .. 10)",
		/* [100] */
		"Which Spell (0 .. 31, see docs)",
		/* [101] */
		"Which Spell (0 .. 31, see docs)",
		/* [102] */
		"Amount (0 .. 25000)",
		/* [103] */
		"Amount (0 .. 25000)",
		/* [104] */
		"Which Recipe (0 .. 19)",
		/* [105] */
		"Amount (0 .. 250)",
		/* [106] */
		"Amount (0 .. 250)",
		/* [107] */
		"Amount (0 .. 250)",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"If at least this value ...",
		/* [132] */
		"If in this town ...",
		/* [133] */
		"If random # (1 - 100) less than ...",
		/* [134] */
		"If has spec. item ...",
		/* [135] */
		"Stuff Done flag 2 Part A",
		/* [136] */
		"X coordinate of space",
		/* [137] */
		"X coordinate of space",
		/* [138] */
		"If party has this much gold ...",
		/* [139] */
		"If party has this much food ...",
		/* [140] */
		"X coordinate of space",
		/* [141] */
		"If has item of this special class ...",
		/* [142] */
		"If has equipped item of this special ...",
		/* [143] */
		"If party has this much gold ...",
		/* [144] */
		"If party has this much food ...",
		/* [145] */
		"X coordinate of space",
		/* [146] */
		"If has item of this special class ...",
		/* [147] */
		"If has equipped item of this class ...",
		/* [148] */
		"If this day has been reached ...",
		/* [149] */
		"Unused",
		/* [150] */
		"Unused",
		/* [151] */
		"If this phase has been reached ...",
		/* [152] */
		"If have this advantage",
		/* [153] */
		"Unused",
		/* [154] */
		"If the party has this sum ...",
		/* [155] */
		"Number of a SCENARIO special message",
		/* [156] */
		"If flag has this value ...",
		/* [157] */
		"If floor this type ...",
		/* [158] */
		"If floor this type ...",
		/* [159] */
		"If this char_flag here ...",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"Unused",
		/* [172] */
		"X coordinate of space",
		/* [173] */
		"X coordinate of space",
		/* [174] */
		"X coordinate of space",
		/* [175] */
		"X coordinate of space",
		/* [176] */
		"X coordinate of space",
		/* [177] */
		"X coordinate of space",
		/* [178] */
		"X coordinate of space",
		/* [179] */
		"X coordinate of space",
		/* [180] */
		"X coordinate of space",
		/* [181] */
		"Unused",
		/* [182] */
		"X coordinate of space to place",
		/* [183] */
		"Type of creature to remove",
		/* [184] */
		"0 - all, 1 - friendly, 2 - hostile",
		/* [185] */
		"Unused",
		/* [186] */
		"X coordinate to telep. to",
		/* [187] */
		"Unused",
		/* [188] */
		"X coordinate to go to ",
		/* [189] */
		"Unused",
		/* [190] */
		"X coordinate to telep. to",
		/* [191] */
		"X coordinate to place at",
		/* [192] */
		"X coordinate of outdoor section",
		/* [193] */
		"X coordinate to place at",
		/* [194] */
		"X coordinate to place lone PC at",
		/* [195] */
		"0 - no sound, 1 - teleport sound",
		/* [196] */
		"Number of moves until event",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"Top of rectangle",
		/* [202] */
		"Top of rectangle",
		/* [203] */
		"Top of rectangle",
		/* [204] */
		"Top of rectangle",
		/* [205] */
		"Top of rectangle",
		/* [206] */
		"Top of rectangle",
		/* [207] */
		"Top of rectangle",
		/* [208] */
		"Top of rectangle",
		/* [209] */
		"Top of rectangle",
		/* [210] */
		"Top of rectangle",
		/* [211] */
		"Top of rectangle",
		/* [212] */
		"Top of rectangle",
		/* [213] */
		"Top of rectangle",
		/* [214] */
		"Top of rectangle",
		/* [215] */
		"Top of rectangle",
		/* [216] */
		"Top of rectangle",
		/* [217] */
		"Top of rectangle",
		/* [218] */
		"Top of rectangle",
		/* [219] */
		"Top of rectangle",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"Unused",
		/* [227] */
		"X coordinate of space",
		/* [228] */
		"Number of special encounter (0 .. 3)",
		/* [229] */
		"X coordinate of space",
		/* [230] */
		"Number of first item in store",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (31, "Special node extra 1b") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Unused",
		/* [2] */
		"Unused",
		/* [3] */
		"0 - increase, 1 - decrease",
		/* [4] */
		"Unused",
		/* [5] */
		"Unused",
		/* [6] */
		"Unused",
		/* [7] */
		"Unused",
		/* [8] */
		"Unused",
		/* [9] */
		"Unused",
		/* [10] */
		"Unused",
		/* [11] */
		"Unused",
		/* [12] */
		"Unused",
		/* [13] */
		"Unused",
		/* [14] */
		"Special to call when timer runs out",
		/* [15] */
		"Unused",
		/* [16] */
		"Unused",
		/* [17] */
		"Unused",
		/* [18] */
		"0 - town hidden, 1 - town visible",
		/* [19] */
		"Unused",
		/* [20] */
		"Unused",
		/* [21] */
		"Special to call if no items taken",
		/* [22] */
		"Unused",
		/* [23] */
		"Unused",
		/* [24] */
		"Flag to change to Part B",
		/* [25] */
		"Special if not casting ritual",
		/* [26] */
		"Health and spell pts. to give",
		/* [27] */
		"Unused",
		/* [28] */
		"Unused",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"",
		/* [51] */
		"Amount of gold to give",
		/* [52] */
		"0 - give item, 1 - take away",
		/* [53] */
		"Unused",
		/* [54] */
		"Unused",
		/* [55] */
		"Unused",
		/* [56] */
		"Special if button 2 pressed",
		/* [57] */
		"Special if button 2 pressed",
		/* [58] */
		"Special if button 2 pressed",
		/* [59] */
		"Amount of gold to give",
		/* [60] */
		"Amount of gold to give",
		/* [61] */
		"Amount of gold to give",
		/* [62] */
		"Unused",
		/* [63] */
		"Unused",
		/* [64] */
		"Trap severity (0 .. 3)",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"",
		/* [81] */
		"Special if Cancel button pressed",
		/* [82] */
		"Number of 'sides' on dice",
		/* [83] */
		"0 - raise, 1 - lower",
		/* [84] */
		"0 - raise, 1 - lower",
		/* [85] */
		"0 - raise, 1 - lower",
		/* [86] */
		"0 - raise, 1 - lower",
		/* [87] */
		"0 - raise dead, 1 - hurt",
		/* [88] */
		"0 - cure, 1 - inflict",
		/* [89] */
		"0 - cure, 1 - inflict",
		/* [90] */
		"0 - cure, 1 - inflict",
		/* [91] */
		"0 - cure, 1 - inflict",
		/* [92] */
		"0 - cure, 1 - inflict",
		/* [93] */
		"0 - cure, 1 - inflict",
		/* [94] */
		"0 - adds, 1 - removes",
		/* [95] */
		"0 - blesses, 1 - curses",
		/* [96] */
		"0 - cure, 1 - inflict",
		/* [97] */
		"0 - cure, 1 - inflict",
		/* [98] */
		"0 - cure, 1 - inflict",
		/* [99] */
		"0 - increase, 1 - decrease",
		/* [100] */
		"Unused",
		/* [101] */
		"Unused",
		/* [102] */
		"0 - increase, 1 - decrease",
		/* [103] */
		"0 - increase, 1 - decrease",
		/* [104] */
		"Unused",
		/* [105] */
		"Unused",
		/* [106] */
		"Unused",
		/* [107] */
		"Unused",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"Call this special ...",
		/* [132] */
		"Call this special ...",
		/* [133] */
		"Call this special ...",
		/* [134] */
		"Call this special ...",
		/* [135] */
		"Stuff Done flag 2 Part B",
		/* [136] */
		"Y coordinate of space",
		/* [137] */
		"Y coordinate of space",
		/* [138] */
		"Call this special ...",
		/* [139] */
		"Call this special ...",
		/* [140] */
		"Y coordinate of space",
		/* [141] */
		"Call this special ...",
		/* [142] */
		"Call this special ...",
		/* [143] */
		"Call this special ...",
		/* [144] */
		"Call this special ...",
		/* [145] */
		"Y coordinate of space",
		/* [146] */
		"Call this special ...",
		/* [147] */
		"Call this special ...",
		/* [148] */
		"Call this special ...",
		/* [149] */
		"If any barrels, call this special ...",
		/* [150] */
		"If any crates, call this special ...",
		/* [151] */
		"And this event didn't happen before it ."
		"..",
		/* [152] */
		"If have this adv., call this ...",
		/* [153] */
		"If Roman, call this ...",
		/* [154] */
		"Call this special ...",
		/* [155] */
		"If answer matches, call this special ...",
		/* [156] */
		"Call this special ...",
		/* [157] */
		"Call this special ...",
		/* [158] */
		"Call this special ...",
		/* [159] */
		"Call this special ...",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"Unused",
		/* [172] */
		"Y coordinate of space",
		/* [173] */
		"Y coordinate of space",
		/* [174] */
		"Y coordinate of space",
		/* [175] */
		"Y coordinate of space",
		/* [176] */
		"Y coordinate of space",
		/* [177] */
		"Y coordinate of space",
		/* [178] */
		"Y coordinate of space",
		/* [179] */
		"Y coordinate of space",
		/* [180] */
		"Y coordinate of space",
		/* [181] */
		"Unused",
		/* [182] */
		"Y coordinate of space to place",
		/* [183] */
		"Unused",
		/* [184] */
		"Unused",
		/* [185] */
		"If Pulled, call this special ...",
		/* [186] */
		"Y coordinate to telep. to",
		/* [187] */
		"If Pushed, call this special ...",
		/* [188] */
		"Y coordinate to go to",
		/* [189] */
		"If Pulled, call this special ...",
		/* [190] */
		"Y coordinate to telep. to",
		/* [191] */
		"Y coordinate to place at",
		/* [192] */
		"Y coordinate of outdoor section",
		/* [193] */
		"Y coordinate to place at",
		/* [194] */
		"Y coordinate to place lone PC at",
		/* [195] */
		"Unused",
		/* [196] */
		"Call this special when time runs out ...",
		/* [197] */
		"Dialogue picture",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"Left of rectangle",
		/* [202] */
		"Left of rectangle",
		/* [203] */
		"Left of rectangle",
		/* [204] */
		"Left of rectangle",
		/* [205] */
		"Left of rectangle",
		/* [206] */
		"Left of rectangle",
		/* [207] */
		"Left of rectangle",
		/* [208] */
		"Left of rectangle",
		/* [209] */
		"Left of rectangle",
		/* [210] */
		"Left of rectangle",
		/* [211] */
		"Left of rectangle",
		/* [212] */
		"Left of rectangle",
		/* [213] */
		"Left of rectangle",
		/* [214] */
		"Left of rectangle",
		/* [215] */
		"Left of rectangle",
		/* [216] */
		"Left of rectangle",
		/* [217] */
		"Left of rectangle",
		/* [218] */
		"Left of rectangle",
		/* [219] */
		"Left of rectangle",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"Unused",
		/* [227] */
		"Y coordinate of space",
		/* [228] */
		"Unused",
		/* [229] */
		"Y coordinate of space",
		/* [230] */
		"Store type (see docs. for list)",
		/* [231] */
		"",
		/* [232] */
		"Dialogue picture",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (32, "Special node extra 2a") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Unused",
		/* [2] */
		"Unused",
		/* [3] */
		"Unused",
		/* [4] */
		"Unused",
		/* [5] */
		"Unused",
		/* [6] */
		"Unused",
		/* [7] */
		"Unused",
		/* [8] */
		"Unused",
		/* [9] */
		"Unused",
		/* [10] */
		"Unused",
		/* [11] */
		"Unused",
		/* [12] */
		"Unused",
		/* [13] */
		"Unused",
		/* [14] */
		"Unused",
		/* [15] */
		"Unused",
		/* [16] */
		"0 - not property, 1 - becomes property",
		/* [17] */
		"0 - not property, 1 - becomes property",
		/* [18] */
		"Unused",
		/* [19] */
		"Unused",
		/* [20] */
		"Unused",
		/* [21] */
		"Amount to pay for each item",
		/* [22] */
		"Unused",
		/* [23] */
		"Unused",
		/* [24] */
		"Unused",
		/* [25] */
		"Unused",
		/* [26] */
		"Unused",
		/* [27] */
		"Unused",
		/* [28] */
		"Unused",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"",
		/* [51] */
		"Amount of food to give",
		/* [52] */
		"Unused",
		/* [53] */
		"Unused",
		/* [54] */
		"Unused",
		/* [55] */
		"Unused",
		/* [56] */
		"Label of 3rd button (-1 - no button)",
		/* [57] */
		"Label of 3rd button (-1 - no button)",
		/* [58] */
		"Label of 3rd button (-1 - no button)",
		/* [59] */
		"Amount of food to give",
		/* [60] */
		"Amount of food to give",
		/* [61] */
		"Amount of food to give",
		/* [62] */
		"Unused",
		/* [63] */
		"Unused",
		/* [64] */
		"Penalty (0 .. 100, higher is harder)",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"",
		/* [81] */
		"Unused",
		/* [82] */
		"Amount of extra damage",
		/* [83] */
		"Unused",
		/* [84] */
		"Unused",
		/* [85] */
		"Unused",
		/* [86] */
		"Unused",
		/* [87] */
		"Unused",
		/* [88] */
		"Unused",
		/* [89] */
		"Unused",
		/* [90] */
		"Unused",
		/* [91] */
		"Unused",
		/* [92] */
		"Unused",
		/* [93] */
		"Unused",
		/* [94] */
		"Unused",
		/* [95] */
		"Unused",
		/* [96] */
		"Unused",
		/* [97] */
		"Unused",
		/* [98] */
		"Unused",
		/* [99] */
		"Stat. to adjust (see docs. for list)",
		/* [100] */
		"Unused",
		/* [101] */
		"Unused",
		/* [102] */
		"Unused",
		/* [103] */
		"Unused",
		/* [104] */
		"Unused",
		/* [105] */
		"Unused",
		/* [106] */
		"Unused",
		/* [107] */
		"Unused",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"If less than this ...",
		/* [132] */
		"Unused",
		/* [133] */
		"Unused",
		/* [134] */
		"Unused",
		/* [135] */
		"Unused",
		/* [136] */
		"If space is this terrain type ...",
		/* [137] */
		"If space is this terrain type ...",
		/* [138] */
		"Unused",
		/* [139] */
		"Unused",
		/* [140] */
		"If item of this class on space ...",
		/* [141] */
		"Unused",
		/* [142] */
		"Unused",
		/* [143] */
		"Unused",
		/* [144] */
		"Unused",
		/* [145] */
		"If item of this class on space ...",
		/* [146] */
		"Unused",
		/* [147] */
		"Unused",
		/* [148] */
		"Unused",
		/* [149] */
		"Unused",
		/* [150] */
		"Unused",
		/* [151] */
		"Unused",
		/* [152] */
		"Unused",
		/* [153] */
		"Unused",
		/* [154] */
		"Stat to sum",
		/* [155] */
		"Number of a SCENARIO special message",
		/* [156] */
		"Unused",
		/* [157] */
		"",
		/* [158] */
		"",
		/* [159] */
		"",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"Unused",
		/* [172] */
		"Terrain to change to",
		/* [173] */
		"Swap this terrain ...",
		/* [174] */
		"Unused",
		/* [175] */
		"0 - Just move, 1 - Teleport",
		/* [176] */
		"Damage to inflict (0 .. 1000)",
		/* [177] */
		"Damage to inflict (0 .. 1000)",
		/* [178] */
		"Unused",
		/* [179] */
		"Unused",
		/* [180] */
		"0 - fire, 1 - elec., 2 - telep.",
		/* [181] */
		"Unused",
		/* [182] */
		"Number of creature to place",
		/* [183] */
		"Unused",
		/* [184] */
		"Unused",
		/* [185] */
		"Unused",
		/* [186] */
		"Unused",
		/* [187] */
		"Unused",
		/* [188] */
		"Number of town to place party in",
		/* [189] */
		"Unused",
		/* [190] */
		"Unused",
		/* [191] */
		"Number of town to place party in",
		/* [192] */
		"X coordinate inside section ",
		/* [193] */
		"Item to place",
		/* [194] */
		"0 - no telep. noise, 1 - play telep. noi"
		"se",
		/* [195] */
		"Unused",
		/* [196] */
		"Unused",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"Bottom of rectangle",
		/* [202] */
		"Bottom of rectangle",
		/* [203] */
		"Bottom of rectangle",
		/* [204] */
		"Bottom of rectangle",
		/* [205] */
		"Bottom of rectangle",
		/* [206] */
		"Bottom of rectangle",
		/* [207] */
		"Bottom of rectangle",
		/* [208] */
		"Bottom of rectangle",
		/* [209] */
		"Bottom of rectangle",
		/* [210] */
		"Bottom of rectangle",
		/* [211] */
		"Bottom of rectangle",
		/* [212] */
		"Bottom of rectangle",
		/* [213] */
		"Bottom of rectangle",
		/* [214] */
		"Bottom of rectangle",
		/* [215] */
		"Bottom of rectangle",
		/* [216] */
		"Bottom of rectangle",
		/* [217] */
		"Bottom of rectangle",
		/* [218] */
		"Bottom of rectangle",
		/* [219] */
		"Bottom of rectangle",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"Unused",
		/* [227] */
		"Terrain to change to",
		/* [228] */
		"Unused",
		/* [229] */
		"Unused",
		/* [230] */
		"Number of items in store (1 .. 40)",
		/* [231] */
		"X coord of enc.",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (33, "Special node extra 2b") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Unused",
		/* [2] */
		"Unused",
		/* [3] */
		"Unused",
		/* [4] */
		"Unused",
		/* [5] */
		"Unused",
		/* [6] */
		"Unused",
		/* [7] */
		"Unused",
		/* [8] */
		"Unused",
		/* [9] */
		"Unused",
		/* [10] */
		"Unused",
		/* [11] */
		"Unused",
		/* [12] */
		"Unused",
		/* [13] */
		"Unused",
		/* [14] */
		"Unused",
		/* [15] */
		"Unused",
		/* [16] */
		"Unused",
		/* [17] */
		"Unused",
		/* [18] */
		"Unused",
		/* [19] */
		"Unused",
		/* [20] */
		"Special if item not given",
		/* [21] */
		"Unused",
		/* [22] */
		"Unused",
		/* [23] */
		"Unused",
		/* [24] */
		"Unused",
		/* [25] */
		"Unused",
		/* [26] */
		"Unused",
		/* [27] */
		"Unused",
		/* [28] */
		"Unused",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"",
		/* [51] */
		"Special if item not given",
		/* [52] */
		"Unused",
		/* [53] */
		"Unused",
		/* [54] */
		"Unused",
		/* [55] */
		"Unused",
		/* [56] */
		"Special if button 3 pressed",
		/* [57] */
		"Special if button 3 pressed",
		/* [58] */
		"Special if button 3 pressed",
		/* [59] */
		"Special if item IS taken",
		/* [60] */
		"Special if item IS taken",
		/* [61] */
		"Special if item IS taken",
		/* [62] */
		"Unused",
		/* [63] */
		"Unused",
		/* [64] */
		"Unused",
		/* [65] */
		"Unused",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"",
		/* [81] */
		"Unused",
		/* [82] */
		"Type of damage (for list, see docs.)",
		/* [83] */
		"Unused",
		/* [84] */
		"Unused",
		/* [85] */
		"Unused",
		/* [86] */
		"Unused",
		/* [87] */
		"Unused",
		/* [88] */
		"Unused",
		/* [89] */
		"Unused",
		/* [90] */
		"Unused",
		/* [91] */
		"Unused",
		/* [92] */
		"Unused",
		/* [93] */
		"Unused",
		/* [94] */
		"Unused",
		/* [95] */
		"Unused",
		/* [96] */
		"Unused",
		/* [97] */
		"Unused",
		/* [98] */
		"Unused",
		/* [99] */
		"Unused",
		/* [100] */
		"Unused",
		/* [101] */
		"Unused",
		/* [102] */
		"Unused",
		/* [103] */
		"Unused",
		/* [104] */
		"Unused",
		/* [105] */
		"Unused",
		/* [106] */
		"Unused",
		/* [107] */
		"Unused",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"Call this special ...",
		/* [132] */
		"Unused",
		/* [133] */
		"Unused",
		/* [134] */
		"Unused",
		/* [135] */
		"Call this special is 2nd flag lower ...",
		/* [136] */
		"Call this special ...",
		/* [137] */
		"Call this special ...",
		/* [138] */
		"Unused",
		/* [139] */
		"Unused",
		/* [140] */
		"Call this special ...",
		/* [141] */
		"Unused",
		/* [142] */
		"Unused",
		/* [143] */
		"Unused",
		/* [144] */
		"Unused",
		/* [145] */
		"Call this special ...",
		/* [146] */
		"Unused",
		/* [147] */
		"Unused",
		/* [148] */
		"Unused",
		/* [149] */
		"Unused",
		/* [150] */
		"Unused",
		/* [151] */
		"Call this special ...",
		/* [152] */
		"Unused",
		/* [153] */
		"Unused",
		/* [154] */
		"Unused",
		/* [155] */
		"If answer matches, call this special ...",
		/* [156] */
		"Unused",
		/* [157] */
		"",
		/* [158] */
		"",
		/* [159] */
		"",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"Unused",
		/* [172] */
		"Unused",
		/* [173] */
		"With this terrain ...",
		/* [174] */
		"Unused",
		/* [175] */
		"Unused",
		/* [176] */
		"Unused",
		/* [177] */
		"Type of damage (for list, see docs.)",
		/* [178] */
		"Unused",
		/* [179] */
		"Unused",
		/* [180] */
		"Unused",
		/* [181] */
		"Unused",
		/* [182] */
		"0 - don't force, 1 - force",
		/* [183] */
		"Unused",
		/* [184] */
		"Unused",
		/* [185] */
		"Unused",
		/* [186] */
		"Unused",
		/* [187] */
		"Unused",
		/* [188] */
		"What text? (see docs, 0 - up, 1 - down)",
		/* [189] */
		"Unused",
		/* [190] */
		"Unused",
		/* [191] */
		"If 1, always change level.",
		/* [192] */
		"Y coordinate inside section ",
		/* [193] */
		"Unused",
		/* [194] */
		"Unused",
		/* [195] */
		"Unused",
		/* [196] */
		"Unused",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"Right of rectangle",
		/* [202] */
		"Right of rectangle",
		/* [203] */
		"Right of rectangle",
		/* [204] */
		"Right of rectangle",
		/* [205] */
		"Right of rectangle",
		/* [206] */
		"Right of rectangle",
		/* [207] */
		"Right of rectangle",
		/* [208] */
		"Right of rectangle",
		/* [209] */
		"Right of rectangle",
		/* [210] */
		"Right of rectangle",
		/* [211] */
		"Right of rectangle",
		/* [212] */
		"Right of rectangle",
		/* [213] */
		"Right of rectangle",
		/* [214] */
		"Right of rectangle",
		/* [215] */
		"Right of rectangle",
		/* [216] */
		"Right of rectangle",
		/* [217] */
		"Right of rectangle",
		/* [218] */
		"Right of rectangle",
		/* [219] */
		"Right of rectangle",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"Unused",
		/* [227] */
		"Floor type to change to",
		/* [228] */
		"Unused",
		/* [229] */
		"Unused",
		/* [230] */
		"Cost adjust (0 .. 6, lower = cheaper)",
		/* [231] */
		"Y coord of enc.",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (35, "Scen default strs") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Scen name",
		/* [2] */
		"Who wrote 1 ",
		/* [3] */
		"Who wrote 2",
		/* [4] */
		"Contact info",
		/* [5] */
		"",
		/* [6] */
		"",
		/* [7] */
		"",
		/* [8] */
		"",
		/* [9] */
		"",
		/* [10] */
		"",
		/* [11] */
		"Begin journal strs",
		/* [12] */
		"",
		/* [13] */
		"",
		/* [14] */
		"",
		/* [15] */
		"",
		/* [16] */
		"",
		/* [17] */
		"",
		/* [18] */
		"",
		/* [19] */
		"",
		/* [20] */
		"",
		/* [21] */
		"",
		/* [22] */
		"",
		/* [23] */
		"",
		/* [24] */
		"",
		/* [25] */
		"",
		/* [26] */
		"",
		/* [27] */
		"",
		/* [28] */
		"",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"",
		/* [51] */
		"",
		/* [52] */
		"",
		/* [53] */
		"",
		/* [54] */
		"",
		/* [55] */
		"",
		/* [56] */
		"",
		/* [57] */
		"",
		/* [58] */
		"",
		/* [59] */
		"",
		/* [60] */
		"End journal strs",
		/* [61] */
		"Unused Special Item",
		/* [62] */
		"",
		/* [63] */
		"Unused Special Item",
		/* [64] */
		"",
		/* [65] */
		"Unused Special Item",
		/* [66] */
		"",
		/* [67] */
		"Unused Special Item",
		/* [68] */
		"",
		/* [69] */
		"Unused Special Item",
		/* [70] */
		"",
		/* [71] */
		"Unused Special Item",
		/* [72] */
		"",
		/* [73] */
		"Unused Special Item",
		/* [74] */
		"",
		/* [75] */
		"Unused Special Item",
		/* [76] */
		"",
		/* [77] */
		"Unused Special Item",
		/* [78] */
		"",
		/* [79] */
		"Unused Special Item",
		/* [80] */
		"",
		/* [81] */
		"Unused Special Item",
		/* [82] */
		"",
		/* [83] */
		"Unused Special Item",
		/* [84] */
		"",
		/* [85] */
		"Unused Special Item",
		/* [86] */
		"",
		/* [87] */
		"Unused Special Item",
		/* [88] */
		"",
		/* [89] */
		"Unused Special Item",
		/* [90] */
		"",
		/* [91] */
		"Unused Special Item",
		/* [92] */
		"",
		/* [93] */
		"Unused Special Item",
		/* [94] */
		"",
		/* [95] */
		"Unused Special Item",
		/* [96] */
		"",
		/* [97] */
		"Unused Special Item",
		/* [98] */
		"",
		/* [99] */
		"Unused Special Item",
		/* [100] */
		"",
		/* [101] */
		"Unused Special Item",
		/* [102] */
		"",
		/* [103] */
		"Unused Special Item",
		/* [104] */
		"",
		/* [105] */
		"Unused Special Item",
		/* [106] */
		"",
		/* [107] */
		"Unused Special Item",
		/* [108] */
		"",
		/* [109] */
		"Unused Special Item",
		/* [110] */
		"",
		/* [111] */
		"Unused Special Item",
		/* [112] */
		"",
		/* [113] */
		"Unused Special Item",
		/* [114] */
		"",
		/* [115] */
		"Unused Special Item",
		/* [116] */
		"",
		/* [117] */
		"Unused Special Item",
		/* [118] */
		"",
		/* [119] */
		"Unused Special Item",
		/* [120] */
		"",
		/* [121] */
		"Unused Special Item",
		/* [122] */
		"",
		/* [123] */
		"Unused Special Item",
		/* [124] */
		"",
		/* [125] */
		"Unused Special Item",
		/* [126] */
		"",
		/* [127] */
		"Unused Special Item",
		/* [128] */
		"",
		/* [129] */
		"Unused Special Item",
		/* [130] */
		"",
		/* [131] */
		"Unused Special Item",
		/* [132] */
		"",
		/* [133] */
		"Unused Special Item",
		/* [134] */
		"",
		/* [135] */
		"Unused Special Item",
		/* [136] */
		"",
		/* [137] */
		"Unused Special Item",
		/* [138] */
		"",
		/* [139] */
		"Unused Special Item",
		/* [140] */
		"",
		/* [141] */
		"Unused Special Item",
		/* [142] */
		"",
		/* [143] */
		"Unused Special Item",
		/* [144] */
		"",
		/* [145] */
		"Unused Special Item",
		/* [146] */
		"",
		/* [147] */
		"Unused Special Item",
		/* [148] */
		"",
		/* [149] */
		"Unused Special Item",
		/* [150] */
		"",
		/* [151] */
		"Unused Special Item",
		/* [152] */
		"",
		/* [153] */
		"Unused Special Item",
		/* [154] */
		"",
		/* [155] */
		"Unused Special Item",
		/* [156] */
		"",
		/* [157] */
		"Unused Special Item",
		/* [158] */
		"",
		/* [159] */
		"Unused Special Item",
		/* [160] */
		"End special item descs",
		/* [161] */
		"*Begin special strs",
		/* [162] */
		"*",
		/* [163] */
		"*",
		/* [164] */
		"*",
		/* [165] */
		"*",
		/* [166] */
		"*",
		/* [167] */
		"*",
		/* [168] */
		"*",
		/* [169] */
		"*",
		/* [170] */
		"*",
		/* [171] */
		"*",
		/* [172] */
		"*",
		/* [173] */
		"*",
		/* [174] */
		"*",
		/* [175] */
		"*",
		/* [176] */
		"*",
		/* [177] */
		"*",
		/* [178] */
		"*",
		/* [179] */
		"*",
		/* [180] */
		"*",
		/* [181] */
		"*",
		/* [182] */
		"*",
		/* [183] */
		"*",
		/* [184] */
		"*",
		/* [185] */
		"*",
		/* [186] */
		"*",
		/* [187] */
		"*",
		/* [188] */
		"*",
		/* [189] */
		"*",
		/* [190] */
		"*",
		/* [191] */
		"*",
		/* [192] */
		"*",
		/* [193] */
		"*",
		/* [194] */
		"*",
		/* [195] */
		"*",
		/* [196] */
		"*",
		/* [197] */
		"*",
		/* [198] */
		"*",
		/* [199] */
		"*",
		/* [200] */
		"*",
		/* [201] */
		"*",
		/* [202] */
		"*",
		/* [203] */
		"*",
		/* [204] */
		"*",
		/* [205] */
		"*",
		/* [206] */
		"*",
		/* [207] */
		"*",
		/* [208] */
		"*",
		/* [209] */
		"*",
		/* [210] */
		"*",
		/* [211] */
		"*",
		/* [212] */
		"*",
		/* [213] */
		"*",
		/* [214] */
		"*",
		/* [215] */
		"*",
		/* [216] */
		"*",
		/* [217] */
		"*",
		/* [218] */
		"*",
		/* [219] */
		"*",
		/* [220] */
		"*",
		/* [221] */
		"*",
		/* [222] */
		"*",
		/* [223] */
		"*",
		/* [224] */
		"*",
		/* [225] */
		"*",
		/* [226] */
		"*",
		/* [227] */
		"*",
		/* [228] */
		"*",
		/* [229] */
		"*",
		/* [230] */
		"*",
		/* [231] */
		"*",
		/* [232] */
		"*",
		/* [233] */
		"*",
		/* [234] */
		"*",
		/* [235] */
		"*",
		/* [236] */
		"*",
		/* [237] */
		"*",
		/* [238] */
		"*",
		/* [239] */
		"*",
		/* [240] */
		"*",
		/* [241] */
		"*",
		/* [242] */
		"*",
		/* [243] */
		"*",
		/* [244] */
		"*",
		/* [245] */
		"*",
		/* [246] */
		"*",
		/* [247] */
		"*",
		/* [248] */
		"*",
		/* [249] */
		"*",
		/* [250] */
		"*",
		/* [251] */
		"*",
		/* [252] */
		"*",
		/* [253] */
		"*",
		/* [254] */
		"*",
		/* [255] */
		"*",
		/* [256] */
		"*",
		/* [257] */
		"*",
		/* [258] */
		"*",
		/* [259] */
		"*",
		/* [260] */
		"*End special strs",
		/* [261] */
		"From here on, reserved for furute use",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (36, "Town default strs") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Town name",
		/* [2] */
		"Rectangle 1",
		/* [3] */
		"Rectangle 2",
		/* [4] */
		"Rectangle 3",
		/* [5] */
		"Rectangle 4",
		/* [6] */
		"Rectangle 5",
		/* [7] */
		"Rectangle 6",
		/* [8] */
		"Rectangle 7",
		/* [9] */
		"Rectangle 8",
		/* [10] */
		"Rectangle 9",
		/* [11] */
		"Rectangle 10",
		/* [12] */
		"Rectangle 11",
		/* [13] */
		"Rectangle 12",
		/* [14] */
		"Rectangle 13",
		/* [15] */
		"Rectangle 14",
		/* [16] */
		"Rectangle 15",
		/* [17] */
		"Rectangle 16",
		/* [18] */
		"Comment 1",
		/* [19] */
		"Comment 2",
		/* [20] */
		"Comment 3",
		/* [21] */
		"*Begin special strs",
		/* [22] */
		"*",
		/* [23] */
		"*",
		/* [24] */
		"*",
		/* [25] */
		"*",
		/* [26] */
		"*",
		/* [27] */
		"*",
		/* [28] */
		"*",
		/* [29] */
		"*",
		/* [30] */
		"*",
		/* [31] */
		"*",
		/* [32] */
		"*",
		/* [33] */
		"*",
		/* [34] */
		"*",
		/* [35] */
		"*",
		/* [36] */
		"*",
		/* [37] */
		"*",
		/* [38] */
		"*",
		/* [39] */
		"*",
		/* [40] */
		"*",
		/* [41] */
		"*",
		/* [42] */
		"*",
		/* [43] */
		"*",
		/* [44] */
		"*",
		/* [45] */
		"*",
		/* [46] */
		"*",
		/* [47] */
		"*",
		/* [48] */
		"*",
		/* [49] */
		"*",
		/* [50] */
		"*",
		/* [51] */
		"*",
		/* [52] */
		"*",
		/* [53] */
		"*",
		/* [54] */
		"*",
		/* [55] */
		"*",
		/* [56] */
		"*",
		/* [57] */
		"*",
		/* [58] */
		"*",
		/* [59] */
		"*",
		/* [60] */
		"*",
		/* [61] */
		"*",
		/* [62] */
		"*",
		/* [63] */
		"*",
		/* [64] */
		"*",
		/* [65] */
		"*",
		/* [66] */
		"*",
		/* [67] */
		"*",
		/* [68] */
		"*",
		/* [69] */
		"*",
		/* [70] */
		"*",
		/* [71] */
		"*",
		/* [72] */
		"*",
		/* [73] */
		"*",
		/* [74] */
		"*",
		/* [75] */
		"*",
		/* [76] */
		"*",
		/* [77] */
		"*",
		/* [78] */
		"*",
		/* [79] */
		"*",
		/* [80] */
		"*",
		/* [81] */
		"*",
		/* [82] */
		"*",
		/* [83] */
		"*",
		/* [84] */
		"*",
		/* [85] */
		"*",
		/* [86] */
		"*",
		/* [87] */
		"*",
		/* [88] */
		"*",
		/* [89] */
		"*",
		/* [90] */
		"*",
		/* [91] */
		"*",
		/* [92] */
		"*",
		/* [93] */
		"*",
		/* [94] */
		"*",
		/* [95] */
		"*",
		/* [96] */
		"*",
		/* [97] */
		"*",
		/* [98] */
		"*",
		/* [99] */
		"*",
		/* [100] */
		"*",
		/* [101] */
		"*",
		/* [102] */
		"*",
		/* [103] */
		"*",
		/* [104] */
		"*",
		/* [105] */
		"*",
		/* [106] */
		"*",
		/* [107] */
		"*",
		/* [108] */
		"*",
		/* [109] */
		"*",
		/* [110] */
		"*",
		/* [111] */
		"*",
		/* [112] */
		"*",
		/* [113] */
		"*",
		/* [114] */
		"*",
		/* [115] */
		"*",
		/* [116] */
		"*",
		/* [117] */
		"*",
		/* [118] */
		"*",
		/* [119] */
		"*",
		/* [120] */
		"*",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"",
		/* [132] */
		"",
		/* [133] */
		"",
		/* [134] */
		"",
		/* [135] */
		"",
		/* [136] */
		"",
		/* [137] */
		"",
		/* [138] */
		"",
		/* [139] */
		"",
		/* [140] */
		"",
		/* [141] */
		"",
		/* [142] */
		"",
		/* [143] */
		"",
		/* [144] */
		"",
		/* [145] */
		"",
		/* [146] */
		"",
		/* [147] */
		"",
		/* [148] */
		"",
		/* [149] */
		"",
		/* [150] */
		"",
		/* [151] */
		"",
		/* [152] */
		"",
		/* [153] */
		"",
		/* [154] */
		"",
		/* [155] */
		"",
		/* [156] */
		"",
		/* [157] */
		"",
		/* [158] */
		"",
		/* [159] */
		"",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"",
		/* [172] */
		"",
		/* [173] */
		"",
		/* [174] */
		"",
		/* [175] */
		"",
		/* [176] */
		"",
		/* [177] */
		"",
		/* [178] */
		"",
		/* [179] */
		"",
		/* [180] */
		"",
		/* [181] */
		"",
		/* [182] */
		"",
		/* [183] */
		"",
		/* [184] */
		"",
		/* [185] */
		"",
		/* [186] */
		"",
		/* [187] */
		"",
		/* [188] */
		"",
		/* [189] */
		"",
		/* [190] */
		"",
		/* [191] */
		"",
		/* [192] */
		"",
		/* [193] */
		"",
		/* [194] */
		"",
		/* [195] */
		"",
		/* [196] */
		"",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"",
		/* [202] */
		"",
		/* [203] */
		"",
		/* [204] */
		"",
		/* [205] */
		"",
		/* [206] */
		"",
		/* [207] */
		"",
		/* [208] */
		"",
		/* [209] */
		"",
		/* [210] */
		"",
		/* [211] */
		"",
		/* [212] */
		"",
		/* [213] */
		"",
		/* [214] */
		"",
		/* [215] */
		"",
		/* [216] */
		"",
		/* [217] */
		"",
		/* [218] */
		"",
		/* [219] */
		"",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"",
		/* [227] */
		"",
		/* [228] */
		"",
		/* [229] */
		"",
		/* [230] */
		"",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (37, "Outdoor default strs") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Area name",
		/* [2] */
		"Rectangle 1",
		/* [3] */
		"Rectangle 2",
		/* [4] */
		"Rectangle 3",
		/* [5] */
		"Rectangle 4",
		/* [6] */
		"Rectangle 5",
		/* [7] */
		"Rectangle 6",
		/* [8] */
		"Rectangle 7",
		/* [9] */
		"Rectangle 8",
		/* [10] */
		"Comment",
		/* [11] */
		"*Begin special strs",
		/* [12] */
		"*",
		/* [13] */
		"*",
		/* [14] */
		"*",
		/* [15] */
		"*",
		/* [16] */
		"*",
		/* [17] */
		"*",
		/* [18] */
		"*",
		/* [19] */
		"*",
		/* [20] */
		"*",
		/* [21] */
		"*",
		/* [22] */
		"*",
		/* [23] */
		"*",
		/* [24] */
		"*",
		/* [25] */
		"*",
		/* [26] */
		"*",
		/* [27] */
		"*",
		/* [28] */
		"*",
		/* [29] */
		"*",
		/* [30] */
		"*",
		/* [31] */
		"*",
		/* [32] */
		"*",
		/* [33] */
		"*",
		/* [34] */
		"*",
		/* [35] */
		"*",
		/* [36] */
		"*",
		/* [37] */
		"*",
		/* [38] */
		"*",
		/* [39] */
		"*",
		/* [40] */
		"*",
		/* [41] */
		"*",
		/* [42] */
		"*",
		/* [43] */
		"*",
		/* [44] */
		"*",
		/* [45] */
		"*",
		/* [46] */
		"*",
		/* [47] */
		"*",
		/* [48] */
		"*",
		/* [49] */
		"*",
		/* [50] */
		"*",
		/* [51] */
		"*",
		/* [52] */
		"*",
		/* [53] */
		"*",
		/* [54] */
		"*",
		/* [55] */
		"*",
		/* [56] */
		"*",
		/* [57] */
		"*",
		/* [58] */
		"*",
		/* [59] */
		"*",
		/* [60] */
		"*",
		/* [61] */
		"*",
		/* [62] */
		"*",
		/* [63] */
		"*",
		/* [64] */
		"*",
		/* [65] */
		"*",
		/* [66] */
		"*",
		/* [67] */
		"*",
		/* [68] */
		"*",
		/* [69] */
		"*",
		/* [70] */
		"*",
		/* [71] */
		"*",
		/* [72] */
		"*",
		/* [73] */
		"*",
		/* [74] */
		"*",
		/* [75] */
		"*",
		/* [76] */
		"*",
		/* [77] */
		"*",
		/* [78] */
		"*",
		/* [79] */
		"*",
		/* [80] */
		"*",
		/* [81] */
		"*",
		/* [82] */
		"*",
		/* [83] */
		"*",
		/* [84] */
		"*",
		/* [85] */
		"*",
		/* [86] */
		"*",
		/* [87] */
		"*",
		/* [88] */
		"*",
		/* [89] */
		"*",
		/* [90] */
		"*",
		/* [91] */
		"*",
		/* [92] */
		"*",
		/* [93] */
		"*",
		/* [94] */
		"*",
		/* [95] */
		"*",
		/* [96] */
		"*",
		/* [97] */
		"*",
		/* [98] */
		"*",
		/* [99] */
		"*",
		/* [100] */
		"*End of special strs",
		/* [101] */
		"",
		/* [102] */
		"",
		/* [103] */
		"",
		/* [104] */
		"",
		/* [105] */
		"",
		/* [106] */
		"",
		/* [107] */
		"",
		/* [108] */
		"",
		/* [109] */
		"From here on, reserved for future use",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"",
		/* [132] */
		"",
		/* [133] */
		"",
		/* [134] */
		"",
		/* [135] */
		"",
		/* [136] */
		"",
		/* [137] */
		"",
		/* [138] */
		"",
		/* [139] */
		"",
		/* [140] */
		"",
		/* [141] */
		"",
		/* [142] */
		"",
		/* [143] */
		"",
		/* [144] */
		"",
		/* [145] */
		"",
		/* [146] */
		"",
		/* [147] */
		"",
		/* [148] */
		"",
		/* [149] */
		"",
		/* [150] */
		"",
		/* [151] */
		"",
		/* [152] */
		"",
		/* [153] */
		"",
		/* [154] */
		"",
		/* [155] */
		"",
		/* [156] */
		"",
		/* [157] */
		"",
		/* [158] */
		"",
		/* [159] */
		"",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"",
		/* [172] */
		"",
		/* [173] */
		"",
		/* [174] */
		"",
		/* [175] */
		"",
		/* [176] */
		"",
		/* [177] */
		"",
		/* [178] */
		"",
		/* [179] */
		"",
		/* [180] */
		"",
		/* [181] */
		"",
		/* [182] */
		"",
		/* [183] */
		"",
		/* [184] */
		"",
		/* [185] */
		"",
		/* [186] */
		"",
		/* [187] */
		"",
		/* [188] */
		"",
		/* [189] */
		"",
		/* [190] */
		"",
		/* [191] */
		"",
		/* [192] */
		"",
		/* [193] */
		"",
		/* [194] */
		"",
		/* [195] */
		"",
		/* [196] */
		"",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"",
		/* [202] */
		"",
		/* [203] */
		"",
		/* [204] */
		"",
		/* [205] */
		"",
		/* [206] */
		"",
		/* [207] */
		"",
		/* [208] */
		"",
		/* [209] */
		"",
		/* [210] */
		"",
		/* [211] */
		"",
		/* [212] */
		"",
		/* [213] */
		"",
		/* [214] */
		"",
		/* [215] */
		"",
		/* [216] */
		"",
		/* [217] */
		"",
		/* [218] */
		"",
		/* [219] */
		"",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"",
		/* [227] */
		"",
		/* [228] */
		"",
		/* [229] */
		"",
		/* [230] */
		"",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (40, "Talking descs") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"Regular speech",
		/* [2] */
		"Unused",
		/* [3] */
		"Unused",
		/* [4] */
		"Unused",
		/* [5] */
		"Unused",
		/* [6] */
		"First part of response ...",
		/* [7] */
		"Second part of response ...",
		/* [8] */
		"Response depends on flag",
		/* [9] */
		"Stuff Done flag Pt. A",
		/* [10] */
		"Stuff Done flag Pt. B",
		/* [11] */
		"Value to compare to",
		/* [12] */
		"Unused",
		/* [13] */
		"Response if less than or equal to",
		/* [14] */
		"Response if greater than",
		/* [15] */
		"Set flag to 1",
		/* [16] */
		"Stuff Done flag Pt. A",
		/* [17] */
		"Stuff Done flag Pt. B",
		/* [18] */
		"Unused",
		/* [19] */
		"Quest num (>100 -> turn off)",
		/* [20] */
		"If flag wasnÕt 1.",
		/* [21] */
		"If flag was 1.",
		/* [22] */
		"Inn",
		/* [23] */
		"Cost of Inn",
		/* [24] */
		"Quality of Inn (0 .. 3)",
		/* [25] */
		"Move party to X",
		/* [26] */
		"Move party to Y",
		/* [27] */
		"Response if can afford it ...",
		/* [28] */
		"Response if not enough money ...",
		/* [29] */
		"Change stuff done flag",
		/* [30] */
		"Stuff Done flag Pt. A",
		/* [31] */
		"Stuff Done flag Pt. B",
		/* [32] */
		"What to change to",
		/* [33] */
		"Quest num (>100 -> turn off)",
		/* [34] */
		"First part of response ...",
		/* [35] */
		"Second part of response ...",
		/* [36] */
		"A Particular Day?",
		/* [37] */
		"If this day class has been reached ...",
		/* [38] */
		"Unused",
		/* [39] */
		"Unused",
		/* [40] */
		"Unused",
		/* [41] */
		"Respond with this ...",
		/* [42] */
		"Otherwise respond with this ...",
		/* [43] */
		"Depends on town",
		/* [44] */
		"Town to check",
		/* [45] */
		"Unused",
		/* [46] */
		"Unused",
		/* [47] */
		"Unused",
		/* [48] */
		"Response if in this town ...",
		/* [49] */
		"Otherwise respond ...",
		/* [50] */
		"Buy Items",
		/* [51] */
		"Cost adjustment (0 .. 6)",
		/* [52] */
		"Number of shop",
		/* [53] */
		"Sell adjustment (0 best .. 6)",
		/* [54] */
		"Unused",
		/* [55] */
		"Name of shop",
		/* [56] */
		"Unused",
		/* [57] */
		"Mage Spell Shop",
		/* [58] */
		"Cost adjustment (0 .. 6)",
		/* [59] */
		"Number of first spell in shop",
		/* [60] */
		"Total number of spells in shop",
		/* [61] */
		"Level of spells (1-3)",
		/* [62] */
		"Name of shop",
		/* [63] */
		"Shop Desc Text",
		/* [64] */
		"Priest Spell Shop",
		/* [65] */
		"Cost adjustment (0 .. 6)",
		/* [66] */
		"Number of first spell in shop",
		/* [67] */
		"Total number of spells in shop",
		/* [68] */
		"Level of spells (1-3)",
		/* [69] */
		"Name of shop",
		/* [70] */
		"Shop Desc Text",
		/* [71] */
		"Affect Reputation",
		/* [72] */
		"Stuff Done flag Pt. A",
		/* [73] */
		"Stuff Done flag Pt. B",
		/* [74] */
		"Amount to change by",
		/* [75] */
		"Unused",
		/* [76] */
		"Text if triggered once.",
		/* [77] */
		"Text if triggered later.",
		/* [78] */
		"Alchemy Shop",
		/* [79] */
		"Cost adjustment (0 .. 6)",
		/* [80] */
		"Number of first recipe in shop",
		/* [81] */
		"Total number of recipes in shop",
		/* [82] */
		"Unused",
		/* [83] */
		"Name of shop",
		/* [84] */
		"Description",
		/* [85] */
		"Healer",
		/* [86] */
		"Cost adjustment (0 .. 6)",
		/* [87] */
		"Unused",
		/* [88] */
		"Unused",
		/* [89] */
		"Unused",
		/* [90] */
		"Name of healer",
		/* [91] */
		"Description",
		/* [92] */
		"Introductory Dialogue",
		/* [93] */
		"Unused",
		/* [94] */
		"Unused",
		/* [95] */
		"Unused",
		/* [96] */
		"Unused",
		/* [97] */
		"Text first time met",
		/* [98] */
		"Text for all later times",
		/* [99] */
		"Response Depends on Race",
		/* [100] */
		"Race to check for (1 - neph, 2 - slith)",
		/* [101] */
		"Unused",
		/* [102] */
		"Unused",
		/* [103] */
		"Unused",
		/* [104] */
		"Text if race present",
		/* [105] */
		"Text if race not present",
		/* [106] */
		"Toggle a Quest",
		/* [107] */
		"Quest num (>100 -> turn off)",
		/* [108] */
		"Unused",
		/* [109] */
		"Unused",
		/* [110] */
		"Unused",
		/* [111] */
		"First part of response ...",
		/* [112] */
		"Second part of response ...",
		/* [113] */
		"Identify Items",
		/* [114] */
		"Cost to identify",
		/* [115] */
		"Unused",
		/* [116] */
		"Unused",
		/* [117] */
		"Unused",
		/* [118] */
		"Person identifying items says:",
		/* [119] */
		"Unused",
		/* [120] */
		"Unused",
		/* [121] */
		"Unused",
		/* [122] */
		"Unused",
		/* [123] */
		"Unused",
		/* [124] */
		"Unused",
		/* [125] */
		"Unused",
		/* [126] */
		"Unused",
		/* [127] */
		"Pay For Response",
		/* [128] */
		"Amount of gold taken",
		/* [129] */
		"Amount of drunkenness",
		/* [130] */
		"Unused",
		/* [131] */
		"Unused",
		/* [132] */
		"Response if party has gold",
		/* [133] */
		"Response if they don't",
		/* [134] */
		"Buy response, Change Flag",
		/* [135] */
		"Amount of gold taken",
		/* [136] */
		"Stuff Done Flag, Pt. A",
		/* [137] */
		"Stuff Done Flag, Pt. B",
		/* [138] */
		"Change flag to",
		/* [139] */
		"Response if party has gold",
		/* [140] */
		"Response if they don't",
		/* [141] */
		"Buy Boat",
		/* [142] */
		"Cost of Boat",
		/* [143] */
		"Number of first boat sold",
		/* [144] */
		"Total number of boats sold",
		/* [145] */
		"Unused",
		/* [146] */
		"Response if party has gold",
		/* [147] */
		"Response if they don't",
		/* [148] */
		"Unused",
		/* [149] */
		"Cost of Horse",
		/* [150] */
		"Number of first horse sold",
		/* [151] */
		"Total number of horses sold",
		/* [152] */
		"Unused",
		/* [153] */
		"Response if party has gold",
		/* [154] */
		"Response if they don't",
		/* [155] */
		"Buy Special Item",
		/* [156] */
		"Number of item being sold",
		/* [157] */
		"Cost of item",
		/* [158] */
		"Unused",
		/* [159] */
		"Unused",
		/* [160] */
		"Response if party buys it",
		/* [161] */
		"Response if party can't afford it",
		/* [162] */
		"Job Board",
		/* [163] */
		"Which One (0 .. 5)",
		/* [164] */
		"Unused",
		/* [165] */
		"Unused",
		/* [166] */
		"Unused",
		/* [167] */
		"Name of Job Place",
		/* [168] */
		"Unused",
		/* [169] */
		"Special Hardcode",
		/* [170] */
		"Which one?",
		/* [171] */
		"Unused",
		/* [172] */
		"Unused",
		/* [173] */
		"Unused",
		/* [174] */
		"Chunk of Text 1",
		/* [175] */
		"Chunk of Text 2",
		/* [176] */
		"Force Conversation End",
		/* [177] */
		"Unused",
		/* [178] */
		"Unused",
		/* [179] */
		"Unused",
		/* [180] */
		"Unused",
		/* [181] */
		"First part of response",
		/* [182] */
		"Second part of response",
		/* [183] */
		"Hostile Conversation End",
		/* [184] */
		"Unused",
		/* [185] */
		"Unused",
		/* [186] */
		"Unused",
		/* [187] */
		"Unused",
		/* [188] */
		"First part of response",
		/* [189] */
		"Second part of response",
		/* [190] */
		"Town Hostile Conv. End",
		/* [191] */
		"Unused",
		/* [192] */
		"Unused",
		/* [193] */
		"Unused",
		/* [194] */
		"Unused",
		/* [195] */
		"First part of response",
		/* [196] */
		"Second part of response",
		/* [197] */
		"Eliminate Creature",
		/* [198] */
		"Reputation to give",
		/* [199] */
		"XP to give",
		/* [200] */
		"Unused",
		/* [201] */
		"Unused",
		/* [202] */
		"First part of response",
		/* [203] */
		"Second part of response",
		/* [204] */
		"Unused",
		/* [205] */
		"Number of town special node to call",
		/* [206] */
		"Unused",
		/* [207] */
		"Unused",
		/* [208] */
		"Unused",
		/* [209] */
		"First part of response (if no other resp"
		"onse given in special)",
		/* [210] */
		"Second part of response (if no other res"
		"ponse given in special)",
		/* [211] */
		"Unused",
		/* [212] */
		"Number of scenario special node to call",
		/* [213] */
		"Unused",
		/* [214] */
		"Unused",
		/* [215] */
		"Unused",
		/* [216] */
		"First part of response (if no other resp"
		"onse given in special)",
		/* [217] */
		"Second part of response (if no other res"
		"ponse given in special)",
		/* [218] */
		"",
		/* [219] */
		"",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"",
		/* [227] */
		"",
		/* [228] */
		"",
		/* [229] */
		"",
		/* [230] */
		"",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

resource 'STR#' (199, "300 blanks.") {
	{	/* array StringArray: 300 elements */
		/* [1] */
		"",
		/* [2] */
		"",
		/* [3] */
		"",
		/* [4] */
		"",
		/* [5] */
		"",
		/* [6] */
		"",
		/* [7] */
		"",
		/* [8] */
		"",
		/* [9] */
		"",
		/* [10] */
		"",
		/* [11] */
		"",
		/* [12] */
		"",
		/* [13] */
		"",
		/* [14] */
		"",
		/* [15] */
		"",
		/* [16] */
		"",
		/* [17] */
		"",
		/* [18] */
		"",
		/* [19] */
		"",
		/* [20] */
		"",
		/* [21] */
		"",
		/* [22] */
		"",
		/* [23] */
		"",
		/* [24] */
		"",
		/* [25] */
		"",
		/* [26] */
		"",
		/* [27] */
		"",
		/* [28] */
		"",
		/* [29] */
		"",
		/* [30] */
		"",
		/* [31] */
		"",
		/* [32] */
		"",
		/* [33] */
		"",
		/* [34] */
		"",
		/* [35] */
		"",
		/* [36] */
		"",
		/* [37] */
		"",
		/* [38] */
		"",
		/* [39] */
		"",
		/* [40] */
		"",
		/* [41] */
		"",
		/* [42] */
		"",
		/* [43] */
		"",
		/* [44] */
		"",
		/* [45] */
		"",
		/* [46] */
		"",
		/* [47] */
		"",
		/* [48] */
		"",
		/* [49] */
		"",
		/* [50] */
		"",
		/* [51] */
		"",
		/* [52] */
		"",
		/* [53] */
		"",
		/* [54] */
		"",
		/* [55] */
		"",
		/* [56] */
		"",
		/* [57] */
		"",
		/* [58] */
		"",
		/* [59] */
		"",
		/* [60] */
		"",
		/* [61] */
		"",
		/* [62] */
		"",
		/* [63] */
		"",
		/* [64] */
		"",
		/* [65] */
		"",
		/* [66] */
		"",
		/* [67] */
		"",
		/* [68] */
		"",
		/* [69] */
		"",
		/* [70] */
		"",
		/* [71] */
		"",
		/* [72] */
		"",
		/* [73] */
		"",
		/* [74] */
		"",
		/* [75] */
		"",
		/* [76] */
		"",
		/* [77] */
		"",
		/* [78] */
		"",
		/* [79] */
		"",
		/* [80] */
		"",
		/* [81] */
		"",
		/* [82] */
		"",
		/* [83] */
		"",
		/* [84] */
		"",
		/* [85] */
		"",
		/* [86] */
		"",
		/* [87] */
		"",
		/* [88] */
		"",
		/* [89] */
		"",
		/* [90] */
		"",
		/* [91] */
		"",
		/* [92] */
		"",
		/* [93] */
		"",
		/* [94] */
		"",
		/* [95] */
		"",
		/* [96] */
		"",
		/* [97] */
		"",
		/* [98] */
		"",
		/* [99] */
		"",
		/* [100] */
		"",
		/* [101] */
		"",
		/* [102] */
		"",
		/* [103] */
		"",
		/* [104] */
		"",
		/* [105] */
		"",
		/* [106] */
		"",
		/* [107] */
		"",
		/* [108] */
		"",
		/* [109] */
		"",
		/* [110] */
		"",
		/* [111] */
		"",
		/* [112] */
		"",
		/* [113] */
		"",
		/* [114] */
		"",
		/* [115] */
		"",
		/* [116] */
		"",
		/* [117] */
		"",
		/* [118] */
		"",
		/* [119] */
		"",
		/* [120] */
		"",
		/* [121] */
		"",
		/* [122] */
		"",
		/* [123] */
		"",
		/* [124] */
		"",
		/* [125] */
		"",
		/* [126] */
		"",
		/* [127] */
		"",
		/* [128] */
		"",
		/* [129] */
		"",
		/* [130] */
		"",
		/* [131] */
		"",
		/* [132] */
		"",
		/* [133] */
		"",
		/* [134] */
		"",
		/* [135] */
		"",
		/* [136] */
		"",
		/* [137] */
		"",
		/* [138] */
		"",
		/* [139] */
		"",
		/* [140] */
		"",
		/* [141] */
		"",
		/* [142] */
		"",
		/* [143] */
		"",
		/* [144] */
		"",
		/* [145] */
		"",
		/* [146] */
		"",
		/* [147] */
		"",
		/* [148] */
		"",
		/* [149] */
		"",
		/* [150] */
		"",
		/* [151] */
		"",
		/* [152] */
		"",
		/* [153] */
		"",
		/* [154] */
		"",
		/* [155] */
		"",
		/* [156] */
		"",
		/* [157] */
		"",
		/* [158] */
		"",
		/* [159] */
		"",
		/* [160] */
		"",
		/* [161] */
		"",
		/* [162] */
		"",
		/* [163] */
		"",
		/* [164] */
		"",
		/* [165] */
		"",
		/* [166] */
		"",
		/* [167] */
		"",
		/* [168] */
		"",
		/* [169] */
		"",
		/* [170] */
		"",
		/* [171] */
		"",
		/* [172] */
		"",
		/* [173] */
		"",
		/* [174] */
		"",
		/* [175] */
		"",
		/* [176] */
		"",
		/* [177] */
		"",
		/* [178] */
		"",
		/* [179] */
		"",
		/* [180] */
		"",
		/* [181] */
		"",
		/* [182] */
		"",
		/* [183] */
		"",
		/* [184] */
		"",
		/* [185] */
		"",
		/* [186] */
		"",
		/* [187] */
		"",
		/* [188] */
		"",
		/* [189] */
		"",
		/* [190] */
		"",
		/* [191] */
		"",
		/* [192] */
		"",
		/* [193] */
		"",
		/* [194] */
		"",
		/* [195] */
		"",
		/* [196] */
		"",
		/* [197] */
		"",
		/* [198] */
		"",
		/* [199] */
		"",
		/* [200] */
		"",
		/* [201] */
		"",
		/* [202] */
		"",
		/* [203] */
		"",
		/* [204] */
		"",
		/* [205] */
		"",
		/* [206] */
		"",
		/* [207] */
		"",
		/* [208] */
		"",
		/* [209] */
		"",
		/* [210] */
		"",
		/* [211] */
		"",
		/* [212] */
		"",
		/* [213] */
		"",
		/* [214] */
		"",
		/* [215] */
		"",
		/* [216] */
		"",
		/* [217] */
		"",
		/* [218] */
		"",
		/* [219] */
		"",
		/* [220] */
		"",
		/* [221] */
		"",
		/* [222] */
		"",
		/* [223] */
		"",
		/* [224] */
		"",
		/* [225] */
		"",
		/* [226] */
		"",
		/* [227] */
		"",
		/* [228] */
		"",
		/* [229] */
		"",
		/* [230] */
		"",
		/* [231] */
		"",
		/* [232] */
		"",
		/* [233] */
		"",
		/* [234] */
		"",
		/* [235] */
		"",
		/* [236] */
		"",
		/* [237] */
		"",
		/* [238] */
		"",
		/* [239] */
		"",
		/* [240] */
		"",
		/* [241] */
		"",
		/* [242] */
		"",
		/* [243] */
		"",
		/* [244] */
		"",
		/* [245] */
		"",
		/* [246] */
		"",
		/* [247] */
		"",
		/* [248] */
		"",
		/* [249] */
		"",
		/* [250] */
		"",
		/* [251] */
		"",
		/* [252] */
		"",
		/* [253] */
		"",
		/* [254] */
		"",
		/* [255] */
		"",
		/* [256] */
		"",
		/* [257] */
		"",
		/* [258] */
		"",
		/* [259] */
		"",
		/* [260] */
		"",
		/* [261] */
		"",
		/* [262] */
		"",
		/* [263] */
		"",
		/* [264] */
		"",
		/* [265] */
		"",
		/* [266] */
		"",
		/* [267] */
		"",
		/* [268] */
		"",
		/* [269] */
		"",
		/* [270] */
		"",
		/* [271] */
		"",
		/* [272] */
		"",
		/* [273] */
		"",
		/* [274] */
		"",
		/* [275] */
		"",
		/* [276] */
		"",
		/* [277] */
		"",
		/* [278] */
		"",
		/* [279] */
		"",
		/* [280] */
		"",
		/* [281] */
		"",
		/* [282] */
		"",
		/* [283] */
		"",
		/* [284] */
		"",
		/* [285] */
		"",
		/* [286] */
		"",
		/* [287] */
		"",
		/* [288] */
		"",
		/* [289] */
		"",
		/* [290] */
		"",
		/* [291] */
		"",
		/* [292] */
		"",
		/* [293] */
		"",
		/* [294] */
		"",
		/* [295] */
		"",
		/* [296] */
		"",
		/* [297] */
		"",
		/* [298] */
		"",
		/* [299] */
		"",
		/* [300] */
		""
	}
};

data 'TMPL' (128, "PRFN") {
	$"0044 4C4E 4700 444C 4E47 0044 4C4E 4700"            /* .DLNG.DLNG.DLNG. */
	$"444C 4E47 0044 4C4E 4700 444C 4E47 0044"            /* DLNG.DLNG.DLNG.D */
	$"4C4E 4700 444C 4E47 0044 4C4E 4700 444C"            /* LNG.DLNG.DLNG.DL */
	$"4E47"                                               /* NG */
};

resource 'vers' (2) {
	0x1,
	0x10,
	release,
	0x0,
	0,
	"1.1",
	"1.1 Blades of Avernum Editor\n©2004, Spid"
	"erweb Software, Inc."
};

data 'WIND' (128) {
	$"FFFA FFFA 0220 02B6 0004 0100 0100 0000"            /* ÿúÿú. .¶........ */
	$"0000 1745 7869 6C65 2049 4949 3A20 5275"            /* ...Exile III: Ru */
	$"696E 6564 2057 6F72 6C64"                           /* ined World */
};

resource 'WIND' (900) {
	{57, 63, 346, 494},
	noGrowDocProc,
	visible,
	noGoAway,
	0x0,
	"Bob Land",
	centerMainScreen
};

resource 'xmnu' (570) {
	versionZero {
		{	/* array ItemExtensions: 22 elements */
			/* [1] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [2] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [3] */
			skipItem {

			},
			/* [4] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [5] */
			dataItem {
				0,
				0x1,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [6] */
			dataItem {
				0,
				0x2,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [7] */
			dataItem {
				0,
				0x4,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [8] */
			skipItem {

			},
			/* [9] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [10] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [11] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [12] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [13] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [14] */
			skipItem {

			},
			/* [15] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [16] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [17] */
			skipItem {

			},
			/* [18] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [19] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [20] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [21] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [22] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			}
		}
	}
};

resource 'xmnu' (600) {
	versionZero {
		{	/* array ItemExtensions: 22 elements */
			/* [1] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [2] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [3] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [4] */
			skipItem {

			},
			/* [5] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [6] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [7] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [8] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [9] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [10] */
			dataItem {
				0,
				0x2,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [11] */
			dataItem {
				0,
				0x3,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [12] */
			skipItem {

			},
			/* [13] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [14] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [15] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [16] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [17] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [18] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [19] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [20] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [21] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [22] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			}
		}
	}
};

resource 'xmnu' (650) {
	versionZero {
		{	/* array ItemExtensions: 21 elements */
			/* [1] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [2] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [3] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [4] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [5] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [6] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [7] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [8] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [9] */
			dataItem {
				0,
				0x1,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [10] */
			skipItem {

			},
			/* [11] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [12] */
			skipItem {

			},
			/* [13] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [14] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [15] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [16] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [17] */
			skipItem {

			},
			/* [18] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [19] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [20] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			},
			/* [21] */
			dataItem {
				0,
				0x0,
				currScript,
				0,
				0,
				noHierID,
				sysFont,
				naturalGlyph
			}
		}
	}
};

