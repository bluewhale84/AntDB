#-------------------------------------------------------------------------
#
# Makefile--
#    Makefile for src/adbmgrd/postmaster
#
# IDENTIFICATION
#    src/adbmgrd/postmaster/Makefile
#
#-------------------------------------------------------------------------

subdir = src/adbmgrd/postmaster
top_builddir = ../../..
include $(top_builddir)/src/Makefile.global

OBJS = autovacuum.o bgworker.o bgwriter.o checkpointer.o fork_process.o \
	pgarch.o pgstat.o postmaster.o startup.o syslogger.o walwriter.o adbmonitor.o

include $(top_srcdir)/src/adbmgrd/common.mk
