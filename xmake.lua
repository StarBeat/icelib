
if is_plat("windows") then 
    add_cflags("/W3")
    if is_mode("debug") then 
        set_symbols("debug")
    end
elseif is_plat("linux") then 
    add_cflags("-std=gnu99", "-Wall", "-Wextra", "-pedantic")
    add_defines("CTEST_SEGFAULT")
end 

set_optimize("fast")

add_requires("xnet")
add_requires("stunlib")

target("icelib")
    set_kind("shared")
    
    add_packages("xnet")
    add_packages("stunlib")
    
    add_includedirs("include")
    add_headerfiles("include/**.h")
    add_files("src/fifo.c",
      "src/icelib.c",
      "src/timer.c",
      "src/icelibtypes.c")

target("icelib.test.icelib")
    set_kind("binary")
    
    set_group("icelib.test")
    add_deps("icelib")
    add_packages("xnet")
    add_packages("stunlib")
    
    add_includedirs("test")
    add_includedirs("include")
    add_files("test/test_utils.c")
    add_files("test/icelib_test.c")
target_end()

target("icelib.test.icelibtypes")
    set_kind("binary")
    
    set_group("icelib.test")
    add_deps("icelib")
    add_packages("xnet")
    add_packages("stunlib")
    
    add_includedirs("test")
    add_includedirs("include")
    add_files("test/test_utils.c")
    add_files("test/icelibtypes_test.c")
target_end()

target("icelib.test.icelib_running")
    set_kind("binary")
    
    set_group("icelib.test")
    add_deps("icelib")
    add_packages("xnet")
    add_packages("stunlib")
    
    add_includedirs("test")
    add_includedirs("include")
    add_files("test/test_utils.c")
    add_files("test/icelib_running_test.c")
target_end()

target("icelib.test.icelib_ce")
    set_kind("binary")
    
    set_group("icelib.test")
    add_packages("stunlib")
    add_packages("xnet")
    add_deps("icelib")
    
    add_includedirs("test")
    add_includedirs("include")
    add_files("test/test_utils.c")
    add_files("test/icelib_ce_test.c")
target_end()

target("icelib.test.icelib_nomination")
    set_kind("binary")
    
    set_group("icelib.test")
    add_packages("stunlib")
    add_packages("xnet")
    add_deps("icelib")
    
    add_includedirs("test")
    add_includedirs("include")
    add_files("test/test_utils.c")
    add_files("test/icelib_nomination_test.c")
target_end()

target("icelib.test.icelib_nomination_medialines")
    set_kind("binary")
    
    set_group("icelib.test")
    add_packages("stunlib")
    add_packages("xnet")
    add_deps("icelib")
    
    add_includedirs("test")
    add_includedirs("include")
    add_files("test/test_utils.c")
    add_files("test/icelib_nomination_medialines_test.c")
target_end()
