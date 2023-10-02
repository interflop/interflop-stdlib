project("Interflop_stdlib")

# fmaqApprox.c was removed because of quad implementation depending on compiler runtime.
# PinCRT doesn't support this part of GCC C library
# usage of fmaq for single and double precision was replaced by fmal (lib math)
set (INTERFLOP_STDLIB_C_SRC
    # FMA
    "fma/fmaqApproxM.c"
    # # HASHMAP
    "hashmap/vfc_hashmap.c"
    # # IOSTREAM
    "iostream/logger.c"
    # PRNG
    "prng/tinymt64.c"
    # # RNG
    "rng/splitmix64.c"
    "rng/vfc_rng.c"
    "rng/xoroshiro128.c"
    "interflop_stdlib.c"
)

set (INTERFLOP_STDLIB_CXX_SRC
    # FMA
    "fma/interflop_fma.cxx"
    # PRNG
    "prng/xoshiro.cxx"
)

add_library(interflop_stdlib_c OBJECT ${INTERFLOP_STDLIB_C_SRC})
target_compile_definitions(interflop_stdlib_c PRIVATE ${CRT_COMPILE_DEFINITIONS})
target_compile_options (interflop_stdlib_c PRIVATE ${CRT_PREPROCESS_OPTIONS} ${CRT_COMPILE_OPTIONS})


add_library(interflop_stdlib_cxx OBJECT ${INTERFLOP_STDLIB_CXX_SRC})
target_compile_definitions(interflop_stdlib_cxx PRIVATE  ${CRT_COMPILE_DEFINITIONS})
target_compile_options (interflop_stdlib_cxx PRIVATE ${CRT_PREPROCESS_OPTIONS} ${CRT_COMPILE_OPTIONS} ${CRT_CXX_COMPILE_OPTIONS})



add_library (interflop_stdlib SHARED $<TARGET_OBJECTS:interflop_stdlib_c>  $<TARGET_OBJECTS:interflop_stdlib_cxx>)
target_link_options (interflop_stdlib PRIVATE ${CRT_LINK_OPTIONS})
target_link_libraries (interflop_stdlib ${CRT_LINK_LIBRARIES})