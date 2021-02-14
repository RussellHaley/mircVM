package("mirVM")

set_homepage("https://github.com/vnmakarov/mir.git")
set_description("Medium Internal Representation (MIR) VM. A library for fast and lightweight interpreters and JITs by Vladimir Makarov.")
--set(CMAKE_BUILD_TYPE "RelWithDebInfo")

target("mir")
	local mir_dir="mir/"
	set_kind("static")
	add_files(mir_dir.."mir.c", mir_dir.."mir-gen.c", mir_dir.."c2mir/c2mir.c")
	if is_arch("arm*") then
		add_defines("MIR_ARMV7")
		print("Added Define?")
	
	end
	--~ add_defines("MIR_PARALLEL_GEN")
	--~ add_links("pthread")
	add_includedirs(mir_dir)

target("c2m")
	set_kind("binary")
	add_includedirs(mir_dir)
	add_files(mir_dir.."c2mir/c2mir-driver.c")
	add_deps("mir")
	add_links("dl")

target("b2m")
	set_kind("binary")
	add_includedirs(mir_dir)
	add_files(mir_dir.."mir-utils/b2m.c")
	add_deps("mir")

target("m2b")
	set_kind("binary")
	add_includedirs(mir_dir)
	add_files(mir_dir.."mir-utils/m2b.c")
	add_deps("mir")

target("b2ctab")
	set_kind("binary")
	add_includedirs(mir_dir)
	add_files(mir_dir.."mir-utils/b2ctab.c")
	add_deps("mir")

--~ if(NOT WIN32)
  --~ add_compile_options(
    --~ $<$<CONFIG:RELEASE>:-O3>
    --~ $<$<CONFIG:RelWithDebInfo>:-O3>
  --~ )
  --~ add_compile_options(-std=gnu11 -Wno-abi -fsigned-char)
--~ endif()

--~ include(CheckCCompilerFlag)
--~ if(CMAKE_COMPILER_IS_GNUCC)
  --~ check_c_compiler_flag(-fno-tree-sra NO_TREE_SRA)
  --~ if (NO_TREE_SRA)
    --~ add_compile_options(-fno-tree-sra)
  --~ endif()
  --~ check_c_compiler_flag(-fno-ipa-cp-clone NO_IPA_CP_CLONE)
  --~ if (NO_IPA_CP_CLONE)
    --~ add_compile_options(-fno-ipa-cp-clone)
  --~ endif()
--~ endif()

