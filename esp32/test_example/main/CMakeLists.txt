idf_component_register(SRCS "jpeg_test.c"
                            "esp_audio_mem.c"
                        INCLUDE_DIRS "."
                        EMBED_TXTFILES server_root_cert.pem
                        REQUIRES nvs_flash protocol_examples_common jpeg_turbo_codec)
