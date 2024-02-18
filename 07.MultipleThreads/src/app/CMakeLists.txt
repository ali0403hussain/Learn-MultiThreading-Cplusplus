set(EXE_SRC main.cpp)

add_executable(${EXE} ${EXE_SRC})

if(${ENABLE_WARNINGS})
    target_set_warnings(${EXE}
                        ${ENABLE_WARNINGS}
                        ${ENABLE_WARNINGS_AS_ERRORS})
endif()