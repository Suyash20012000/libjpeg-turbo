idf_component_register(SRCS "src/jpeg_turbo_dec.c"
			                "src/jpeg_turbo_enc.c"
					"src/idct.c"
                       INCLUDE_DIRS "./include"
                       REQUIRES libjpeg_turbo)
