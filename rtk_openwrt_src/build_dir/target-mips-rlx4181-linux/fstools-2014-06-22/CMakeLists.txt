cmake_minimum_required(VERSION 2.6)

PROJECT(fs-tools C)
ADD_DEFINITIONS(-Os -ggdb -Wall -Werror --std=gnu99 -Wmissing-declarations)

SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

ADD_LIBRARY(fstools SHARED
		libfstools/snapshot.c
		libfstools/extroot.c
		libfstools/overlay.c
		libfstools/volume.c
		libfstools/mtd.c
		libfstools/mount.c
		libfstools/ubi.c
		libfstools/find.c)
TARGET_LINK_LIBRARIES(fstools ubox)
INSTALL(TARGETS fstools LIBRARY DESTINATION lib)

ADD_LIBRARY(blkid-tiny SHARED
		libblkid-tiny/libblkid-tiny.c
		libblkid-tiny/mkdev.c
		libblkid-tiny/ext.c
		libblkid-tiny/jffs2.c
		libblkid-tiny/vfat.c
		libblkid-tiny/hfs.c
		libblkid-tiny/swap.c
		libblkid-tiny/ubifs.c
		libblkid-tiny/squashfs.c)
INSTALL(TARGETS blkid-tiny LIBRARY DESTINATION lib)

ADD_LIBRARY(ubi-utils STATIC
		libubi/libubi.c
		libubi/libubi-tiny.c
		libubi/ubiutils-common.c)
INSTALL(TARGETS ubi-utils ARCHIVE DESTINATION lib)

SET_TARGET_PROPERTIES(ubi-utils PROPERTIES COMPILE_FLAGS
		"-ffunction-sections -fdata-sections")

INSTALL(FILES libubi/libubi-tiny.h libubi/libubi.h libubi/ubi-media.h
		libubi/ubi-user.h libubi/ubi-media.h
	DESTINATION include
)

ADD_EXECUTABLE(mount_root mount_root.c)
TARGET_LINK_LIBRARIES(mount_root fstools)
INSTALL(TARGETS mount_root RUNTIME DESTINATION sbin)

ADD_EXECUTABLE(block block.c)
TARGET_LINK_LIBRARIES(block blkid-tiny uci ubox blobmsg_json)
INSTALL(TARGETS block RUNTIME DESTINATION sbin)

ADD_EXECUTABLE(jffs2reset jffs2reset.c)
TARGET_LINK_LIBRARIES(jffs2reset fstools)
INSTALL(TARGETS jffs2reset RUNTIME DESTINATION sbin)

ADD_EXECUTABLE(snapshot_tool snapshot.c)
TARGET_LINK_LIBRARIES(snapshot_tool fstools)
INSTALL(TARGETS snapshot_tool RUNTIME DESTINATION sbin)

ADD_EXECUTABLE(ubi ubi.c)
TARGET_LINK_LIBRARIES(ubi ubi-utils)
INSTALL(TARGETS ubi RUNTIME DESTINATION sbin)
