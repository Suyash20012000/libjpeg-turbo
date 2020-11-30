idf_component_register(SRCS "decoder_def.c"
			    "encoder_def.c"
                       INCLUDE_DIRS "."
                       REQUIRES nvs_flash protocol_examples_common mbedtls libjpeg-turbo)
