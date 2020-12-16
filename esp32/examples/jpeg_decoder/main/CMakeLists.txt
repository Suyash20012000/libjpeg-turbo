idf_component_register(SRCS "smtp_client.c"
                            "esp_audio_mem.c"
                            "example_jpeg_decoder.c"
                        INCLUDE_DIRS "."
                        EMBED_TXTFILES server_root_cert.pem
                        EMBED_FILES test2_100.jpeg
                        REQUIRES nvs_flash protocol_examples_common mbedtls jpeg_turbo_codec)
