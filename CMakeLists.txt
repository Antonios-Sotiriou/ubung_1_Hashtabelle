cmake_minimum_required (VERSION 3.20)

# Aktivieren Sie Hot Reload für MSVC-Compiler, sofern unterstützt.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (hashtable)

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (hashtable "main.cpp" "headers/menu.h" "source/menu.cpp" "headers/structs.h" "headers/main.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET hashtable PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(hashtable PUBLIC "${PROJECT_SOURCE_DIR}/")

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.