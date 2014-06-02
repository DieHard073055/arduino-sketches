
//////////////////////////////////////////////////////////////////////////////////////////////////////
// UNO_20_Servos_Controller.ino - High definition (15 bit), low jitter, 20 servo software for Atmega328P and Arduino UNO. Version 1.
// Jitter is typical 200-400 ns. 32000 steps resolution for 0-180 degrees. In 18 servos mode it can receive serial servo-move commands.
//
// Copyright (c) 2013 Arvid Mortensen.  All right reserved. 
// http://www.lamja.com
// 
// This software is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                              !!!!!!!!!!!!!!!!!!!
// This software will only work with ATMEGA328P (Arduino UNO and compatible. Or that is what I have tested it with anyways....  !!!!
//                              !!!!!!!!!!!!!!!!!!!
// How it works:
// 18 or 20 pins are used for the servos. These pins are all pre configured.
// All 18/20 servos are always active and updated. To change the servo position, change the
// values in the ServoPW[] array, use the serial commands (int 18 servos mode only) or use 
// ServoMove() function. The range of the ServoPW is 8320 to 39680. 8320=520us. 39680=2480us.
//
// Some formulas:
// micro second = ServoPW value / 16
// angle = (ServoPW value - 8000) / 177.77  (or there about)
// ServoPW value = angle * 177.77 + 8000
// ServoPW value = micro second * 16
//
