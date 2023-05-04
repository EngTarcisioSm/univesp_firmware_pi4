idf_component_register(SRCS "internet.c"
                    INCLUDE_DIRS "include"
                    REQUIRES INFOSYS
                    PRIV_REQUIRES main nvs_flash 
                    )

