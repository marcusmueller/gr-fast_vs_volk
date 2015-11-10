INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_FAST_VS_VOLK fast_vs_volk)

FIND_PATH(
    FAST_VS_VOLK_INCLUDE_DIRS
    NAMES fast_vs_volk/api.h
    HINTS $ENV{FAST_VS_VOLK_DIR}/include
        ${PC_FAST_VS_VOLK_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    FAST_VS_VOLK_LIBRARIES
    NAMES gnuradio-fast_vs_volk
    HINTS $ENV{FAST_VS_VOLK_DIR}/lib
        ${PC_FAST_VS_VOLK_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FAST_VS_VOLK DEFAULT_MSG FAST_VS_VOLK_LIBRARIES FAST_VS_VOLK_INCLUDE_DIRS)
MARK_AS_ADVANCED(FAST_VS_VOLK_LIBRARIES FAST_VS_VOLK_INCLUDE_DIRS)

