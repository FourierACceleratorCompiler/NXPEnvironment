
// which accelerator class to benchmark.
#define FFT 1
//#define CRC 1

// CRC Projects:
//#define PROJ_gityf_crc 1

#define TIMES_CRC 1000

// FFT Projects:
//#define PROJ_akw0088_fft
//#define PROJ_cpuimage_cpuFFT 1
//#define PROJ_cpuimage_FFTResampler 1
//#define PROJ_cpuimage_StockhamFFT 1
//#define PROJ_dlinyj_fft 1
//#define PROJ_gregfjohnson_fft 1
//#define PROJ_JodiTheTigger_meow_fft 1
//#define PROJ_jtfell_c_fft 1
//#define PROJ_liscio_fft 1
#define PROJ_marton78_pffft 1
//#define PROJ_mborgerding_kissfft 1
//#define PROJ_MiBench_MiBench 1
//#define PROJ_mozanunal_SimpleDSP 1
//#define PROJ_omnister_fftp 1
//#define PROJ_tasimon_FFT 1
//#define PROJ_xbarin02_uFFT 1
//#define PROJ_xbarin02_uFFT_2 1
//#define PROJ_xiahouzouxin_fft 1


// Define one of the below to run either the original or the accelerator.
#define RUNFUN run_original
//#define RUNFUN run_accelerator


/* Add your custom header content here */
#define TIMES 100 // How many times to do FFT per loop
#define BENCHMARK_TIMES 2 // How many times to loop over the entire suite:
// timings are deterministic, so just loop enough to show that.
