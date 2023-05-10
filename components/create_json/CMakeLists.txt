idf_component_register(SRCS "create_json.c"
                    INCLUDE_DIRS "include"
                    REQUIRES INFOSYS capture_data time_sys
                    PRIV_REQUIRES main)
