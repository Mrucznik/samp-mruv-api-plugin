include(AMXConfig)
include(AddSAMPPlugin)

set(SAMP_SDK_ROOT "${PROJECT_SOURCE_DIR}/lib/samp-plugin-sdk")
find_package(SAMPSDK REQUIRED)

include_directories(
        ${SAMPSDK_INCLUDE_DIR}
)

include_directories(
        ${PROJECT_SOURCE_DIR}/lib/mruv-pb-cpp
)

add_samp_plugin(mruvapi
        ${SAMPSDK_DIR}/amxplugin.cpp
        ${SAMPSDK_DIR}/amxplugin2.cpp
        ${SAMPSDK_DIR}/amx/getch.c
        common.hpp
        main.cpp
        impl.cpp
        impl.hpp
        natives.cpp
        natives.hpp
        plugin.def

        API.h
        API.cpp
        AsyncClientCall.h
        AsyncClientCall.cpp
        CCallback.hpp
        CCallback.cpp
        CLog.hpp
        CLog.cpp
        CError.hpp
        CSingleton.hpp

        #mruv-pb-cpp
        ../lib/mruv-pb-cpp/accounts/accounts.grpc.pb.cc
        ../lib/mruv-pb-cpp/accounts/accounts.pb.cc
        ../lib/mruv-pb-cpp/accounts/accounts_model.grpc.pb.cc
        ../lib/mruv-pb-cpp/accounts/accounts_model.pb.cc
        ../lib/mruv-pb-cpp/characters/characters.grpc.pb.cc
        ../lib/mruv-pb-cpp/characters/characters.pb.cc
        ../lib/mruv-pb-cpp/characters/characters_model.grpc.pb.cc
        ../lib/mruv-pb-cpp/characters/characters_model.pb.cc
        ../lib/mruv-pb-cpp/common/health.grpc.pb.cc
        ../lib/mruv-pb-cpp/common/health.pb.cc
        ../lib/mruv-pb-cpp/common/spatial.grpc.pb.cc
        ../lib/mruv-pb-cpp/common/spatial.pb.cc
        ../lib/mruv-pb-cpp/devtools/devtools.grpc.pb.cc
        ../lib/mruv-pb-cpp/devtools/devtools.pb.cc
        ../lib/mruv-pb-cpp/devtools/devtools_model.grpc.pb.cc
        ../lib/mruv-pb-cpp/devtools/devtools_model.pb.cc
        ../lib/mruv-pb-cpp/groups/groups.grpc.pb.cc
        ../lib/mruv-pb-cpp/groups/groups.pb.cc
        ../lib/mruv-pb-cpp/groups/groups_model.grpc.pb.cc
        ../lib/mruv-pb-cpp/groups/groups_model.pb.cc
        ../lib/mruv-pb-cpp/items/items.grpc.pb.cc
        ../lib/mruv-pb-cpp/items/items.pb.cc
        ../lib/mruv-pb-cpp/items/items_model.grpc.pb.cc
        ../lib/mruv-pb-cpp/items/items_model.pb.cc
        ../lib/mruv-pb-cpp/server/server.grpc.pb.cc
        ../lib/mruv-pb-cpp/server/server.pb.cc
        ../lib/mruv-pb-cpp/server/server_model.grpc.pb.cc
        ../lib/mruv-pb-cpp/server/server_model.pb.cc

        ../lib/mruv-pb-cpp/google/api/annotations.grpc.pb.cc
        ../lib/mruv-pb-cpp/google/api/annotations.pb.cc
        ../lib/mruv-pb-cpp/google/api/http.grpc.pb.cc
        ../lib/mruv-pb-cpp/google/api/http.pb.cc
)

target_link_libraries(mruvapi grpc++ log-core fmt)

get_target_property(LOGCORE_LOCATION log-core LOCATION)
install(FILES "${LOGCORE_LOCATION}" DESTINATION "./")
