function(target_set_warnings TARGET ENABLE WARNINGS_AS_ERRORS)
    if(NOT ${ENABLE})
        message(STATUS "warnings disabled for : ${TARGET}")
        return()
    endif()

    set(MSVC_WARNINGS
        /W4
        /permissive-)
    set(CLANG_WARNINGS
        -Wall
        -Wextra
        -Wpedantic)
    set(GCC_WARNINGS ${CLANG_WARNINGS})

    if(${WARNINGS_AS_ERRORS})
        set(MSVC_WARNINGS ${MSVC_WARNINGS} /WX)
        set(CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
        set(GCC_WARNINGS ${GCC_WARNINGS} -Werror)
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(WARNINGS ${MSVC_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "CLANG")
        set(WARNINGS ${CLANG_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        set(WARNINGS ${GCC_WARNINGS})
    else()
        message(ERROR "Compiler Not Recognized : ${CMAKE_CXX_COMPILER_ID}")
    endif()

    target_compile_options(${TARGET} PRIVATE ${WARNINGS})

endfunction(target_set_warnings TARGET ENABLE WARNINGS_AS_ERRORS)