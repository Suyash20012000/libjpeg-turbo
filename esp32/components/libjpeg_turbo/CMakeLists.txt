# Need to find a way to avoid "./../../../"

set(esp32_simd 1)
                              set(srcs 
                                 "./../../../jcapistd.c"
                                 "./../../../jcapimin.c"
                                 "./../../../jccoefct.c"
                                 "./../../../jccolor.c"
                                 "./../../../jcdctmgr.c"
                                 "./../../../jchuff.c"
                                 "./../../../jcicc.c"
                                 "./../../../jcinit.c"
                                 "./../../../jcmainct.c"
                                 "./../../../jcmarker.c"
                                 "./../../../jcmaster.c"
                                 "./../../../jcomapi.c"
                                 "./../../../jcparam.c"
                                 "./../../../jcphuff.c"
                                 "./../../../jcprepct.c"
                                 "./../../../jcsample.c"
                                 "./../../../jctrans.c"
                                 "./../../../jdapimin.c"
                                 "./../../../jdapistd.c"
                                 "./../../../jdatadst.c"
                                 "./../../../jdatasrc.c"
                                 "./../../../jdcoefct.c"
                                 "./../../../jdcolor.c"
                                 "./../../../jddctmgr.c"
                                 "./../../../jdhuff.c"
                                 "./../../../jdicc.c"
                                 "./../../../jdinput.c"
                                 "./../../../jdmainct.c"
                                 "./../../../jdmarker.c"
                                 "./../../../jdmaster.c"
                                 "./../../../jdmerge.c"
                                 "./../../../jdphuff.c"
                                 "./../../../jdpostct.c"
                                 "./../../../jdsample.c"
                                 "./../../../jdtrans.c"
                                 "./../../../jerror.c"
                                 "./../../../jfdctflt.c"
                                 "./../../../jfdctfst.c"
                                 "./../../../jfdctint.c"
                                 "./../../../jidctflt.c"
                                 "./../../../jidctfst.c"
                                 "./../../../jidctint.c"
                                 "./../../../jidctred.c"
                                 "./../../../jquant1.c"
                                 "./../../../jquant2.c"
                                 "./../../../jutils.c"
                                 "./../../../jmemmgr.c"
                                 "./../../../jmemnobs.c"
                                 "./../../../cjpeg.c"
                                 "./../../../djpeg.c"
                                 "./../../../cdjpeg.c"
                                 "./../../../rdgif.c"
                                 "./../../../rdppm.c"
                                 "./../../../rdswitch.c"
                                 "./../../../jaricom.c"
                                 "./../../../jcarith.c"
                                 "./../../../jdarith.c"
                                 )

if(esp32_simd)
list(APPEND srcs "./../../../simd/esp32/jsimd.c")
message("FLAG IS SET")
else()
message("FLAG IS NOT SET")
list(APPEND srcs "./../../../jsimd_none.c")
endif()

idf_component_register(SRCS "${srcs}"

                       INCLUDE_DIRS "./../../../."
                       )
