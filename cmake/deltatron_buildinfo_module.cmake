add_library("buildinfo" INTERFACE)

target_compile_options(buildinfo
  INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++latest /EHsc>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:--std=c++17>)

target_compile_definitions(buildinfo
  INTERFACE
    $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:DT_DEBUG>
    $<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>)
