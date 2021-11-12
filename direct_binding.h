/******************************************************************************
 * Copyright (c) 2012-2017 All Rights Reserved, http://www.evocortex.com      *
 *  Evocortex GmbH                                                            *
 *  Emilienstr. 1                                                             *
 *  90489 Nuremberg                                                           *
 *  Germany                                                                   *
 *                                                                            *
 * Contributors:                                                              *
 *  Initial version for Linux 64-Bit platform supported by Fraunhofer IPA,    *
 *  http://www.ipa.fraunhofer.de                                              *
 *****************************************************************************/

/*! @file direct_binding.h
 * @brief Provides Easy API C-Library Interface
 *
 * This header defines the function of the Easy API, which can be also used 
 * from other programming languages supporting C-Library calls like 
 * LabView, Matlab, Python etc.
 */

#ifndef DIRECT_BINDING_H_
#define DIRECT_BINDING_H_

#include "irdirectsdk_defs.h"
#include "EvoIRFrameMetadata.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes an IRImager instance connected to this computer via USB
 * @param[in] xml_config path to xml config
 * @param[in] formats_def path to Formats.def file. Set zero for standard value.
 * @param[in] log_file path to log file. Set zero for standard value.
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_usb_init(const char* xml_config, const char* formats_def, const char* log_file);

/**
 * @brief Initializes an IRImager instance connected to this computer via USB for multiple cameras
 * @param[out] camera instance id for reference
 * @param[in] xml_config path to xml config
 * @param[in] formats_def path to Formats.def file. Set zero for standard value.
 * @param[in] log_file path to log file. Set zero for standard value.
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_usb_init(unsigned int* outCamId, const char* xml_config, const char* formats_def, const char* log_file);

/**
 * @brief Initializes the TCP connection to the daemon process (non-blocking)
 * @param[in] IP address of the machine where the daemon process is running ("localhost" can be resolved)
 * @param port Port of daemon, default 1337
 * @return  error code: 0 on success, -1 on host not found (wrong IP, daemon not running), -2 on fatal error
 */
__IRDIRECTSDK_API__ int evo_irimager_tcp_init(const char* ip, int port);


/**
 * @brief Initializes the TCP connection to the daemon process (non-blocking) for multiple cameras
 * @param[out] camera instance id for reference
 * @param[in] IP address of the machine where the daemon process is running ("localhost" can be resolved)
 * @param port Port of daemon, default 1337
 * @return  error code: 0 on success, -1 on host not found (wrong IP, daemon not running), -2 on fatal error
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_tcp_init(unsigned int* outCamId, const char* ip, int port);

/**
 * @brief Disconnects the camera, either connected via USB or TCP
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_terminate();

/**
 * @brief Disconnects the camera, either connected via USB or TCP for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_terminate(const unsigned int camId);

/**
 * @brief Get the serial number of the connected camera
 * @param[out] serial number of camera
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_get_serial(unsigned long *serial);

/**
 * @brief Get the serial number of the connected camera for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[out] serial number of camera
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_serial(const unsigned int camId, unsigned long *serial);

/**
 * @brief Accessor to image width and height
 * @param[out] w width
 * @param[out] h height
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_get_thermal_image_size(int* w, int* h);

/**
 * @brief Accessor to image width and height for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[out] w width
 * @param[out] h height
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_thermal_image_size(const unsigned int camId,  int* w, int* h);

/**
 * @brief Accessor to width and height of false color coded palette image
 * @param[out] w width
 * @param[out] h height
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_get_palette_image_size(int* w, int* h);

/**
 * @brief Accessor to width and height of false color coded palette image for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[out] w width
 * @param[out] h height
 * @return 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_palette_image_size(const unsigned int camId, int* w, int* h);

/**
 * @brief Accessor to thermal image by reference
 * Conversion to temperature values are to be performed as follows:
 * t = ((double)data[x] - 1000.0) / 10.0;
 * @param[in] w image width
 * @param[in] h image height
 * @param[out] data pointer to unsigned short array allocate by the user (size of w * h)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_get_thermal_image(int* w, int* h, unsigned short* data);

/**
 * @brief Accessor to thermal image by reference for multiple cameras
 * Conversion to temperature values are to be performed as follows:
 * t = ((double)data[x] - 1000.0) / 10.0;
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] w image width
 * @param[in] h image height
 * @param[out] data pointer to unsigned short array allocate by the user (size of w * h)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_thermal_image(const unsigned int camId, int* w, int* h, unsigned short* data);

/**
 * @brief Accessor to thermal image and frame metadata by reference
 * Conversion to temperature values are to be performed as follows:
 * t = ((double)data[x] - 1000.0) / 10.0;
 * @param[in] w image width
 * @param[in] h image height
 * @param[out] data pointer to unsigned short array allocate by the user (size of w * h)
 * @param[out] metadata pointer to EvoIRFrameMetadata allocate by the user
 * @return error code: 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_get_thermal_image_metadata(int* w, int* h, unsigned short* data, EvoIRFrameMetadata* metadata);

/**
 * @brief Accessor to thermal image and frame metadata by reference for multiple cameras
 * Conversion to temperature values are to be performed as follows:
 * t = ((double)data[x] - 1000.0) / 10.0;
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] w image width
 * @param[in] h image height
 * @param[out] data pointer to unsigned short array allocate by the user (size of w * h)
 * @param[out] metadata pointer to EvoIRFrameMetadata allocate by the user
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_thermal_image_metadata(const unsigned int camId, int* w, int* h, unsigned short* data, EvoIRFrameMetadata* metadata);

/**
 * @brief Accessor to an RGB palette image by reference
 * data format: unsigned char array (size 3 * w * h) r,g,b
 * @param[in] w image width
 * @param[in] h image height
 * @param[out] data pointer to unsigned char array allocate by the user (size of 3 * w * h)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_get_palette_image(int* w, int* h, unsigned char* data);

/**
 * @brief Accessor to an RGB palette image by reference for multiple cameras
 * data format: unsigned char array (size 3 * w * h) r,g,b
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] w image width
 * @param[in] h image height
 * @param[out] data pointer to unsigned char array allocate by the user (size of 3 * w * h)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_palette_image(const unsigned int camId, int* w, int* h, unsigned char* data);

/**
 * @brief Accessor to an RGB palette image and frame metadata by reference
 * data format: unsigned char array (size 3 * w * h) r,g,b
 * @param[in] w image width
 * @param[in] h image height
 * @param[out] data pointer to unsigned char array allocate by the user (size of 3 * w * h)
 * @param[out] metadata pointer to EvoIRFrameMetadata allocate by the user
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_get_palette_image_metadata(int* w, int* h, unsigned char* data, EvoIRFrameMetadata* metadata);

/**
 * @brief Accessor to an RGB palette image and frame metadata by reference for multiple cameras
 * data format: unsigned char array (size 3 * w * h) r,g,b
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] w image width
 * @param[in] h image height
 * @param[out] data pointer to unsigned char array allocate by the user (size of 3 * w * h)
 * @param[out] metadata pointer to EvoIRFrameMetadata allocate by the user
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_palette_image_metadata(const unsigned int camId, int* w, int* h, unsigned char* data, EvoIRFrameMetadata* metadata);

/**
 * @brief Accessor to an RGB palette image and a thermal image by reference
 * @param[in] w_t width of thermal image
 * @param[in] h_t height of thermal image
 * @param[out] data_t data pointer to unsigned short array allocate by the user (size of w * h)
 * @param[in] w_p width of palette image (can differ from thermal image width due to striding)
 * @param[in] h_p height of palette image (can differ from thermal image height due to striding)
 * @param[out] data_p data pointer to unsigned char array allocate by the user (size of 3 * w * h)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_get_thermal_palette_image(int w_t, int h_t, unsigned short* data_t, int w_p, int h_p, unsigned char* data_p );

/**
 * @brief Accessor to an RGB palette image and a thermal image by reference for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] w_t width of thermal image
 * @param[in] h_t height of thermal image
 * @param[out] data_t data pointer to unsigned short array allocate by the user (size of w * h)
 * @param[in] w_p width of palette image (can differ from thermal image width due to striding)
 * @param[in] h_p height of palette image (can differ from thermal image height due to striding)
 * @param[out] data_p data pointer to unsigned char array allocate by the user (size of 3 * w * h)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_thermal_palette_image(const unsigned int camId, int w_t, int h_t, unsigned short* data_t, int w_p, int h_p, unsigned char* data_p );

/**
 * @brief Accessor to an RGB palette image, thermal imagea and frame metadat by reference
 * @param[in] w_t width of thermal image
 * @param[in] h_t height of thermal image
 * @param[out] data_t data pointer to unsigned short array allocate by the user (size of w * h)
 * @param[in] w_p width of palette image (can differ from thermal image width due to striding)
 * @param[in] h_p height of palette image (can differ from thermal image height due to striding)
 * @param[out] data_p data pointer to unsigned char array allocate by the user (size of 3 * w * h)
 * @param[out] metadata pointer to EvoIRFrameMetadata allocate by the user
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_get_thermal_palette_image_metadata(int w_t, int h_t, unsigned short* data_t, int w_p, int h_p, unsigned char* data_p, EvoIRFrameMetadata* metadata);

/**
 * @brief Accessor to an RGB palette image, thermal image and frame metadata by reference for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] w_t width of thermal image
 * @param[in] h_t height of thermal image
 * @param[out] data_t data pointer to unsigned short array allocate by the user (size of w * h)
 * @param[in] w_p width of palette image (can differ from thermal image width due to striding)
 * @param[in] h_p height of palette image (can differ from thermal image height due to striding)
 * @param[out] data_p data pointer to unsigned char array allocate by the user (size of 3 * w * h)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_thermal_palette_image_metadata(const unsigned int camId, int w_t, int h_t, unsigned short* data_t, int w_p, int h_p, unsigned char* data_p, EvoIRFrameMetadata* metadata);


/**
 * @brief sets palette format.
 * Defined in IRImager Direct-SDK, see
 * enum EnumOptrisColoringPalette{eAlarmBlue   = 1,
 *                                eAlarmBlueHi = 2,
 *                                eGrayBW      = 3,
 *                                eGrayWB      = 4,
 *                                eAlarmGreen  = 5,
 *                                eIron        = 6,
 *                                eIronHi      = 7,
 *                                eMedical     = 8,
 *                                eRainbow     = 9,
 *                                eRainbowHi   = 10,
 *                                eAlarmRed    = 11 };
 *
 * @param id palette id
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_set_palette(int paletteId);

/**
 * @brief sets palette format for multiple cameras.
 * Defined in IRImager Direct-SDK, see
 * enum EnumOptrisColoringPalette{eAlarmBlue   = 1,
 *                                eAlarmBlueHi = 2,
 *                                eGrayBW      = 3,
 *                                eGrayWB      = 4,
 *                                eAlarmGreen  = 5,
 *                                eIron        = 6,
 *                                eIronHi      = 7,
 *                                eMedical     = 8,
 *                                eRainbow     = 9,
 *                                eRainbowHi   = 10,
 *                                eAlarmRed    = 11 };
 *
 * @param[in] camId Camera instance id  from init to apply this function
 * @param paletteId palette id
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_set_palette(const unsigned int camId, int paletteId);


/**
 * @brief sets palette scaling method
 * Defined in IRImager Direct-SDK, see
 * enum EnumOptrisPaletteScalingMethod{eManual = 1,
 *                                     eMinMax = 2,
 *                                     eSigma1 = 3,
 *                                     eSigma3 = 4 };
 * @param scale scaling method id
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_set_palette_scale(int scale);

/**
 * @brief sets palette scaling method for multiple cameras
 * Defined in IRImager Direct-SDK, see
 * enum EnumOptrisPaletteScalingMethod{eManual = 1,
 *                                     eMinMax = 2,
 *                                     eSigma1 = 3,
 *                                     eSigma3 = 4 };
 * @param[in] camId Camera instance id  from init to apply this function
 * @param scale scaling method id
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_set_palette_scale(const unsigned int camId, int scale);

/**
 * @brief Only available in eManual palette scale mode. Sets palette manual scaling temperature range.
 * @param min Minimum temperature
 * @param max Maximum temperature
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_set_palette_manual_temp_range(float min, float max);

/**
 * @brief Only available in eManual palette scale mode. Sets palette manual scaling temperature range for multiple cameras.
 * @param[in] camId Camera instance id  from init to apply this function
 * @param min Minimum temperature
 * @param max Maximum temperature
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_set_palette_manual_temp_range(const unsigned int camId, float min, float max);

/**
 * @brief sets shutter flag control mode
 * @param mode 0 means manual control, 1 means automode
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_set_shutter_mode(int mode);

/**
 * @brief sets shutter flag control mode for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] mode 0 means manual control, 1 means automode
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_set_shutter_mode(const unsigned int camId, int mode);

/**
 * @brief forces a shutter flag cycle
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_trigger_shutter_flag();

/**
 * @brief forces a shutter flag cycle for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_trigger_shutter_flag(const unsigned int camId);

/**
 * @brief sets the minimum and maximum remperature range to the camera. Only values which are defined in teh optris cali files are supported. (also configurable in xml-config)
 * @param[in] t_min Minimal temperature (has to be defined in the optris cali files) 
 * @param[in] t_min Maximal temperature (has to be defined in the optris cali files)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_set_temperature_range(int t_min, int t_max);

/**
 * @brief sets the minimum and maximum remperature range to the camera. Only values which are defined in teh optris cali files are supported. (also configurable in xml-config) for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] t_min Minimal temperature (has to be defined in the optris cali files) 
 * @param[in] t_min Maximal temperature (has to be defined in the optris cali files)
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_set_temperature_range(const unsigned int camId, int t_min, int t_max);

/**
 * @brief sets radiation properties, i.e. emissivity and transmissivity parameters (not implemented for TCP connection, usb mode only)
 * @param[in] emissivity emissivity of observed object [0;1]
 * @param[in] transmissivity transmissivity of observed object [0;1]
 * @param[in] tAmbient ambient temperature, setting invalid values (below -273,15 degrees) forces the library to take its own measurement values.
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_set_radiation_parameters(float emissivity, float transmissivity, float tAmbient);

/**
 * @brief sets radiation properties, i.e. emissivity and transmissivity parameters (not implemented for TCP connection, usb mode only) for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] emissivity emissivity of observed object [0;1]
 * @param[in] transmissivity transmissivity of observed object [0;1]
 * @param[in] tAmbient ambient temperature, setting invalid values (below -273,15 degrees) forces the library to take its own measurement values.
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_set_radiation_parameters(const unsigned int camId, float emissivity, float transmissivity, float tAmbient);

#ifdef _WIN32
/**
* @brief saves thermal image as png on given path
* @return error code: 0 on success, -1 on error
*/
__IRDIRECTSDK_API__ int evo_irimager_to_palette_save_png(unsigned short* thermal_data, int w, int h, const char* path, int palette, int palette_scale);

/**
* @brief saves thermal image as png on given path and given decimal places
* @return error code: 0 on success, -1 on error
*/
__IRDIRECTSDK_API__ int evo_irimager_to_palette_save_png_high_precision(unsigned short* thermal_data, int w, int h, const char* path, int palette, int palette_scale, short decimalPlaces);
#endif

/**
 * @brief Set the position of the focusmotor
 * @param[in] pos fucos motor position in %
 * @return error code: 0 on success, -1 on error or if no focusmotor is available
 */
__IRDIRECTSDK_API__ int evo_irimager_set_focusmotor_pos(float pos);

/**
 * @brief Set the position of the focusmotor for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] pos fucos motor position in %
 * @return error code: 0 on success, -1 on error or if no focusmotor is available
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_set_focusmotor_pos(const unsigned int camId, float pos);

/**
 * @brief Get the position of the focusmotor
 * @param[out] posOut Data pointer to float for current fucos motor position in % (< 0 if no focusmotor available)
 * @return error code: 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_get_focusmotor_pos(float *posOut);

/**
 * @brief Get the position of the focusmotor for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[out] posOut Data pointer to float for current fucos motor position in % (< 0 if no focusmotor available)
 * @return error code: 0 on success, -1 on error
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_get_focusmotor_pos(const unsigned int camId, float *posOut);

/**
 * @brief sets the framesync output
 * @param[in] aoChannelId Analog Output Channel for framesync starting with 0
 * @param[in] analogOutputMode Determines the output range and voltage or current mode (depends on used PIF-Device)
 * enum IRChannelAnalogOutputMode {
 *   Range_0V_10V = 0,   ///< Set output range to 0V..10V
 *   Range_0mA_20mA = 1, ///< Set output range to 0mA..20mA
 *   Range_4mA_20mA = 2, ///< Set output range to 4mA..20mA
 * };
 * @param[in] analogValue Analog Output Voltage/Milliampere on Frame for syncing
 */
__IRDIRECTSDK_API__ int evo_irimager_set_pif_framesync_output(const unsigned int aoChannelId, unsigned int analogOutputMode, float analogValue);

/**
 * @brief sets the framesync output for multiple cameras
 * @param[in] camId Camera instance id  from init to apply this function
 * @param[in] aoChannelId Analog Output Channel for framesync starting with 0
 * @param[in] analogOutputMode Determines the output range and voltage or current mode (depends on used PIF-Device)
 * enum IRChannelAnalogOutputMode {
 *   Range_0V_10V = 0,   ///< Set output range to 0V..10V
 *   Range_0mA_20mA = 1, ///< Set output range to 0mA..20mA
 *   Range_4mA_20mA = 2, ///< Set output range to 4mA..20mA
 * };
 * @param[in] analogValue Analog Output Voltage/Milliampere on Frame for syncing
 */
__IRDIRECTSDK_API__ int evo_irimager_multi_set_pif_framesync_output(const unsigned int camId, const unsigned int aoChannelId, unsigned int analogOutputMode, float analogValue);


/*-------------------------------------------------*/
/*-------------------- DAEMON ---------------------*/
/*-------------------------------------------------*/

/**
 * Launch TCP daemon
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_daemon_launch();

/**
 * Check whether daemon is already running
 * @return error code: 0 daemon is already active, -1 daemon is not started yet
 */
__IRDIRECTSDK_API__ int evo_irimager_daemon_is_running();

/**
 * Kill TCP daemon
 * @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)
 */
__IRDIRECTSDK_API__ int evo_irimager_daemon_kill();

#ifdef  __cplusplus
}
#endif

#endif /* DIRECT_BINDING_H_ */
