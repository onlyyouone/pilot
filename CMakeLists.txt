cmake_minimum_required(VERSION 3.0)

project(proj C)

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "\nIn-source builds not allowed.\n Please make a new directory (called a build directory) and run CMake from there.\n You may need to manually remove CMakeCache.txt")
    return()
endif()

#Set up packaging related variables.

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE})

set(EX_PROJ_PLATFORM "linux")
set(proj_LIBTYPE STATIC)
list(APPEND CMAKE_C_FLAGS "-std=c99 -pedantic-errors -Wall -fpic -fPIC")

# Global include file directory where all product header are located.
# And the target to create the directory
set(proj_INC "${CMAKE_CURRENT_SOURCE_DIR}/inc")
add_custom_target(make_inc_dir)
add_custom_command(TARGET make_inc_dir PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E make_directory ${proj_INC})

# Target to copy all header files into global header directory. 
file(GLOB_RECURSE INC "src/*.h" "src/*.inc" "src/obj_list*" )
add_custom_target(copy_inc_file)
foreach(incFile ${INC})
  add_custom_command(TARGET copy_inc_file PRE_BUILD
                     COMMAND ${CMAKE_COMMAND} -E
                         copy_if_different ${incFile} ${proj_INC}
 		 )
endforeach()

####
set(proj_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR})

file(GLOB_RECURSE SRCS "src/*.c" )
file(GLOB_RECURSE HDRS "src/*.h" )
source_group("src" FILES ${SRCS} ${HDRS} )

set(proj_SRC ${SRCS} ${proj_public_SRC})
add_library(proj STATIC ${SRCS})
# Make sure include files are copied to inc directory 
add_dependencies(copy_inc_file make_inc_dir)
add_dependencies(proj copy_inc_file)

include_directories(${INCLUDE_DIRECTORIES} ${proj_INC})
link_directories(${LINK_DIRECTORIES})

target_include_directories(proj PUBLIC ${proj_INC})
set_target_properties(proj PROPERTIES LINK_FLAGS "-fvisibility=hidden")
target_link_libraries(proj dl pthread rt)


# ------------------------------------------------------------------------------
# Clang Tidy
# ------------------------------------------------------------------------------
if(ENABLE_CLANG_TIDY)

    find_program(CLANG_TIDY_BIN clang-tidy-4.0)
    find_program(RUN_CLANG_TIDY_BIN run-clang-tidy-4.0.py)

    if(CLANG_TIDY_BIN STREQUAL "CLANG_TIDY_BIN-NOTFOUND")
        message(FATAL_ERROR "unable to locate clang-tidy-4.0")
    endif()

    if(RUN_CLANG_TIDY_BIN STREQUAL "RUN_CLANG_TIDY_BIN-NOTFOUND")
        message(FATAL_ERROR "unable to locate run-clang-tidy-4.0.py")
    endif()

    list(APPEND RUN_CLANG_TIDY_BIN_ARGS
        -clang-tidy-binary ${CLANG_TIDY_BIN}
        -header-filter=.*
        -checks=clan*,cert*,misc*,perf*,cppc*,read*,mode*,-cert-err58-cpp,-misc-noexcept-move-constructor
    )

    add_custom_target(
        tidy
        COMMAND ${RUN_CLANG_TIDY_BIN} ${RUN_CLANG_TIDY_BIN_ARGS}
        COMMENT "running clang tidy"
    )

endif()


# ------------------------------------------------------------------------------
# Coverage
# ------------------------------------------------------------------------------

if(ENABLE_COVERAGE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# ------------------------------------------------------------------------------
# Google Sanitizers
# ------------------------------------------------------------------------------

if(ENABLE_ASAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
endif()

if(ENABLE_USAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
endif()

if(ENABLE_TSAN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
endif()

# ------------------------------------------------------------------------------
# Valgrind
# ------------------------------------------------------------------------------

set(MEMORYCHECK_COMMAND_OPTIONS "${MEMORYCHECK_COMMAND_OPTIONS} --leak-check=full")
set(MEMORYCHECK_COMMAND_OPTIONS "${MEMORYCHECK_COMMAND_OPTIONS} --track-fds=yes")
set(MEMORYCHECK_COMMAND_OPTIONS "${MEMORYCHECK_COMMAND_OPTIONS} --trace-children=yes")
set(MEMORYCHECK_COMMAND_OPTIONS "${MEMORYCHECK_COMMAND_OPTIONS} --error-exitcode=1")

# ------------------------------------------------------------------------------
# Main Executable
# ------------------------------------------------------------------------------

# add_executable(ci_helloworld src/main.cpp)
# add_dependencies(ci_helloworld gsl)
# target_compile_definitions(ci_helloworld PRIVATE VIRTUAL= MAIN=main)

# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------

include(CMake_Tests.txt)

