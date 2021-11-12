# ThermalRecorder
Matlab App for Optris Pi405i direct SDK
--
_PColor_Mchanels.mlapp_ is just a GUI based on evocortex direct SDK for Optris Pi cameras
SDK download address: https://evocortex.org/downloads/  
  
**********************************************************************  

  MATLAB Interface for Optris PI-Series  
	
  Version Information:  libirimager 2.1.0		  
  Date:                 July 10th, 2017  
  Documentation:        www.evocortex.com		  		
  Contact:              direct-sdk@optris.com  
					
**********************************************************************  

1) Dependencies:
  The library is built with toolset version v120 (Visual Studio 2013). 
  Get the Redistributable packages for 32-Bit-Systems from (*1) and 
  for 64-Bit-Systems from (*2).
  
2) Additional Software
  To use the library libirimager via MATLAB's loadlibrary() command a 
  compatible compiler must be available on the system. See (*3) for 
  detailed information.
  
  Successfully tested compilers are:   
    - MinGW 4.9  
    __- Microsoft Visual C++ 2013 Professional__  
    __- Microsoft Windows SDK 7.1__  

**********************************************************************

*1) https://download.microsoft.com/download/2/E/6/2E61CFA4-993B-4DD4-91DA-3737CD5CD6E3/vcredist_x86.exe

*2) https://download.microsoft.com/download/2/E/6/2E61CFA4-993B-4DD4-91DA-3737CD5CD6E3/vcredist_x64.exe

*3) https://de.mathworks.com/support/compilers.html

--
> /**
>  * @brief sets palette format to daemon.  
> * Defined in IRImager Direct-SDK, see  
 > enum EnumOptrisColoringPalette{eAlarmBlue   = 1,  
 >                                eAlarmBlueHi = 2,  
 >                                eGrayBW      = 3,  
 >                                eGrayWB      = 4,  
 >                                eAlarmGreen  = 5,  
 >                                eIron        = 6,  
 >                                eIronHi      = 7,  
 >                                eMedical     = 8,  
 >                                eRainbow     = 9,  
 >                                eRainbowHi   = 10,  
 >                                eAlarmRed    = 11 };  
 >
 > @param id palette id  
 > @return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)  
 >*/  
>__IRDIRECTSDK_API__ int evo_irimager_set_palette(int id);  
>  
>/**  
> @brief sets palette scaling method  
> Defined in IRImager Direct-SDK, see  
> enum EnumOptrisPaletteScalingMethod{eManual = 1,  
>                                     eMinMax = 2,  
>                                     eSigma1 = 3,  
>                                    eSigma3 = 4 };  
> @param scale scaling method id  
>@return error code: 0 on success, -1 on error, -2 on fatal error (only TCP connection)  
> */  
--
