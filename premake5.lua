workspace "Notepad"
    architecture "x86_64"
    startproject "Main"

    configurations { "Debug", "Release" }

    flags { "MultiProcessorCompile" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Tools"
    include "vendor/premake"

group ""

include "Main"
include "Arithmetic"