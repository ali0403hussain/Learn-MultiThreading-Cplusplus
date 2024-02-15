function(add_sanitizers_flags)
    if((NOT ${NABLE_SANITIZE_ADDR}) AND (NOT ${ENABLE_SANITIZE_UNDEF}))
        message(STATUS "Sanitizers deactivated")
        return()
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "CLANG" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options("-fno-omit-frame-pointer")
        add_link_options("-fno-omit-frame-pointer")

        if(${ENABLE_SANITIZE_ADDR})
            add_compile_options("-fsanitize=address")
            add_link_options("-fsanitize=address")
        endif()

        if(${ENABLE_SANITIZE_UNDEF})
            add_compile_options("-fsanitize=undefined")
            add_link_options("-fsanitize=undefined")
        endif()

        message(STATUS "Sanitizers activated for ${CMAKE_CXX_COMPILER_ID}")

    elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")

        if(${ENABLE_SANITIZE_ADDR})
            add_compile_options("-/fsanitize=address")
        endif()

        if(${ENABLE_SANITIZE_UNDEF})
            message(STATUS "Undefined sanitizers not Implemented for MSVC")
        endif()

        message(STATUS "Sanitizers activated for ${CMAKE_CXX_COMPILER_ID}")
        
    else()
        message(ERROR "Compiler Not supported for Sanitizers")
    endif()
    
endfunction(add_sanitizers_flags)