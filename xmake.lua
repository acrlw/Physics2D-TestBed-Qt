add_rules("mode.debug", "mode.release")
set_languages("c++20")


target("Physics2D-TestBed-Qt")
    add_rules("qt.application")
    add_headerfiles("Physics2D-TestBed-Qt/include/*.h")
    add_files("Physics2D-TestBed-Qt/dependencies/Physics2D/*.cpp")
    add_includedirs("Physics2D-TestBed-Qt/include")
    add_files("Physics2D-TestBed-Qt/source/*.cpp")
    add_files("Physics2D-TestBed-Qt/main.cpp")
    add_files("Physics2D-TestBed-Qt/include/testbed.h")
    add_frameworks("QtWidgets")
    