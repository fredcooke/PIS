/*
	Copyright 2010 Jason Roughley

	This file is part of PIS firmware.

    PIS firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PIS firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PIS firmware.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "config.h"

struct _config __attribute__((section(".config"), aligned(2))) config =
{
	1,		// inject event skips
	2,		// cylinders
	TRUE,  // two stroke?

	// rpm bins
	{ 400, 800, 1000, 1200, 1500, 2000, 2500, 3000,
	  4000, 5000, 6000, 7000, 7500, 8000, 8500, 9000
	},

	// map idx bins kpa
	{
		20, 30, 40, 50, 60, 70, 80, 85,
		90, 95, 100, 150, 200, 250, 275, 300
	},

	// boost control
	{
	    10,	// boost hysterisis
	    {
			{ 101, 117, 133, 149, 165, 181, 197, 213, 229, 245 },
			{ 102, 118, 134, 150, 166, 182, 198, 214, 230, 246 },
			{ 103, 119, 135, 151, 167, 183, 199, 215, 231, 247 },
			{ 104, 120, 136, 152, 168, 184, 200, 216, 232, 248 },
			{ 105, 121, 137, 153, 169, 185, 201, 217, 233, 249 },
			{ 106, 122, 138, 154, 170, 186, 202, 218, 234, 250 },
			{ 107, 123, 139, 155, 171, 187, 203, 219, 235, 251 },
			{ 108, 124, 140, 156, 172, 188, 204, 220, 236, 252 },
			{ 109, 125, 141, 157, 173, 189, 205, 221, 237, 253 },
			{ 110, 126, 142, 158, 174, 190, 206, 222, 238, 254 },
			{ 111, 127, 143, 159, 175, 191, 207, 223, 239, 255 },
			{ 112, 128, 144, 160, 176, 192, 208, 224, 240, 256 },
			{ 113, 129, 145, 161, 177, 193, 209, 225, 241, 257 },
			{ 114, 130, 146, 162, 178, 194, 210, 226, 242, 258 },
			{ 115, 131, 147, 163, 179, 195, 211, 227, 243, 259 },
			{ 116, 132, 148, 164, 180, 196, 212, 228, 244, 260 }
	    }
	},

	400,	// cranking threshold

	// fuel cranking pulse widths ms * 66
	{//  -40,   0,  20,  40,  60,  80,  86,  90, 100, 110
		 10.00 * 66, 9.00 * 66, 8.00 * 66, 7.00 * 66, 6.00 * 66, 5.00 * 66, 4.00 * 66, 3.00 * 66, 2.00 * 66, 1.00 * 66
	},

	// CTS
	{
	    // CTS idx bins (kelvin)
	    {
			273 - 40,
			273 + 0,
			273 + 20,
			273 + 40,
			273 + 60,
			273 + 80,
			273 + 86,
			273 + 90,
			273 + 100,
			273 + 110
	    },

	    // CTS adjustment %000.00 x 327.768 vs CTS
	    {
	        130.00 * 327.68,	// -40
	        125.00 * 327.68,	// 0
	        120.00 * 327.68,	// 20
	        115.00 * 327.68,	// 40
	        110.00 * 327.68,	// 60
	        105.00 * 327.68,	// 80
	        100.00 * 327.68,	// 86
	        100.00 * 327.68,	// 90
	        100.00 * 327.68,	// 100
	        95.00 * 327.68		// 110
	    },

	    // CTS ignition +advance / -retard degrees x 2.8444 vs CTS
	    {
	    	4.0 * 2.8444,	// -40
	    	3.0 * 2.8444,	// 0
	    	2.0 * 2.8444,	// 20
	    	1.0 * 2.8444,	// 40
	    	0.0 * 2.8444,	// 60
	    	0.0 * 2.8444,	// 80
	    	0.0 * 2.8444,	// 86
	    	0.0 * 2.8444,	// 90
	    	0.0 * 2.8444,	// 100
	    	-3.0 * 2.8444	// 110
	    },

	    // CTS ADC -> kelvins
	    {
	    	475, 475, 441, 423, 411, 402, 395, 389, 384, 380, 376, 373, 370, 367, 364, 362,
	    	360, 358, 356, 354, 352, 351, 349, 348, 347, 345, 344, 343, 342, 340, 339, 338,
	    	337, 336, 335, 335, 334, 333, 332, 331, 330, 330, 329, 328, 327, 327, 326, 325,
	    	325, 324, 323, 323, 322, 321, 321, 320, 320, 319, 318, 318, 317, 317, 316, 316,
	    	315, 315, 314, 314, 313, 313, 312, 312, 311, 311, 310, 310, 310, 309, 309, 308,
	    	308, 307, 307, 307, 306, 306, 305, 305, 305, 304, 304, 303, 303, 303, 302, 302,
	    	301, 301, 301, 300, 300, 300, 299, 299, 298, 298, 298, 297, 297, 297, 296, 296,
	    	296, 295, 295, 295, 294, 294, 294, 293, 293, 293, 292, 292, 292, 291, 291, 291,
	    	290, 290, 290, 289, 289, 289, 288, 288, 288, 287, 287, 287, 286, 286, 286, 285,
	    	285, 285, 284, 284, 284, 283, 283, 283, 282, 282, 282, 281, 281, 281, 280, 280,
	    	280, 279, 279, 279, 278, 278, 278, 277, 277, 277, 276, 276, 276, 275, 275, 275,
	    	274, 274, 274, 273, 273, 273, 272, 272, 272, 271, 271, 270, 270, 270, 269, 269,
	    	268, 268, 268, 267, 267, 267, 266, 266, 265, 265, 264, 264, 264, 263, 263, 262,
	    	262, 261, 261, 260, 260, 259, 259, 258, 258, 257, 257, 256, 256, 255, 255, 254,
	    	253, 253, 252, 252, 251, 250, 249, 249, 248, 247, 246, 246, 245, 244, 243, 242,
	    	241, 240, 238, 237, 236, 234, 233, 231, 229, 227, 224, 221, 218, 212, 204, 204
	    },
	    273 + 92,	// fan on @ 92c
	    273 + 86	// fan off @ 86c
	},

	// MAT
	{
	    // MAT idx bins (kelvin)
	    {
			273 - 40,
			273 + 0,
			273 + 20,
			273 + 40,
			273 + 60,
			273 + 70,
			273 + 80,
			273 + 90,
			273 + 100,
			273 + 110
	    },

	    // MAT adjustment %000.00 x 327.768 vs MAT
	    {
	        110.00 * 327.68,	// -40
	        108.00 * 327.68,	// 0
	        104.00 * 327.68,	// 20
	        102.00 * 327.68,	// 40
	        100.00 * 327.68,	// 60
	        100.00 * 327.68,	// 70
	        98.00 * 327.68,		// 80
	        96.00 * 327.68,		// 90
	        94.00 * 327.68,		// 100
	        92.00 * 327.68		// 110
	    },

		// MAT ignition +advance / -retard degrees x 2.8444 vs MAT
		{
		    4.0 * 2.8444,	// -40
		    3.0 * 2.8444,	// 0
		    2.0 * 2.8444,	// 20
		    1.0 * 2.8444,	// 40
		    0.0 * 2.8444,	// 60
		    0.0 * 2.8444,	// 70
		    -1.0 * 2.8444,	// 80
		    -3.0 * 2.8444,	// 90
		    -4.0 * 2.8444,	// 100
		    -5.0 * 2.8444	// 110
		},

		// MAT ADC -> kelvins
		{
		    484, 484, 447, 427, 414, 405, 397, 391, 386, 381, 378, 374, 371, 368, 365, 363,
		    361, 359, 357, 355, 353, 351, 350, 348, 347, 346, 344, 343, 342, 341, 340, 338,
		    337, 336, 335, 335, 334, 333, 332, 331, 330, 329, 329, 328, 327, 326, 326, 325,
		    324, 324, 323, 322, 322, 321, 320, 320, 319, 319, 318, 317, 317, 316, 316, 315,
		    315, 314, 314, 313, 313, 312, 312, 311, 311, 310, 310, 309, 309, 309, 308, 308,
		    307, 307, 306, 306, 306, 305, 305, 304, 304, 303, 303, 303, 302, 302, 302, 301,
		    301, 300, 300, 300, 299, 299, 299, 298, 298, 297, 297, 297, 296, 296, 296, 295,
		    295, 295, 294, 294, 294, 293, 293, 293, 292, 292, 292, 291, 291, 290, 290, 290,
		    289, 289, 289, 289, 288, 288, 288, 287, 287, 287, 286, 286, 286, 285, 285, 285,
		    284, 284, 284, 283, 283, 283, 282, 282, 282, 281, 281, 281, 280, 280, 280, 279,
		    279, 279, 278, 278, 278, 277, 277, 277, 276, 276, 276, 275, 275, 275, 274, 274,
		    274, 273, 273, 273, 272, 272, 271, 271, 271, 270, 270, 270, 269, 269, 269, 268,
		    268, 267, 267, 267, 266, 266, 265, 265, 265, 264, 264, 263, 263, 262, 262, 262,
		    261, 261, 260, 260, 259, 259, 258, 258, 257, 257, 256, 256, 255, 255, 254, 253,
		    253, 252, 252, 251, 250, 250, 249, 248, 248, 247, 246, 245, 244, 243, 243, 242,
		    241, 239, 238, 237, 236, 234, 233, 231, 229, 227, 225, 222, 218, 213, 205, 205
		}
	},

	// after start adjustment
	{
		// asc fuel correction %000.00 x 327.768
		{
		    111.00 * 327.68,	// -40
		    110.00 * 327.68,	// 0
		    120.00 * 327.68,	// 20
		    115.00 * 327.68,	// 40
		    110.00 * 327.68,	// 60
		    105.00 * 327.68,	// 80
		    102.00 * 327.68,	// 86
		    102.00 * 327.68,	// 90
		    98.00 * 327.68,		// 100
		    95.00 * 327.68		// 110
		},

		// duration in # injections
		{//  -40,  0, 20, 40, 60, 80, 86, 90, 100, 110
		    500, 400, 300, 200, 150, 125, 50, 25,  25, 50
		}
	},

	//  base pulse widths ms / 66 (open loop before ANY % corrections)
	{
		{ 0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240 },
		{ 1, 17, 33, 49, 65, 81, 97, 113, 129, 145, 161, 177, 193, 209, 225, 241 },
		{ 2, 18, 34, 50, 66, 82, 98, 114, 130, 146, 162, 178, 194, 210, 226, 242 },
		{ 3, 19, 35, 51, 67, 83, 99, 115, 131, 147, 163, 179, 195, 211, 227, 243 },
		{ 4, 20, 36, 52, 68, 84, 100, 116, 132, 148, 164, 180, 196, 212, 228, 244 },
		{ 5, 21, 37, 53, 69, 85, 101, 117, 133, 149, 165, 181, 197, 213, 229, 245 },
		{ 6, 22, 38, 54, 70, 86, 102, 118, 134, 150, 166, 182, 198, 214, 230, 246 },
		{ 7, 23, 39, 55, 71, 87, 103, 119, 135, 151, 167, 183, 199, 215, 231, 247 },
		{ 8, 24, 40, 56, 72, 88, 104, 120, 136, 152, 168, 184, 200, 216, 232, 248 },
		{ 9, 25, 41, 57, 73, 89, 105, 121, 137, 153, 169, 185, 201, 217, 233, 249 },
		{ 10, 26, 42, 58, 74, 90, 106, 122, 138, 154, 170, 186, 202, 218, 234, 250 },
		{ 11, 27, 43, 59, 75, 91, 107, 123, 139, 155, 171, 187, 203, 219, 235, 251 },
		{ 12, 28, 44, 60, 76, 92, 108, 124, 140, 156, 172, 188, 204, 220, 236, 252 },
		{ 13, 29, 45, 61, 77, 93, 109, 125, 141, 157, 173, 189, 205, 221, 237, 253 },
		{ 14, 30, 46, 62, 78, 94, 110, 126, 142, 158, 174, 190, 206, 222, 238, 254 },
		{ 15, 31, 47, 63, 79, 95, 111, 127, 143, 159, 175, 191, 207, 223, 239, 255 }
	},

	// injector open time & compensation
	{
		5.0 * 66,	// 0V
		4.0 * 66,	// 3.2V
		2.00 * 66,	// 6.4V
		1.20 * 66,	// 9.6V
		1.00 * 66,	// 12.8V
		.80 * 66,	// 16.0
		.69 * 66,	// 19.2
		.40 * 66,	// 22.4
		.20 * 66	// 25.5
	},

	{
		// ignition reference angle +advance / -retard * 2.8444
		10 * 2.8444,
		// crank
		{
			TRUE, 		// ignition bypass during cranking
			6.0 * 66	// cranking coil dwell
		},

		// run time
		{
			// dwell vs volts
			{
				5.00 * 66,	// 0V
				4.00 * 66,	// 3.2V
				3.00 * 66,	// 6.4V
				3.20 * 66,	// 9.6V
				3.00 * 66,	// 12.8V
				2.80 * 66,	// 16.0
				2.69 * 66,	// 19.2
				2.40 * 66,	// 22.4
				2.20 * 66	// 25.5
			},
			2.0 * 66,	// min dwell
			4.5 * 66	// max dwell
		},

		// min ignition timing +advance / -retard * 2.8444
		-10 * 2.8444,

		// max ignition timing +advance / -retard * 2.8444
		40 * 2.8444,

		// base ignition +advance / -retard degrees x 2.8444
		{
			{ 0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240 },
			{ 1, 17, 33, 49, 65, 81, 97, 113, 129, 145, 161, 177, 193, 209, 225, 241 },
			{ 2, 18, 34, 50, 66, 82, 98, 114, 130, 146, 162, 178, 194, 210, 226, 242 },
			{ 3, 19, 35, 51, 67, 83, 99, 115, 131, 147, 163, 179, 195, 211, 227, 243 },
			{ 4, 20, 36, 52, 68, 84, 100, 116, 132, 148, 164, 180, 196, 212, 228, 244 },
			{ 5, 21, 37, 53, 69, 85, 101, 117, 133, 149, 165, 181, 197, 213, 229, 245 },
			{ 6, 22, 38, 54, 70, 86, 102, 118, 134, 150, 166, 182, 198, 214, 230, 246 },
			{ 7, 23, 39, 55, 71, 87, 103, 119, 135, 151, 167, 183, 199, 215, 231, 247 },
			{ 8, 24, 40, 56, 72, 88, 104, 120, 136, 152, 168, 184, 200, 216, 232, 248 },
			{ 9, 25, 41, 57, 73, 89, 105, 121, 137, 153, 169, 185, 201, 217, 233, 249 },
			{ 10, 26, 42, 58, 74, 90, 106, 122, 138, 154, 170, 186, 202, 218, 234, 250 },
			{ 11, 27, 43, 59, 75, 91, 107, 123, 139, 155, 171, 187, 203, 219, 235, 251 },
			{ 12, 28, 44, 60, 76, 92, 108, 124, 140, 156, 172, 188, 204, 220, 236, 252 },
			{ 13, 29, 45, 61, 77, 93, 109, 125, 141, 157, 173, 189, 205, 221, 237, 253 },
			{ 14, 30, 46, 62, 78, 94, 110, 126, 142, 158, 174, 190, 206, 222, 238, 254 },
			{ 15, 31, 47, 63, 79, 95, 111, 127, 143, 159, 175, 191, 207, 223, 239, 255 }
		}
	},

	// TPS
	{
		0,		// tps ADC @ 0%
		245,	// tps ADC @ 100%
		900,	// tps flood clear

		// tps x 10 idx % bins
		{
			10.0 * 10,
			20.0 * 10,
			30.0 * 10,
			40.0 * 10,
			50.0 * 10,
			60.0 * 10,
			70.0 * 10,
			80.0 * 10,
			90.0 * 10,
			100.0 * 10
		}
	},

	// MAP
	{
		6,		// kpa @ 0V
		304,	// kpa @ 5V (3 bar map sensor)
	},

	// iac stepper control
	{
		TRUE,		// iac enabled
		196,		// iac step range
		5, 			// 5ms IAC update rate

		// iac cts idx bins
		{
			273 - 40,
			273 + 0,
			273 + 40,
			273 + 80
		},

		// idle target rpm	vs cts
		{
			1200,
			1000,
			900,
			800
		},

		// engine crank pos vs cts
	    {
	    	150,
	    	100,
	    	70,
	    	80
	    },

		// start position when entering idle control
		{
			70,
			65,
			55,
			55
		},

		120,	// 100% tps IAC step position

		// minimum position
		{
			55,
			50,
			45,
			45
		},

		25, 		// +- idle hysteris
		25, 		// max rpm roc before entering idle control
		.5 * 10,	// max tps x10 for idle control .5%
		2			// delay before entering closed loop idle
	},

	// rpm limiter
	{
		// rpm limits vs CTS
		{// -40,     0,   20,   40,   60,   80,   86,   90,  100,  110
		    3000, 4000, 4500, 5000, 7000, 9000, 9000, 9000, 9000, 9000
		},

		100, 			// hard limit (fuel cut) hysterisis
		200,			// soft limit offset (ignition retard) from hard limit
		0 * 2.8444, 	// timing change @ soft limit degrees * 2.8444
		-10 * 2.8444,	// timing change @ hard limit degrees * 2.8444
	},

	// ego
	{
		TRUE,			// enabled
		100,			// ms update rate (LM2 updates about 12/sec)
		0,				// min rpm
		16384,			// max rpm
		0,				// min tps
		1000,			// max tps
		0,				// min map
		300,			// max map
		0,				// min up time (allows wideband warmup)
		273 + 80,		// min CTS kelvin
		80 * 327.68,	// min % correction
		120 * 327.68,	// max % correction
		2,				// transient delay

		// we are calculating the % change each ADC count makes thus later we can multiply the adc error by this value to get a new % of BPW
		(327.68 * .5 / 129) * 90.00,	// 90% proportional
		(327.68 * .5 / 129) * 10.00,	// integral

		// ego ADC targets
		{
			{ 0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240 },
			{ 1, 17, 33, 49, 65, 81, 97, 113, 129, 145, 161, 177, 193, 209, 225, 241 },
			{ 2, 18, 34, 50, 66, 82, 98, 114, 130, 146, 162, 178, 194, 210, 226, 242 },
			{ 3, 19, 35, 51, 67, 83, 99, 115, 131, 147, 163, 179, 195, 211, 227, 243 },
			{ 4, 20, 36, 52, 68, 84, 100, 116, 132, 148, 164, 180, 196, 212, 228, 244 },
			{ 5, 21, 37, 53, 69, 85, 101, 117, 133, 149, 165, 181, 197, 213, 229, 245 },
			{ 6, 22, 38, 54, 70, 86, 102, 118, 134, 150, 166, 182, 198, 214, 230, 246 },
			{ 7, 23, 39, 55, 71, 87, 103, 119, 135, 151, 167, 183, 199, 215, 231, 247 },
			{ 8, 24, 40, 56, 72, 88, 104, 120, 136, 152, 168, 184, 200, 216, 232, 248 },
			{ 9, 25, 41, 57, 73, 89, 105, 121, 137, 153, 169, 185, 201, 217, 233, 249 },
			{ 10, 26, 42, 58, 74, 90, 106, 122, 138, 154, 170, 186, 202, 218, 234, 250 },
			{ 11, 27, 43, 59, 75, 91, 107, 123, 139, 155, 171, 187, 203, 219, 235, 251 },
			{ 12, 28, 44, 60, 76, 92, 108, 124, 140, 156, 172, 188, 204, 220, 236, 252 },
			{ 13, 29, 45, 61, 77, 93, 109, 125, 141, 157, 173, 189, 205, 221, 237, 253 },
			{ 14, 30, 46, 62, 78, 94, 110, 126, 142, 158, 174, 190, 206, 222, 238, 254 },
			{ 15, 31, 47, 63, 79, 95, 111, 127, 143, 159, 175, 191, 207, 223, 239, 255 }
		}
	},
	// acceleration enrichment BPW(rpm, tps) * ROC_FACTOR * CTS_FACTOR
	{
		// how many times to inject the acceleration pulse width
		12,

		// tps
		{
			2.0 * 10,			// tps roc threshold WOT in 2.5 seconds

			// tps x 10 idx bins
			{
				0.0 * 10, 10.0 * 10, 25.0 * 10, 50.0 * 10
			}
		},

		// rpm idx bins
		{
			1000, 2000, 3000, 4000
		},

		// roc/100ms % vs PW
		{
			// roc % / 50ms idx bins
			{
				2.5 * 10, 5.0 * 10, 10 * 10, 50.0 * 10
			},

			{	// roc %000.00 vs PW
				60.00 * 327.68, 75.00 * 327.68, 90.00 * 327.68, 100.00 * 327.68
			},
		},

		// CTS adjustment %000.00 x 327.768 vs CTS
		{
		    150.00 * 327.68,	// -40
		    135.00 * 327.68,	// 0
		    120.00 * 327.68,	// 20
		    115.00 * 327.68,	// 40
		    110.00 * 327.68,	// 60
		    105.00 * 327.68,	// 80
		    100.00 * 327.68,	// 86
		    100.00 * 327.68,	// 90
		    100.00 * 327.68,	// 100
		    95.00 * 327.68		// 110
		},

		// (rpm vs tps) PW
		{
			{ 5.00 * 66, 5.00 * 66, 2.00 * 66, 0.00 * 66 },
			{ 5.00 * 66, 5.00 * 66, 2.00 * 66, 0.00 * 66 },
			{ 3.50 * 66, 3.50 * 66, 2.00 * 66, 0.00 * 66 },
			{ 2.00 * 66, 2.00 * 66, 2.00 * 66, 0.00 * 66 }
		}
	},

	// alpha-N
	{
		0,		// rpm below this is pure alpha-N
		0,		// rpm above this is pure MAP
		{
			{ 0, 16, 32, 48, 64, 80, 96, 112, 128, 144 },
			{ 1, 17, 33, 49, 65, 81, 97, 113, 129, 145 },
			{ 2, 18, 34, 50, 66, 82, 98, 114, 130, 146 },
			{ 3, 19, 35, 51, 67, 83, 99, 115, 131, 147 },
			{ 4, 20, 36, 52, 68, 84, 100, 116, 132, 148 },
			{ 5, 21, 37, 53, 69, 85, 101, 117, 133, 149 },
			{ 6, 22, 38, 54, 70, 86, 102, 118, 134, 150 },
			{ 7, 23, 39, 55, 71, 87, 103, 119, 135, 151 },
			{ 8, 24, 40, 56, 72, 88, 104, 120, 136, 152 },
			{ 9, 25, 41, 57, 73, 89, 105, 121, 137, 153 },
			{ 10, 26, 42, 58, 74, 90, 106, 122, 138, 154 },
			{ 11, 27, 43, 59, 75, 91, 107, 123, 139, 155 },
			{ 12, 28, 44, 60, 76, 92, 108, 124, 140, 156 },
			{ 13, 29, 45, 61, 77, 93, 109, 125, 141, 157 },
			{ 14, 30, 46, 62, 78, 94, 110, 126, 142, 158 },
			{ 15, 31, 47, 63, 79, 95, 111, 127, 143, 159 }
		},
		{
			{ 0, 16, 32, 48, 64, 80, 96, 112, 128, 144 },
			{ 1, 17, 33, 49, 65, 81, 97, 113, 129, 145 },
			{ 2, 18, 34, 50, 66, 82, 98, 114, 130, 146 },
			{ 3, 19, 35, 51, 67, 83, 99, 115, 131, 147 },
			{ 4, 20, 36, 52, 68, 84, 100, 116, 132, 148 },
			{ 5, 21, 37, 53, 69, 85, 101, 117, 133, 149 },
			{ 6, 22, 38, 54, 70, 86, 102, 118, 134, 150 },
			{ 7, 23, 39, 55, 71, 87, 103, 119, 135, 151 },
			{ 8, 24, 40, 56, 72, 88, 104, 120, 136, 152 },
			{ 9, 25, 41, 57, 73, 89, 105, 121, 137, 153 },
			{ 10, 26, 42, 58, 74, 90, 106, 122, 138, 154 },
			{ 11, 27, 43, 59, 75, 91, 107, 123, 139, 155 },
			{ 12, 28, 44, 60, 76, 92, 108, 124, 140, 156 },
			{ 13, 29, 45, 61, 77, 93, 109, 125, 141, 157 },
			{ 14, 30, 46, 62, 78, 94, 110, 126, 142, 158 },
			{ 15, 31, 47, 63, 79, 95, 111, 127, 143, 159 }
		}
	}
};
