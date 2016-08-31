/*!
	@file      System.h
	@brief     Management class of basis about AVR MCU.
	@author    Kazuyuki TAKASE
	@copyright The MIT License - http://opensource.org/licenses/mit-license.php
*/

#pragma once

#ifndef PLEN2_SYSTEM_H
#define PLEN2_SYSTEM_H


class Stream;

#define DEVICE_NAME ("PLEN2")

#define CODE_NAME   ("Cytisus")

#define VERSION     ("1.3.1")

#define CLOCK_WISE false
#define CHECK_BATTERY true

#define DEBUG       (false)
#define DEBUG_LESS  (true)
#define DEBUG_HARD  (false)


namespace PLEN2
{
	class System;
}

/*!
	@brief Management class of basis about AVR MCU
*/
class PLEN2::System
{
private:
	
	//! @brief Communication speed of USB serial
	inline static const long SERIAL_BAUDRATE() { return 115200L; }

public:
	/*!
		@brief Constructor
	*/
	System();

	/*!
		@brief Get USB-serial instance

		@return Reference of USB-serial instance
	*/
	static Stream& SystemSerial();

	/*!
		@brief Get input-serial instance

		@return Reference of input-serial instance
	*/
	static Stream& inputSerial();

	/*!
		@brief Get output-serial instance
		
		@return Reference of output-serial instance
	*/
	static Stream& outputSerial();

	/*!
		@brief Get debug-serial instance
		
		@return Reference of debug-serial instance
	*/
	static Stream& debugSerial();

	/*!
		@brief Dump information of the system

		Outputs result like JSON format below.
		@code
		{
			"device": <string>,
			"codename": <string>,
			"version": <string>
		}
		@endcode
	*/
	static bool tcp_available();

    static char tcp_read();

    static bool tcp_connected();

	static void setup_smartconfig();

	static void smart_config();

	static void StartAp();
	
	static void dump();

    static void handleClient();
};

#endif // PLEN2_SYSTEM_H
